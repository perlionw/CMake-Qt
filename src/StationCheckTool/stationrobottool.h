#ifndef STATIONROBOTTOOL_H
#define STATIONROBOTTOOL_H

#include <QtWidgets/QWidget>
#include "ui_stationrobottool.h"
#include "qtreewidget.h"
#include "qstackedwidget.h"
#include "qlayout.h"
#include "TaskControlView.h"
#include "RobotControlView.h"
#include "StationDeviceControlView.h"
#include "DataView.h"
#include "RobotSelfDataView.h"
#include "TaskDataView.h"
#include "PatrolDataView.h"
class StationRobotTool : public QWidget
{
	Q_OBJECT

public:
	StationRobotTool(QWidget *parent = 0);
	~StationRobotTool();

	void ReadConfig(std::string file_path);

private:
	Ui::StationRobotToolClass ui;
	QTreeWidget *treeWidget;
	QStackedWidget *stackWindow;
	QHBoxLayout *mainLayout;
	TaskControlView* taskcontrolview;
	RobotControlView* robotcontrolview;
	StationDeviceControlView* stationdevicecontrolview;
	DataView* dataView;
	RobotSelfDataView* robotselfdataview;
	TaskDataView* taskdataview;
	PatrolDataView* patroldataview;
	QVBoxLayout* menuLayout;
	QLabel* currentAction;
	QString currentActionText;
	QPushButton* getRobotTimeBtn;
	QLabel* robotTimeLabel;

	QString robot_time_;

	std::string robotdata_addr;
	std::string taskdata_addr;
	std::string taskfinish_addr;
public slots:
	void ChangeModule(QTreeWidgetItem *item1, int count1);
	void GetRobotTimeBtnSlot();
};

#endif // STATIONROBOTTOOL_H
