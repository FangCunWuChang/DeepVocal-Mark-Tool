/********************************************************************************
** Form generated from reading UI file 'center.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTER_H
#define UI_CENTER_H

#include <AuPlot/auplot.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <as.h>
#include <autowav.h>
#include <ctool.h>
#include <dow.h>
#include <egg.h>
#include <menu.h>
#include <search.h>

QT_BEGIN_NAMESPACE

class Ui_Center
{
public:
    QListWidget *list;
    AuPlot *plot;
    Search *sear;
    Egg *egg;
    AutoWav *aww;
    CTool *ct;
    DoW *dow;
    Menu *mt;
    AS *as;
    QPushButton *sb;

    void setupUi(QWidget *Center)
    {
        if (Center->objectName().isEmpty())
            Center->setObjectName(QString::fromUtf8("Center"));
        Center->resize(666, 420);
        Center->setMouseTracking(true);
        Center->setTabletTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Center->setWindowIcon(icon);
        Center->setStyleSheet(QString::fromUtf8("QToolTip{\n"
"\n"
"background-color:rgb(31,31,31);\n"
"color: rgb(211, 215, 207);\n"
"border:1px solid rgb(31,31,31);\n"
"}\n"
"\n"
"\n"
"\n"
"QWidget{\n"
"background-color: rgb(31,31,31);\n"
"	color: rgb(238, 238, 236);\n"
"}\n"
"QScrollBar:vertical {\n"
"        border: 1px solid grey;\n"
"        background-color:rgb(194,204,208);\n"
"        width: 20px;\n"
"        margin: 0px 0 0px 0;\n"
"    }\n"
"    QScrollBar::handle:vertical {\n"
"        border: 	1px solid grey;\n"
"        border-radius: 7px;\n"
"        background-color: rgb(31,31,31);\n"
"        min-height: 60px;\n"
"        margin: 0px 0px 0px 0px;\n"
"    }\n"
"    QScrollBar::add-line:vertical {\n"
"        border: none;\n"
"        background: rgb(31,31,31);\n"
"        height: 0px;\n"
"        subcontrol-position: bottom;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::sub-line:vertical {\n"
"        border: none;\n"
"background: rgb(31,31,31);\n"
"        height: 0px;\n"
"        subcontrol-position: top;\n"
"        "
                        "subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::add-page:vertical {\n"
"        background-color: rgb(194,204,208);\n"
"    }\n"
"    QScrollBar::sub-page:vertical {\n"
"        background-color:rgb(194,204,208);\n"
"    }\n"
"QScrollBar:vertical:disabled{\n"
"        border: 1px solid rgb(238, 238, 236);\n"
"        background-color:rgb(186, 189, 182);\n"
"        width: 20px;\n"
"        margin: 0px 0 0px 0;\n"
"    }\n"
"    QScrollBar::handle:vertical:disabled{\n"
"        border: 	1px solid rgb(238, 238, 236);\n"
"        border-radius: 7px;\n"
"        background-color:rgb(186, 189, 182);\n"
"        min-height: 60px;\n"
"        margin: 0px 0px 0px 0px;\n"
"    }\n"
"    QScrollBar::add-line:vertical:disabled{\n"
"        border: none;\n"
"        background: rgb(31,31,31);\n"
"        height: 0px;\n"
"        subcontrol-position: bottom;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::sub-line:vertical:disabled{\n"
"        border: none;\n"
"background: rgb(31,31,31);\n"
""
                        "        height: 0px;\n"
"        subcontrol-position: top;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::add-page:vertical:disabled{\n"
"        background-color:rgb(186, 189, 182);\n"
"    }\n"
"    QScrollBar::sub-page:vertical:disabled {\n"
"        background-color:rgb(186, 189, 182);\n"
"    }"));
        list = new QListWidget(Center);
        list->setObjectName(QString::fromUtf8("list"));
        list->setEnabled(true);
        list->setGeometry(QRect(10, 160, 131, 192));
        list->setStyleSheet(QString::fromUtf8("\n"
"QListWidget{\n"
"background-color: rgb(31,31,31);\n"
"color: rgb(211, 215, 207);\n"
"border:1px solid grey;\n"
"}\n"
"\n"
"QListWidget::disabled{\n"
"background-color: rgb(194,204,208);\n"
"color: rgb(211, 215, 207);\n"
"border:1px solid grey;\n"
"}\n"
"\n"
"    \n"
""));
        list->setUniformItemSizes(false);
        list->setSelectionRectVisible(false);
        plot = new AuPlot(Center);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(430, 20, 120, 80));
        sear = new Search(Center);
        sear->setObjectName(QString::fromUtf8("sear"));
        sear->setGeometry(QRect(520, 120, 120, 80));
        egg = new Egg(Center);
        egg->setObjectName(QString::fromUtf8("egg"));
        egg->setGeometry(QRect(400, 290, 120, 80));
        aww = new AutoWav(Center);
        aww->setObjectName(QString::fromUtf8("aww"));
        aww->setGeometry(QRect(490, 210, 120, 80));
        ct = new CTool(Center);
        ct->setObjectName(QString::fromUtf8("ct"));
        ct->setGeometry(QRect(250, 30, 120, 80));
        dow = new DoW(Center);
        dow->setObjectName(QString::fromUtf8("dow"));
        dow->setGeometry(QRect(270, 120, 120, 80));
        mt = new Menu(Center);
        mt->setObjectName(QString::fromUtf8("mt"));
        mt->setGeometry(QRect(260, 230, 120, 80));
        as = new AS(Center);
        as->setObjectName(QString::fromUtf8("as"));
        as->setGeometry(QRect(180, 320, 120, 80));
        sb = new QPushButton(Center);
        sb->setObjectName(QString::fromUtf8("sb"));
        sb->setGeometry(QRect(30, 40, 131, 28));
        sb->setStyleSheet(QString::fromUtf8("background-color: rgba(31,31,31,255);\n"
"color: rgb(255, 255, 255);\n"
"border: 1px solid white;\n"
"border-radius: 2px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        sb->setIcon(icon1);

        retranslateUi(Center);

        list->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(Center);
    } // setupUi

    void retranslateUi(QWidget *Center)
    {
        Center->setWindowTitle(QCoreApplication::translate("Center", "\346\240\270\345\277\203\347\273\204\344\273\266", nullptr));
        sb->setText(QCoreApplication::translate("Center", "\346\234\252\351\200\211\346\213\251\345\217\221\351\237\263\347\254\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Center: public Ui_Center {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTER_H
