#include "RobotSelfDataView.h"
#include "basictool.h"
#include "robotdata_imply.h"

RobotSelfDataView::RobotSelfDataView(QWidget *parent) : QWidget(parent)
{
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(CreateBatteryInfoGroupBox(), 0, 0);
	mainLayout->addWidget(CreateSpeedInfoGroupBox(), 0, 1);
	mainLayout->addWidget(CreatePosInfoGroupBox(), 1, 0);
	mainLayout->addWidget(CreateMileageInfoGroupBox(), 1, 1);
	mainLayout->addWidget(CreateGasInfoGroupBox(), 2, 0);
	mainLayout->addWidget(CreateAlarmInfoGroupBox(), 2, 1);
	ConnectInfo();
}

void RobotSelfDataView::ConnectInfo()
{
	connect(batteryInfoBtn, SIGNAL(clicked()), this, SLOT(BatteryInfoBtnSlot()));
	connect(speedInfoBtn, SIGNAL(clicked()), this, SLOT(SpeedInfoBtnSlot()));
	connect(posInfoBtn, SIGNAL(clicked()), this, SLOT(PosInfoBtnSlot()));
	connect(mileageInfoBtn, SIGNAL(clicked()), this, SLOT(MileageInfoBtnSlot()));
	connect(gasInfoBtn, SIGNAL(clicked()), this, SLOT(GasInfoBtnSlot()));
	connect(alarmInfoBtn, SIGNAL(clicked()), this, SLOT(AlarmInfoBtnSlot()));

}

QGroupBox* RobotSelfDataView::CreateBatteryInfoGroupBox(){
	batteryInfoGroupBox = new QGroupBox("机器人电量信息");
	QVBoxLayout* batteryInfoLayout = new QVBoxLayout;
	QHBoxLayout* tempLayout = new QHBoxLayout;

	trueBatteryInfoRadio = new QRadioButton("多");
	falseBatteryInfoRadio = new QRadioButton("单");
	falseBatteryInfoRadio->setChecked(true);

	batteryInfoBtn = new QPushButton("获取机器人电量信息");
	batteryInfoTable = new QTableWidget;
	batteryInfoTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	batteryInfoTable->setColumnCount(3);
	int width = 80;
	batteryInfoTable->setColumnWidth(0, width + 80);
	batteryInfoTable->setColumnWidth(1, width);
	batteryInfoTable->setColumnWidth(2, width);

	QStringList headers;
	headers << "机器人IP" << "电量值" << "电量百分比";
	batteryInfoTable->setHorizontalHeaderLabels(headers);

	tempLayout->addWidget(trueBatteryInfoRadio);
	tempLayout->addWidget(falseBatteryInfoRadio);
	tempLayout->addWidget(batteryInfoBtn);
	tempLayout->addStretch();

	batteryInfoLayout->addLayout(tempLayout);
	batteryInfoLayout->addWidget(batteryInfoTable);
	batteryInfoGroupBox->setLayout(batteryInfoLayout);
	return batteryInfoGroupBox;
}
QGroupBox* RobotSelfDataView::CreateSpeedInfoGroupBox(){
	speedInfoGroupBox = new QGroupBox("机器人速度信息");
	QVBoxLayout* speedInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	trueSpeedInfoRadio = new QRadioButton("多");
	falseSpeedInfoRadio = new QRadioButton("单");
	falseSpeedInfoRadio->setChecked(true);

	speedInfoBtn = new QPushButton("获取机器人速度信息");
	speedInfoTable = new QTableWidget;
	speedInfoTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	speedInfoTable->setColumnCount(2);
	int width = 80;
	speedInfoTable->setColumnWidth(0, width + 80);
	speedInfoTable->setColumnWidth(1, width);

	QStringList headers;
	headers << "机器人IP" << "速度";
	speedInfoTable->setHorizontalHeaderLabels(headers);

	tempLayout->addWidget(trueSpeedInfoRadio);
	tempLayout->addWidget(falseSpeedInfoRadio);
	tempLayout->addWidget(speedInfoBtn);
	tempLayout->addStretch();

	speedInfoLayout->addLayout(tempLayout);
	speedInfoLayout->addWidget(speedInfoTable);
	speedInfoGroupBox->setLayout(speedInfoLayout);
	return speedInfoGroupBox;
}
QGroupBox* RobotSelfDataView::CreatePosInfoGroupBox(){
	posInfoGroupBox = new QGroupBox("机器人位置信息");
	QVBoxLayout* posInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	truePosInfoRadio = new QRadioButton("多");
	falsePosInfoRadio = new QRadioButton("单");
	falsePosInfoRadio->setChecked(true);

	posInfoBtn = new QPushButton("获取机器人位置信息");
	posInfoTable = new QTableWidget;
	posInfoTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	posInfoTable->setColumnCount(6);
	int width = 80;
	posInfoTable->setColumnWidth(0, width + 80);
	posInfoTable->setColumnWidth(1, width);
	posInfoTable->setColumnWidth(2, width);
	posInfoTable->setColumnWidth(3, width);
	posInfoTable->setColumnWidth(4, width);
	posInfoTable->setColumnWidth(5, width);
	QStringList headers;
	headers << "机器人IP" << "PosX" << "PosY" << "Angle" << "边ID" << "占边百分比";

	posInfoTable->setHorizontalHeaderLabels(headers);

	tempLayout->addWidget(truePosInfoRadio);
	tempLayout->addWidget(falsePosInfoRadio);
	tempLayout->addWidget(posInfoBtn);
	tempLayout->addStretch();

	posInfoLayout->addLayout(tempLayout);
	posInfoLayout->addWidget(posInfoTable);
	posInfoGroupBox->setLayout(posInfoLayout);
	return posInfoGroupBox;
}
QGroupBox* RobotSelfDataView::CreateMileageInfoGroupBox(){
	mileageInfoGroupBox = new QGroupBox("机器人里程信息");
	QVBoxLayout* mileageInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	trueMileageInfoRadio = new QRadioButton("多");
	falseMileageInfoRadio = new QRadioButton("单");
	falseMileageInfoRadio->setChecked(true);

	mileageInfoBtn = new QPushButton("获取机器人里程信息");
	mileageInfoTable = new QTableWidget;
	mileageInfoTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	mileageInfoTable->setColumnCount(2);
	int width = 80;
	mileageInfoTable->setColumnWidth(0, width + 80);
	mileageInfoTable->setColumnWidth(1, width);

	QStringList headers;
	headers << "机器人IP" << "里程值";
	mileageInfoTable->setHorizontalHeaderLabels(headers);

	tempLayout->addWidget(trueMileageInfoRadio);
	tempLayout->addWidget(falseMileageInfoRadio);
	tempLayout->addWidget(mileageInfoBtn);
	tempLayout->addStretch();
	mileageInfoLayout->addLayout(tempLayout);
	mileageInfoLayout->addWidget(mileageInfoTable);
	mileageInfoGroupBox->setLayout(mileageInfoLayout);
	return mileageInfoGroupBox;
}

QGroupBox* RobotSelfDataView::CreateGasInfoGroupBox(){
	gasInfoGroupBox = new QGroupBox("机器人检测气体信息");
	QVBoxLayout* gasInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	trueGasInfoRadio = new QRadioButton("多");
	falseGasInfoRadio = new QRadioButton("单");
	falseGasInfoRadio->setChecked(true);

	gasInfoBtn = new QPushButton("获取机器人检测气体信息");
	gasInfoTable = new QTableWidget;
	gasInfoTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	gasInfoTable->setColumnCount(12);
	int width = 40;
	gasInfoTable->setColumnWidth(0, width);
	gasInfoTable->setColumnWidth(1, width);
	gasInfoTable->setColumnWidth(2, width);
	gasInfoTable->setColumnWidth(3, width);
	gasInfoTable->setColumnWidth(4, width);
	gasInfoTable->setColumnWidth(5, width);
	gasInfoTable->setColumnWidth(6, width);
	gasInfoTable->setColumnWidth(7, width);
	gasInfoTable->setColumnWidth(8, width);
	gasInfoTable->setColumnWidth(9, width);
	gasInfoTable->setColumnWidth(10, width);
	gasInfoTable->setColumnWidth(11, width);

	QStringList headers;
	headers << "机器人IP" << "H2S" << "CO" << "O2" << "CH4" << "TEMP" 
		<< "HUM" << "PM25" << "PM10" << "O3" << "SF6" << "Desc";
	gasInfoTable->setHorizontalHeaderLabels(headers);

	tempLayout->addWidget(trueGasInfoRadio);
	tempLayout->addWidget(falseGasInfoRadio);
	tempLayout->addWidget(gasInfoBtn);
	tempLayout->addStretch();

	gasInfoLayout->addLayout(tempLayout);
	gasInfoLayout->addWidget(gasInfoTable);
	gasInfoGroupBox->setLayout(gasInfoLayout);
	return gasInfoGroupBox;
}

QGroupBox* RobotSelfDataView::CreateAlarmInfoGroupBox(){
	alarmInfoGroupBox = new QGroupBox("机器人本体告警信息");
	QVBoxLayout* alarmInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	trueAlarmInfoRadio = new QRadioButton("多");
	falseAlarmInfoRadio = new QRadioButton("单");
	falseAlarmInfoRadio->setChecked(true);

	alarmInfoBtn = new QPushButton("获取机器人本体告警信息");
	alarmInfoTable = new QTableWidget;
	alarmInfoTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	alarmInfoTable->setColumnCount(4);
	int width = 80;
	alarmInfoTable->setColumnWidth(0, width + 80);
	alarmInfoTable->setColumnWidth(1, width);
	alarmInfoTable->setColumnWidth(2, width);
	alarmInfoTable->setColumnWidth(3, width);

	QStringList headers;
	headers << "机器人IP" << "告警描述" << "告警类型" << "告警事件";
	alarmInfoTable->setHorizontalHeaderLabels(headers);
	tempLayout->addWidget(trueAlarmInfoRadio);
	tempLayout->addWidget(falseAlarmInfoRadio);
	tempLayout->addWidget(alarmInfoBtn);
	tempLayout->addStretch();

	alarmInfoLayout->addLayout(tempLayout);
	alarmInfoLayout->addWidget(alarmInfoTable);
	alarmInfoGroupBox->setLayout(alarmInfoLayout);
	return alarmInfoGroupBox;
}


void RobotSelfDataView::BatteryInfoBtnSlot()
{
	bool flag = trueBatteryInfoRadio->isChecked();
	std::vector<BatteryInfo> battery_infos;
	int ret = GetRobotBatteryInfo(flag, battery_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取成功");
		batteryInfoTable->setRowCount(battery_infos.size());
		for (int i = 0; i < battery_infos.size(); ++i)
		{
			QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(battery_infos[i].RobotIp));
			batteryInfoTable->setItem(i, 0, strItem0);
			QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(std::to_string(battery_infos[i].BatteryValue)));
			batteryInfoTable->setItem(i, 1, strItem1);
			QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(std::to_string(battery_infos[i].BatteryPercent)));
			batteryInfoTable->setItem(i, 2, strItem2);
		}
	}
	else
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取失败: " + QString::number(ret));
	}

}
void RobotSelfDataView::SpeedInfoBtnSlot()
{
	bool flag = trueSpeedInfoRadio->isChecked();
	std::vector<SpeedInfo> speed_infos;
	int ret = GetRobotSpeedInfo(flag, speed_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取成功");
		speedInfoTable->setRowCount(speed_infos.size());
		for (int i = 0; i < speed_infos.size(); ++i)
		{
			QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString((speed_infos[i].robot_ip)));
			speedInfoTable->setItem(i, 0, strItem0);
			QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(std::to_string(speed_infos[i].speed)));
			speedInfoTable->setItem(i, 1, strItem1);
		}
	}
	else
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取失败: " + QString::number(ret));
	}
}
void RobotSelfDataView::PosInfoBtnSlot()
{
	bool flag = truePosInfoRadio->isChecked();
	std::vector<RobotPosInfo> pos_infos;
	int ret = GetRobotPosInfo(flag, pos_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取成功");
		posInfoTable->setRowCount(pos_infos.size());
		for (int i = 0; i < pos_infos.size(); ++i)
		{
			QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(pos_infos[i].RobotIp));
			posInfoTable->setItem(i, 0, strItem0);
			QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(pos_infos[i].PosX));
			posInfoTable->setItem(i, 1, strItem1);
			QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(pos_infos[i].PosY));
			posInfoTable->setItem(i, 2, strItem2);
			QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(pos_infos[i].Angle));
			posInfoTable->setItem(i, 3, strItem3);
			QTableWidgetItem *strItem4 = new QTableWidgetItem(QString::fromStdString(pos_infos[i].EdgeID));
			posInfoTable->setItem(i, 4, strItem4);
			QTableWidgetItem *strItem5 = new QTableWidgetItem(QString::fromStdString(pos_infos[i].Precent));
			posInfoTable->setItem(i, 5, strItem5);
		}
	}
	else
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取失败: " + QString::number(ret));
	}
}
void RobotSelfDataView::MileageInfoBtnSlot()
{
	bool flag = trueMileageInfoRadio->isChecked();
	std::vector<RobotMileageInfo> mileage_infos;
	int ret = GetRobotMileageInfo(flag, mileage_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取成功");
		mileageInfoTable->setRowCount(mileage_infos.size());
		for (int i = 0; i < mileage_infos.size(); ++i)
		{
			QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(mileage_infos[i].RobotIp));
			mileageInfoTable->setItem(i, 0, strItem0);
			QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(std::to_string(mileage_infos[i].Mileage)));
			mileageInfoTable->setItem(i, 1, strItem1);
		}
	}
	else
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取失败: " + QString::number(ret));
	}
}
void RobotSelfDataView::GasInfoBtnSlot()
{
	bool flag = trueGasInfoRadio->isChecked();
	std::vector<RobotGasInfo> gas_infos;
	int ret = GetRobotGasInfo(flag, gas_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取成功");
		gasInfoTable->setRowCount(gas_infos.size());
		for (int i = 0; i < gas_infos.size(); ++i)
		{
			QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].robot_ip));
			gasInfoTable->setItem(i, 0, strItem0);
			QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].H2S));
			gasInfoTable->setItem(i, 1, strItem1);
			QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].CO));
			gasInfoTable->setItem(i, 2, strItem2);
			QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].O2));
			gasInfoTable->setItem(i, 3, strItem3);
			QTableWidgetItem *strItem4 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].CH4));
			gasInfoTable->setItem(i, 4, strItem4);
			QTableWidgetItem *strItem5 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].TEMP));
			gasInfoTable->setItem(i, 5, strItem5);
			QTableWidgetItem *strItem6 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].HUM));
			gasInfoTable->setItem(i, 6, strItem6);
			QTableWidgetItem *strItem7 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].PM25));
			gasInfoTable->setItem(i, 7, strItem7);
			QTableWidgetItem *strItem8 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].PM10));
			gasInfoTable->setItem(i, 8, strItem8);
			QTableWidgetItem *strItem9 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].O3));
			gasInfoTable->setItem(i, 9, strItem9);
			QTableWidgetItem *strItem10 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].SF6));
			gasInfoTable->setItem(i, 10, strItem10);
			QTableWidgetItem *strItem11 = new QTableWidgetItem(QString::fromStdString(gas_infos[i].Desc));
			gasInfoTable->setItem(i, 11, strItem11);
		}
	}
	else
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取失败: " + QString::number(ret));
	}
}
void RobotSelfDataView::AlarmInfoBtnSlot()
{
	bool flag = trueAlarmInfoRadio->isChecked();
	std::vector<RobotAlarmInfo> alarm_infos;
	int ret = GetRobotAlarmInfo(flag, alarm_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取成功");
		alarmInfoTable->setRowCount(alarm_infos.size());
		for (int i = 0; i < alarm_infos.size(); ++i)
		{
			QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(alarm_infos[i].RobotIp));
			alarmInfoTable->setItem(i, 0, strItem0);
			QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(alarm_infos[i].AlarmDesc));
			alarmInfoTable->setItem(i, 1, strItem1);
			QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(alarm_infos[i].AlarmType));
			alarmInfoTable->setItem(i, 2, strItem2);
			QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(alarm_infos[i].AlarmTime));
			alarmInfoTable->setItem(i, 3, strItem3);
		}
	}
	else
	{
		QMessageBox::information(this, "机器人本体数据获取提示", "获取失败: " + QString::number(ret));
	}
}

RobotSelfDataView::~RobotSelfDataView()
{
}
