/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QPushButton *newp;
    QPushButton *open;
    QPushButton *save;
    QPushButton *sets;
    QPushButton *read;
    QPushButton *about;
    QPushButton *push;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->setEnabled(true);
        Menu->resize(732, 553);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Menu->setWindowIcon(icon);
        Menu->setStyleSheet(QString::fromUtf8("QToolTip{\n"
"\n"
"background-color:rgb(31,31,31);\n"
"color: rgb(255,255,255);\n"
"border:none;\n"
"}\n"
"\n"
"QWidget{\n"
"	background-color: rgb(31,31,31);\n"
"}"));
        newp = new QPushButton(Menu);
        newp->setObjectName(QString::fromUtf8("newp"));
        newp->setEnabled(true);
        newp->setGeometry(QRect(240, 140, 171, 25));
        newp->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        open = new QPushButton(Menu);
        open->setObjectName(QString::fromUtf8("open"));
        open->setGeometry(QRect(250, 180, 171, 25));
        open->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        save = new QPushButton(Menu);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(240, 220, 171, 25));
        save->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        sets = new QPushButton(Menu);
        sets->setObjectName(QString::fromUtf8("sets"));
        sets->setGeometry(QRect(230, 260, 171, 25));
        sets->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        read = new QPushButton(Menu);
        read->setObjectName(QString::fromUtf8("read"));
        read->setGeometry(QRect(240, 300, 171, 25));
        read->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        about = new QPushButton(Menu);
        about->setObjectName(QString::fromUtf8("about"));
        about->setGeometry(QRect(250, 350, 171, 25));
        about->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        push = new QPushButton(Menu);
        push->setObjectName(QString::fromUtf8("push"));
        push->setGeometry(QRect(590, 180, 89, 16));
        push->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,0);\n"
"border:none;"));

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "\350\217\234\345\215\225", nullptr));
#if QT_CONFIG(tooltip)
        newp->setToolTip(QCoreApplication::translate("Menu", "Ctrl+N", nullptr));
#endif // QT_CONFIG(tooltip)
        newp->setText(QCoreApplication::translate("Menu", "\346\226\260\351\241\271\347\233\256(N)", nullptr));
#if QT_CONFIG(shortcut)
        newp->setShortcut(QCoreApplication::translate("Menu", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        open->setToolTip(QCoreApplication::translate("Menu", "Ctrl+O", nullptr));
#endif // QT_CONFIG(tooltip)
        open->setText(QCoreApplication::translate("Menu", "\346\211\223\345\274\200\351\241\271\347\233\256(O)", nullptr));
#if QT_CONFIG(shortcut)
        open->setShortcut(QCoreApplication::translate("Menu", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        save->setToolTip(QCoreApplication::translate("Menu", "Ctrl+S", nullptr));
#endif // QT_CONFIG(tooltip)
        save->setText(QCoreApplication::translate("Menu", "\344\277\235\345\255\230\351\241\271\347\233\256(S)", nullptr));
#if QT_CONFIG(shortcut)
        save->setShortcut(QCoreApplication::translate("Menu", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        sets->setToolTip(QCoreApplication::translate("Menu", "F2", nullptr));
#endif // QT_CONFIG(tooltip)
        sets->setText(QCoreApplication::translate("Menu", "\351\241\271\347\233\256\350\256\276\347\275\256(F2)", nullptr));
#if QT_CONFIG(shortcut)
        sets->setShortcut(QCoreApplication::translate("Menu", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        read->setToolTip(QCoreApplication::translate("Menu", "Ctrl+P", nullptr));
#endif // QT_CONFIG(tooltip)
        read->setText(QCoreApplication::translate("Menu", "\346\217\222\344\273\266\345\210\227\350\241\250(P)", nullptr));
#if QT_CONFIG(tooltip)
        about->setToolTip(QCoreApplication::translate("Menu", "Ctrl+A", nullptr));
#endif // QT_CONFIG(tooltip)
        about->setText(QCoreApplication::translate("Menu", "\345\205\263\344\272\216DVMT(A)", nullptr));
#if QT_CONFIG(shortcut)
        about->setShortcut(QCoreApplication::translate("Menu", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        push->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
