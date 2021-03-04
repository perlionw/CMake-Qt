#pragma once
#include "qwidget.h"
#include "qpushbutton.h"
#include "qtablewidget.h"
#include "qlayout.h"
#include "qheaderview.h"
#include "basictool.h"
#include "taskdata_imply.h"
#include "qgroupbox.h"
#include "qmessagebox.h"
#include "qlabel.h"
#include "qlineedit.h"
class TaskDataView :
	public QWidget
{
	Q_OBJECT
public:
	TaskDataView(QWidget* parent = 0);
	~TaskDataView();

	QGroupBox* CreateMapAreaInfoGroupBox();
	QGroupBox* CreateMapEdgeInfoGroupBox();
	QGroupBox* CreateDockPointInfoGroupBox();
	QGroupBox* CreatePatrolAreaInfoGroupBox();
	QGroupBox* CreatePatrolPointInfoGroupBox();

	void ConnectSlot();

public slots:
	void MapAreaInfoBtnSlot();	
	void MapEdgeInfoBtnSlot();
	void DockPointInfoBtnSlot();
	void PatrolAreaInfoBtnSlot();
	void PatrolPointInfoBtnSlot();
private:

	QGridLayout* mainLayout;

	QGroupBox* mapAreaInfoGroupBox;
	QPushButton* mapAreaInfoBtn;
	QTableWidget* mapAreaInfoTable;

	QGroupBox* mapEdgeInfoGroupBox;
	QPushButton* mapEdgeInfoBtn;
	QTableWidget* mapEdgeInfoTable;
	QLineEdit* areaIdEdit;

	QGroupBox* dockPointInfoGroupBox;
	QPushButton* dockPointInfoBtn;
	QTableWidget* dockPointInfoTable;

	QGroupBox* patrolAreaInfoGroupBox;
	QPushButton* patrolAreaInfoBtn;
	QTableWidget* patrolAreaInfoTable;

	QGroupBox* patrolPointInfoGroupBox;
	QPushButton* patrolPointInfoBtn;
	QTableWidget* patrolPointInfoTable;
};

