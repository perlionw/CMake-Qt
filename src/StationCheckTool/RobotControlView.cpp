#include "RobotControlView.h"
#include "basictool.h"
#include "robotdata_imply.h"
#include "qsqlquery.h"
#include "qvariant.h"

RobotControlView::RobotControlView(QWidget *parent) : QWidget(parent)
{
	mainLayout = new QVBoxLayout(this);
	

	robotIpList_ = GetRobotIp();
	robotIpList_ << "127.0.0.1";
	mainLayout->addWidget(CreateControlModeGroupBox());
	mainLayout->addWidget(CreateRobotControlGroupBox());
	mainLayout->addWidget(CreateRobotInfoGroupBox());
	mainLayout->addStretch();

	ConnectSlot();
}

void RobotControlView::ConnectSlot()
{
	connect(forwardBtn, SIGNAL(clicked()), this, SLOT(ForwardSlot()));
	connect(backwardBtn, SIGNAL(clicked()), this, SLOT(BackwardSlot()));
	connect(leftBtn, SIGNAL(clicked()), this, SLOT(LeftSlot()));
	connect(rightBtn, SIGNAL(clicked()), this, SLOT(RightSlot()));
	connect(stopBtn, SIGNAL(clicked()), this, SLOT(StopSlot()));

	connect(autoModeRadioBtn, SIGNAL(clicked()), this, SLOT(AutoModeSlot()));
	connect(manualModeRadioBtn, SIGNAL(clicked()), this, SLOT(ManualModeSlot()));
	connect(releaseCurrentRobotBtn, SIGNAL(clicked()), this, SLOT(ReleaseCurrentRobotBtnSlot()));
	connect(robotInfoBtn, SIGNAL(clicked()), this, SLOT(RobotInfoBtnSlot()));
	connect(robotIpComboBox, SIGNAL(activated(const QString &)), this, SLOT(GetRobotIpSlot(const QString &)));
}

bool RobotControlView::SearchControlMap(QString text, QString &ControlId)
{
	std::map<QString, QString>::iterator it = controlMap.begin();
	for (; it != controlMap.end(); ++it)
	{
		if (it->first.contains(QRegExp(text)))
		{
			ControlId = it->second;
			return true;
		}
	}
	return false;
}

void RobotControlView::InitControlConfig()
{
	QString selectCarSql = "select TID, TNAME from typeinfo where TGRADE = 99 and TSTATUS <= 1";
	QSqlQuery query;
	bool b = query.exec(selectCarSql);
	while (query.next())
	{
		controlMap[query.value(1).toString()] = query.value(0).toString();
	}
}

QStringList RobotControlView::GetRobotIp()
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

QGroupBox* RobotControlView::CreateControlModeGroupBox()
{
	controlmodeGroupBox = new QGroupBox;
	controlmodeGroupBox->setTitle("设置控制模式");
	controlModeLayout = new QHBoxLayout;
	manualModeRadioBtn = new QRadioButton;
	autoModeRadioBtn = new QRadioButton;
	manualModeRadioBtn->setText("手动模式");
	autoModeRadioBtn->setText("自动模式");
	autoModeRadioBtn->setChecked(true);
	robotIpComboBox = new QComboBox;
	robotIpComboBox->addItems(robotIpList_);

	releaseCurrentRobotBtn = new QPushButton("释放当前机器人");


	controlModeLayout->addWidget(robotIpComboBox);
	controlModeLayout->addWidget(autoModeRadioBtn);
	controlModeLayout->addWidget(manualModeRadioBtn);
	controlModeLayout->addWidget(releaseCurrentRobotBtn);
	controlModeLayout->addStretch();
	controlmodeGroupBox->setLayout(controlModeLayout);
	return controlmodeGroupBox;
}

QGroupBox* RobotControlView::CreateRobotControlGroupBox()
{
	actionGroupBox = new QGroupBox;
	actionGroupBox->setTitle("机器人控制");
	actionLayout = new QHBoxLayout;
	forwardBtn = new QPushButton("朝前");
	backwardBtn = new QPushButton("朝后");
	leftBtn = new QPushButton("朝左");
	rightBtn = new QPushButton("朝右");
	stopBtn = new QPushButton("停止");
	lineSpeedSpinBox = new QDoubleSpinBox;
	lineSpeedSpinBox->setMinimum(0);
	lineSpeedSpinBox->setMaximum(0.4);
	lineSpeedSpinBox->setSingleStep(0.1);
	lineSpeedSpinBox->setValue(0.4);

	angleSpeedSpinBox = new QDoubleSpinBox;
	angleSpeedSpinBox->setMinimum(0);
	angleSpeedSpinBox->setMaximum(0.15);
	angleSpeedSpinBox->setSingleStep(0.01);
	angleSpeedSpinBox->setValue(0.15);

	lineSpeedLabel = new QLabel("线速度: ");
	angleSpeedLabel = new QLabel("角速度: ");
	actionLayout->addWidget(lineSpeedLabel);
	actionLayout->addWidget(lineSpeedSpinBox);
	actionLayout->addWidget(angleSpeedLabel);
	actionLayout->addWidget(angleSpeedSpinBox);
	actionLayout->addWidget(forwardBtn);
	actionLayout->addWidget(backwardBtn);
	actionLayout->addWidget(leftBtn);
	actionLayout->addWidget(rightBtn);
	actionLayout->addWidget(stopBtn);
	actionGroupBox->setLayout(actionLayout);

	return actionGroupBox;
}

QGroupBox* RobotControlView::CreateRobotInfoGroupBox()
{
	robotInfoGroupBox = new QGroupBox("机器人信息");
	QVBoxLayout* robotInfoLayout = new QVBoxLayout;
	robotInfoBtn = new QPushButton("获取机器人信息");
	robotInfoTable = new QTableWidget;
	robotInfoTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	robotInfoTable->setColumnCount(14);
	int width = 80;
	int i = 0;
	robotInfoTable->setColumnWidth(i++, width + 60);
	robotInfoTable->setColumnWidth(i++, width + 20);
	robotInfoTable->setColumnWidth(i++, width + 20);
	robotInfoTable->setColumnWidth(i++, width);
	robotInfoTable->setColumnWidth(i++, width);
	robotInfoTable->setColumnWidth(i++, width);
	robotInfoTable->setColumnWidth(i++, width + 20);
	robotInfoTable->setColumnWidth(i++, width);
	robotInfoTable->setColumnWidth(i++, width);
	robotInfoTable->setColumnWidth(i++, width);
	robotInfoTable->setColumnWidth(i++, width + 20);
	robotInfoTable->setColumnWidth(i++, width);
	robotInfoTable->setColumnWidth(i++, width);
	robotInfoTable->setColumnWidth(i++, width);

	QStringList headers;
	headers << "机器人IP" << "机器人名称" 
		<< "相机用户名" << "相机密码" << "相机IP" << "相机端口" 
		<< "红外用户名" << "红外密码" << "红外IP" << "红外端口" 
		<< "视频用户名" << "视频密码" << "视频IP" << "视频端口";
	robotInfoTable->setHorizontalHeaderLabels(headers);


	robotInfoLayout->addWidget(robotInfoBtn);
	robotInfoLayout->addWidget(robotInfoTable);
	robotInfoGroupBox->setLayout(robotInfoLayout);
	return robotInfoGroupBox;
}

void RobotControlView::GetRobotIpSlot(const QString &robot_ip)
{
	robot_ip_ = robot_ip;
	int ret = SetCurrentRobot(robot_ip.toStdString());
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "设置当前机器人为: " + robot_ip + "成功" );
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "设置当前机器人为: " + robot_ip + "失败：" + QString::number(ret));
	}
}

void RobotControlView::ForwardSlot()
{
	linespeed = lineSpeedSpinBox->value();
	anglespeed = angleSpeedSpinBox->value();
	SpeedInfo speed_info;
	speed_info.AngularVelocity = anglespeed;
	speed_info.LinearVelocity = linespeed;
	int ret = RobotSpeedControl(speed_info);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制失败: " + QString::number(ret));
	}
}
void RobotControlView::BackwardSlot()
{
	linespeed = lineSpeedSpinBox->value();
	anglespeed = angleSpeedSpinBox->value();
	SpeedInfo speed_info;
	speed_info.AngularVelocity = anglespeed;
	speed_info.LinearVelocity = linespeed;
	int ret = RobotSpeedControl(speed_info);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制失败: " + QString::number(ret));
	}
}
void RobotControlView::LeftSlot()
{
	linespeed = lineSpeedSpinBox->value();
	anglespeed = angleSpeedSpinBox->value();
	SpeedInfo speed_info;
	speed_info.AngularVelocity = anglespeed;
	speed_info.LinearVelocity = linespeed;
	int ret = RobotSpeedControl(speed_info);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制失败: " + QString::number(ret));
	}

}
void RobotControlView::RightSlot()
{
	linespeed = lineSpeedSpinBox->value();
	anglespeed = angleSpeedSpinBox->value();
	SpeedInfo speed_info;
	speed_info.AngularVelocity = anglespeed;
	speed_info.LinearVelocity = linespeed;
	int ret = RobotSpeedControl(speed_info);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制失败: " + QString::number(ret));
	}
}

void RobotControlView::StopSlot()
{
	SpeedInfo speed_info;
	speed_info.AngularVelocity = 0;
	speed_info.LinearVelocity = 0;
	int ret = RobotSpeedControl(speed_info);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制失败: " + QString::number(ret));
	}
}


void RobotControlView::AutoModeSlot()
{
	std::cout << "自动模式" << std::endl;

	ControlMode control_mode;
	control_mode.robot_ip = robot_ip_.toStdString();
	control_mode.ControlType = 0;
	int ret = SetControlMode(control_mode);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "设置为自动模式成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "设置为自动模式失败: " + QString::number(ret));
	}
}

void RobotControlView::ManualModeSlot()
{
	std::cout << "手动模式" << std::endl;
	ControlMode control_mode;
	control_mode.robot_ip = robot_ip_.toStdString();
	control_mode.ControlType = 1;
	int ret = SetControlMode(control_mode);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "设置为手动模式成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "设置为手动模式失败: " + QString::number(ret));
	}
}

void RobotControlView::ReleaseCurrentRobotBtnSlot()
{
	int ret = ReleaseCurrentRobot(robot_ip_.toStdString());
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "释放当前机器人成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "释放当前机器人失败: " + QString::number(ret));
	}
}

void RobotControlView::RobotInfoBtnSlot()
{
	std::vector<RobotInfo> robot_infos;
	int ret = GetRobotInfo(robot_infos);
	if (ret == 0)
	{
		if (robot_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "获取机器人信息成功");
			robotInfoTable->setRowCount(robot_infos.size());
			for (int i = 0; i < robot_infos.size(); ++i)
			{
				QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].RobotIp));
				robotInfoTable->setItem(i, 0, strItem0);
				QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].RobotName));
				robotInfoTable->setItem(i, 1, strItem1);
				QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].CameraUser));
				robotInfoTable->setItem(i, 2, strItem2);
				QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].CameraPassword));
				robotInfoTable->setItem(i, 3, strItem3);
				QTableWidgetItem *strItem4 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].CameraIp));
				robotInfoTable->setItem(i, 4, strItem4);
				QTableWidgetItem *strItem5 = new QTableWidgetItem(QString::fromStdString(std::to_string(robot_infos[i].CameraPort)));
				robotInfoTable->setItem(i, 5, strItem5);
				QTableWidgetItem *strItem6 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].FlirUser));
				robotInfoTable->setItem(i, 6, strItem6);
				QTableWidgetItem *strItem7 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].FlirPassword));
				robotInfoTable->setItem(i, 7, strItem7);
				QTableWidgetItem *strItem8 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].FlirIp));
				robotInfoTable->setItem(i, 8, strItem8);
				QTableWidgetItem *strItem9 = new QTableWidgetItem(QString::fromStdString(std::to_string(robot_infos[i].FlirPort)));
				robotInfoTable->setItem(i, 9, strItem9);
				QTableWidgetItem *strItem10 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].VideoUser));
				robotInfoTable->setItem(i, 10, strItem10);
				QTableWidgetItem *strItem11 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].VideoPassword));
				robotInfoTable->setItem(i, 11, strItem11);
				QTableWidgetItem *strItem12 = new QTableWidgetItem(QString::fromStdString(robot_infos[i].VideoIp));
				robotInfoTable->setItem(i, 12, strItem12);
				QTableWidgetItem *strItem13 = new QTableWidgetItem(QString::fromStdString(std::to_string(robot_infos[i].VideoPort)));
				robotInfoTable->setItem(i, 13, strItem13);

			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "数据获取为空");
		}

	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "获取机器人信息失败: " + QString::number(ret));
	}
}

RobotControlView::~RobotControlView()
{
}
