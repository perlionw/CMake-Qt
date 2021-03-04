/********************************************************************************
** Form generated from reading UI file 'stationrobottool.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONROBOTTOOL_H
#define UI_STATIONROBOTTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StationRobotToolClass
{
public:

    void setupUi(QWidget *StationRobotToolClass)
    {
        if (StationRobotToolClass->objectName().isEmpty())
            StationRobotToolClass->setObjectName(QStringLiteral("StationRobotToolClass"));
        StationRobotToolClass->resize(600, 400);

        retranslateUi(StationRobotToolClass);

        QMetaObject::connectSlotsByName(StationRobotToolClass);
    } // setupUi

    void retranslateUi(QWidget *StationRobotToolClass)
    {
        StationRobotToolClass->setWindowTitle(QApplication::translate("StationRobotToolClass", "StationRobotTool", 0));
    } // retranslateUi

};

namespace Ui {
    class StationRobotToolClass: public Ui_StationRobotToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONROBOTTOOL_H
