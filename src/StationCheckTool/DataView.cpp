#include "DataView.h"
#include "basictool.h"
#include "taskfinish_imply.h"
DataView::DataView(QWidget* parent) :QWidget(parent)
{
	mainLayout = new QGridLayout(this);
	InitStationDeviceConfig();
	InitRobotDataConfig();

	mainLayout->addWidget(CreateStationDeviceGroupBox(), 0, 0);
	mainLayout->addWidget(CreateRobotDataGroupBox(), 0, 1);
	mainLayout->addWidget(CreateControlModeGroupBox(), 1, 1);
	mainLayout->addWidget(CreateTaskStatusGroupBox(), 1, 0);
	mainLayout->addWidget(CreateRobotPosGroupBox(), 2, 0);
	mainLayout->addWidget(CreateRobotPatrolEdgeGroupBox(), 2, 1);
	ConnectSlot();
}

QGroupBox* DataView::CreateRobotPosGroupBox()
{
	robotPosGroupBox = new QGroupBox("机器人位置信息");
	robotPosLayout = new QVBoxLayout;
	robotPosGroupBox->setLayout(robotPosLayout);
	return robotPosGroupBox;
}

QGroupBox* DataView::CreateRobotPatrolEdgeGroupBox()
{
	robotPatrolEdgeGroupBox = new QGroupBox("机器人巡检路径信息");
	return robotPatrolEdgeGroupBox;
}

QGroupBox* DataView::CreateStationDeviceGroupBox()
{
	stationDeviceGroupBox = new QGroupBox("站设备信息");
	QVBoxLayout* stationDeviceLayout = new QVBoxLayout;

	stationDeviceCombox = new QComboBox;

	QStringList stationDeviceList;
	
	std::map<QString, QString>::iterator it = station_device_map.begin();
	for (; it != station_device_map.end(); ++it)
	{
		stationDeviceList << it->first;
	}

	stationDeviceCombox->addItems(stationDeviceList);

	stationDeviceListWidget = new QListWidget;
	stationDeviceLayout->addWidget(stationDeviceCombox);
	stationDeviceLayout->addWidget(stationDeviceListWidget);

	stationDeviceGroupBox->setLayout(stationDeviceLayout);

	return stationDeviceGroupBox;
}

QGroupBox* DataView::CreateControlModeGroupBox()
{
	controlModeGroupBox = new QGroupBox("控制模式");
	getControlModeBtn = new QPushButton("获取控制模式");
	QVBoxLayout* layout = new QVBoxLayout;
	QHBoxLayout* controlModeLayout = new QHBoxLayout;
	QLabel* label = new QLabel("请输入机器人IP: ");
	robotIpLineEdit = new QLineEdit;

	
	controlModeLayout->addWidget(label);
	controlModeLayout->addWidget(robotIpLineEdit);

	controlModeLayout->addStretch();

	layout->addLayout(controlModeLayout);
	layout->addWidget(getControlModeBtn);
	layout->addStretch();
	controlModeGroupBox->setLayout(layout);
	return controlModeGroupBox;
}

QGroupBox* DataView::CreateTaskStatusGroupBox()
{

	taskStatusGroupBox = new QGroupBox("任务状态信息");
	QVBoxLayout* taskStatusLayout = new QVBoxLayout;
	
	QHBoxLayout* layout = new QHBoxLayout;

	QLabel* label = new QLabel("请输入机器人IP: ");
	getTaskStatusBtn = new QPushButton("获取任务信息");
	robot_ipLineEdit = new QLineEdit;
	layout->addWidget(label);
	layout->addWidget(robot_ipLineEdit);
	layout->addWidget(getTaskStatusBtn);
	
	taskInfoTable = new QTableWidget;
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
	taskInfoTable->setColumnWidth(8, width+ 40);
	taskInfoTable->setColumnWidth(9, width + 20);
	taskInfoTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
    QStringList header;
    header << "机器人IP" << "任务ID" << "任务名称"  << "任务状态" << "任务进度" 
		<< "设备总数" << "当前点位名" << "当前点位" << "下一个巡检点名" << "下一个巡检点";
	taskInfoTable->setHorizontalHeaderLabels(header);
	taskStatusLayout->addLayout(layout);
	taskStatusLayout->addWidget(taskInfoTable);


	taskStatusGroupBox->setLayout(taskStatusLayout);
	return taskStatusGroupBox;
}

QGroupBox* DataView::CreateRobotDataGroupBox()
{
	robotDataGroupBox = new QGroupBox("机器人数据信息");

	QVBoxLayout* robotDataLayout = new QVBoxLayout;
	QStringList robotDataList;

	robotDataCombox = new QComboBox;

	std::map<QString, QString>::iterator it = robot_data_map.begin();
	for (; it != robot_data_map.end(); ++it)
	{
		robotDataList << it->first;
	}

	robotDataCombox->addItems(robotDataList);

	robotDataListWidget = new QListWidget;
	robotDataLayout->addWidget(robotDataCombox);
	robotDataLayout->addWidget(robotDataListWidget);

	robotDataGroupBox->setLayout(robotDataLayout);
	return robotDataGroupBox;
}

void DataView::ConnectSlot()
{
	connect(stationDeviceCombox, SIGNAL(activated(const QString &)), this, SLOT(StationDeviceSlot(const QString &)));
	connect(robotDataCombox, SIGNAL(activated(const QString &)), this, SLOT(RobotDataSlot(const QString &)));
	connect(getControlModeBtn, SIGNAL(clicked()), this, SLOT(GetControlModeSlot()));
	connect(getTaskStatusBtn, SIGNAL(clicked()), this, SLOT(GetTaskStatusSlot()));
}

void DataView::StationDeviceSlot(const QString &station_device)
{
	QString device = station_device;
	std::map<QString, QString>::iterator it = station_device_map.find(device);
	if (it != station_device_map.end())
	{
		QString device_id = it->second;
		//调用接口获取信息
		std::string jdata;
		//std::string task_id;
		//std::vector<TaskExcuteInfo> task_excute_infos;
		//int ret = GetTaskExcuteInfoByTaskId(task_id, task_excute_infos);
		//if (ret == 0)
		//{
		//	QMessageBox::information(this, "获取数据提示", "站设备信息获取成功");
		//}
		//else
		//{
		//	QMessageBox::information(this, "获取数据提示", "站设备信息获取失败: " + QString::number(ret));
		//}

	}
}

void DataView::RobotDataSlot(const QString &robot_id_desc)
{
	QString desc = robot_id_desc;
	std::map<QString, QString>::iterator it = robot_data_map.find(desc);
	if (it != robot_data_map.end())
	{
		QString robot_id = it->second;
		//调用接口获取信息
		std::string jdata;
		//int ret = GetRobotData(robot_id.toStdString(), jdata);
		//if (ret == 0)
		//{
		//	QMessageBox::information(this, "获取数据提示", "机器人信息获取成功");
		//}
		//else
		//{
		//	QMessageBox::information(this, "获取数据提示", "机器人信息获取失败: " + QString::number(ret));
		//}
		//json解析

	}
}

void DataView::InitStationDeviceConfig()
{
	station_device_map["微气象数据"] = "201100100103";
	station_device_map["小室门状态"] = "201101100106";
}

void DataView::InitRobotDataConfig()
{
	robot_data_map["机器人角速度"] = "200100100102";
	robot_data_map["机器人线速度"] = "200100106";
}

void DataView::GetControlModeSlot()
{
	QString robot_ip = robotIpLineEdit->text();
	std::string jdata;
	//int ret = GetControlMode(robot_ip.toStdString(), jdata);
	//if (ret == 0)
	//{
	//	QMessageBox::information(this, "获取数据提示", "控制模式获取成功");
	//}
	//else
	//{
	//	QMessageBox::information(this, "获取数据提示", "控制模式获取失败: " + QString::number(ret));
	//}
	//json解析

}

void DataView::GetTaskStatusSlot()
{
	QString robot_ip = robot_ipLineEdit->text();

	std::string jdata;
	//int ret = GetRobotTaskData(robot_ip.toStdString(), jdata);
	//if (ret == 0)
	//{
	//	QMessageBox::information(this, "获取数据提示", "任务信息获取成功");
	//}
	//else
	//{
	//	QMessageBox::information(this, "获取数据提示", "任务信息获取失败: " + QString::number(ret));
	//}
	//json解析


}

DataView::~DataView()
{
}
