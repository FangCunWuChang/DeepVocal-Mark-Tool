/********************************************************************************
** Form generated from reading UI file 'ctool.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTOOL_H
#define UI_CTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTool
{
public:
    QPushButton *wavname;

    void setupUi(QWidget *CTool)
    {
        if (CTool->objectName().isEmpty())
            CTool->setObjectName(QString::fromUtf8("CTool"));
        CTool->resize(858, 61);
        CTool->setMouseTracking(true);
        CTool->setTabletTracking(true);
        wavname = new QPushButton(CTool);
        wavname->setObjectName(QString::fromUtf8("wavname"));
        wavname->setGeometry(QRect(490, 10, 161, 31));
        wavname->setStyleSheet(QString::fromUtf8("background-color: rgba(31,31,31,0);\n"
"color: rgb(255, 255, 255);\n"
"border: none;"));

        retranslateUi(CTool);

        QMetaObject::connectSlotsByName(CTool);
    } // setupUi

    void retranslateUi(QWidget *CTool)
    {
        CTool->setWindowTitle(QCoreApplication::translate("CTool", "Form", nullptr));
        wavname->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CTool: public Ui_CTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTOOL_H
