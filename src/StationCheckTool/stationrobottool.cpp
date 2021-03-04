#include "stationrobottool.h"
#include "qstring.h"
#include "basictool.h"
#include "qtimer.h"
#include <ctime>
#include "robotdata_imply.h"
#include "taskdata_imply.h"
#include "taskfinish_imply.h"
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
#include <Windows.h>
std::string GetExePath(void)
{
	char szFilePath[MAX_PATH + 1] = { 0 };
	GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
	(strrchr(szFilePath, '\\'))[0] = 0; // 删除文件名，只获得路径字串  
	std::string path = szFilePath;
	return path;
}

void StationRobotTool::ReadConfig(std::string file_path)
{
	rapidxml::file<> xml_file(file_path.c_str());
	rapidxml::xml_document<> document;
	document.parse<0>(xml_file.data());

	rapidxml::xml_node<>* root;
	root = document.first_node();
	if (root == NULL) {
		return;
	}
	while (root)
	{
		rapidxml::xml_node<>* node = root->first_node();
		if (strcmp(node->name(), "WebInfo") == 0)
		{
			rapidxml::xml_node<>* tcpinfo_node = node->first_node();
			rapidxml::xml_attribute<>* attr = tcpinfo_node->first_attribute();
			while (attr)
			{
				if (strcmp(attr->name(), "robotdata_addr") == 0)
				{
					robotdata_addr = attr->value();
				}
				else if (strcmp(attr->name(), "taskdata_addr") == 0)
				{
					taskdata_addr = attr->value();
				}
				else if (strcmp(attr->name(), "taskfinish_addr") == 0)
				{
					taskfinish_addr = attr->value();
				}
				attr = attr->next_attribute();
			}
		}
		root = root->next_sibling();
	}
}

StationRobotTool::StationRobotTool(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	std::string file_path = GetExePath();
	file_path = file_path + "\\etc\\ConfigInfo.xml";
	ReadConfig(file_path);

	//QMessageBox::information(this, CONTROL_TIP, QString::fromStdString(file_path));
	//QMessageBox::information(this, CONTROL_TIP, QString::fromStdString(robotdata_addr));

	treeWidget = new QTreeWidget(this);
	treeWidget->setObjectName("treeWidget");
	treeWidget->setHeaderHidden(true);
	treeWidget->setIndentation(0);
	QStringList menuList;
	menuList << "任务控制" << "机器人控制" << "控制站内设备" << "机器人本体数据" << "任务类数据" << "巡检类数据";
	//menuList << "任务控制" << "机器人控制" << "控制站内设备" << "数据获取" << "机器人本体数据" << "任务类数据" << "巡检类数据";


	stackWindow = new QStackedWidget;
	stackWindow->setObjectName("stackWindow");
	stackWindow->setStyleSheet("QWidget#stackWindow{border: 1px solid #000000; border-radius: 5px;}");
	taskcontrolview = new TaskControlView;
	robotcontrolview = new RobotControlView;
	stationdevicecontrolview = new StationDeviceControlView;
	dataView = new DataView;
	robotselfdataview = new RobotSelfDataView;
	taskdataview = new TaskDataView;
	patroldataview = new PatrolDataView;
	stackWindow->addWidget(taskcontrolview);
	stackWindow->addWidget(robotcontrolview);
	stackWindow->addWidget(stationdevicecontrolview);
	//stackWindow->addWidget(dataView);
	stackWindow->addWidget(robotselfdataview);
	stackWindow->addWidget(taskdataview);
	stackWindow->addWidget(patroldataview);
	qsrand(time(NULL));
	for (int i = 0; i < menuList.size(); ++i)
	{
		QTreeWidgetItem* item = new QTreeWidgetItem(treeWidget, QStringList(menuList.at(i)));
		int r = qrand() % 256;
		int g = qrand() % 256;
		int b = qrand() % 256;
		if ((r == 0 && g == 0 && b == 0 ) || (r <= 111 && g <= 111 && b <= 111))
		{
			r = 255;
			g = 255;
			b = 255;
		}
		item->setSizeHint(0, QSize(30, 50));
		item->setBackground(0, QBrush(QColor(r, g, b)));
		item->setTextAlignment(0, Qt::AlignCenter);
	}


	mainLayout = new QHBoxLayout;
	mainLayout->addWidget(treeWidget);
	mainLayout->addWidget(stackWindow);
	mainLayout->setStretchFactor(treeWidget, 1);
	mainLayout->setStretchFactor(stackWindow, 5);

	QHBoxLayout* tagLayout = new QHBoxLayout;
	QLabel* label = new QLabel("当前处于： ");
	currentActionText = "任务控制";
	currentAction = new QLabel(currentActionText);
	QPalette palette;
	palette.setColor(QPalette::WindowText, Qt::red);
	currentAction->setPalette(palette);

	getRobotTimeBtn = new QPushButton("获取机器人时间");
	robotTimeLabel = new QLabel;
	robotTimeLabel->setPalette(palette);

	tagLayout->addWidget(label);
	tagLayout->addWidget(currentAction);
	tagLayout->addWidget(getRobotTimeBtn);
	tagLayout->addWidget(robotTimeLabel);

	tagLayout->addStretch();
	menuLayout = new QVBoxLayout(this);
	menuLayout->addLayout(tagLayout);
	menuLayout->addLayout(mainLayout);
	init_robotdata_config(robotdata_addr.c_str());
	init_taskdata_config(taskdata_addr.c_str());
	init_taskfinsih_config(taskfinish_addr.c_str());
	QObject::connect(treeWidget, SIGNAL(itemPressed(QTreeWidgetItem*, int)), this, SLOT(ChangeModule(QTreeWidgetItem*, int)));//注释1
	connect(getRobotTimeBtn, SIGNAL(clicked()), this, SLOT(GetRobotTimeBtnSlot()));
}

void StationRobotTool::GetRobotTimeBtnSlot()
{
	std::string robot_time;
	int ret = GetRobotTime(robot_time);
	if (ret == 0)
	{
		QMessageBox::information(this, "获取数据提示", "获取机器人时间成功");
		robot_time_ = QString::fromStdString(robot_time);
		robotTimeLabel->setText(robot_time_);
	}
	else
	{
		QMessageBox::information(this, "获取数据提示", "获取机器人时间失败: " + QString::number(ret));
	}
}

void StationRobotTool::ChangeModule(QTreeWidgetItem *item1, int count1)
{
	QTreeWidgetItem *item = item1;
	if (item->text(count1) == "任务控制")
	{
		stackWindow->setCurrentWidget(taskcontrolview);
		currentAction->setText(item->text(count1));
	}
	else if (item->text(count1) == "机器人控制")
	{
		stackWindow->setCurrentWidget(robotcontrolview);
		currentAction->setText(item->text(count1));
	}
	else if (item->text(count1) == "控制站内设备")
	{
		stackWindow->setCurrentWidget(stationdevicecontrolview);
		currentAction->setText(item->text(count1));
	}
	else if (item->text(count1) == "数据获取")
	{
		stackWindow->setCurrentWidget(dataView);
		currentAction->setText(item->text(count1));
	}
	else if (item->text(count1) == "机器人本体数据")
	{
		stackWindow->setCurrentWidget(robotselfdataview);
		currentAction->setText(item->text(count1));
	}
	else if (item->text(count1) == "任务类数据")
	{
		stackWindow->setCurrentWidget(taskdataview);
		currentAction->setText(item->text(count1));
	}
	else if (item->text(count1) == "巡检类数据")
	{
		stackWindow->setCurrentWidget(patroldataview);
		currentAction->setText(item->text(count1));
	}
}


StationRobotTool::~StationRobotTool()
{

}
