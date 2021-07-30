/********************************************************************************
** Form generated from reading UI file 'title.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLE_H
#define UI_TITLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Title
{
public:
    QLabel *title;
    QPushButton *close;
    QPushButton *min;

    void setupUi(QWidget *Title)
    {
        if (Title->objectName().isEmpty())
            Title->setObjectName(QString::fromUtf8("Title"));
        Title->resize(835, 40);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Title->setWindowIcon(icon);
        title = new QLabel(Title);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(70, 10, 701, 20));
        title->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"background-color: rgba(255, 255, 255,0);"));
        title->setAlignment(Qt::AlignCenter);
        close = new QPushButton(Title);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(740, 0, 91, 31));
        close->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border:none;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 0, 0,255);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border:none;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255,255, 255,200);\n"
"}\n"
""));
        min = new QPushButton(Title);
        min->setObjectName(QString::fromUtf8("min"));
        min->setGeometry(QRect(650, 0, 91, 31));
        min->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255, 255, 255,0);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border:none;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(0, 0, 0,200);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border:none;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgba(255,255, 255,200);\n"
"}\n"
""));

        retranslateUi(Title);

        QMetaObject::connectSlotsByName(Title);
    } // setupUi

    void retranslateUi(QWidget *Title)
    {
        Title->setWindowTitle(QCoreApplication::translate("Title", "title", nullptr));
        title->setText(QCoreApplication::translate("Title", "DeepVocal Mark Tool - \346\234\252\345\221\275\345\220\215\351\241\271\347\233\256.dvmtp", nullptr));
        close->setText(QCoreApplication::translate("Title", "X", nullptr));
        min->setText(QCoreApplication::translate("Title", "_", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Title: public Ui_Title {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLE_H
