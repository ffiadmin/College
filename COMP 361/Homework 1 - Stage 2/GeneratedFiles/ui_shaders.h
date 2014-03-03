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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <myglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_ShadersClass
{
public:
    QWidget *centralWidget;
    MyGLWidget *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ShadersClass)
    {
        if (ShadersClass->objectName().isEmpty())
            ShadersClass->setObjectName(QStringLiteral("ShadersClass"));
        ShadersClass->resize(600, 483);
        centralWidget = new QWidget(ShadersClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 571, 411));
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

        QMetaObject::connectSlotsByName(ShadersClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShadersClass)
    {
        ShadersClass->setWindowTitle(QApplication::translate("ShadersClass", "Shaders", 0));
    } // retranslateUi

};

namespace Ui {
    class ShadersClass: public Ui_ShadersClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHADERS_H
