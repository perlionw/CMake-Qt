#include "PatrolDataView.h"


PatrolDataView::PatrolDataView(QWidget* parent) : QWidget(parent)
{
	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(CreateTaskFinishInfoByTimeGroupBox());
	mainLayout->addWidget(CreateTaskExcuteInfoByTaskIdGroupBox());
	ConnectSlot();
}

void PatrolDataView::ConnectSlot()
{
	connect(taskExcuteInfoByTaskIdBtn, SIGNAL(clicked()), this, SLOT(TaskExcuteInfoByTaskIdBtnSlot()));
	connect(taskFinishInfoByTimeBtn, SIGNAL(clicked()), this, SLOT(TaskFinishInfoByTimeBtnSlot()));
}


void PatrolDataView::TaskExcuteInfoByTaskIdBtnSlot()
{
	std::string task_id = taskIdEdit->text().toStdString();
	std::vector<TaskExcuteInfo> task_excute_infos;
	int ret = GetTaskExcuteInfoByTaskId(task_id, task_excute_infos);
	if (ret == 0)
	{
		if (task_excute_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "数据获取成功");
			taskExcuteInfoByTaskIdTable->setRowCount(task_excute_infos.size());
			for (int i = 0; i < task_excute_infos.size(); ++i)
			{
				QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].TaskId));
				taskExcuteInfoByTaskIdTable->setItem(i, 0, strItem0);
				QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].TaskName));
				taskExcuteInfoByTaskIdTable->setItem(i, 1, strItem1);
				QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].TaskType));
				taskExcuteInfoByTaskIdTable->setItem(i, 2, strItem2);
				QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].TaskPathId));
				taskExcuteInfoByTaskIdTable->setItem(i, 3, strItem3);
				QTableWidgetItem *strItem4 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].TargetId));
				taskExcuteInfoByTaskIdTable->setItem(i, 4, strItem4);
				QTableWidgetItem *strItem5 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].PointId));
				taskExcuteInfoByTaskIdTable->setItem(i, 5, strItem5);
				QTableWidgetItem *strItem6 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].PointName));
				taskExcuteInfoByTaskIdTable->setItem(i, 6, strItem6);
				QTableWidgetItem *strItem7 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].PointType));
				taskExcuteInfoByTaskIdTable->setItem(i, 7, strItem7);
				QTableWidgetItem *strItem8 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].ExcuteTime));
				taskExcuteInfoByTaskIdTable->setItem(i, 8, strItem8);
				QTableWidgetItem *strItem9 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].ExcuteValue));
				taskExcuteInfoByTaskIdTable->setItem(i, 9, strItem9);
				QTableWidgetItem *strItem10 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].ExcuteState));
				taskExcuteInfoByTaskIdTable->setItem(i, 10, strItem10);
				QTableWidgetItem *strItem11 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].ExcuteDesc));
				taskExcuteInfoByTaskIdTable->setItem(i, 11, strItem11);
				QTableWidgetItem *strItem12 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].HDPicture));
				taskExcuteInfoByTaskIdTable->setItem(i, 12, strItem12);
				QTableWidgetItem *strItem13 = new QTableWidgetItem(QString::fromStdString(task_excute_infos[i].InfraredPicture));
				taskExcuteInfoByTaskIdTable->setItem(i, 13, strItem13);
			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "数据获取为空");
		}
	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "数据获取失败: " + QString::number(ret));
	}
}

void PatrolDataView::TaskFinishInfoByTimeBtnSlot()
{
	std::string start_time = startTimeEdit->text().toStdString();
	std::string end_time = endTimeEdit->text().toStdString();
	std::vector<TaskFinishInfo> task_finish_infos;
	int ret = GetTaskFinishInfoByTime(start_time, end_time, task_finish_infos);
	if (ret == 0)
	{
		if (task_finish_infos.size() > 0)
		{
			QMessageBox::information(this, GETDATA_TIP, "数据获取成功");
			taskFinishInfoByTimeTable->setRowCount(task_finish_infos.size());
			for (int i = 0; i < task_finish_infos.size(); ++i)
			{
				QTableWidgetItem *strItem0 = new QTableWidgetItem(QString::fromStdString(task_finish_infos[i].TaskId));
				taskFinishInfoByTimeTable->setItem(i, 0, strItem0);
				QTableWidgetItem *strItem1 = new QTableWidgetItem(QString::fromStdString(task_finish_infos[i].TaskName));
				taskFinishInfoByTimeTable->setItem(i, 1, strItem1);
				QTableWidgetItem *strItem2 = new QTableWidgetItem(QString::fromStdString(task_finish_infos[i].TaskType));
				taskFinishInfoByTimeTable->setItem(i, 2, strItem2);
				QTableWidgetItem *strItem3 = new QTableWidgetItem(QString::fromStdString(task_finish_infos[i].TaskPathId));
				taskFinishInfoByTimeTable->setItem(i, 3, strItem3);
				QTableWidgetItem *strItem4 = new QTableWidgetItem(QString::fromStdString(std::to_string(task_finish_infos[i].PointList.size())));
				taskFinishInfoByTimeTable->setItem(i, 4, strItem4);
				QTableWidgetItem *strItem5 = new QTableWidgetItem(QString::fromStdString(task_finish_infos[i].StartTime));
				taskFinishInfoByTimeTable->setItem(i, 5, strItem5);
				QTableWidgetItem *strItem6 = new QTableWidgetItem(QString::fromStdString(task_finish_infos[i].EndTime));
				taskFinishInfoByTimeTable->setItem(i, 6, strItem6);
				QTableWidgetItem *strItem7 = new QTableWidgetItem(QString::fromStdString(task_finish_infos[i].FinishState));
				taskFinishInfoByTimeTable->setItem(i, 7, strItem7);
				QTableWidgetItem *strItem8 = new QTableWidgetItem(QString::fromStdString(task_finish_infos[i].ExcuteRobot));
				taskFinishInfoByTimeTable->setItem(i, 8, strItem8);
			}
		}
		else
		{
			QMessageBox::information(this, GETDATA_TIP, "数据获取为空");
		}
		
	}
	else
	{
		QMessageBox::information(this, GETDATA_TIP, "数据获取失败: " + QString::number(ret));
	}
}

QGroupBox* PatrolDataView::CreateTaskFinishInfoByTimeGroupBox()
{
	taskFinishInfoByTimeGroupBox = new QGroupBox("任务列表信息");
	QVBoxLayout* taskFinishInfoByTimeLayout = new QVBoxLayout;

	QHBoxLayout* tempLayout = new QHBoxLayout;
	taskFinishInfoByTimeBtn = new QPushButton("获取任务列表信息");
	QLabel* startTimeLabel = new QLabel("开始时间");
	startTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime());
	startTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
	startTimeEdit->setCalendarPopup(true);  // 日历弹出

	QLabel* endTimeLabel = new QLabel("结束时间");
	endTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime());
	endTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
	endTimeEdit->setCalendarPopup(true);  // 日历弹出

	tempLayout->addWidget(startTimeLabel);
	tempLayout->addWidget(startTimeEdit);
	tempLayout->addWidget(endTimeLabel);
	tempLayout->addWidget(endTimeEdit);
	tempLayout->addWidget(taskFinishInfoByTimeBtn);
	
	taskFinishInfoByTimeTable = new QTableWidget;
	taskFinishInfoByTimeTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	taskFinishInfoByTimeTable->setColumnCount(9);
	QStringList headers;
	headers << "任务ID" << "任务名称" << "任务类型" << "任务模板Id" <<
		"完成巡检点位列表" << "开始时间" << "结束时间" << "任务状态" << "机器人IP";
	taskFinishInfoByTimeTable->setHorizontalHeaderLabels(headers);

	taskFinishInfoByTimeLayout->addLayout(tempLayout);
	taskFinishInfoByTimeLayout->addWidget(taskFinishInfoByTimeTable);
	taskFinishInfoByTimeGroupBox->setLayout(taskFinishInfoByTimeLayout);
	return taskFinishInfoByTimeGroupBox;
	

}

QGroupBox* PatrolDataView::CreateTaskExcuteInfoByTaskIdGroupBox()
{
	taskExcuteInfoByTaskIdGroupBox = new QGroupBox("完成任务数据信息");
	taskExcuteInfoByTaskIdBtn = new QPushButton("获取完成任务数据信息");

	QVBoxLayout* taskExcuteInfoByTaskIdLayout = new QVBoxLayout;

	taskIdEdit = new QLineEdit;
	QLabel* label = new QLabel("请输入任务ID：");
	QHBoxLayout* tempLayout = new QHBoxLayout;
	tempLayout->addWidget(label);
	tempLayout->addWidget(taskIdEdit);
	tempLayout->addWidget(taskExcuteInfoByTaskIdBtn);

	taskExcuteInfoByTaskIdTable = new QTableWidget;
	taskExcuteInfoByTaskIdTable->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
	taskExcuteInfoByTaskIdTable->setColumnCount(14);
	QStringList headers;
	headers << "任务ID" << "任务名称" << "任务类型" << "任务模板Id" <<
		"巡检结果id" << "巡检点位id" << "巡检点位名称" << "巡检点位类型" << "执行时间" << "执行结果值"
		<< "执行结果状态" << "执行结果描述" << "高清图片" << "红外图片";
	taskExcuteInfoByTaskIdTable->setHorizontalHeaderLabels(headers);

	taskExcuteInfoByTaskIdLayout->addLayout(tempLayout);
	taskExcuteInfoByTaskIdLayout->addWidget(taskExcuteInfoByTaskIdTable);
	taskExcuteInfoByTaskIdGroupBox->setLayout(taskExcuteInfoByTaskIdLayout);
	return taskExcuteInfoByTaskIdGroupBox;
}

PatrolDataView::~PatrolDataView()
{
}
