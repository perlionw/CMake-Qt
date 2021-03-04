#pragma once
#include "qwidget.h"
#include "qgroupbox.h"
#include "qlayout.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "qheaderview.h"
#include "taskfinish_imply.h"
#include "qdatetimeedit.h"
#include "qtablewidget.h"
#include "qheaderview.h"
#include "basictool.h"
#include "qlabel.h"
#include "qlineedit.h"
class PatrolDataView :
	public QWidget
{
	Q_OBJECT
public:
	PatrolDataView(QWidget* parent = 0);
	~PatrolDataView();

	QGroupBox* CreateTaskFinishInfoByTimeGroupBox();
	QGroupBox* CreateTaskExcuteInfoByTaskIdGroupBox();

	void ConnectSlot();

public slots:
	void TaskExcuteInfoByTaskIdBtnSlot();
	void TaskFinishInfoByTimeBtnSlot();
private:

	QVBoxLayout* mainLayout;

	QGroupBox* taskFinishInfoByTimeGroupBox;
	QPushButton* taskFinishInfoByTimeBtn;
	QDateTimeEdit* startTimeEdit;
	QDateTimeEdit* endTimeEdit;
	QTableWidget* taskFinishInfoByTimeTable;
	

	QGroupBox* taskExcuteInfoByTaskIdGroupBox;
	QPushButton* taskExcuteInfoByTaskIdBtn;
	QLineEdit* taskIdEdit;
	QTableWidget* taskExcuteInfoByTaskIdTable;
};

