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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <center.h>
#include <title.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centeral;
    Center *cen;
    Title *title;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMouseTracking(true);
        MainWindow->setTabletTracking(true);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QToolTip{\n"
"\n"
"background-color:rgb(31,31,31);\n"
"color: rgb(211, 215, 207);\n"
"border:1px solid rgb(31,31,31);\n"
"}\n"
"QWidget{\n"
"	background-color: rgb(31,31,31);\n"
"}\n"
""));
        centeral = new QWidget(MainWindow);
        centeral->setObjectName(QString::fromUtf8("centeral"));
        cen = new Center(centeral);
        cen->setObjectName(QString::fromUtf8("cen"));
        cen->setGeometry(QRect(270, 340, 120, 80));
        title = new Title(centeral);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(330, 120, 120, 80));
        MainWindow->setCentralWidget(centeral);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "DeepVocal Mark Tool - \346\234\252\345\221\275\345\220\215\351\241\271\347\233\256.dvmtp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
