/********************************************************************************
** Form generated from reading UI file 'custom.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOM_H
#define UI_CUSTOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CustomClass
{
public:
    QWidget *centralWidget;
    QCustomPlot *widget;
    QPushButton *paint;
    QComboBox *comboBox_1;
    QComboBox *comboBox_2;
    QPushButton *exp;
    QPushButton *exit;
    QPushButton *animation;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CustomClass)
    {
        if (CustomClass->objectName().isEmpty())
            CustomClass->setObjectName(QStringLiteral("CustomClass"));
        CustomClass->resize(621, 335);
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/\320\220\320\273\320\265\320\275\320\260/Desktop/Documents.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CustomClass->setWindowIcon(icon);
        centralWidget = new QWidget(CustomClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(163, 10, 451, 271));
        paint = new QPushButton(centralWidget);
        paint->setObjectName(QStringLiteral("paint"));
        paint->setGeometry(QRect(10, 110, 131, 23));
        comboBox_1 = new QComboBox(centralWidget);
        comboBox_1->setObjectName(QStringLiteral("comboBox_1"));
        comboBox_1->setGeometry(QRect(10, 30, 131, 22));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 80, 131, 22));
        exp = new QPushButton(centralWidget);
        exp->setObjectName(QStringLiteral("exp"));
        exp->setGeometry(QRect(10, 150, 131, 23));
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(10, 260, 131, 23));
        animation = new QPushButton(centralWidget);
        animation->setObjectName(QStringLiteral("animation"));
        animation->setGeometry(QRect(10, 220, 131, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 183, 61, 21));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(100, 190, 42, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 195, 61, 21));
        CustomClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CustomClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 621, 21));
        CustomClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CustomClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CustomClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CustomClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CustomClass->setStatusBar(statusBar);

        retranslateUi(CustomClass);

        QMetaObject::connectSlotsByName(CustomClass);
    } // setupUi

    void retranslateUi(QMainWindow *CustomClass)
    {
        CustomClass->setWindowTitle(QApplication::translate("CustomClass", "Custom", 0));
        paint->setText(QApplication::translate("CustomClass", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\260", 0));
        exp->setText(QApplication::translate("CustomClass", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", 0));
        exit->setText(QApplication::translate("CustomClass", "\320\222\321\213\321\205\320\276\320\264", 0));
        animation->setText(QApplication::translate("CustomClass", "\320\220\320\275\320\270\320\274\320\260\321\206\320\270\321\217", 0));
        label->setText(QApplication::translate("CustomClass", "\320\236\321\201\321\214 \320\236\321\205:", 0));
        label_2->setText(QApplication::translate("CustomClass", "\320\236\321\201\321\214 \320\236\321\203:", 0));
        label_3->setText(QApplication::translate("CustomClass", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0));
        label_4->setText(QApplication::translate("CustomClass", "\320\260\320\275\320\270\320\274\320\260\321\206\320\270\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class CustomClass: public Ui_CustomClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOM_H
