#include "TaskControlView.h"
#include "basictool.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "qmessagebox.h"
#include "taskdata_imply.h"
#include "robotdata_imply.h"
#include "qsqlerror.h"
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"

extern std::string GetExePath(void);

void TaskControlView::ReadDatabaseConfig(std::string file_path)
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

		while (node)
		{
			if (strcmp(node->name(), "DataBaseInfo") == 0)
			{
				rapidxml::xml_node<>* tcpinfo_node = node->first_node();
				rapidxml::xml_attribute<>* attr = tcpinfo_node->first_attribute();
				while (attr)
				{
					if (strcmp(attr->name(), "db_user") == 0)
					{
						db_user_ = attr->value();
					}
					else if (strcmp(attr->name(), "db_host") == 0)
					{
						db_host_ = attr->value();
					}
					else if (strcmp(attr->name(), "db_port") == 0)
					{
						db_port_ = attr->value();
					}
					else if (strcmp(attr->name(), "db_name") == 0)
					{
						db_name_ = attr->value();
					}
					else if (strcmp(attr->name(), "db_pass") == 0)
					{
						db_pass_ = attr->value();
					}
					attr = attr->next_attribute();
				}
			}
			node = node->next_sibling();
		}

		root = root->next_sibling();
	}
}

TaskControlView::TaskControlView(QWidget *parent) : QWidget(parent)
{
	//std::string file_path = GetExePath();
	//file_path = file_path + "\\etc\\ConfigInfo.xml";

	//ReadDatabaseConfig(file_path);
	//QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	//db.setHostName(QString::fromStdString(db_host_));
	//db.setDatabaseName(QString::fromStdString(db_name_));
	//db.setPort(atoi(db_port_.c_str()));
	//db.setUserName(QString::fromStdString(db_user_));
	//db.setPassword(QString::fromStdString(db_pass_));
	//bool ok = db.open();
	//if (ok)
	//{
	//	QMessageBox::information(this, "数据库提示", "连接数据库成功");
	//}
	//else
	//{
	//	QMessageBox::information(this, "数据库提示", "连接数据库失败: " + db.lastError().text());
	//}

	robotIpList_ = GetRobotIp();
	robotIpList_ << "127.0.0.1";

	mainLayout = new QVBoxLayout(this);
	mainLayout->addLayout(CreateActionLayout());
	mainLayout->addLayout(CreateSearchLayout());
	mainLayout->addLayout(CreateLabelLayout());
	mainLayout->addLayout(CreateTaskLayout());

	QHBoxLayout* comboLayout = new QHBoxLayout;
	comboLayout->addWidget(CreateSetTaskPathGroupBox());
	comboLayout->addWidget(CreateTaskStatusGroupBox());

	mainLayout->addLayout(comboLayout);
	mainLayout->addWidget(CreateTaskExcuteDataGroupBox());
	ConnectSlot();
	
}

QStringList TaskControlView::GetRobotIp()
{
	QStringList robotIpList;
	QString selectCarSql = "select PC_IP from carinfo";
	QSqlQuery query;
	bool b = query.exec(selectCarSql);
	while (query.next())
	{
		robotIpList << query.value(0).toString();
	}

	return robotIpList;
}

void TaskControlView::TaskStartSlot()
{
	//label->setText("任务开始");
	std::vector<QString> currentTaskInfo;
	std::vector<std::string> device_list;
	int row = 0;

	while (row<(task_list_widget_->count()))
	{
		QString line;
		line = task_list_widget_->item(row)->text();
		currentTaskInfo.push_back(line);
		row++;
	}

	for (int i = 0; i < currentTaskInfo.size(); ++i)
	{
		QStringList list = currentTaskInfo[i].split(" ");
		device_list.push_back(list.at(0).toStdString());
	}

	if (device_list.size() > 0)
	{
		std::string task_id = "";
		int ret = StartTaskByPointList(task_id, device_list);
		if (ret == 0)
		{
			QMessageBox::information(this, TASK_TIP, "任务下发成功");
		}
		else
		{
			QMessageBox::information(this, TASK_TIP, "任务下发失败: " + QString::number(ret));
		}
	}
	else
	{
		QMessageBox::information(this, TASK_TIP, "所选点位为空, 请选择！");
	}
}

QHBoxLayout* TaskControlView::CreateActionLayout()
{
	robotIpcomboBox = new QComboBox;

	robotIpcomboBox->addItems(robotIpList_);


	taskStartBtn = new QPushButton("任务开始");
	loadPointBtn = new QPushButton("加载点位");
	taskPauseBtn = new QPushButton("任务暂停");
	taskCancelBtn = new QPushButton("任务取消");
	taskRestartBtn = new QPushButton("任务恢复");
	taskAutoChargeBtn = new QPushButton("自主充电");
	loadTaskPathBtn = new QPushButton("加载任务模板");

	actionLayout = new QHBoxLayout;
	actionLayout->addWidget(robotIpcomboBox);
	actionLayout->addWidget(loadTaskPathBtn);
	actionLayout->addWidget(loadPointBtn);
	actionLayout->addWidget(taskStartBtn);
	actionLayout->addWidget(taskPauseBtn);
	actionLayout->addWidget(taskRestartBtn);
	actionLayout->addWidget(taskCancelBtn);
	actionLayout->addWidget(taskAutoChargeBtn);
	return actionLayout;
}

QHBoxLayout* TaskControlView::CreateSearchLayout()
{
	searchLayout = new QHBoxLayout;
	pointLineEdit = new QLineEdit;
	searchBtn = new QPushButton("搜索点位");
	searchLayout->addWidget(pointLineEdit);
	searchLayout->addWidget(searchBtn);
	return searchLayout;
}

QHBoxLayout* TaskControlView::CreateLabelLayout()
{
	labelLayout = new QHBoxLayout;
	QLabel* taskPathLabel = new QLabel("任务模板列表");
	QLabel* pointInfoLabel = new QLabel("点位信息列表");
	QLabel* taskPointLabel = new QLabel("被选任务点位列表");
	labelLayout->addWidget(taskPathLabel);
	labelLayout->addWidget(pointInfoLabel);
	labelLayout->addWidget(taskPointLabel);
	return labelLayout;
}

QHBoxLayout* TaskControlView::CreateTaskLayout()
{
	taskLayout = new QHBoxLayout;
	point_list_widget_ = new QListWidget;
	task_list_widget_ = new QListWidget;
	task_path_list_widget_ = new QListWidget;
	taskLayout->addWidget(task_path_list_widget_);
	taskLayout->addWidget(point_list_widget_);
	taskLayout->addWidget(task_list_widget_);
	return taskLayout;
}

QGroupBox* TaskControlView::CreateTaskExcuteDataGroupBox()
{
	taskExcuteGroupBox = new QGroupBox("获取任务执行信息");
	QVBoxLayout* taskExcuteLayout = new QVBoxLayout;

	taskExcuteDataBtn = new QPushButton("获取任务执行信息");
	
	taskExcuteDataTable = new QTableWidget;
	taskExcuteDataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	taskExcuteDataTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	taskExcuteDataTable->setEditTriggers(QAbstractItemView::DoubleClicked);
	taskExcuteDataTable->setColumnCount(10);
	int width = 80;
	taskExcuteDataTable->setColumnWidth(0, width);
	taskExcuteDataTable->setColumnWidth(1, width);
	taskExcuteDataTable->setColumnWidth(2, width);
	taskExcuteDataTable->setColumnWidth(3, width);
	taskExcuteDataTable->setColumnWidth(4, width);
	taskExcuteDataTable->setColumnWidth(5, width);
	taskExcuteDataTable->setColumnWidth(6, width);
	taskExcuteDataTable->setColumnWidth(7, width);
	taskExcuteDataTable->setColumnWidth(8, width + 40);
	taskExcuteDataTable->setColumnWidth(9, width + 20);
	taskExcuteDataTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	QStringList header;
	header << "机器人IP" << "任务ID" << "任务名称" << "任务类型" << "任务进度" 
		<< "设备总数" << "当前点位名" << "当前点位" << "异常巡检点数量" << "已完成巡检点数量";
	taskExcuteDataTable->setHorizontalHeaderLabels(header);
	taskExcuteLayout->addWidget(taskExcuteDataBtn);
	taskExcuteLayout->addWidget(taskExcuteDataTable);

	taskExcuteGroupBox->setLayout(taskExcuteLayout);
	return taskExcuteGroupBox;
}

void TaskControlView::ConnectSlot()
{
	connect(loadPointBtn, SIGNAL(clicked()), this, SLOT(LoadPointSlot()));
	connect(loadTaskPathBtn, SIGNAL(clicked()), this, SLOT(GetTaskPathSlot()));
	connect(taskStartBtn, SIGNAL(clicked()), this, SLOT(TaskStartSlot()));
	connect(searchBtn, SIGNAL(clicked()), this, SLOT(SearchPointSlot()));
	connect(taskPauseBtn, SIGNAL(clicked()), this, SLOT(TaskPauseSlot()));
	connect(taskCancelBtn, SIGNAL(clicked()), this, SLOT(TaskCancelSlot()));
	connect(taskRestartBtn, SIGNAL(clicked()), this, SLOT(TaskRestartSlot()));
	connect(taskAutoChargeBtn, SIGNAL(clicked()), this, SLOT(TaskAutoChargeSlot()));
	connect(point_list_widget_, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(SetTaskPointSlot(QListWidgetItem *)));
	connect(task_list_widget_, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(DeleteTaskPointSlot(QListWidgetItem *)));
	connect(task_path_list_widget_, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(GetTaskPathSlot(QListWidgetItem *)));
	connect(robotIpcomboBox, SIGNAL(activated(const QString &)), this, SLOT(GetRobotIpSlot(const QString &)));

	connect(getTaskStatusBtn, SIGNAL(clicked()), this, SLOT(GetTaskStatusSlot()));
	connect(taskExcuteDataBtn, SIGNAL(clicked()), this, SLOT(GetTaskExcuteDataSlot()));
	connect(setTaskPathBtn, SIGNAL(clicked()), this, SLOT(SetTaskPathSlot()));

	connect(taskInfoTable, SIGNAL(cellClicked(int, int)), this, SLOT(TaskStatuSlot(int, int)));
}

void TaskControlView::TaskStatuSlot(int row, int column)
{
	QTableWidgetItem *item = taskInfoTable->item(row, 1);
	current_task_id = item->text();
}




QGroupBox* TaskControlView::CreateTaskStatusGroupBox()
{
	taskStatusGroupBox = new QGroupBox("任务状态信息");
	QVBoxLayout* taskStatusLayout = new QVBoxLayout;

	QHBoxLayout* layout = new QHBoxLayout;
	getTaskStatusBtn = new QPushButton("获取任务信息");
	trueTaskStatusRadio = new QRadioButton("多");
	falseTaskStatusRadio = new QRadioButton("单");
	falseTaskStatusRadio->setChecked(true);

	layout->addWidget(trueTaskStatusRadio);
	layout->addWidget(falseTaskStatusRadio);
	layout->addWidget(getTaskStatusBtn);

	layout->setStretchFactor(trueTaskStatusRadio, 1);
	layout->setStretchFactor(falseTaskStatusRadio, 1);
	layout->setStretchFactor(getTaskStatusBtn, 10);


	taskInfoTable = new QTableWidget;
	taskInfoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	taskInfoTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	taskInfoTable->setEditTriggers(QAbstractItemView::DoubleClicked);
	taskInfoTable->setColumnCount(10);
	int width = 80;
	taskInfoTable->setColumnWidth(0, width);
	taskInfoTable->setColumnWidth(1, width);
	taskInfoTable->setColumnWidth(2, width);
	taskInfoTable->setColumnWidth(3, width);
	taskInfoTable->setColumnWidth(4, width);
	taskInfoTable->setColumnWidth(5, width);
	taskInfoTable->setColumnWidth(6, width);
	taskInfoTable->setColumnWidth(7, width);
	taskInfoTable->setColumnWidth(8, width + 40);
	taskInfoTable->setColumnWidth(9, width + 20);
	taskInfoTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	QStringList header;
	header << "机器人IP" << "任务ID" << "任务名称" << "任务状态" << "任务进度"
		<< "设备总数" << "当前点位名" << "当前点位" << "下一个巡检点名" << "下一个巡检点";
	taskInfoTable->setHorizontalHeaderLabels(header);
	taskInfoTable->setColumnHidden(1, true);
	taskInfoTable->setColumnHidden(4, true);
	taskInfoTable->setColumnHidden(5, true);
	taskInfoTable->setColumnHidden(6, true);
	taskInfoTable->setColumnHidden(7, true);
	taskInfoTable->setColumnHidden(8, true);
	taskInfoTable->setColumnHidden(9, true);
	taskStatusLayout->addLayout(layout);
	taskStatusLayout->addWidget(taskInfoTable);

	taskStatusGroupBox->setLayout(taskStatusLayout);
	return taskStatusGroupBox;
}

QGroupBox* TaskControlView::CreateSetTaskPathGroupBox()
{
	setTaskPathGroupBox = new QGroupBox("设置任务模板");

	QVBoxLayout* setTaskPathLayout = new QVBoxLayout;

	setTaskPathBtn = new QPushButton("设置任务模板");


	QHBoxLayout* taskIdLayout = new QHBoxLayout;
	QLabel* taskIdLabel = new QLabel("请输入任务ID: ");
	taskPathIdEdit = new QLineEdit;
	taskIdLayout->addWidget(taskIdLabel);
	taskIdLayout->addWidget(taskPathIdEdit);

	QHBoxLayout* taskNameLayout = new QHBoxLayout;
	QLabel* taskNameLabel = new QLabel("请输入任务名称: ");
	taskNameEdit = new QLineEdit;
	taskNameLayout->addWidget(taskNameLabel);
	taskNameLayout->addWidget(taskNameEdit);

	QHBoxLayout* taskTypeLayout = new QHBoxLayout;
	QLabel* taskTypeLabel = new QLabel("请输入任务类型: ");
	taskTypeCombox = new QComboBox;
	QStringList taskTypeList;
	taskTypeList << "全面巡检" << "例行巡检" << "专项巡检" << "特殊巡检";
	taskTypeCombox->addItems(taskTypeList);
	taskTypeLayout->addWidget(taskTypeLabel);
	taskTypeLayout->addWidget(taskTypeCombox);

	QHBoxLayout* createTimeLayout = new QHBoxLayout;
	QLabel* createTimeLabel = new QLabel("请选择时间: ");
	createTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime());
	createTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
	createTimeEdit->setCalendarPopup(true);  // 日历弹出
	createTimeLayout->addWidget(createTimeLabel);
	createTimeLayout->addWidget(createTimeEdit);

	QHBoxLayout* actionLayout = new QHBoxLayout;
	stopActionRadio = new QRadioButton("原地待命");
	returnChargeActionRadio = new QRadioButton("返回充电");
	returnChargeActionRadio->setChecked(true);
	actionLayout->addWidget(stopActionRadio);
	actionLayout->addWidget(returnChargeActionRadio);

	
	setTaskPathLayout->addLayout(taskIdLayout);
	setTaskPathLayout->addLayout(taskNameLayout);
	setTaskPathLayout->addLayout(taskTypeLayout);
	setTaskPathLayout->addLayout(createTimeLayout);
	setTaskPathLayout->addLayout(actionLayout);
	setTaskPathLayout->addWidget(setTaskPathBtn);

	setTaskPathGroupBox->setLayout(setTaskPathLayout);


	return setTaskPathGroupBox;
}

void TaskControlView::GetRobotIpSlot(const QString &robot_ip)
{
	robot_ip_ = robot_ip;
}

void TaskControlView::TaskPauseSlot()
{
	int ret = RobotControlTask(ControlTaskType::ControlTaskType__PauseTask);
	if (ret == 0)
	{
		QMessageBox::information(this, TASK_TIP, "任务暂停成功");
	}
	else
	{
		QMessageBox::information(this, TASK_TIP, "任务暂停。。失败: " + QString::number(ret));
	}
}
void TaskControlView::TaskRestartSlot()
{
	int ret = RobotControlTask(ControlTaskType::ControlTaskType__ResumeTask);
	if (ret == 0)
	{
		QMessageBox::information(this, TASK_TIP, "任务恢复成功");
	}
	else
	{
		QMessageBox::information(this, TASK_TIP, "任务恢复失败: " + QString::number(ret));
	}
}
void TaskControlView::TaskCancelSlot()
{

	int ret = RobotControlTask(ControlTaskType::ControlTaskType__CancelTask);
	if (ret == 0)
	{
		QMessageBox::information(this, TASK_TIP, "任务取消成功");
	}
	else
	{
		QMessageBox::information(this, TASK_TIP, "任务取消失败: " + QString::number(ret));
	}

}

void TaskControlView::TaskAutoChargeSlot()
{
	int ret = RobotControlTask(ControlTaskType::ControlTaskType__ChargeTask);
	if (ret == 0)
	{
		QMessageBox::information(this, TASK_TIP, "自主充电成功");
	}
	else
	{
		QMessageBox::information(this, TASK_TIP, "自主充电失败: " + QString::number(ret));
	}
}

void TaskControlView::LoadPointSlot()
{
	QString selectPointSql = "select device_id, device_desc from deviceinfo";	
	QSqlQuery query;
	bool b = query.exec(selectPointSql);
	while (query.next())
	{
		PointInfo pointinfo;

		pointinfo.device_id = query.value(0).toString();
		pointinfo.device_desc = query.value(1).toString();
		pointinfo.device_desc = pointinfo.device_id + " " + pointinfo.device_desc;
		vct_point_info_.push_back(pointinfo);
	}

	for (unsigned int i = 0; i < vct_point_info_.size(); i++)
	{
		point_list_widget_->addItem(vct_point_info_[i].device_desc);
	}

	if (vct_point_info_.size()>0)
	{
		loadPointBtn->setEnabled(false);
	}
}

void TaskControlView::SearchPointSlot()
{
	QString pointinfo = pointLineEdit->text();
	for (unsigned int i = 0; i < vct_point_info_.size(); i++)
	{
		if (strstr(vct_point_info_[i].device_desc.toStdString().c_str(), pointinfo.toStdString().c_str()))
		{
			point_list_widget_->setCurrentRow(i);
		}
	}

}

void TaskControlView::SetTaskPointSlot(QListWidgetItem *item)
{
	QString pointinfo = item->text();
	task_list_widget_->addItem(pointinfo);
}

void TaskControlView::DeleteTaskPointSlot(QListWidgetItem *item)
{
	task_list_widget_->removeItemWidget(item);
	delete item;
}

void TaskControlView::LoadTaskPathSlot()
{
	std::vector<TaskPathInfo1> task_path_info_vec;
	QString selectTaskPathSql = "select task_path_desc, device_count, path_insert_time, task_path_id from taskpathinfo";
	QSqlQuery query;
	bool b = query.exec(selectTaskPathSql);
	while (query.next())
	{
		TaskPathInfo1 task_path_info;
		task_path_info.task_path_desc = query.value(0).toString();
		task_path_info.device_count = query.value(1).toString();
		task_path_info.path_insert_time = query.value(2).toString();
		task_path_info.path_insert_time = task_path_info.path_insert_time.replace(QRegExp("T"), " ");
		task_path_info.task_path_id = query.value(3).toString();
		task_path_info.task_path_desc = task_path_info.task_path_desc + " " + task_path_info.device_count + " " + task_path_info.path_insert_time + " " + task_path_info.task_path_id;
		task_path_info_vec.push_back(task_path_info);
	}

	
	for (unsigned int i = 0; i < task_path_info_vec.size(); i++)
	{
		task_path_list_widget_->addItem(task_path_info_vec[i].task_path_desc);
	}

	if (task_path_info_vec.size() > 0)
	{
		loadTaskPathBtn->setEnabled(false);
	}

}

void TaskControlView::GetTaskPathSlot()
{
	std::vector<TaskPathInfo1> task_path_info_vec;
	std::vector<TaskPathInfo> task_path_infos;
	int ret = GetTaskPathInfo(task_path_infos);
	if (ret == 0)
	{
		if (task_path_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "获取任务模板成功");
			for (int i = 0; i < task_path_infos.size(); ++i)
			{
				TaskPathInfo1 task_path_info;
				task_path_info.task_path_desc = QString::fromStdString(task_path_infos[i].TaskPathName);
				task_path_info.device_count = QString::fromStdString(std::to_string(task_path_infos[i].PointList.size()));
				task_path_info.path_insert_time = QString::fromStdString(task_path_infos[i].CreateTime);
				task_path_info.task_path_id = QString::fromStdString(task_path_infos[i].TaskPathId);
				task_path_info.task_path_desc = task_path_info.task_path_desc + " " + task_path_info.device_count + " " + task_path_info.path_insert_time + " " + task_path_info.task_path_id;
				task_path_info_vec.push_back(task_path_info);
			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "数据获取为空");
		}

	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "获取任务模板失败: " + QString::number(ret));
	}

	for (unsigned int i = 0; i < task_path_info_vec.size(); i++)
	{
		task_path_list_widget_->addItem(task_path_info_vec[i].task_path_desc);
	}

	if (task_path_info_vec.size() > 0)
	{
		loadTaskPathBtn->setEnabled(false);
	}
}

void TaskControlView::GetTaskPathSlot(QListWidgetItem *item)
{
	QString task_path_info = item->text();

	QStringList info = task_path_info.split(" ");



	QMessageBox::StandardButton result = QMessageBox::information(this, TASK_TIP, "确定下发任务[" + *info.begin() + "]?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

	switch (result)
	{
		case QMessageBox::Yes:
		{
								 QString task_path_id = info.back();
								 std::string task_id = "";
								 int ret = StartTaskByPathId(task_id, task_path_id.toStdString());
								 if (ret == 0)
								 {
									 QMessageBox::information(this, TASK_TIP, "任务下发成功");
								 }
								 else
								 {
									 QMessageBox::information(this, TASK_TIP, "任务下发失败: " + QString::number(ret));
								 }
		}
			break;
		case QMessageBox::No:
			break;
		default:
			break;
	}

}

void TaskControlView::GetTaskStatusSlot()
{
	bool flag = trueTaskStatusRadio->isChecked();
	std::vector<RobotState> task_status_infos;
	int ret = GetRobotTaskState(flag, task_status_infos);
	if (ret == 0)
	{
		if (task_status_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "获取任务状态成功");
			taskInfoTable->setRowCount(task_status_infos.size());
			for (int i = 0; i < task_status_infos.size(); ++i)
			{
				TaskStatusInfo task_info;
				task_info.task_id = "59f180cad8b119860e6fe2bb745650c7";
				task_info.task_desc = QString::fromStdString(task_status_infos[i].TaskDesc);
				task_info.robot_ip = QString::fromStdString(task_status_infos[i].RobotIp);
				task_info.task_status = QString::fromStdString(task_status_infos[i].TaskType);
				task_info.task_process = "80%";
				task_info.total_count = "78";
				task_info.current_device_name = "避雷器";
				task_info.current_device_id = "a001_32";
				task_info.next_device_name = "断路器";
				task_info.next_device_id = "a001_78";
				QTableWidgetItem *strItem0 = new QTableWidgetItem(task_info.robot_ip);
				taskInfoTable->setItem(i, 0, strItem0);
				QTableWidgetItem *strItem1 = new QTableWidgetItem(task_info.task_id);
				taskInfoTable->setItem(i, 1, strItem1);
				QTableWidgetItem *strItem2 = new QTableWidgetItem(task_info.task_desc);
				taskInfoTable->setItem(i, 2, strItem2);
				QTableWidgetItem *strItem3 = new QTableWidgetItem(task_info.task_status);
				taskInfoTable->setItem(i, 3, strItem3);
				QTableWidgetItem *strItem4 = new QTableWidgetItem(task_info.task_process);
				taskInfoTable->setItem(i, 4, strItem4);
				QTableWidgetItem *strItem5 = new QTableWidgetItem(task_info.total_count);
				taskInfoTable->setItem(i, 5, strItem5);
				QTableWidgetItem *strItem6 = new QTableWidgetItem(task_info.current_device_name);
				taskInfoTable->setItem(i, 6, strItem6);
				QTableWidgetItem *strItem7 = new QTableWidgetItem(task_info.current_device_id);
				taskInfoTable->setItem(i, 7, strItem7);
				QTableWidgetItem *strItem8 = new QTableWidgetItem(task_info.next_device_name);
				taskInfoTable->setItem(i, 8, strItem8);
				QTableWidgetItem *strItem9 = new QTableWidgetItem(task_info.next_device_id);
				taskInfoTable->setItem(i, 9, strItem9);
			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "数据获取为空");
		}
	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "获取任务状态失败: " + QString::number(ret));
	}
}

void TaskControlView::GetTaskExcuteDataSlot()
{
	TaskExcuteData task_excute_info;
	int ret = GetTaskExcuteData(robot_ip_.toStdString(), task_excute_info);
	if (ret == 0)
	{
		taskInfoTable->setRowCount(1);
		QMessageBox::information(this, GETDATA_TIP, "获取任务状态成功");
		int i = 0;
		QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(task_excute_info.RobotIp));
		taskInfoTable->setItem(i, 0, strItem0);
		QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(task_excute_info.TaskId));
		taskInfoTable->setItem(i, 1, strItem1);
		QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(task_excute_info.TaskName));
		taskInfoTable->setItem(i, 2, strItem2);
		QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(task_excute_info.TaskType));
		taskInfoTable->setItem(i, 3, strItem3);
		QTableWidgetItem *strItem4 = new QTableWidgetItem(task_excute_info.TaskFinishPercentage);
		taskInfoTable->setItem(i, 4, strItem4);
		QTableWidgetItem *strItem5 = new QTableWidgetItem(task_excute_info.TotalDeviceSize);
		taskInfoTable->setItem(i, 5, strItem5);
		QTableWidgetItem *strItem6 = new QTableWidgetItem(QString::fromStdString(task_excute_info.PatrolDeviceId));
		taskInfoTable->setItem(i, 6, strItem6);
		QTableWidgetItem *strItem7 = new QTableWidgetItem(QString::fromStdString(task_excute_info.PatrolDeviceName));
		taskInfoTable->setItem(i, 7, strItem7);
		QTableWidgetItem *strItem8 = new QTableWidgetItem(task_excute_info.ErrorDeviceSize);
		taskInfoTable->setItem(i, 8, strItem8);
		QTableWidgetItem *strItem9 = new QTableWidgetItem(task_excute_info.FinishDeviceSize);
		taskInfoTable->setItem(i, 9, strItem9);
	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "获取任务状态失败: " + QString::number(ret));
	}
}

void TaskControlView::SetTaskPathSlot()
{
	QString task_path_id = taskPathIdEdit->text();
	QString task_name = taskNameEdit->text();
	QString task_type = taskTypeCombox->currentText();
	QString create_time = createTimeEdit->text();
	bool flag = stopActionRadio->isChecked();
	int finishAction;
	if (flag)
	{
		finishAction = 1;//原地待命
	}
	else
	{
		finishAction = 0;//返回充电
	}
	std::vector<QString> currentTaskInfo;
	std::vector<std::string> device_list;
	int row = 0;
	while (row<(task_list_widget_->count()))
	{
		QString line;
		line = task_list_widget_->item(row)->text();
		currentTaskInfo.push_back(line);
		row++;
	}

	for (int i = 0; i < currentTaskInfo.size(); ++i)
	{
		QStringList list = currentTaskInfo[i].split(" ");
		device_list.push_back(list.at(0).toStdString());
	}

	if (device_list.size() > 0)
	{
	
		TaskPathInfo task_path_info;
		task_path_info.TaskPathId = task_path_id.toStdString();
		task_path_info.TaskPathName = task_name.toStdString();

		if (task_path_info.TaskPathId == "")
		{
			QMessageBox::information(this, TASK_TIP, "任务模板ID为空, 请输入！");
			return;
		}
		
		if (task_path_info.TaskPathName == "")
		{
			QMessageBox::information(this, TASK_TIP, "任务名称为空, 请输入！");
			return;
		}

		if (task_type.toStdString() == "全面巡检")
		{
			task_path_info.TaskPathType = "001";
		}
		else if (task_type.toStdString() == "例行巡检")
		{
			task_path_info.TaskPathType = "002";
		}
		else if (task_type.toStdString() == "专项巡检")
		{
			task_path_info.TaskPathType = "003";
		}
		else if (task_type.toStdString() == "特殊巡检")
		{
			task_path_info.TaskPathType = "004";
		}


		task_path_info.CreateTime = create_time.toStdString();
		task_path_info.FinishAction = finishAction;
		task_path_info.PointList = device_list;

		int ret = SetTaskPathInfo(task_path_info);
		if (ret == 0)
		{
			QMessageBox::information(this, TASK_TIP, "设置任务模板成功");
		}
		else
		{
			QMessageBox::information(this, TASK_TIP, "设置任务模板失败: " + QString::number(ret));
		}
	}
	else
	{
		QMessageBox::information(this, TASK_TIP, "所选点位为空, 请选择！");
	}
}

TaskControlView::~TaskControlView()
{

}

