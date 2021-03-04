#pragma once
#include "qwidget.h"
#include "qgroupbox.h"
#include "qlayout.h"
#include "qcombobox.h"
#include "qlistwidget.h"
#include "qpushbutton.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qtablewidget.h"
#include "qheaderview.h"
#include "qmessagebox.h"
class DataView :
	public QWidget
{
	Q_OBJECT
public:
	DataView(QWidget* parent = 0);
	~DataView();

	QGroupBox* CreateRobotPosGroupBox();
	QGroupBox* CreateRobotPatrolEdgeGroupBox();
	QGroupBox* CreateStationDeviceGroupBox();
	QGroupBox* CreateControlModeGroupBox();
	QGroupBox* CreateTaskStatusGroupBox();
	QGroupBox* CreateRobotDataGroupBox();

	void InitStationDeviceConfig();
	void InitRobotDataConfig();
	void ConnectSlot();
public slots:
	void StationDeviceSlot(const QString &);
	void RobotDataSlot(const QString &);
	void GetControlModeSlot();
	void GetTaskStatusSlot();
public:
	QGroupBox* robotPosGroupBox;
	QVBoxLayout* robotPosLayout;

	QGroupBox* robotPatrolEdgeGroupBox;
	
	QGroupBox* stationDeviceGroupBox;
	QComboBox* stationDeviceCombox;
	QListWidget* stationDeviceListWidget;

	QGroupBox* controlModeGroupBox;
	QPushButton* getControlModeBtn;
	QLineEdit* robotIpLineEdit;

	QGroupBox* taskStatusGroupBox;
	QPushButton* getTaskStatusBtn;
	QTableWidget* taskInfoTable;
	QLineEdit* robot_ipLineEdit;

	QGroupBox* robotDataGroupBox;
	QComboBox* robotDataCombox;
	QListWidget* robotDataListWidget;

	QGridLayout* mainLayout;

	std::map<QString, QString> station_device_map;
	std::map<QString, QString> robot_data_map;
};

