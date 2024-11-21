/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "profileswidget.h"
#include "radotechwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *measure;
    ProfilesWidget *profiles;
    QWidget *history;
    RadotechWidget *radotech;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 700);
        MainWindow->setMinimumSize(QSize(1200, 700));
        MainWindow->setMaximumSize(QSize(1200, 700));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: gray;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 450, 700));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab:selected {background-color: blue; color: white;}"));
        tabWidget->setTabsClosable(false);
        measure = new QWidget();
        measure->setObjectName(QString::fromUtf8("measure"));
        measure->setStyleSheet(QString::fromUtf8("background-color: black;"));
        tabWidget->addTab(measure, QString());
        profiles = new ProfilesWidget();
        profiles->setObjectName(QString::fromUtf8("profiles"));
        tabWidget->addTab(profiles, QString());
        history = new QWidget();
        history->setObjectName(QString::fromUtf8("history"));
        tabWidget->addTab(history, QString());
        radotech = new RadotechWidget(centralwidget);
        radotech->setObjectName(QString::fromUtf8("radotech"));
        radotech->setGeometry(QRect(450, 0, 800, 700));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(measure), QCoreApplication::translate("MainWindow", "Measure", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(profiles), QCoreApplication::translate("MainWindow", "Profiles", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(history), QCoreApplication::translate("MainWindow", "History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
