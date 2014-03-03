/********************************************************************************
** Form generated from reading UI file 'shaders.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHADERS_H
#define UI_SHADERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
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
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

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
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(110, 500, 160, 16));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(110, 440, 201, 21));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 440, 75, 23));
        ShadersClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ShadersClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        ShadersClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ShadersClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ShadersClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ShadersClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ShadersClass->setStatusBar(statusBar);

        retranslateUi(ShadersClass);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), widget, SLOT(rUD(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), widget, SLOT(rLR(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), widget, SLOT(updateFile()));

        QMetaObject::connectSlotsByName(ShadersClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShadersClass)
    {
        ShadersClass->setWindowTitle(QApplication::translate("ShadersClass", "Shaders", 0));
        label->setText(QApplication::translate("ShadersClass", "Configuration file:", 0));
        label_2->setText(QApplication::translate("ShadersClass", "Rotate up/down:", 0));
        label_3->setText(QApplication::translate("ShadersClass", "Rotate left/right:", 0));
        pushButton->setText(QApplication::translate("ShadersClass", "Load", 0));
    } // retranslateUi

};

namespace Ui {
    class ShadersClass: public Ui_ShadersClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHADERS_H
