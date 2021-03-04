#pragma once
#include "qwidget.h"
#include "qlayout.h"
#include "qpushbutton.h"
#include "qtablewidget.h"
#include "qlineedit.h"
#include "qlabel.h"
#include "qgroupbox.h"
#include "qheaderview.h"
#include "qradiobutton.h"
#include "qmessagebox.h"
class RobotSelfDataView :
	public QWidget
{
	Q_OBJECT
public:
	RobotSelfDataView(QWidget *parent = 0);
	~RobotSelfDataView();

	QGroupBox* CreateBatteryInfoGroupBox();
	QGroupBox* CreateSpeedInfoGroupBox();
	QGroupBox* CreatePosInfoGroupBox();
	QGroupBox* CreateMileageInfoGroupBox();
	QGroupBox* CreateGasInfoGroupBox();
	QGroupBox* CreateAlarmInfoGroupBox();

	void ConnectInfo();

public slots:
	void BatteryInfoBtnSlot();
	void SpeedInfoBtnSlot();
	void PosInfoBtnSlot();
	void MileageInfoBtnSlot();
	void GasInfoBtnSlot();
	void AlarmInfoBtnSlot();

private:
	QGridLayout* mainLayout;
	QGroupBox* batteryInfoGroupBox;
	QPushButton* batteryInfoBtn;
	QTableWidget* batteryInfoTable;
	QRadioButton* trueBatteryInfoRadio;
	QRadioButton* falseBatteryInfoRadio;


	QGroupBox* speedInfoGroupBox;
	QPushButton* speedInfoBtn;
	QTableWidget* speedInfoTable;
	QRadioButton* trueSpeedInfoRadio;
	QRadioButton* falseSpeedInfoRadio;
	
	
	QGroupBox* posInfoGroupBox;
	QPushButton* posInfoBtn;
	QTableWidget* posInfoTable;
	QRadioButton* truePosInfoRadio;
	QRadioButton* falsePosInfoRadio;

	QGroupBox* mileageInfoGroupBox;
	QPushButton* mileageInfoBtn;
	QTableWidget* mileageInfoTable;
	QRadioButton* trueMileageInfoRadio;
	QRadioButton* falseMileageInfoRadio;

	QGroupBox* gasInfoGroupBox;
	QPushButton* gasInfoBtn;
	QTableWidget* gasInfoTable;
	QRadioButton* trueGasInfoRadio;
	QRadioButton* falseGasInfoRadio;

	QGroupBox* alarmInfoGroupBox;
	QPushButton* alarmInfoBtn;
	QTableWidget* alarmInfoTable;
	QRadioButton* trueAlarmInfoRadio;
	QRadioButton* falseAlarmInfoRadio;
};

