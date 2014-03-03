/********************************************************************************
** Form generated from reading UI file 'awesome.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AWESOME_H
#define UI_AWESOME_H

#include <MyLCD.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AwesomeClass
{
public:
    QWidget *centralWidget;
    MyLCD *lcdNumber;
    MyLCD *lcdNumber_2;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AwesomeClass)
    {
        if (AwesomeClass->objectName().isEmpty())
            AwesomeClass->setObjectName(QStringLiteral("AwesomeClass"));
        AwesomeClass->resize(600, 400);
        centralWidget = new QWidget(AwesomeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber = new MyLCD(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(160, 50, 111, 61));
        lcdNumber_2 = new MyLCD(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(290, 50, 111, 61));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(210, 160, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 210, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 290, 75, 23));
        AwesomeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AwesomeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        AwesomeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AwesomeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AwesomeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AwesomeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AwesomeClass->setStatusBar(statusBar);

        retranslateUi(AwesomeClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), AwesomeClass, SLOT(close()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(lcdNumber_2, SIGNAL(pass()), lcdNumber, SLOT(increment()));
        QObject::connect(lcdNumber_2, SIGNAL(override(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), lcdNumber_2, SLOT(increment10()));

        QMetaObject::connectSlotsByName(AwesomeClass);
    } // setupUi

    void retranslateUi(QMainWindow *AwesomeClass)
    {
        AwesomeClass->setWindowTitle(QApplication::translate("AwesomeClass", "Awesome", 0));
        pushButton->setText(QApplication::translate("AwesomeClass", "Add 10", 0));
        pushButton_2->setText(QApplication::translate("AwesomeClass", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class AwesomeClass: public Ui_AwesomeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AWESOME_H
