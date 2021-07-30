/********************************************************************************
** Form generated from reading UI file 'openwav.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENWAV_H
#define UI_OPENWAV_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OpenWav
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextEdit *plist;
    QPushButton *cancel;
    QPushButton *enter;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *name;
    QListWidget *olist;
    QLabel *la;
    QLabel *le;

    void setupUi(QDialog *OpenWav)
    {
        if (OpenWav->objectName().isEmpty())
            OpenWav->setObjectName(QString::fromUtf8("OpenWav"));
        OpenWav->resize(576, 378);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        OpenWav->setWindowIcon(icon);
        OpenWav->setStyleSheet(QString::fromUtf8("\n"
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
        gridLayout_2 = new QGridLayout(OpenWav);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(OpenWav);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plist = new QTextEdit(groupBox);
        plist->setObjectName(QString::fromUtf8("plist"));
        plist->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
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
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::add-page:vertical {\n"
"        background-color: rgb(194,204,208);\n"
"    }\n"
"    QScrollBar::sub-page:vertical {\n"
"        background-color:rgb(194,204,208);\n"
"    }"
                        "\n"
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
"        height: 0px;\n"
"        subcontrol-position: top;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::add-page:vertical:disabled{\n"
"        background-color:rgb(186, 189, 182);\n"
"    }\n"
"    QScrollB"
                        "ar::sub-page:vertical:disabled {\n"
"        background-color:rgb(186, 189, 182);\n"
"    }\n"
"    \n"
""));
        plist->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        plist->setReadOnly(true);

        gridLayout->addWidget(plist, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 2);

        cancel = new QPushButton(OpenWav);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setAutoDefault(false);

        gridLayout_2->addWidget(cancel, 2, 0, 1, 1);

        enter = new QPushButton(OpenWav);
        enter->setObjectName(QString::fromUtf8("enter"));
        enter->setEnabled(false);

        gridLayout_2->addWidget(enter, 2, 1, 1, 1);

        groupBox_2 = new QGroupBox(OpenWav);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        name = new QLineEdit(groupBox_2);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout->addWidget(name);

        olist = new QListWidget(groupBox_2);
        olist->setObjectName(QString::fromUtf8("olist"));
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
"        subco"
                        "ntrol-position: top;\n"
"        subcontrol-origin: margin;\n"
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
""
                        "background: rgb(31,31,31);\n"
"        height: 0px;\n"
"        subcontrol-position: top;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::add-page:vertical:disabled{\n"
"        background-color:rgb(186, 189, 182);\n"
"    }\n"
"    QScrollBar::sub-page:vertical:disabled {\n"
"        background-color:rgb(186, 189, 182);\n"
"    }\n"
"    \n"
""));
        olist->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        olist->setEditTriggers(QAbstractItemView::NoEditTriggers);
        olist->setProperty("showDropIndicator", QVariant(false));
        olist->setDefaultDropAction(Qt::IgnoreAction);
        olist->setSelectionBehavior(QAbstractItemView::SelectItems);
        olist->setTextElideMode(Qt::ElideMiddle);

        verticalLayout->addWidget(olist);

        la = new QLabel(groupBox_2);
        la->setObjectName(QString::fromUtf8("la"));
        la->setStyleSheet(QString::fromUtf8("color: rgb(138, 226, 52);"));

        verticalLayout->addWidget(la);

        le = new QLabel(groupBox_2);
        le->setObjectName(QString::fromUtf8("le"));
        le->setStyleSheet(QString::fromUtf8("color: rgb(239, 41, 41);"));

        verticalLayout->addWidget(le);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 2);


        retranslateUi(OpenWav);

        enter->setDefault(true);


        QMetaObject::connectSlotsByName(OpenWav);
    } // setupUi

    void retranslateUi(QDialog *OpenWav)
    {
        OpenWav->setWindowTitle(QCoreApplication::translate("OpenWav", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OpenWav", "\344\273\216\344\270\213\351\235\242\347\232\204\347\233\256\345\275\225\344\270\255\346\237\245\346\211\276wav\346\226\207\344\273\266", nullptr));
        plist->setPlaceholderText(QCoreApplication::translate("OpenWav", "\346\262\241\346\234\211\347\233\256\345\275\225\345\210\227\350\241\250\357\274\214\350\257\267\345\210\260\351\241\271\347\233\256\350\256\276\347\275\256\344\270\255\350\277\233\350\241\214\350\256\276\347\275\256", nullptr));
        cancel->setText(QCoreApplication::translate("OpenWav", "\345\217\226\346\266\210", nullptr));
        enter->setText(QCoreApplication::translate("OpenWav", "\347\241\256\345\256\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("OpenWav", "wav\346\226\207\344\273\266", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("OpenWav", "\344\273\216\345\210\227\350\241\250\344\270\255\346\220\234\347\264\242wav\346\226\207\344\273\266", nullptr));
        la->setText(QCoreApplication::translate("OpenWav", "\346\255\243\347\241\256", nullptr));
        le->setText(QCoreApplication::translate("OpenWav", "\351\224\231\350\257\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenWav: public Ui_OpenWav {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENWAV_H
