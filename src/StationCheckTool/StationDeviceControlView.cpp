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
	//�������
	connect(focusUpBtn, SIGNAL(clicked()), this, SLOT(FocusUpBtnSlot()));
	connect(focusDownBtn, SIGNAL(clicked()), this, SLOT(FocusDownBtnSlot()));
	connect(autoFocusBtn, SIGNAL(clicked()), this, SLOT(AutoFocusBtnSlot()));

	//�������
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

	//��̨����
	connect(turnUpBtn, SIGNAL(clicked()), this, SLOT(TurnUpBtnSlot()));
	connect(turnDownBtn, SIGNAL(clicked()), this, SLOT(TurnDownBtnSlot()));
	connect(turnLeftBtn, SIGNAL(clicked()), this, SLOT(TurnLeftBtnSlot()));
	connect(turnRightBtn, SIGNAL(clicked()), this, SLOT(TurnRightBtnSlot()));
	connect(turnStopBtn, SIGNAL(clicked()), this, SLOT(TurnStopBtnSlot()));
	connect(turnResetBtn, SIGNAL(clicked()), this, SLOT(TurnResetBtnSlot()));

	//��������
	connect(lifterUpBtn, SIGNAL(clicked()), this, SLOT(LifterUpBtnSlot()));
	connect(lifterDownBtn, SIGNAL(clicked()), this, SLOT(LifterDownBtnSlot()));
	connect(lifterStopBtn, SIGNAL(clicked()), this, SLOT(LifterStopBtnSlot()));

	//�ַŻ�������
	connect(pdForWardBtn, SIGNAL(clicked()), this, SLOT(PdForWardBtnSlot()));
	connect(pdBackWordBtn, SIGNAL(clicked()), this, SLOT(PdBackWordBtnSlot()));
	connect(pdStopBtn, SIGNAL(clicked()), this, SLOT(PdStopBtnSlot()));

	//��ˢ����
	connect(wiperOnBtn, SIGNAL(clicked()), this, SLOT(WiperOnBtnSlot()));
	connect(wiperOffBtn, SIGNAL(clicked()), this, SLOT(WiperOffBtnSlot()));
	
}

QGroupBox* StationDeviceControlView::CreateFlirControlGroupBox()
{
	flirControlGroupBox = new QGroupBox;
	flirControlGroupBox->setTitle("�������");
	focusUpBtn = new QPushButton("�۽�+");
	focusDownBtn = new QPushButton("�۽�-");
	autoFocusBtn = new QPushButton("�Զ��۽�");
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
	cameraControlGroupBox->setTitle("�������");

	cameraControlLayout = new QVBoxLayout;
	zoomUpBtn = new QPushButton("�䱶+");
	zoomUpStopBtn = new QPushButton("�䱶+ֹͣ");
	zoomDownBtn = new QPushButton("�䱶-");
	zoomDownStopBtn = new QPushButton("�䱶-ֹͣ");
	focusNearBtn = new QPushButton("�佹+");
	focusNearStopBtn = new QPushButton("�佹+ֹͣ");
	focusFarBtn = new QPushButton("�佹-");
	focusFarStopBtn = new QPushButton("�佹-ֹͣ");
	cameraResetBtn = new QPushButton("��λ");
	lightOnBtn = new QPushButton("����ƿ�");
	lightOffBtn = new QPushButton("����ƹ�");

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
	yuntaiControlGroupBox->setTitle("��̨����");
	yuntaiControlLayout = new QVBoxLayout;
	turnUpBtn = new QPushButton("����");
	turnDownBtn = new QPushButton("�¸�");
	turnLeftBtn = new QPushButton("��ת");
	turnRightBtn = new QPushButton("��ת");
	turnStopBtn = new QPushButton("ֹͣ");
	turnResetBtn = new QPushButton("��λ");
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
	robotLifterControlGroupBox->setTitle("��������");
	robotLifterControlLayout = new QVBoxLayout;
	lifterUpBtn = new QPushButton("����");
	lifterDownBtn = new QPushButton("�½�");
	lifterStopBtn = new QPushButton("����ֹͣ");
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
	robotPdControlGroupBox->setTitle("�ַſ���");
	robotPdControlLayout = new QVBoxLayout;
	pdForWardBtn = new QPushButton("�ַ�ǰ");
	pdBackWordBtn = new QPushButton("�ַź�");
	pdStopBtn = new QPushButton("�ַ�ֹͣ");
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
	robotWiperControlGroupBox->setTitle("��ˢ����");
	robotWiperControlLayout = new QVBoxLayout;
	wiperOnBtn = new QPushButton("��ˢ��");
	wiperOffBtn = new QPushButton("��ˢ��");
	robotWiperControlLayout->addWidget(wiperOnBtn);
	robotWiperControlLayout->addWidget(wiperOffBtn);
	robotWiperControlLayout->addStretch();
	robotWiperControlGroupBox->setLayout(robotWiperControlLayout);
	return robotWiperControlGroupBox;
}

//����۽�+
void StationDeviceControlView::FocusUpBtnSlot()
{

	int ret = RobotFlirControl(FilrControlType::FilrControlType__FocusUp); 
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}
}

//����۽�-
void StationDeviceControlView::FocusDownBtnSlot()
{

	int ret = RobotFlirControl(FilrControlType::FilrControlType__FocusDown);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�Զ��۽�
void StationDeviceControlView::AutoFocusBtnSlot()
{
	int ret = RobotFlirControl(FilrControlType::FilrControlType__AutoFocus);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}
}	

//�䱶+
void StationDeviceControlView::ZoomUpBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__ZoomUp);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}
}

//�䱶+ֹͣ
void StationDeviceControlView::ZoomUpStopBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__ZoomUpStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�䱶-
void StationDeviceControlView::ZoomDownBtnSlot()
{

	int ret = RobotCameraControl(CameraControlType::CameraControlType__ZoomDown);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�䱶-ֹͣ
void StationDeviceControlView::ZoomDownStopBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__ZoomDownStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�佹+
void StationDeviceControlView::FocusNearBtnSlot()
{

	int ret = RobotCameraControl(CameraControlType::CameraControlType__FocusNear);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�佹+ֹͣ
void StationDeviceControlView::FocusNearStopBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__FocusNearStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}
}	

//�佹-
void StationDeviceControlView::FocusFarBtnSlot()
{

	int ret = RobotCameraControl(CameraControlType::CameraControlType__FocusFar);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�佹-ֹͣ
void StationDeviceControlView::FocusFarStopBtnSlot()
{

	int ret = RobotCameraControl(CameraControlType::CameraControlType__FocusFarStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�����λ
void StationDeviceControlView::CameraResetBtnSlot()
{
	int ret = RobotCameraControl(CameraControlType::CameraControlType__CameraReset);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}
}

//����ƿ�
void StationDeviceControlView::LightOnBtnSlot()
{

	int ret = RobotLightControl(LightControlType::LightControlType__LightOn);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//����ƹ�
void StationDeviceControlView::LightOffBtnSlot()
{
	int ret = RobotLightControl(LightControlType::LightControlType__LightOff);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//����
void StationDeviceControlView::TurnUpBtnSlot()
{
	
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnUp);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�¸�
void StationDeviceControlView::TurnDownBtnSlot()
{

	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnDown);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//��ת
void StationDeviceControlView::TurnLeftBtnSlot()
{
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnLeft);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//��ת
void StationDeviceControlView::TurnRightBtnSlot()
{
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnRight);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//��ֹ̨ͣ
void StationDeviceControlView::TurnStopBtnSlot()
{
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//��̨��λ
void StationDeviceControlView::TurnResetBtnSlot()
{
	int ret = RobotYuntaiControl(YuntaiControlType::YuntaiControlType__TurnReset);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}
}

//����
void StationDeviceControlView::LifterUpBtnSlot()
{
	int ret = RobotLifterControl(LifterControlType::LifterControlType__LifterUp);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�½�
void StationDeviceControlView::LifterDownBtnSlot()
{
	int ret = RobotLifterControl(LifterControlType::LifterControlType__LifterDown);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//����ֹͣ
void StationDeviceControlView::LifterStopBtnSlot()
{
	int ret = RobotLifterControl(LifterControlType::LifterControlType__LifterStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�ַ�ǰ
void StationDeviceControlView::PdForWardBtnSlot()
{
	int ret = RobotPdControl(PdControlType::PdControlType__PdForWard);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�ַź�
void StationDeviceControlView::PdBackWordBtnSlot()
{
	int ret = RobotPdControl(PdControlType::PdControlType__PdBackWord);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//�ַ�ֹͣ
void StationDeviceControlView::PdStopBtnSlot()
{
	int ret = RobotPdControl(PdControlType::PdControlType__PdStop);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//��ˢ��
void StationDeviceControlView::WiperOnBtnSlot()
{

	int ret = RobotWiperControl(WiperControlType::WiperControlType__WiperOn);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

//��ˢ��
void StationDeviceControlView::WiperOffBtnSlot()
{
	int ret = RobotWiperControl(WiperControlType::WiperControlType__WiperOff);
	if (ret == 0)
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸�ɹ�");
	}
	else
	{
		QMessageBox::information(this, CONTROL_TIP, "�����豸ʧ��: " + QString::number(ret));
	}

}

StationDeviceControlView::~StationDeviceControlView()
{
}
