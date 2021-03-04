#include "TaskDataView.h"


TaskDataView::TaskDataView(QWidget* parent) : QWidget(parent)
{
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(CreateMapAreaInfoGroupBox(), 0, 0);
	mainLayout->addWidget(CreatePatrolAreaInfoGroupBox(), 0, 1);
	mainLayout->addWidget(CreateMapEdgeInfoGroupBox(), 1, 0, 1, 2);
	mainLayout->addWidget(CreatePatrolPointInfoGroupBox(), 2, 0);
	mainLayout->addWidget(CreateDockPointInfoGroupBox(), 2, 1);
	ConnectSlot();
}

void TaskDataView::ConnectSlot()
{
	connect(mapAreaInfoBtn, SIGNAL(clicked()), this, SLOT(MapAreaInfoBtnSlot()));
	connect(mapEdgeInfoBtn, SIGNAL(clicked()), this, SLOT(MapEdgeInfoBtnSlot()));
	connect(dockPointInfoBtn, SIGNAL(clicked()), this, SLOT(DockPointInfoBtnSlot()));
	connect(patrolAreaInfoBtn, SIGNAL(clicked()), this, SLOT(PatrolAreaInfoBtnSlot()));
	connect(patrolPointInfoBtn, SIGNAL(clicked()), this, SLOT(PatrolPointInfoBtnSlot()));
}

QGroupBox* TaskDataView::CreateMapAreaInfoGroupBox()
{
	mapAreaInfoGroupBox = new QGroupBox("��ͼ������Ϣ");
	QVBoxLayout* mapAreaInfoLayout = new QVBoxLayout;
	mapAreaInfoBtn = new QPushButton("��ȡ��ͼ������Ϣ");
	mapAreaInfoTable = new QTableWidget;
	mapAreaInfoTable->horizontalHeader()->setStretchLastSection(true);
	mapAreaInfoTable->setColumnCount(3);
	int width = 80;

	mapAreaInfoTable->setColumnWidth(0, width);
	mapAreaInfoTable->setColumnWidth(1, width);
	mapAreaInfoTable->setColumnWidth(2, width);

	QStringList headers;
	headers << "����ID" << "��������" << "��ͼͼƬ";
	mapAreaInfoTable->setHorizontalHeaderLabels(headers);

	mapAreaInfoLayout->addWidget(mapAreaInfoBtn);
	mapAreaInfoLayout->addWidget(mapAreaInfoTable);
	mapAreaInfoGroupBox->setLayout(mapAreaInfoLayout);
	return mapAreaInfoGroupBox;
}

QGroupBox* TaskDataView::CreateMapEdgeInfoGroupBox()
{
	mapEdgeInfoGroupBox = new QGroupBox("Ѳ��·����Ϣ");
	QVBoxLayout* mapEdgeInfoLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	QLabel* areaIdLabel = new QLabel("����������ID: ");
	areaIdEdit = new QLineEdit;
	mapEdgeInfoBtn = new QPushButton("��ȡѲ��·����Ϣ");
	tempLayout->addWidget(areaIdLabel);
	tempLayout->addWidget(areaIdEdit);
	tempLayout->addWidget(mapEdgeInfoBtn);

	mapEdgeInfoTable = new QTableWidget;
	mapEdgeInfoTable->horizontalHeader()->setStretchLastSection(true);
	mapEdgeInfoTable->setColumnCount(11);
	int width = 80;
	mapEdgeInfoTable->setColumnWidth(0, width - 10);
	mapEdgeInfoTable->setColumnWidth(1, width - 10);
	mapEdgeInfoTable->setColumnWidth(2, width - 10);
	QStringList headers;
	headers << "·��ID" << "��ʼ��ID" << "��ֹ��ID" << "��ʼ��x����" << "��ʼ��y����"
		<< "��ֹ��x����" << "��ֹ��y����" << "first���Ƶ�x����" << "first���Ƶ�y����" 
		<< "second���Ƶ�x����" << "second���Ƶ�y����";
	mapEdgeInfoTable->setHorizontalHeaderLabels(headers);

	mapEdgeInfoLayout->addLayout(tempLayout);
	mapEdgeInfoLayout->addWidget(mapEdgeInfoTable);
	mapEdgeInfoGroupBox->setLayout(mapEdgeInfoLayout);
	return mapEdgeInfoGroupBox;
}

QGroupBox* TaskDataView::CreateDockPointInfoGroupBox()
{
	dockPointInfoGroupBox = new QGroupBox("ͣ����λ��Ϣ");
	QVBoxLayout* dockPointInfoLayout = new QVBoxLayout;
	dockPointInfoBtn = new QPushButton("��ȡͣ����λ��Ϣ");
	dockPointInfoTable = new QTableWidget;
	dockPointInfoTable->horizontalHeader()->setStretchLastSection(true);
	dockPointInfoTable->setColumnCount(4);
	int width = 80;

	dockPointInfoTable->setColumnWidth(0, width + 20);
	dockPointInfoTable->setColumnWidth(1, width + 20);
	dockPointInfoTable->setColumnWidth(2, width + 20);
	dockPointInfoTable->setColumnWidth(3, width);

	QStringList headers;
	headers << "ͣ����λID" << "ͣ����x����" << "ͣ����y����" << "Ѳ���λ�б�����";
	dockPointInfoTable->setHorizontalHeaderLabels(headers);

	dockPointInfoLayout->addWidget(dockPointInfoBtn);
	dockPointInfoLayout->addWidget(dockPointInfoTable);
	dockPointInfoGroupBox->setLayout(dockPointInfoLayout); 
	return dockPointInfoGroupBox;
}

QGroupBox* TaskDataView::CreatePatrolAreaInfoGroupBox()
{
	patrolAreaInfoGroupBox = new QGroupBox("Ѳ��������Ϣ");
	QVBoxLayout* patrolAreaInfoLayout = new QVBoxLayout;
	patrolAreaInfoBtn = new QPushButton("��ȡѲ��������Ϣ");
	patrolAreaInfoTable = new QTableWidget;
	patrolAreaInfoTable->horizontalHeader()->setStretchLastSection(true);
	patrolAreaInfoTable->setColumnCount(3);
	int width = 80;

	patrolAreaInfoTable->setColumnWidth(0, width);
	patrolAreaInfoTable->setColumnWidth(1, width);
	patrolAreaInfoTable->setColumnWidth(2, width);

	QStringList headers;
	headers << "����ID" << "��������" << "����������ID";
	patrolAreaInfoTable->setHorizontalHeaderLabels(headers);

	patrolAreaInfoLayout->addWidget(patrolAreaInfoBtn);
	patrolAreaInfoLayout->addWidget(patrolAreaInfoTable);
	patrolAreaInfoGroupBox->setLayout(patrolAreaInfoLayout);
	return patrolAreaInfoGroupBox;
}

QGroupBox* TaskDataView::CreatePatrolPointInfoGroupBox()
{
	patrolPointInfoGroupBox = new QGroupBox("Ѳ���λ��Ϣ");
	QVBoxLayout* patrolPointInfoLayout = new QVBoxLayout;
	patrolPointInfoBtn = new QPushButton("��ȡѲ���λ��Ϣ");
	patrolPointInfoTable = new QTableWidget;
	patrolPointInfoTable->horizontalHeader()->setStretchLastSection(true);
	patrolPointInfoTable->setColumnCount(5);
	int width = 80;

	patrolPointInfoTable->setColumnWidth(0, width + 15);
	patrolPointInfoTable->setColumnWidth(1, width + 20);
	patrolPointInfoTable->setColumnWidth(2, width + 20);
	patrolPointInfoTable->setColumnWidth(3, width + 4);


	QStringList headers;
	headers << "Ѳ���λID" << "Ѳ���λ����" << "Ѳ���λ����" << "��������ID" << "����ͣ����ID";
	patrolPointInfoTable->setHorizontalHeaderLabels(headers);

	patrolPointInfoLayout->addWidget(patrolPointInfoBtn);
	patrolPointInfoLayout->addWidget(patrolPointInfoTable);
	patrolPointInfoGroupBox->setLayout(patrolPointInfoLayout);
	return patrolPointInfoGroupBox;
}

void TaskDataView::MapAreaInfoBtnSlot()
{
	std::vector<MapAreaInfo> map_area_infos;
	int ret = GetMapAreaInfo(map_area_infos);
	if (ret == 0)
	{
		if (map_area_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "��ȡ���ݳɹ�");
			mapAreaInfoTable->setRowCount(map_area_infos.size());
			for (int i = 0; i < map_area_infos.size(); ++i)
			{
				QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(map_area_infos[i].AreaId));
				mapAreaInfoTable->setItem(i, 0, strItem0);
				QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(map_area_infos[i].AreaName));
				mapAreaInfoTable->setItem(i, 1, strItem1);
				QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(map_area_infos[i].AreaMap));
				mapAreaInfoTable->setItem(i, 2, strItem2);
			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "���ݻ�ȡΪ��");
		}

	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "��ȡ����ʧ��: " + QString::number(ret));
	}
}

void TaskDataView::MapEdgeInfoBtnSlot()
{
	std::string area_id = areaIdEdit->text().toStdString();
	std::vector<MapEdgeInfo> map_edge_infos;
	int ret = GetMapEdgeInfo(area_id, map_edge_infos);
	if (ret == 0)
	{
		if (map_edge_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "��ȡ���ݳɹ�");
			mapEdgeInfoTable->setRowCount(map_edge_infos.size());
			for (int i = 0; i < map_edge_infos.size(); ++i)
			{
				QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].EdgeId));
				mapEdgeInfoTable->setItem(i, 0, strItem0);
				QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].StartNodeId));
				mapEdgeInfoTable->setItem(i, 1, strItem1);
				QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].EdgeId));
				mapEdgeInfoTable->setItem(i, 2, strItem2);
				QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].StartNodeX));
				mapEdgeInfoTable->setItem(i, 3, strItem3);
				QTableWidgetItem *strItem4 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].StartNodeY));
				mapEdgeInfoTable->setItem(i, 4, strItem4);
				QTableWidgetItem *strItem5 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].EndNodeX));
				mapEdgeInfoTable->setItem(i, 5, strItem5);
				QTableWidgetItem *strItem6 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].EndNodeY));
				mapEdgeInfoTable->setItem(i, 6, strItem6);
				QTableWidgetItem *strItem7 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].FirstControlX));
				mapEdgeInfoTable->setItem(i, 7, strItem7);
				QTableWidgetItem *strItem8 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].FirstControlY));
				mapEdgeInfoTable->setItem(i, 8, strItem8);
				QTableWidgetItem *strItem9 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].SecondControlX));
				mapEdgeInfoTable->setItem(i, 9, strItem9);
				QTableWidgetItem *strItem10 = new QTableWidgetItem(QString::fromStdString(map_edge_infos[i].SecondControlY));
				mapEdgeInfoTable->setItem(i, 10, strItem10);
			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "���ݻ�ȡΪ��");
		}
	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "��ȡ����ʧ��: " + QString::number(ret));
	}
	
}

void TaskDataView::DockPointInfoBtnSlot()
{
	std::vector<DockPointInfo> dock_point_infos;
	int ret = GetDockPointInfo(dock_point_infos);
	if (ret == 0)
	{
		if (dock_point_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "��ȡ���ݳɹ�");
			dockPointInfoTable->setRowCount(dock_point_infos.size());
			for (int i = 0; i < dock_point_infos.size(); ++i)
			{
				QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(dock_point_infos[i].DockId));
				dockPointInfoTable->setItem(i, 0, strItem0);
				QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(dock_point_infos[i].DockX));
				dockPointInfoTable->setItem(i, 1, strItem1);
				QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(dock_point_infos[i].DockY));
				dockPointInfoTable->setItem(i, 2, strItem2);
				QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(std::to_string(dock_point_infos[i].PointList.size())));
				dockPointInfoTable->setItem(i, 3, strItem3);
			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "���ݻ�ȡΪ��");
		}
	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "��ȡ����ʧ��: " + QString::number(ret));
	}
}

void TaskDataView::PatrolAreaInfoBtnSlot()
{
	std::vector<PatrolValueInfo> patrol_value_infos;
	int ret = GetPatrolAreaInfo(patrol_value_infos);
	if (ret == 0)
	{
		if (patrol_value_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "��ȡ���ݳɹ�");
			patrolAreaInfoTable->setRowCount(patrol_value_infos.size());
			for (int i = 0; i < patrol_value_infos.size(); ++i)
			{
				QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(patrol_value_infos[i].AreaId));
				patrolAreaInfoTable->setItem(i, 0, strItem0);
				QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(patrol_value_infos[i].AreaName));
				patrolAreaInfoTable->setItem(i, 1, strItem1);
				QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(patrol_value_infos[i].ParentId));
				patrolAreaInfoTable->setItem(i, 2, strItem2);
			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "���ݻ�ȡΪ��");
		}
	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "��ȡ����ʧ��: " + QString::number(ret));
	}
}

void TaskDataView::PatrolPointInfoBtnSlot()
{
	std::vector<PatrolPointInfo> patrol_point_infos;
	int ret = GetPatrolPointInfo(patrol_point_infos);
	if (ret == 0)
	{
		if (patrol_point_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "��ȡ���ݳɹ�");
			patrolPointInfoTable->setRowCount(patrol_point_infos.size());
			for (int i = 0; i < patrol_point_infos.size(); ++i)
			{
				QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(patrol_point_infos[i].PointId));
				patrolPointInfoTable->setItem(i, 0, strItem0);
				QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(patrol_point_infos[i].PointName));
				patrolPointInfoTable->setItem(i, 1, strItem1);
				QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(patrol_point_infos[i].PointType));
				patrolPointInfoTable->setItem(i, 2, strItem2);
				QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(patrol_point_infos[i].AreaId));
				patrolPointInfoTable->setItem(i, 3, strItem3);
				QTableWidgetItem *strItem4 = new QTableWidgetItem(QString::fromStdString(patrol_point_infos[i].DockId));
				patrolPointInfoTable->setItem(i, 4, strItem4);
			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "���ݻ�ȡΪ��");
		}
	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "��ȡ����ʧ��: " + QString::number(ret));
	}
}

TaskDataView::~TaskDataView()
{
}
