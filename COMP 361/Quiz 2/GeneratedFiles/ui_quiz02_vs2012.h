/********************************************************************************
** Form generated from reading UI file 'quiz02_vs2012.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZ02_VS2012_H
#define UI_QUIZ02_VS2012_H

#include <FilenameLine.h>
#include <MyGLWidget.h>
#include <PlanarLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Quiz02_VS2012Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    FilenameLine *lineEdit;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    MyGLWidget *widget;
    QPushButton *pushButton_3;
    PlanarLabel *label;

    void setupUi(QMainWindow *Quiz02_VS2012Class)
    {
        if (Quiz02_VS2012Class->objectName().isEmpty())
            Quiz02_VS2012Class->setObjectName(QStringLiteral("Quiz02_VS2012Class"));
        Quiz02_VS2012Class->resize(991, 622);
        centralWidget = new QWidget(Quiz02_VS2012Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(850, 110, 41, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(890, 60, 46, 13));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(890, 140, 51, 21));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(850, 180, 51, 21));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(930, 180, 51, 21));
        lineEdit = new FilenameLine(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(850, 220, 131, 20));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(850, 250, 131, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(940, 110, 41, 23));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 9, 831, 601));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(890, 80, 51, 23));
        label = new PlanarLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(850, 390, 131, 41));
        QFont font;
        font.setFamily(QStringLiteral("Old English Text MT"));
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setLineWidth(1);
        label->setAlignment(Qt::AlignCenter);
        Quiz02_VS2012Class->setCentralWidget(centralWidget);

        retranslateUi(Quiz02_VS2012Class);
        QObject::connect(pushButton_7, SIGNAL(clicked()), lineEdit, SLOT(signalFile()));
        QObject::connect(lineEdit, SIGNAL(sendContent(QString)), widget, SLOT(loadFile(QString)));
        QObject::connect(pushButton_3, SIGNAL(clicked()), widget, SLOT(orbitUp()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), widget, SLOT(orbitDown()));
        QObject::connect(pushButton, SIGNAL(clicked()), widget, SLOT(orbitLeft()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(orbitRight()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), widget, SLOT(zoomIn()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), widget, SLOT(zoomOut()));
        QObject::connect(widget, SIGNAL(sendPlanarity(bool)), label, SLOT(setBool(bool)));

        QMetaObject::connectSlotsByName(Quiz02_VS2012Class);
    } // setupUi

    void retranslateUi(QMainWindow *Quiz02_VS2012Class)
    {
        Quiz02_VS2012Class->setWindowTitle(QApplication::translate("Quiz02_VS2012Class", "Quiz02_VS2012", 0));
        pushButton->setText(QApplication::translate("Quiz02_VS2012Class", "Left", 0));
        label_2->setText(QApplication::translate("Quiz02_VS2012Class", "Camera", 0));
        pushButton_4->setText(QApplication::translate("Quiz02_VS2012Class", "Down", 0));
        pushButton_5->setText(QApplication::translate("Quiz02_VS2012Class", "In", 0));
        pushButton_6->setText(QApplication::translate("Quiz02_VS2012Class", "Out", 0));
        pushButton_7->setText(QApplication::translate("Quiz02_VS2012Class", "Load Config", 0));
        pushButton_2->setText(QApplication::translate("Quiz02_VS2012Class", "Right", 0));
        pushButton_3->setText(QApplication::translate("Quiz02_VS2012Class", "Up", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Quiz02_VS2012Class: public Ui_Quiz02_VS2012Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZ02_VS2012_H
