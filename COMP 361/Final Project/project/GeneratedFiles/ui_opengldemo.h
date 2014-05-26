/********************************************************************************
** Form generated from reading UI file 'opengldemo.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLDEMO_H
#define UI_OPENGLDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "FileTextBox.h"
#include "MyGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OpenGLdemoClass
{
public:
    QWidget *centralWidget;
    MyGLWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    FileTextBox *lineEdit;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_2;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_20;
    QLabel *label_3;
    QPushButton *pushButton_19;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QLabel *label_4;
    QPushButton *pushButton_15;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OpenGLdemoClass)
    {
        if (OpenGLdemoClass->objectName().isEmpty())
            OpenGLdemoClass->setObjectName(QStringLiteral("OpenGLdemoClass"));
        OpenGLdemoClass->resize(765, 621);
        centralWidget = new QWidget(OpenGLdemoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 10, 561, 461));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(580, 480, 81, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 480, 81, 41));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 480, 81, 41));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(480, 480, 81, 41));
        lineEdit = new FileTextBox(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(290, 480, 181, 20));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(290, 500, 181, 23));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 100, 81, 81));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 10, 81, 81));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 300, 46, 13));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 320, 81, 23));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 410, 81, 23));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 350, 21, 51));
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(70, 350, 21, 51));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(40, 350, 21, 23));
        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(40, 380, 21, 23));
        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(670, 300, 81, 81));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(670, 20, 91, 16));
        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(670, 57, 25, 25));
        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(730, 57, 25, 25));
        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(700, 75, 25, 25));
        pushButton_20 = new QPushButton(centralWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(700, 40, 25, 25));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(680, 110, 91, 16));
        pushButton_19 = new QPushButton(centralWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(670, 140, 25, 25));
        pushButton_21 = new QPushButton(centralWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(670, 170, 25, 25));
        pushButton_22 = new QPushButton(centralWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(700, 140, 25, 25));
        pushButton_23 = new QPushButton(centralWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(730, 140, 25, 25));
        pushButton_24 = new QPushButton(centralWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setGeometry(QRect(700, 170, 25, 25));
        pushButton_25 = new QPushButton(centralWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setGeometry(QRect(730, 170, 25, 25));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(680, 200, 91, 16));
        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(680, 220, 25, 75));
        pushButton_26 = new QPushButton(centralWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setGeometry(QRect(720, 220, 25, 75));
        pushButton_27 = new QPushButton(centralWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setGeometry(QRect(290, 530, 181, 23));
        pushButton_28 = new QPushButton(centralWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setEnabled(true);
        pushButton_28->setGeometry(QRect(670, 390, 81, 81));
        OpenGLdemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OpenGLdemoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 765, 21));
        OpenGLdemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OpenGLdemoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OpenGLdemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OpenGLdemoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OpenGLdemoClass->setStatusBar(statusBar);

        retranslateUi(OpenGLdemoClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(left()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), widget, SLOT(up()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), widget, SLOT(down()));
        QObject::connect(pushButton, SIGNAL(clicked()), widget, SLOT(right()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), widget, SLOT(zoomIn()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), widget, SLOT(zoomOut()));
        QObject::connect(lineEdit, SIGNAL(sendFilename(string)), widget, SLOT(load(string)));
        QObject::connect(pushButton_5, SIGNAL(clicked()), lineEdit, SLOT(buttonInput()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), widget, SLOT(lightZMinus()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), widget, SLOT(lightXPlus()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), widget, SLOT(lightXMinus()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), widget, SLOT(lightUp()));
        QObject::connect(pushButton_13, SIGNAL(clicked()), widget, SLOT(lightDown()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), widget, SLOT(lightZPlus()));
        QObject::connect(pushButton_14, SIGNAL(clicked()), widget, SLOT(cycleObjects()));
        QObject::connect(pushButton_20, SIGNAL(clicked()), widget, SLOT(moveZPlus()));
        QObject::connect(pushButton_18, SIGNAL(clicked()), widget, SLOT(moveZMinus()));
        QObject::connect(pushButton_16, SIGNAL(clicked()), widget, SLOT(moveXMinus()));
        QObject::connect(pushButton_17, SIGNAL(clicked()), widget, SLOT(moveXPlus()));
        QObject::connect(pushButton_19, SIGNAL(clicked()), widget, SLOT(scaleXPlus()));
        QObject::connect(pushButton_21, SIGNAL(clicked()), widget, SLOT(scaleXMinus()));
        QObject::connect(pushButton_22, SIGNAL(clicked()), widget, SLOT(scaleYPlus()));
        QObject::connect(pushButton_24, SIGNAL(clicked()), widget, SLOT(scaleYMinus()));
        QObject::connect(pushButton_23, SIGNAL(clicked()), widget, SLOT(scaleZPlus()));
        QObject::connect(pushButton_25, SIGNAL(clicked()), widget, SLOT(scaleZMinus()));
        QObject::connect(pushButton_15, SIGNAL(clicked()), widget, SLOT(rotateMinus()));
        QObject::connect(pushButton_26, SIGNAL(clicked()), widget, SLOT(rotatePlus()));
        QObject::connect(pushButton_27, SIGNAL(clicked()), widget, SLOT(rayTrace()));

        QMetaObject::connectSlotsByName(OpenGLdemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenGLdemoClass)
    {
        OpenGLdemoClass->setWindowTitle(QApplication::translate("OpenGLdemoClass", "OpenGLdemo", 0));
        pushButton->setText(QApplication::translate("OpenGLdemoClass", "->", 0));
        pushButton_2->setText(QApplication::translate("OpenGLdemoClass", "<-", 0));
        pushButton_3->setText(QApplication::translate("OpenGLdemoClass", "Up", 0));
        pushButton_4->setText(QApplication::translate("OpenGLdemoClass", "Down", 0));
        lineEdit->setText(QApplication::translate("OpenGLdemoClass", "scene2.txt", 0));
        pushButton_5->setText(QApplication::translate("OpenGLdemoClass", "Load Config", 0));
        pushButton_7->setText(QApplication::translate("OpenGLdemoClass", "-", 0));
        pushButton_8->setText(QApplication::translate("OpenGLdemoClass", "+", 0));
        label->setText(QApplication::translate("OpenGLdemoClass", "Light", 0));
        pushButton_6->setText(QApplication::translate("OpenGLdemoClass", "-z", 0));
        pushButton_9->setText(QApplication::translate("OpenGLdemoClass", "+z", 0));
        pushButton_10->setText(QApplication::translate("OpenGLdemoClass", "-x", 0));
        pushButton_11->setText(QApplication::translate("OpenGLdemoClass", "+x", 0));
        pushButton_12->setText(QApplication::translate("OpenGLdemoClass", "+y", 0));
        pushButton_13->setText(QApplication::translate("OpenGLdemoClass", "-y", 0));
        pushButton_14->setText(QApplication::translate("OpenGLdemoClass", " Next Object", 0));
        label_2->setText(QApplication::translate("OpenGLdemoClass", "Object Movement", 0));
        pushButton_16->setText(QApplication::translate("OpenGLdemoClass", "-x", 0));
        pushButton_17->setText(QApplication::translate("OpenGLdemoClass", "+x", 0));
        pushButton_18->setText(QApplication::translate("OpenGLdemoClass", "-z", 0));
        pushButton_20->setText(QApplication::translate("OpenGLdemoClass", "+z", 0));
        label_3->setText(QApplication::translate("OpenGLdemoClass", "Object Scale", 0));
        pushButton_19->setText(QApplication::translate("OpenGLdemoClass", "+x", 0));
        pushButton_21->setText(QApplication::translate("OpenGLdemoClass", "-x", 0));
        pushButton_22->setText(QApplication::translate("OpenGLdemoClass", "+y", 0));
        pushButton_23->setText(QApplication::translate("OpenGLdemoClass", "+z", 0));
        pushButton_24->setText(QApplication::translate("OpenGLdemoClass", "-y", 0));
        pushButton_25->setText(QApplication::translate("OpenGLdemoClass", "-z", 0));
        label_4->setText(QApplication::translate("OpenGLdemoClass", "Object Rotation", 0));
        pushButton_15->setText(QApplication::translate("OpenGLdemoClass", "<-", 0));
        pushButton_26->setText(QApplication::translate("OpenGLdemoClass", "->", 0));
        pushButton_27->setText(QApplication::translate("OpenGLdemoClass", "Ray Trace", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_28->setToolTip(QApplication::translate("OpenGLdemoClass", "Sub-divide algorithm is in place, but unavailable for execution due to last minute complications.", 0));
#endif // QT_NO_TOOLTIP
        pushButton_28->setText(QApplication::translate("OpenGLdemoClass", "Sub Divide\n"
"(Hover for\n"
"tooltip)", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenGLdemoClass: public Ui_OpenGLdemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLDEMO_H
