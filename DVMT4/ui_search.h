/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QListWidget *slist;
    QLineEdit *line;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QString::fromUtf8("Search"));
        Search->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Search->setWindowIcon(icon);
        Search->setStyleSheet(QString::fromUtf8("QToolTip{\n"
"\n"
"background-color:rgb(31,31,31);\n"
"color: rgb(211, 215, 207);\n"
"border:1px solid rgb(31,31,31);\n"
"}\n"
"\n"
"QWidget{\n"
"	background-color: rgb(31,31,31);\n"
"	color: rgb(211, 215, 207);\n"
"}"));
        slist = new QListWidget(Search);
        slist->setObjectName(QString::fromUtf8("slist"));
        slist->setGeometry(QRect(60, 111, 256, 161));
        line = new QLineEdit(Search);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(60, 40, 281, 25));
        line->setTabletTracking(true);
        line->setAutoFillBackground(true);
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(31,31,31);\n"
"	color: rgb(255,255,255);\n"
"border:1px solid white;"));
        line->setClearButtonEnabled(false);

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Search", nullptr));
        line->setPlaceholderText(QCoreApplication::translate("Search", "\346\220\234\347\264\242\345\217\221\351\237\263\347\254\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
