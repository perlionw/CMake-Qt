#include "StationDeviceControlView.h"
#include "basictool.h"
//#include "station_imply.h"
#include "qsqlquery.h"
#include "qvariant.h"
#include "robotdata_imply.h"

StationDeviceControlView::StationDeviceControlView(QWidget *parent) : QWidget(parent)
{
	mainLayout = new QGridLayout(this);
	InitControlConfig(); 
	mainLayout->addWidget(CreateCameraControlGroupBox(), 0, 0);
	mainLayout->addWidget(CreateFlirControlGroupBox(), 0, 1);
	mainLayout->addWidget(CreateYuntaiControlGroupBox(), 1, 0);
	mainLayout->addWidget(CreateRobotLifterControlGroupBox(), 1, 1);
	mainLayout->addWidget(CreateRobotPdControlGroupBox(), 2, 0);
	mainLayout->addWidget(CreateRobotWiperControlGroupBox(), 2, 1);
	robotIpList_ = GetRobotIp();
	ConnectSlot();
}

bool StationDeviceControlView::SearchControlMap(QString text, QString &ControlId)
{
	std::map<QString, QString>::iterator it = controlMap.begin();
	for (; it != controlMap.end(); ++it)
	{
		if (it->first.contains(QRegExp(text)))
		{
			ControlId = it->second;
			return true;
		}
	}
	return false;
}

void StationDeviceControlView::InitControlConfig()
{
	QString selectCarSql = "select TID, TNAME from typeinfo where TGRADE = 99 and TSTATUS <= 1";
	QSqlQuery query;
	bool b = query.exec(selectCarSql);
	while (query.next())
	{
		controlMap[query.value(1).toString()] = query.value(0).toString();
	}
}

QStringList StationDeviceControlView::GetRobotIp()
{
	QStringList robotIpList;
	QString selectCarSql = "select PC_IP from carinfo";
	QSqlQuery query;
	bool b = query.exec(selectCarSql);
	while (query.next())
	{
		robotIpList << query.value(0).toString();
	}

	return robotIpList;
}

void StationDeviceControlView::ConnectSlot()
{
	//红外控制
	connect(focusUpBtn, SIGNAL(clicked()), this, SLOT(FocusUpBtnSlot()));
	connect(focusDownBtn, SIGNAL(clicked()), this, SLOT(FocusDownBtnSlot()));
	connect(autoFocusBtn, SIGNAL(clicked()), this, SLOT(AutoFocusBtnSlot()));

	//相机控制
	connect(zoomUpBtn, SIGNAL(clicked()), this, SLOT(ZoomUpBtnSlot()));
	connect(zoomUpStopBtn, SIGNAL(clicked()), this, SLOT(ZoomUpStopBtnSlot()));
	connect(zoomDownBtn, SIGNAL(clicked()), this, SLOT(ZoomDownBtnSlot()));
	connect(zoomDownStopBtn, SIGNAL(clicked()), this, SLOT(ZoomDownStopBtnSlot()));
	connect(focusNearBtn, SIGNAL(clicked()), this, SLOT(FocusNearBtnSlot()));
	connect(focusNearStopBtn, SIGNAL(clicked()), this, SLOT(FocusNearStopBtnSlot()));
	connect(focusFarBtn, SIGNAL(clicked()), this, SLOT(FocusFarBtnSlot()));
	connect(focusFarStopBtn, SIGNAL(clicked()), this, SLOT(FocusFarStopBtnSlot()));
	connect(cameraResetBtn, SIGNAL(clicked()), this, SLOT(CameraResetBtnSlot()));
	connect(lightOnBtn, SIGNAL(clicked()), this, SLOT(LightOnBtnSlot()));
	connect(lightOffBtn, SIGNAL(clicked()), this, SLOT(LightOffBtnSlot()));

	//云台控制
	connect(turnUpBtn, SIGNAL(clicked()), this, SLOT(TurnUpBtnSlot()));
	connect(turnDownBtn, SIGNAL(clicked()), this, SLOT(TurnDownBtnSlot()));
	connect(turnLeftBtn, SIGNAL(clicked()), this, SLOT(TurnLeftBtnSlot()));
	connect(turnRightBtn, SIGNAL(clicked()), this, SLOT(TurnRightBtnSlot()));
	connect(turnStopBtn, SIGNAL(clicked()), this, SLOT(TurnStopBtnSlot()));
	connect(turnResetBtn, SIGNAL(clicked()), this, SLOT(TurnResetBtnSlot()));

	//升降控制
	connect(lifterUpBtn, SIGNAL(clicked()), this, SLOT(LifterUpBtnSlot()));
	connect(lifterDownBtn, SIGNAL(clicked()), this, SLOT(LifterDownBtnSlot()));
	connect(lifterStopBtn, SIGNAL(clicked()), this, SLOT(LifterStopBtnSlot()));

	//局放机构控制
	connect(pdForWardBtn, SIGNAL(clicked()), this, SLOT(PdForWardBtnSlot()));
	connect(pdBackWordBtn, SIGNAL(clicked()), this, SLOT(PdBackWordBtnSlot()));
	connect(pdStopBtn, SIGNAL(clicked()), this, SLOT(PdStopBtnSlot()));

	//雨刷控制
	connect(wiperOnBtn, SIGNAL(clicked()), this, SLOT(WiperOnBtnSlot()));
	connect(wiperOffBtn, SIGNAL(clicked()), this, SLOT(WiperOffBtnSlot()));
	
}

QGroupBox* StationDeviceControlView::CreateFlirControlGroupBox()
{
	flirControlGroupBox = new QGroupBox;
	flirControlGroupBox->setTitle("红外控制");
	focusUpBtn = new QPushButton("聚焦+");
	focusDownBtn = new QPushButton("聚焦-");
	autoFocusBtn = new QPushButton("自动聚焦");
	flirControlLayout = new QVBoxLayout;
	flirControlLayout->addWidget(focusUpBtn);
	flirControlLayout->addWidget(focusDownBtn);
	flirControlLayout->addWidget(autoFocusBtn);
	
	flirControlLayout->addStretch();

	flirControlGroupBox->setLayout(flirControlLayout);
	return flirControlGroupBox;
}
QGroupBox* StationDeviceControlView::CreateCameraControlGroupBox()
{
	cameraControlGroupBox = new QGroupBox;
	cameraControlGroupBox->setTitle("相机控制");

	cameraControlLayout = new QVBoxLayout;
	zoomUpBtn = new QPushButton("变倍+");
	zoomUpStopBtn = new QPushButton("变倍+停止");
	zoomDownBtn = new QPushButton("变倍-");
	zoomDownStopBtn = new QPushButton("变倍-停止");
	focusNearBtn = new QPushButton("变焦+");
	focusNearStopBtn = new QPushButton("变焦+停止");
	focusFarBtn = new QPushButton("变焦-");
	focusFarStopBtn = new QPushButton("变焦-停止");
	cameraResetBtn = new QPushButton("复位");
	lightOnBtn = new QPushButton("补光灯开");
	lightOffBtn = new QPushButton("补光灯关");

	cameraControlLayout->addWidget(zoomUpBtn);
	cameraControlLayout->addWidget(zoomUpStopBtn);
	cameraControlLayout->addWidget(zoomDownBtn);
	cameraControlLayout->addWidget(zoomDownStopBtn);
	cameraControlLayout->addWidget(focusNearBtn);
	cameraControlLayout->addWidget(focusNearStopBtn);
	cameraControlLayout->addWidget(focusFarBtn);
	cameraControlLayout->addWidget(focusFarStopBtn);
	cameraControlLayout->addWidget(cameraResetBtn);
	cameraControlLayout->addWidget(lightOnBtn);
	cameraControlLayout->addWidget(lightOffBtn);
	cameraControlLayout->addStretch();
	cameraControlGroupBox->setLayout(cameraControlLayout);
	return cameraControlGroupBox;
}
QGroupBox* StationDeviceControlView::CreateYuntaiControlGroupBox()
{
	yuntaiControlGroupBox = new QGroupBox;
	yuntaiControlGroupBox->setTitle("云台控制");
	yuntaiControlLayout = new QVBoxLayout;
	turnUpBtn = new QPushButton("上仰");
	turnDownBtn = new QPushButton("下俯");
	turnLeftBtn = new QPushButton("左转");
	turnRightBtn = new QPushButton("右转");
	turnStopBtn = new QPushButton("停止");
	turnResetBtn = new QPushButton("复位");
	yuntaiControlLayout->addWidget(turnUpBtn);
	yuntaiControlLayout->addWidget(turnDownBtn);
	yuntaiControlLayout->addWidget(turnLeftBtn);
	yuntaiControlLayout->addWidget(turnRightBtn);
	yuntaiControlLayout->addWidget(turnStopBtn);
	yuntaiControlLayout->addWidget(turnResetBtn);
	yuntaiControlLayout->addStretch();
	yuntaiControlGroupBox->setLayout(yuntaiControlLayout);
	return yuntaiControlGroupBox;
}

QGroupBox* StationDeviceControlView::CreateRobotLifterControlGroupBox()
{
	robotLifterControlGroupBox = new QGroupBox;
	robotLifterControlGroupBox->setTitle("升降控制");
	robotLifterControlLayout = new QVBoxLayout;
	lifterUpBtn = new QPushButton("上升");
	lifterDownBtn = new QPushButton("下降");
	lifterStopBtn = new QPushButton("升降停止");
	robotLifterControlLayout->addWidget(lifterUpBtn);
	robotLifterControlLayout->addWidget(lifterDownBtn);
	robotLifterControlLayout->addWidget(lifterStopBtn);
	robotLifterControlLayout->addStretch();
	robotLifterControlGroupBox->setLayout(robotLifterControlLayout);
	return robotLifterControlGroupBox;
}

QGroupBox* StationDeviceControlView::CreateRobotPdControlGroupBox()
{
	robotPdControlGroupBox = new QGroupBox;
	robotPdControlGroupBox->setTitle("局放控制");
	robotPdControlLayout = new QVBoxLayout;
	pdForWardBtn = new QPushButton("局放前");
	pdBackWordBtn = new QPushButton("局放后");
	pdStopBtn = new QPushButton("局放停止");
	robotPdControlLayout->addWidget(pdForWardBtn);
	robotPdControlLayout->addWidget(pdBackWordBtn);
	robotPdControlLayout->addWidget(pdStopBtn);
	robotPdControlLayout->addStretch();
	robotPdControlGroupBox->setLayout(robotPdControlLayout);
	return robotPdControlGroupBox;
}

QGroupBox* StationDeviceControlView::CreateRobotWiperControlGroupBox()
{
	robotWiperControlGroupBox = new QGroupBox;
	robotWiperControlGroupBox->setTitle("雨刷控制");
	robotWiperControlLayout = new QVBoxLayout;
	wiperOnBtn = new QPushButton("雨刷开");
	wiperOffBtn = new QPushButton("雨刷关");
	robotWiperControlLayout->addWidget(wiperOnBtn);
	robotWiperControlLayout->addWidget(wiperOffBtn);
	robotWiperControlLayout->addStretch();
	robotWiperControlGroupBox->setLayout(robotWiperControlLayout);
	return robotWiperControlGroupBox;
}

//红外聚焦+
void StationDeviceControlView::FocusUpBtnSlot()
{

	int ret = RobotFlirControl(FilrControlType::FilrControlType__FocusUp); 
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}
}

//红外聚焦-
void StationDeviceControlView::FocusDownBtnSlot()
{

	int ret = RobotFlirControl(FilrControlType::FilrControlType__FocusDown);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//自动聚焦
void StationDeviceControlView::AutoFocusBtnSlot()
{
	int ret = RobotFlirControl(FilrControlType::FilrControlType__AutoFocus);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}
}	

//变倍+
void StationDeviceControlView::ZoomUpBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__ZoomUp);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}
}

//变倍+停止
void StationDeviceControlView::ZoomUpStopBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__ZoomUpStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//变倍-
void StationDeviceControlView::ZoomDownBtnSlot()
{

	int ret = RobotCameraControl(CameraControlType::CameraControlType__ZoomDown);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//变倍-停止
void StationDeviceControlView::ZoomDownStopBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__ZoomDownStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//变焦+
void StationDeviceControlView::FocusNearBtnSlot()
{

	int ret = RobotCameraControl(CameraControlType::CameraControlType__FocusNear);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//变焦+停止
void StationDeviceControlView::FocusNearStopBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__FocusNearStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}
}	

//变焦-
void StationDeviceControlView::FocusFarBtnSlot()
{

	int ret = RobotCameraControl(CameraControlType::CameraControlType__FocusFar);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//变焦-停止
void StationDeviceControlView::FocusFarStopBtnSlot()
{

	int ret = RobotCameraControl(CameraControlType::CameraControlType__FocusFarStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//相机复位
void StationDeviceControlView::CameraResetBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__CameraReset);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}
}

//补光灯开
void StationDeviceControlView::LightOnBtnSlot()
{

	int ret = RobotLightControl(LightControlType::LightControlType__LightOn);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//补光灯关
void StationDeviceControlView::LightOffBtnSlot()
{
	int ret = RobotLightControl(LightControlType::LightControlType__LightOff);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//上仰
void StationDeviceControlView::TurnUpBtnSlot()
{
	
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnUp);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//下俯
void StationDeviceControlView::TurnDownBtnSlot()
{

	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnDown);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//左转
void StationDeviceControlView::TurnLeftBtnSlot()
{
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnLeft);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//右转
void StationDeviceControlView::TurnRightBtnSlot()
{
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnRight);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//云台停止
void StationDeviceControlView::TurnStopBtnSlot()
{
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//云台复位
void StationDeviceControlView::TurnResetBtnSlot()
{
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnReset);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}
}

//上升
void StationDeviceControlView::LifterUpBtnSlot()
{
	int ret = RobotLifterControl(LifterControlType::LifterControlType__LifterUp);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//下降
void StationDeviceControlView::LifterDownBtnSlot()
{
	int ret = RobotLifterControl(LifterControlType::LifterControlType__LifterDown);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//升降停止
void StationDeviceControlView::LifterStopBtnSlot()
{
	int ret = RobotLifterControl(LifterControlType::LifterControlType__LifterStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//局放前
void StationDeviceControlView::PdForWardBtnSlot()
{
	int ret = RobotPdControl(PdControlType::PdControlType__PdForWard);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//局放后
void StationDeviceControlView::PdBackWordBtnSlot()
{
	int ret = RobotPdControl(PdControlType::PdControlType__PdBackWord);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//局放停止
void StationDeviceControlView::PdStopBtnSlot()
{
	int ret = RobotPdControl(PdControlType::PdControlType__PdStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//雨刷开
void StationDeviceControlView::WiperOnBtnSlot()
{

	int ret = RobotWiperControl(WiperControlType::WiperControlType__WiperOn);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

//雨刷关
void StationDeviceControlView::WiperOffBtnSlot()
{
	int ret = RobotWiperControl(WiperControlType::WiperControlType__WiperOff);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备成功");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "控制设备失败: " + QString::number(ret));
	}

}

StationDeviceControlView::~StationDeviceControlView()
{
}
