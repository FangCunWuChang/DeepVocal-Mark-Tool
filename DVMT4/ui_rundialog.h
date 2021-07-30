/********************************************************************************
** Form generated from reading UI file 'rundialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNDIALOG_H
#define UI_RUNDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RunDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *num;

    void setupUi(QDialog *RunDialog)
    {
        if (RunDialog->objectName().isEmpty())
            RunDialog->setObjectName(QString::fromUtf8("RunDialog"));
        RunDialog->resize(292, 114);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        RunDialog->setWindowIcon(icon);
        RunDialog->setStyleSheet(QString::fromUtf8("\n"
"QWidget{\n"
"background-color: rgb(31,31,31);\n"
"	color: rgb(211, 215, 207);\n"
"}\n"
"QToolTip{\n"
"\n"
"background-color:rgb(31,31,31);\n"
"color: rgb(211, 215, 207);\n"
"border:1px solid rgb(31,31,31);\n"
"}"));
        verticalLayout = new QVBoxLayout(RunDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(RunDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        num = new QProgressBar(RunDialog);
        num->setObjectName(QString::fromUtf8("num"));
        num->setStyleSheet(QString::fromUtf8("background-color: rgb(31,31,31);\n"
"color: rgb(211, 215, 207);\n"
"border:none;"));
        num->setValue(24);
        num->setAlignment(Qt::AlignCenter);
        num->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(num);


        retranslateUi(RunDialog);

        QMetaObject::connectSlotsByName(RunDialog);
    } // setupUi

    void retranslateUi(QDialog *RunDialog)
    {
        RunDialog->setWindowTitle(QCoreApplication::translate("RunDialog", "\346\223\215\344\275\234\344\270\255", nullptr));
        label->setText(QCoreApplication::translate("RunDialog", "\347\274\223\345\255\230\344\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RunDialog: public Ui_RunDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNDIALOG_H
