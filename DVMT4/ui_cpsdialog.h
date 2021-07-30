/********************************************************************************
** Form generated from reading UI file 'cpsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPSDIALOG_H
#define UI_CPSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CPSDialog
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *cancel;
    QPushButton *enter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *lcb;
    QLabel *label_2;
    QComboBox *P1;
    QComboBox *P2;

    void setupUi(QDialog *CPSDialog)
    {
        if (CPSDialog->objectName().isEmpty())
            CPSDialog->setObjectName(QString::fromUtf8("CPSDialog"));
        CPSDialog->resize(593, 198);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CPSDialog->setWindowIcon(icon);
        CPSDialog->setStyleSheet(QString::fromUtf8("\n"
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
        gridLayout_2 = new QGridLayout(CPSDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cancel = new QPushButton(CPSDialog);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setAutoDefault(false);

        gridLayout_2->addWidget(cancel, 1, 0, 1, 1);

        enter = new QPushButton(CPSDialog);
        enter->setObjectName(QString::fromUtf8("enter"));
        enter->setEnabled(true);

        gridLayout_2->addWidget(enter, 1, 1, 1, 1);

        groupBox = new QGroupBox(CPSDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lcb = new QComboBox(groupBox);
        lcb->setObjectName(QString::fromUtf8("lcb"));

        gridLayout->addWidget(lcb, 0, 1, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        P1 = new QComboBox(groupBox);
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->setObjectName(QString::fromUtf8("P1"));

        gridLayout->addWidget(P1, 1, 1, 1, 1);

        P2 = new QComboBox(groupBox);
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->setObjectName(QString::fromUtf8("P2"));

        gridLayout->addWidget(P2, 1, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 2);


        retranslateUi(CPSDialog);

        enter->setDefault(true);
        P2->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(CPSDialog);
    } // setupUi

    void retranslateUi(QDialog *CPSDialog)
    {
        CPSDialog->setWindowTitle(QCoreApplication::translate("CPSDialog", "\345\244\215\345\210\266\346\240\207\350\256\260\350\207\263", nullptr));
        cancel->setText(QCoreApplication::translate("CPSDialog", "\345\217\226\346\266\210", nullptr));
        enter->setText(QCoreApplication::translate("CPSDialog", "\347\241\256\345\256\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CPSDialog", "\345\244\215\345\210\266\346\240\207\350\256\260", nullptr));
        label->setText(QCoreApplication::translate("CPSDialog", "\345\244\215\345\210\266\347\233\256\346\240\207", nullptr));
        label_2->setText(QCoreApplication::translate("CPSDialog", "\347\233\256\346\240\207\351\237\263\351\230\266", nullptr));
        P1->setItemText(0, QCoreApplication::translate("CPSDialog", "C", nullptr));
        P1->setItemText(1, QCoreApplication::translate("CPSDialog", "C#", nullptr));
        P1->setItemText(2, QCoreApplication::translate("CPSDialog", "D", nullptr));
        P1->setItemText(3, QCoreApplication::translate("CPSDialog", "D#", nullptr));
        P1->setItemText(4, QCoreApplication::translate("CPSDialog", "E", nullptr));
        P1->setItemText(5, QCoreApplication::translate("CPSDialog", "F", nullptr));
        P1->setItemText(6, QCoreApplication::translate("CPSDialog", "F#", nullptr));
        P1->setItemText(7, QCoreApplication::translate("CPSDialog", "G", nullptr));
        P1->setItemText(8, QCoreApplication::translate("CPSDialog", "G#", nullptr));
        P1->setItemText(9, QCoreApplication::translate("CPSDialog", "A", nullptr));
        P1->setItemText(10, QCoreApplication::translate("CPSDialog", "A#", nullptr));
        P1->setItemText(11, QCoreApplication::translate("CPSDialog", "B", nullptr));

        P2->setItemText(0, QCoreApplication::translate("CPSDialog", "0", nullptr));
        P2->setItemText(1, QCoreApplication::translate("CPSDialog", "1", nullptr));
        P2->setItemText(2, QCoreApplication::translate("CPSDialog", "2", nullptr));
        P2->setItemText(3, QCoreApplication::translate("CPSDialog", "3", nullptr));
        P2->setItemText(4, QCoreApplication::translate("CPSDialog", "4", nullptr));
        P2->setItemText(5, QCoreApplication::translate("CPSDialog", "5", nullptr));
        P2->setItemText(6, QCoreApplication::translate("CPSDialog", "6", nullptr));
        P2->setItemText(7, QCoreApplication::translate("CPSDialog", "7", nullptr));
        P2->setItemText(8, QCoreApplication::translate("CPSDialog", "8", nullptr));
        P2->setItemText(9, QCoreApplication::translate("CPSDialog", "9", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CPSDialog: public Ui_CPSDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPSDIALOG_H
