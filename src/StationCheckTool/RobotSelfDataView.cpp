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
	batteryInfoGroupBox = new QGroupBox("�����˵�����Ϣ");
	QVBoxLayout* batteryInfoLayout = new QVBoxLayout;
	QHBoxLayout* tempLayout = new QHBoxLayout;

	trueBatteryInfoRadio = new QRadioButton("��");
	falseBatteryInfoRadio = new QRadioButton("��");
	falseBatteryInfoRadio->setChecked(true);

	batteryInfoBtn = new QPushButton("��ȡ�����˵�����Ϣ");
	batteryInfoTable = new QTableWidget;
	batteryInfoTable->horizontalHeader()->setStretchLastSection(true); //���ñ�ͷ�������Ŀ��
	batteryInfoTable->setColumnCount(3);
	int width = 80;
	batteryInfoTable->setColumnWidth(0, width + 80);
	batteryInfoTable->setColumnWidth(1, width);
	batteryInfoTable->setColumnWidth(2, width);

	QStringList headers;
	headers << "������IP" << "����ֵ" << "�����ٷֱ�";
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
	speedInfoGroupBox = new QGroupBox("�������ٶ���Ϣ");
	QVBoxLayout* speedInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	trueSpeedInfoRadio = new QRadioButton("��");
	falseSpeedInfoRadio = new QRadioButton("��");
	falseSpeedInfoRadio->setChecked(true);

	speedInfoBtn = new QPushButton("��ȡ�������ٶ���Ϣ");
	speedInfoTable = new QTableWidget;
	speedInfoTable->horizontalHeader()->setStretchLastSection(true); //���ñ�ͷ�������Ŀ��
	speedInfoTable->setColumnCount(2);
	int width = 80;
	speedInfoTable->setColumnWidth(0, width + 80);
	speedInfoTable->setColumnWidth(1, width);

	QStringList headers;
	headers << "������IP" << "�ٶ�";
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
	posInfoGroupBox = new QGroupBox("������λ����Ϣ");
	QVBoxLayout* posInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	truePosInfoRadio = new QRadioButton("��");
	falsePosInfoRadio = new QRadioButton("��");
	falsePosInfoRadio->setChecked(true);

	posInfoBtn = new QPushButton("��ȡ������λ����Ϣ");
	posInfoTable = new QTableWidget;
	posInfoTable->horizontalHeader()->setStretchLastSection(true); //���ñ�ͷ�������Ŀ��
	posInfoTable->setColumnCount(6);
	int width = 80;
	posInfoTable->setColumnWidth(0, width + 80);
	posInfoTable->setColumnWidth(1, width);
	posInfoTable->setColumnWidth(2, width);
	posInfoTable->setColumnWidth(3, width);
	posInfoTable->setColumnWidth(4, width);
	posInfoTable->setColumnWidth(5, width);
	QStringList headers;
	headers << "������IP" << "PosX" << "PosY" << "Angle" << "��ID" << "ռ�߰ٷֱ�";

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
	mileageInfoGroupBox = new QGroupBox("�����������Ϣ");
	QVBoxLayout* mileageInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	trueMileageInfoRadio = new QRadioButton("��");
	falseMileageInfoRadio = new QRadioButton("��");
	falseMileageInfoRadio->setChecked(true);

	mileageInfoBtn = new QPushButton("��ȡ�����������Ϣ");
	mileageInfoTable = new QTableWidget;
	mileageInfoTable->horizontalHeader()->setStretchLastSection(true); //���ñ�ͷ�������Ŀ��
	mileageInfoTable->setColumnCount(2);
	int width = 80;
	mileageInfoTable->setColumnWidth(0, width + 80);
	mileageInfoTable->setColumnWidth(1, width);

	QStringList headers;
	headers << "������IP" << "���ֵ";
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
	gasInfoGroupBox = new QGroupBox("�����˼��������Ϣ");
	QVBoxLayout* gasInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	trueGasInfoRadio = new QRadioButton("��");
	falseGasInfoRadio = new QRadioButton("��");
	falseGasInfoRadio->setChecked(true);

	gasInfoBtn = new QPushButton("��ȡ�����˼��������Ϣ");
	gasInfoTable = new QTableWidget;
	gasInfoTable->horizontalHeader()->setStretchLastSection(true); //���ñ�ͷ�������Ŀ��
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
	headers << "������IP" << "H2S" << "CO" << "O2" << "CH4" << "TEMP" 
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
	alarmInfoGroupBox = new QGroupBox("�����˱���澯��Ϣ");
	QVBoxLayout* alarmInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	trueAlarmInfoRadio = new QRadioButton("��");
	falseAlarmInfoRadio = new QRadioButton("��");
	falseAlarmInfoRadio->setChecked(true);

	alarmInfoBtn = new QPushButton("��ȡ�����˱���澯��Ϣ");
	alarmInfoTable = new QTableWidget;
	alarmInfoTable->horizontalHeader()->setStretchLastSection(true); //���ñ�ͷ�������Ŀ��
	alarmInfoTable->setColumnCount(4);
	int width = 80;
	alarmInfoTable->setColumnWidth(0, width + 80);
	alarmInfoTable->setColumnWidth(1, width);
	alarmInfoTable->setColumnWidth(2, width);
	alarmInfoTable->setColumnWidth(3, width);

	QStringList headers;
	headers << "������IP" << "�澯����" << "�澯����" << "�澯�¼�";
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
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡ�ɹ�");
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
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡʧ��: " + QString::number(ret));
	}

}
void RobotSelfDataView::SpeedInfoBtnSlot()
{
	bool flag = trueSpeedInfoRadio->isChecked();
	std::vector<SpeedInfo> speed_infos;
	int ret = GetRobotSpeedInfo(flag, speed_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡ�ɹ�");
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
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡʧ��: " + QString::number(ret));
	}
}
void RobotSelfDataView::PosInfoBtnSlot()
{
	bool flag = truePosInfoRadio->isChecked();
	std::vector<RobotPosInfo> pos_infos;
	int ret = GetRobotPosInfo(flag, pos_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡ�ɹ�");
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
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡʧ��: " + QString::number(ret));
	}
}
void RobotSelfDataView::MileageInfoBtnSlot()
{
	bool flag = trueMileageInfoRadio->isChecked();
	std::vector<RobotMileageInfo> mileage_infos;
	int ret = GetRobotMileageInfo(flag, mileage_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡ�ɹ�");
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
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡʧ��: " + QString::number(ret));
	}
}
void RobotSelfDataView::GasInfoBtnSlot()
{
	bool flag = trueGasInfoRadio->isChecked();
	std::vector<RobotGasInfo> gas_infos;
	int ret = GetRobotGasInfo(flag, gas_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡ�ɹ�");
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
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡʧ��: " + QString::number(ret));
	}
}
void RobotSelfDataView::AlarmInfoBtnSlot()
{
	bool flag = trueAlarmInfoRadio->isChecked();
	std::vector<RobotAlarmInfo> alarm_infos;
	int ret = GetRobotAlarmInfo(flag, alarm_infos);
	if (ret == 0)
	{
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡ�ɹ�");
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
		QMessageBox::information(this, "�����˱������ݻ�ȡ��ʾ", "��ȡʧ��: " + QString::number(ret));
	}
}

RobotSelfDataView::~RobotSelfDataView()
{
}
