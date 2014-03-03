/********************************************************************************
** Form generated from reading UI file 'shaders.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    MyButton *textEdit;
    QPushButton *pushButton;
    QLabel *label_4;
    QSlider *horizontalSlider_3;

    void setupUi(QMainWindow *ShadersClass)
    {
        if (ShadersClass->objectName().isEmpty())
            ShadersClass->setObjectName(QStringLiteral("ShadersClass"));
        ShadersClass->resize(600, 600);
        centralWidget = new QWidget(ShadersClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 571, 411));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 440, 91, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 470, 91, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 500, 91, 16));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(110, 470, 160, 16));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(80);
        horizontalSlider->setValue(80);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(true);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(110, 500, 160, 16));
        horizontalSlider_2->setMinimum(-180);
        horizontalSlider_2->setMaximum(180);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        textEdit = new MyButton(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(110, 440, 201, 21));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 440, 75, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 530, 91, 16));
        horizontalSlider_3 = new QSlider(centralWidget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(110, 530, 160, 16));
        horizontalSlider_3->setMinimum(10);
        horizontalSlider_3->setMaximum(20);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setTickPosition(QSlider::NoTicks);
        ShadersClass->setCentralWidget(centralWidget);

        retranslateUi(ShadersClass);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), widget, SLOT(rUD(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), widget, SLOT(rLR(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), widget, SLOT(zoom(int)));
        QObject::connect(pushButton, SIGNAL(pressed()), textEdit, SLOT(loadFile()));
        QObject::connect(textEdit, SIGNAL(file(string)), widget, SLOT(updateFile(string)));

        QMetaObject::connectSlotsByName(ShadersClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShadersClass)
    {
        ShadersClass->setWindowTitle(QApplication::translate("ShadersClass", "Shaders", 0));
        label->setText(QApplication::translate("ShadersClass", "Configuration file:", 0));
        label_2->setText(QApplication::translate("ShadersClass", "Rotate up/down:", 0));
        label_3->setText(QApplication::translate("ShadersClass", "Rotate left/right:", 0));
        textEdit->setHtml(QApplication::translate("ShadersClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0));
        pushButton->setText(QApplication::translate("ShadersClass", "Load", 0));
        label_4->setText(QApplication::translate("ShadersClass", "Zoom:", 0));
    } // retranslateUi

};

namespace Ui {
    class ShadersClass: public Ui_ShadersClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHADERS_H
