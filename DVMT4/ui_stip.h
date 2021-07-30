/********************************************************************************
** Form generated from reading UI file 'stip.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STIP_H
#define UI_STIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_STip
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *num;

    void setupUi(QWidget *STip)
    {
        if (STip->objectName().isEmpty())
            STip->setObjectName(QString::fromUtf8("STip"));
        STip->resize(211, 93);
        STip->setStyleSheet(QString::fromUtf8("color: rgb(214,236,240);\n"
"background-color: rgb(31,31,31);"));
        verticalLayout = new QVBoxLayout(STip);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(STip);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        num = new QProgressBar(STip);
        num->setObjectName(QString::fromUtf8("num"));
        num->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"	background-color: rgb(31,31,31);\n"
"	color: rgb(214,236,240);\n"
"	border:none;\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"	background-color: #1bd1a5;\n"
"}"));
        num->setValue(24);
        num->setAlignment(Qt::AlignCenter);
        num->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(num);


        retranslateUi(STip);

        QMetaObject::connectSlotsByName(STip);
    } // setupUi

    void retranslateUi(QWidget *STip)
    {
        STip->setWindowTitle(QCoreApplication::translate("STip", "Form", nullptr));
        label->setText(QCoreApplication::translate("STip", "\347\274\223\345\255\230\344\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class STip: public Ui_STip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STIP_H
