#pragma once
#include "qwidget.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qboxlayout.h"
#include "qlistwidget.h"
#include "qlineedit.h"
//#include "station_imply.h"
#include "qcombobox.h"
#include "qgroupbox.h"
#include "qtablewidget.h"
#include "qheaderview.h"
#include "qmessagebox.h"
#include "qradiobutton.h"
#include "qdatetimeedit.h"

class TaskControlView :
	public QWidget
{
	Q_OBJECT
public:
	TaskControlView(QWidget *parent = 0);
	~TaskControlView();

public:
	QHBoxLayout* CreateActionLayout();
	QHBoxLayout* CreateSearchLayout();
	QHBoxLayout* CreateLabelLayout();
	QHBoxLayout* CreateTaskLayout();

	QGroupBox* CreateTaskStatusGroupBox();
	QGroupBox* CreateTaskExcuteDataGroupBox();
	QGroupBox* CreateSetTaskPathGroupBox();

	QStringList GetRobotIp();
	
	void ReadDatabaseConfig(std::string file_path);
	void ConnectSlot();
public slots:
	void TaskStartSlot();
	void TaskPauseSlot();
	void TaskRestartSlot();
	void TaskCancelSlot();
	void TaskAutoChargeSlot();
	void LoadPointSlot();
	void GetTaskPathSlot();
	void SearchPointSlot();
	void LoadTaskPathSlot();
	void SetTaskPointSlot(QListWidgetItem *);
	void DeleteTaskPointSlot(QListWidgetItem *item);
	void GetTaskPathSlot(QListWidgetItem *item);
	void GetRobotIpSlot(const QString &);
	void GetTaskStatusSlot();
	void TaskStatuSlot(int, int);
	void GetTaskExcuteDataSlot();

	void SetTaskPathSlot();
public:

	struct PointInfo
	{
		QString device_id;
		QString device_desc;
	};

	struct TaskPathInfo1
	{
		QString task_path_desc;
		QString device_count;
		QString path_insert_time;
		QString task_path_id;
	};

	struct TaskStatusInfo
	{
		QString robot_ip;
		QString task_id;
		QString task_desc;
		QString task_status;
		QString task_process;
		QString total_count;
		QString current_device_name;
		QString current_device_id;
		QString next_device_name;
		QString next_device_id;
	};

	QLabel* label;
	QComboBox* robotIpcomboBox;
	QPushButton* taskStartBtn;
	QPushButton* taskPauseBtn;
	QPushButton* taskCancelBtn;
	QPushButton* taskRestartBtn;
	QPushButton* taskAutoChargeBtn;
	QPushButton* loadTaskPathBtn;
	QVBoxLayout* mainLayout;
	QListWidget* point_list_widget_;
	QListWidget* task_list_widget_;
	QHBoxLayout* taskLayout;
	QHBoxLayout* actionLayout;
	QHBoxLayout* searchLayout;
	QPushButton* searchBtn;
	QPushButton* loadPointBtn;
	QLineEdit* pointLineEdit;
	QHBoxLayout* labelLayout;

	QGroupBox* taskStatusGroupBox;
	QRadioButton* trueTaskStatusRadio;
	QRadioButton* falseTaskStatusRadio;
	QPushButton* getTaskStatusBtn;
	QTableWidget* taskInfoTable;

	QGroupBox* taskExcuteGroupBox;
	QPushButton* taskExcuteDataBtn;
	QTableWidget* taskExcuteDataTable;

	QGroupBox* setTaskPathGroupBox;
	QLineEdit* taskPathIdEdit;
	QLineEdit* taskNameEdit;
	QComboBox* taskTypeCombox;
	QDateTimeEdit* createTimeEdit;
	QRadioButton* stopActionRadio;
	QRadioButton* returnChargeActionRadio;
	QPushButton* setTaskPathBtn;

	
	QListWidget* task_path_list_widget_;
	QString current_task_id;

	std::vector<PointInfo> vct_point_info_;
	QString robot_ip_;
	QStringList robotIpList_;


	std::string db_user_;
	std::string db_pass_;
	std::string db_port_;
	std::string db_host_;
	std::string db_name_;


};

