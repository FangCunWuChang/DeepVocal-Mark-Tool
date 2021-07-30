/********************************************************************************
** Form generated from reading UI file 'cbm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBM_H
#define UI_CBM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CBM
{
public:
    QPushButton *sea;
    QPushButton *menu;
    QPushButton *aw;
    QPushButton *lhb;
    QLabel *sname;

    void setupUi(QWidget *CBM)
    {
        if (CBM->objectName().isEmpty())
            CBM->setObjectName(QString::fromUtf8("CBM"));
        CBM->resize(496, 387);
        CBM->setStyleSheet(QString::fromUtf8("background-color: rgb(61, 59, 79);"));
        sea = new QPushButton(CBM);
        sea->setObjectName(QString::fromUtf8("sea"));
        sea->setGeometry(QRect(30, 110, 89, 25));
        sea->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(214,236,240);\n"
"	background-color: rgb(84,150,136);\n"
"	border: 2px solid rgb(117,138,153);\n"
"	border-radius:7px;\n"
"}\n"
"QPushButton:disabled{\n"
"border:2px solid rgb(117,138,153);\n"
"background-color: rgb(31,31,31);\n"
"color:  rgb(100,100,100);\n"
"border-radius:7px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(117,138,153);\n"
"	background-color:  rgb(214,236,240);\n"
"	border: 2px solid rgb(214,236,240);\n"
"	border-radius:7px;\n"
"}"));
        menu = new QPushButton(CBM);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setEnabled(true);
        menu->setGeometry(QRect(20, 70, 89, 25));
        menu->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(214,236,240);\n"
"	background-color: rgb(84,150,136);\n"
"	border: 2px solid rgb(117,138,153);\n"
"	border-radius:7px;\n"
"}\n"
"QPushButton:disabled{\n"
"border:2px solid rgb(117,138,153);\n"
"background-color: rgb(31,31,31);\n"
"color:  rgb(100,100,100);\n"
"border-radius:7px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(117,138,153);\n"
"	background-color:  rgb(214,236,240);\n"
"	border: 2px solid rgb(214,236,240);\n"
"	border-radius:7px;\n"
"}"));
        aw = new QPushButton(CBM);
        aw->setObjectName(QString::fromUtf8("aw"));
        aw->setGeometry(QRect(30, 170, 89, 25));
        aw->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(214,236,240);\n"
"	background-color: rgb(84,150,136);\n"
"	border: 2px solid rgb(117,138,153);\n"
"	border-radius:7px;\n"
"}\n"
"QPushButton:disabled{\n"
"border:2px solid rgb(117,138,153);\n"
"background-color: rgb(31,31,31);\n"
"color:  rgb(100,100,100);\n"
"border-radius:7px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(117,138,153);\n"
"	background-color:  rgb(214,236,240);\n"
"	border: 2px solid rgb(214,236,240);\n"
"	border-radius:7px;\n"
"}"));
        lhb = new QPushButton(CBM);
        lhb->setObjectName(QString::fromUtf8("lhb"));
        lhb->setGeometry(QRect(150, 220, 89, 25));
        lhb->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(214,236,240);\n"
"	background-color: rgb(84,150,136);\n"
"	border: 2px solid rgb(117,138,153);\n"
"	border-radius:7px;\n"
"}\n"
"QPushButton:disabled{\n"
"border:2px solid rgb(117,138,153);\n"
"background-color: rgb(31,31,31);\n"
"color:  rgb(100,100,100);\n"
"border-radius:7px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(117,138,153);\n"
"	background-color:  rgb(214,236,240);\n"
"	border: 2px solid rgb(214,236,240);\n"
"	border-radius:7px;\n"
"}"));
        lhb->setCheckable(true);
        lhb->setChecked(true);
        sname = new QLabel(CBM);
        sname->setObjectName(QString::fromUtf8("sname"));
        sname->setGeometry(QRect(190, 60, 111, 21));
        sname->setStyleSheet(QString::fromUtf8("color:rgb(214, 236, 240);\n"
"background-color: rgba(255, 255, 255, 0);"));
        sname->setAlignment(Qt::AlignCenter);

        retranslateUi(CBM);

        QMetaObject::connectSlotsByName(CBM);
    } // setupUi

    void retranslateUi(QWidget *CBM)
    {
        CBM->setWindowTitle(QCoreApplication::translate("CBM", "Form", nullptr));
        sea->setText(QCoreApplication::translate("CBM", "\346\220\234\347\264\242", nullptr));
#if QT_CONFIG(tooltip)
        menu->setToolTip(QCoreApplication::translate("CBM", "Alt+M", nullptr));
#endif // QT_CONFIG(tooltip)
        menu->setText(QCoreApplication::translate("CBM", "\350\217\234\345\215\225(M)", nullptr));
#if QT_CONFIG(shortcut)
        menu->setShortcut(QCoreApplication::translate("CBM", "Alt+M", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        aw->setToolTip(QCoreApplication::translate("CBM", "Alt+Z", nullptr));
#endif // QT_CONFIG(tooltip)
        aw->setText(QCoreApplication::translate("CBM", "\351\242\204\346\265\213(Z)", nullptr));
#if QT_CONFIG(shortcut)
        aw->setShortcut(QCoreApplication::translate("CBM", "Alt+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        lhb->setText(QCoreApplication::translate("CBM", "\345\210\227\350\241\250", nullptr));
        sname->setText(QCoreApplication::translate("CBM", "\345\275\223\345\211\215\347\254\246\345\217\267\344\270\272\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CBM: public Ui_CBM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBM_H
