/********************************************************************************
** Form generated from reading UI file 'shaders.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHADERS_H
#define UI_SHADERS_H

#include <MyButton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <myglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_ShadersClass
{
public:
    QWidget *centralWidget;
    MyGLWidget *widget;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *horizontalSlider;
    MyButton *textEdit;
    QPushButton *pushButton;
    QLabel *label_4;
    QSlider *horizontalSlider_3;
    QDial *dial;
    QLabel *label_5;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_10;
    QPushButton *pushButton_7;

    void setupUi(QMainWindow *ShadersClass)
    {
        if (ShadersClass->objectName().isEmpty())
            ShadersClass->setObjectName(QStringLiteral("ShadersClass"));
        ShadersClass->resize(971, 570);
        centralWidget = new QWidget(ShadersClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 751, 551));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(820, 50, 91, 16));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(820, 160, 91, 16));
        label_3->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(790, 80, 151, 16));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(89);
        horizontalSlider->setValue(45);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        textEdit = new MyButton(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(790, 510, 151, 21));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(790, 540, 151, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(830, 100, 71, 16));
        label_4->setAlignment(Qt::AlignCenter);
        horizontalSlider_3 = new QSlider(centralWidget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(790, 130, 151, 16));
        horizontalSlider_3->setMinimum(1);
        horizontalSlider_3->setMaximum(40);
        horizontalSlider_3->setValue(15);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setTickPosition(QSlider::NoTicks);
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(810, 180, 111, 121));
        dial->setMaximum(360);
        dial->setPageStep(1);
        dial->setTracking(true);
        dial->setInvertedAppearance(true);
        dial->setWrapping(true);
        dial->setNotchesVisible(false);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(790, 10, 151, 21));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(770, 300, 191, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(770, 450, 191, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(820, 470, 91, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(770, 320, 191, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(810, 360, 21, 21));
        label_8->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(840, 360, 31, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(880, 360, 31, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(880, 390, 31, 23));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(810, 390, 21, 21));
        label_9->setAlignment(Qt::AlignCenter);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(840, 390, 31, 23));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(880, 420, 31, 23));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(810, 420, 21, 21));
        label_10->setAlignment(Qt::AlignCenter);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(840, 420, 31, 23));
        ShadersClass->setCentralWidget(centralWidget);

        retranslateUi(ShadersClass);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), widget, SLOT(rUD(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), widget, SLOT(zoom(int)));
        QObject::connect(pushButton, SIGNAL(pressed()), textEdit, SLOT(loadFile()));
        QObject::connect(textEdit, SIGNAL(file(string)), widget, SLOT(updateFile(string)));
        QObject::connect(dial, SIGNAL(valueChanged(int)), widget, SLOT(rLR(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(lXUp()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), widget, SLOT(lXDown()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), widget, SLOT(lYUp()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), widget, SLOT(lYDown()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), widget, SLOT(lZUp()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), widget, SLOT(lZDown()));

        QMetaObject::connectSlotsByName(ShadersClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShadersClass)
    {
        ShadersClass->setWindowTitle(QApplication::translate("ShadersClass", "Shaders", 0));
        label_2->setText(QApplication::translate("ShadersClass", "Rotate up/down:", 0));
        label_3->setText(QApplication::translate("ShadersClass", "Rotate left/right:", 0));
        textEdit->setHtml(QApplication::translate("ShadersClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0));
        pushButton->setText(QApplication::translate("ShadersClass", "Load", 0));
        label_4->setText(QApplication::translate("ShadersClass", "Zoom:", 0));
        label_5->setText(QApplication::translate("ShadersClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Move the camera</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("ShadersClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Load a file</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("ShadersClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Move the light source</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("ShadersClass", "X:", 0));
        pushButton_2->setText(QApplication::translate("ShadersClass", "+", 0));
        pushButton_3->setText(QApplication::translate("ShadersClass", "-", 0));
        pushButton_4->setText(QApplication::translate("ShadersClass", "-", 0));
        label_9->setText(QApplication::translate("ShadersClass", "Y:", 0));
        pushButton_5->setText(QApplication::translate("ShadersClass", "+", 0));
        pushButton_6->setText(QApplication::translate("ShadersClass", "-", 0));
        label_10->setText(QApplication::translate("ShadersClass", "Z:", 0));
        pushButton_7->setText(QApplication::translate("ShadersClass", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class ShadersClass: public Ui_ShadersClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHADERS_H
