/********************************************************************************
** Form generated from reading UI file 'as.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AS_H
#define UI_AS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AS
{
public:
    QPushButton *ene;
    QPushButton *cle;
    QPushButton *rptz;
    QPushButton *rea;

    void setupUi(QWidget *AS)
    {
        if (AS->objectName().isEmpty())
            AS->setObjectName(QString::fromUtf8("AS"));
        AS->resize(400, 300);
        AS->setStyleSheet(QString::fromUtf8("QToolTip{\n"
"\n"
"background-color:rgb(31,31,31);\n"
"color: rgb(255,255,255);\n"
"border:none;\n"
"}\n"
"\n"
"QWidget{\n"
"	background-color: rgb(31,31,31);\n"
"}"));
        ene = new QPushButton(AS);
        ene->setObjectName(QString::fromUtf8("ene"));
        ene->setEnabled(true);
        ene->setGeometry(QRect(90, 20, 171, 25));
        ene->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgba(31,31,31,0);\n"
"	border: none;\n"
"}\n"
"QPushButton:disabled{\n"
"	color:rgba(255,255,255,150);\n"
"	background-color: rgba(255,255,255,100);\n"
"	border: none;\n"
"}\n"
"QPushButton:pressed{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(31,31,31);\n"
"	border: none;\n"
"}\n"
"QPushButton:hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgba(119,119,119,150);\n"
"	border: none;\n"
"}"));
        ene->setCheckable(true);
        ene->setChecked(true);
        cle = new QPushButton(AS);
        cle->setObjectName(QString::fromUtf8("cle"));
        cle->setEnabled(false);
        cle->setGeometry(QRect(80, 140, 171, 25));
        cle->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(31,31,31);\n"
"	border: none;\n"
"}\n"
"QPushButton:disabled{\n"
"	color:rgba(255,255,255,150);\n"
"	background-color: rgba(255,255,255,100);\n"
"	border: none;\n"
"}\n"
"QPushButton:pressed{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(31,31,31);\n"
"	border: none;\n"
"}\n"
"QPushButton:hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgba(119,119,119,150);\n"
"	border: none;\n"
"}"));
        rptz = new QPushButton(AS);
        rptz->setObjectName(QString::fromUtf8("rptz"));
        rptz->setGeometry(QRect(100, 60, 171, 25));
        rptz->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgba(31,31,31,0);\n"
"	border: none;\n"
"}\n"
"QPushButton:disabled{\n"
"	color:rgba(255,255,255,150);\n"
"	background-color: rgba(255,255,255,100);\n"
"	border: none;\n"
"}\n"
"QPushButton:pressed{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(31,31,31);\n"
"	border: none;\n"
"}\n"
"QPushButton:hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgba(119,119,119,150);\n"
"	border: none;\n"
"}"));
        rptz->setCheckable(true);
        rptz->setChecked(true);
        rea = new QPushButton(AS);
        rea->setObjectName(QString::fromUtf8("rea"));
        rea->setEnabled(false);
        rea->setGeometry(QRect(90, 100, 171, 25));
        rea->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(31,31,31);\n"
"	border: none;\n"
"}\n"
"QPushButton:disabled{\n"
"	color:rgba(255,255,255,150);\n"
"	background-color: rgba(255,255,255,100);\n"
"	border: none;\n"
"}\n"
"QPushButton:pressed{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgb(31,31,31);\n"
"	border: none;\n"
"}\n"
"QPushButton:hover{\n"
"	color:rgb(255,255,255);\n"
"	background-color: rgba(119,119,119,150);\n"
"	border: none;\n"
"}"));

        retranslateUi(AS);

        QMetaObject::connectSlotsByName(AS);
    } // setupUi

    void retranslateUi(QWidget *AS)
    {
        AS->setWindowTitle(QCoreApplication::translate("AS", "Form", nullptr));
#if QT_CONFIG(tooltip)
        ene->setToolTip(QCoreApplication::translate("AS", "Alt+E", nullptr));
#endif // QT_CONFIG(tooltip)
        ene->setText(QCoreApplication::translate("AS", "\347\237\255\346\227\266\350\203\275\351\207\217(E)", nullptr));
#if QT_CONFIG(shortcut)
        ene->setShortcut(QCoreApplication::translate("AS", "Alt+E", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        cle->setToolTip(QCoreApplication::translate("AS", "Alt+C", nullptr));
#endif // QT_CONFIG(tooltip)
        cle->setText(QCoreApplication::translate("AS", "\346\270\205\347\251\272\347\274\223\345\255\230(C)", nullptr));
#if QT_CONFIG(shortcut)
        cle->setShortcut(QCoreApplication::translate("AS", "Alt+C", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        rptz->setToolTip(QCoreApplication::translate("AS", "Alt+P", nullptr));
#endif // QT_CONFIG(tooltip)
        rptz->setText(QCoreApplication::translate("AS", "\347\237\255\346\227\266\350\277\207\351\233\266\347\216\207(P)", nullptr));
#if QT_CONFIG(shortcut)
        rptz->setShortcut(QCoreApplication::translate("AS", "Alt+P", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        rea->setToolTip(QCoreApplication::translate("AS", "Alt+R", nullptr));
#endif // QT_CONFIG(tooltip)
        rea->setText(QCoreApplication::translate("AS", "\351\207\215\346\226\260\345\210\206\346\236\220(R)", nullptr));
#if QT_CONFIG(shortcut)
        rea->setShortcut(QCoreApplication::translate("AS", "Alt+R", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class AS: public Ui_AS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AS_H
