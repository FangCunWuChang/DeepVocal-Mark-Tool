/********************************************************************************
** Form generated from reading UI file 'autowav.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOWAV_H
#define UI_AUTOWAV_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoWav
{
public:
    QLineEdit *name;
    QListWidget *olist;

    void setupUi(QWidget *AutoWav)
    {
        if (AutoWav->objectName().isEmpty())
            AutoWav->setObjectName(QString::fromUtf8("AutoWav"));
        AutoWav->resize(743, 546);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        AutoWav->setWindowIcon(icon);
        AutoWav->setStyleSheet(QString::fromUtf8("QToolTip{\n"
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
        name = new QLineEdit(AutoWav);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(60, 99, 534, 25));
        name->setStyleSheet(QString::fromUtf8("background-color: rgba(31,31,31,0);\n"
"color: rgb(255, 255, 255);\n"
"border: 1px solid rgb(255, 255, 255);"));
        olist = new QListWidget(AutoWav);
        olist->setObjectName(QString::fromUtf8("olist"));
        olist->setGeometry(QRect(60, 130, 534, 70));
        olist->setStyleSheet(QString::fromUtf8("\n"
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
        olist->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        olist->setEditTriggers(QAbstractItemView::NoEditTriggers);
        olist->setProperty("showDropIndicator", QVariant(false));
        olist->setDefaultDropAction(Qt::IgnoreAction);
        olist->setSelectionBehavior(QAbstractItemView::SelectItems);
        olist->setTextElideMode(Qt::ElideMiddle);

        retranslateUi(AutoWav);

        QMetaObject::connectSlotsByName(AutoWav);
    } // setupUi

    void retranslateUi(QWidget *AutoWav)
    {
        AutoWav->setWindowTitle(QCoreApplication::translate("AutoWav", "\350\207\252\345\212\250\351\242\204\346\265\213", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("AutoWav", "\346\211\213\345\212\250\346\237\245\346\211\276wav\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutoWav: public Ui_AutoWav {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOWAV_H
