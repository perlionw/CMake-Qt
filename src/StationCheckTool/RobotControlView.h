#pragma once
#include "qwidget.h"
#include "qlabel.h"
#include "qboxlayout.h"
#include "qpushbutton.h"
#include "qspinbox.h"
#include "qradiobutton.h"
#include "qgroupbox.h"
#include "qcombobox.h"
#include "qmessagebox.h"
#include "qtablewidget.h"
#include "qheaderview.h"
class RobotControlView :
	public QWidget
{
	Q_OBJECT
public:
	RobotControlView(QWidget *parent = 0);
	~RobotControlView();

	void InitControlConfig();
	bool SearchControlMap(QString text, QString& ControlId);

	QGroupBox* CreateControlModeGroupBox();
	QGroupBox* CreateRobotControlGroupBox();
	QGroupBox* CreateRobotInfoGroupBox();

	void ConnectSlot();
public slots:
	void ForwardSlot();
	void BackwardSlot();
	void LeftSlot();
	void RightSlot();
	void StopSlot();

	void AutoModeSlot();
	void ManualModeSlot();
	void ReleaseCurrentRobotBtnSlot();
	void RobotInfoBtnSlot();

	void GetRobotIpSlot(const QString &);
	QStringList GetRobotIp();

public:
	QVBoxLayout* mainLayout;
	QPushButton* forwardBtn;
	QPushButton* backwardBtn;
	QPushButton* leftBtn;
	QPushButton* rightBtn;
	QHBoxLayout* actionLayout;
	QDoubleSpinBox* lineSpeedSpinBox;
	QDoubleSpinBox* angleSpeedSpinBox;
	QRadioButton* manualModeRadioBtn;
	QRadioButton* autoModeRadioBtn;
	QPushButton* stopBtn;

	QHBoxLayout* controlModeLayout;

	QGroupBox* actionGroupBox;
	QGroupBox* controlmodeGroupBox;
	QComboBox* robotIpComboBox;
	QPushButton* releaseCurrentRobotBtn;

	QLabel* lineSpeedLabel;
	QLabel* angleSpeedLabel;
	double linespeed;
	double anglespeed;

	QVBoxLayout* robotInfoLayout;
	QGroupBox* robotInfoGroupBox;
	QPushButton* robotInfoBtn;
	QTableWidget* robotInfoTable;

	QString robot_ip_;
	QStringList robotIpList_;

	std::map<QString, QString> controlMap;
};

