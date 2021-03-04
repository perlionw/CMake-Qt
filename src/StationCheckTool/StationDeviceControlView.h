#pragma once
#include "qwidget.h"
#include "qgroupbox.h"
#include "qlayout.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
class StationDeviceControlView :
	public QWidget
{
	Q_OBJECT
public:
	StationDeviceControlView(QWidget *parent = 0);
	~StationDeviceControlView();

	void InitControlConfig();
	bool SearchControlMap(QString text, QString& ControlId);

public slots:
	void FocusUpBtnSlot();
	void FocusDownBtnSlot();
	void AutoFocusBtnSlot();

	void ZoomUpBtnSlot();
	void ZoomUpStopBtnSlot();
	void ZoomDownBtnSlot();
	void ZoomDownStopBtnSlot();
	void FocusNearBtnSlot();
	void FocusNearStopBtnSlot();
	void FocusFarBtnSlot();
	void FocusFarStopBtnSlot();
	void CameraResetBtnSlot();
	void LightOnBtnSlot();
	void LightOffBtnSlot();

	void TurnUpBtnSlot();
	void TurnDownBtnSlot();
	void TurnLeftBtnSlot();
	void TurnRightBtnSlot();
	void TurnStopBtnSlot();
	void TurnResetBtnSlot();

	void LifterUpBtnSlot();
	void LifterDownBtnSlot();
	void LifterStopBtnSlot();

	void PdForWardBtnSlot();
	void PdBackWordBtnSlot();
	void PdStopBtnSlot();

	void WiperOnBtnSlot();
	void WiperOffBtnSlot();

	void ConnectSlot();

	QStringList GetRobotIp();

public:
	QGroupBox* CreateFlirControlGroupBox();
	QGroupBox* CreateCameraControlGroupBox();
	QGroupBox* CreateYuntaiControlGroupBox();
	QGroupBox* CreateRobotLifterControlGroupBox();
	QGroupBox* CreateRobotPdControlGroupBox();
	QGroupBox* CreateRobotWiperControlGroupBox();
public:
	QGridLayout* mainLayout;
	//红外控制
	QGroupBox* flirControlGroupBox;
	QPushButton* focusUpBtn;
	QPushButton* focusDownBtn;
	QPushButton* autoFocusBtn;
	QVBoxLayout* flirControlLayout;

	//相机控制
	QGroupBox* cameraControlGroupBox;
	QVBoxLayout* cameraControlLayout;
	QPushButton* zoomUpBtn;
	QPushButton* zoomUpStopBtn;
	QPushButton* zoomDownBtn;
	QPushButton* zoomDownStopBtn;
	QPushButton* focusNearBtn;
	QPushButton* focusNearStopBtn;
	QPushButton* focusFarBtn;
	QPushButton* focusFarStopBtn;
	QPushButton* cameraResetBtn;
	QPushButton* lightOnBtn;
	QPushButton* lightOffBtn;

	//云台控制
	QGroupBox* yuntaiControlGroupBox;
	QVBoxLayout* yuntaiControlLayout;
	QPushButton* turnUpBtn;
	QPushButton* turnDownBtn;
	QPushButton* turnLeftBtn;
	QPushButton* turnRightBtn;
	QPushButton* turnStopBtn;
	QPushButton* turnResetBtn;

	//升降控制
	QGroupBox* robotLifterControlGroupBox;
	QVBoxLayout* robotLifterControlLayout;
	QPushButton* lifterUpBtn;
	QPushButton* lifterDownBtn;
	QPushButton* lifterStopBtn;

	//局放机构控制
	QGroupBox* robotPdControlGroupBox;
	QVBoxLayout* robotPdControlLayout;
	QPushButton* pdForWardBtn;
	QPushButton* pdBackWordBtn;
	QPushButton* pdStopBtn;

	//雨刷控制
	QGroupBox* robotWiperControlGroupBox;
	QVBoxLayout* robotWiperControlLayout;
	QPushButton* wiperOnBtn;
	QPushButton* wiperOffBtn;

	QStringList robotIpList_;
	std::map<QString, QString> controlMap;
};

