/********************************************************************************
** Form generated from reading UI file 'psm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PSM_H
#define UI_PSM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PSM
{
public:
    QFormLayout *formLayout_2;
    QListWidget *pslist;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *sl;
    QLabel *label_2;
    QLineEdit *pl;
    QLabel *label_4;
    QLineEdit *ptl;
    QLabel *label_5;
    QLineEdit *stl;
    QLabel *label_6;
    QLineEdit *wnl;
    QLabel *label_7;
    QLineEdit *utl;
    QLabel *label_8;
    QLineEdit *cpl;
    QLabel *label_9;
    QLineEdit *prl;
    QLabel *label_10;
    QLineEdit *srtl;
    QLabel *label_11;
    QLineEdit *spl;
    QLabel *label_12;
    QLineEdit *etl;
    QLabel *label_13;
    QLineEdit *epl;
    QLabel *label_14;
    QLineEdit *tpl;
    QLabel *label_15;
    QLineEdit *vsl;
    QLabel *label_16;
    QLineEdit *vel;
    QPushButton *des;
    QPushButton *cos;

    void setupUi(QDialog *PSM)
    {
        if (PSM->objectName().isEmpty())
            PSM->setObjectName(QString::fromUtf8("PSM"));
        PSM->resize(637, 678);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        PSM->setWindowIcon(icon);
        PSM->setStyleSheet(QString::fromUtf8("QToolTip{\n"
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
        formLayout_2 = new QFormLayout(PSM);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        pslist = new QListWidget(PSM);
        pslist->setObjectName(QString::fromUtf8("pslist"));
        pslist->setStyleSheet(QString::fromUtf8("\n"
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

        formLayout_2->setWidget(0, QFormLayout::LabelRole, pslist);

        groupBox = new QGroupBox(PSM);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        sl = new QLineEdit(groupBox);
        sl->setObjectName(QString::fromUtf8("sl"));
        sl->setReadOnly(true);

        gridLayout->addWidget(sl, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pl = new QLineEdit(groupBox);
        pl->setObjectName(QString::fromUtf8("pl"));
        pl->setReadOnly(true);

        gridLayout->addWidget(pl, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        ptl = new QLineEdit(groupBox);
        ptl->setObjectName(QString::fromUtf8("ptl"));
        ptl->setReadOnly(true);

        gridLayout->addWidget(ptl, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        stl = new QLineEdit(groupBox);
        stl->setObjectName(QString::fromUtf8("stl"));
        stl->setReadOnly(true);

        gridLayout->addWidget(stl, 3, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        wnl = new QLineEdit(groupBox);
        wnl->setObjectName(QString::fromUtf8("wnl"));
        wnl->setReadOnly(true);

        gridLayout->addWidget(wnl, 4, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        utl = new QLineEdit(groupBox);
        utl->setObjectName(QString::fromUtf8("utl"));
        utl->setReadOnly(true);

        gridLayout->addWidget(utl, 5, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        cpl = new QLineEdit(groupBox);
        cpl->setObjectName(QString::fromUtf8("cpl"));
        cpl->setReadOnly(true);

        gridLayout->addWidget(cpl, 6, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 7, 0, 1, 1);

        prl = new QLineEdit(groupBox);
        prl->setObjectName(QString::fromUtf8("prl"));
        prl->setReadOnly(true);

        gridLayout->addWidget(prl, 7, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 8, 0, 1, 1);

        srtl = new QLineEdit(groupBox);
        srtl->setObjectName(QString::fromUtf8("srtl"));
        srtl->setReadOnly(true);

        gridLayout->addWidget(srtl, 8, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 9, 0, 1, 1);

        spl = new QLineEdit(groupBox);
        spl->setObjectName(QString::fromUtf8("spl"));
        spl->setReadOnly(true);

        gridLayout->addWidget(spl, 9, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 10, 0, 1, 1);

        etl = new QLineEdit(groupBox);
        etl->setObjectName(QString::fromUtf8("etl"));
        etl->setReadOnly(true);

        gridLayout->addWidget(etl, 10, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 11, 0, 1, 1);

        epl = new QLineEdit(groupBox);
        epl->setObjectName(QString::fromUtf8("epl"));
        epl->setReadOnly(true);

        gridLayout->addWidget(epl, 11, 1, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 12, 0, 1, 1);

        tpl = new QLineEdit(groupBox);
        tpl->setObjectName(QString::fromUtf8("tpl"));
        tpl->setReadOnly(true);

        gridLayout->addWidget(tpl, 12, 1, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 13, 0, 1, 1);

        vsl = new QLineEdit(groupBox);
        vsl->setObjectName(QString::fromUtf8("vsl"));
        vsl->setReadOnly(true);

        gridLayout->addWidget(vsl, 13, 1, 1, 1);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 14, 0, 1, 1);

        vel = new QLineEdit(groupBox);
        vel->setObjectName(QString::fromUtf8("vel"));
        vel->setReadOnly(true);

        gridLayout->addWidget(vel, 14, 1, 1, 1);

        des = new QPushButton(groupBox);
        des->setObjectName(QString::fromUtf8("des"));
        des->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(des, 15, 0, 1, 2);

        cos = new QPushButton(groupBox);
        cos->setObjectName(QString::fromUtf8("cos"));
        cos->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cos, 16, 0, 1, 2);


        formLayout_2->setWidget(0, QFormLayout::FieldRole, groupBox);


        retranslateUi(PSM);

        pslist->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(PSM);
    } // setupUi

    void retranslateUi(QDialog *PSM)
    {
        PSM->setWindowTitle(QCoreApplication::translate("PSM", "\347\274\226\350\276\221\346\240\207\350\256\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PSM", "\346\240\207\350\256\260\344\277\241\346\201\257", nullptr));
        label_3->setText(QCoreApplication::translate("PSM", "symbol:", nullptr));
        sl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_2->setText(QCoreApplication::translate("PSM", "path:", nullptr));
        pl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_4->setText(QCoreApplication::translate("PSM", "pitch:", nullptr));
        ptl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_5->setText(QCoreApplication::translate("PSM", "srcType:", nullptr));
        stl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_6->setText(QCoreApplication::translate("PSM", "wavName:", nullptr));
        wnl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_7->setText(QCoreApplication::translate("PSM", "updateTime:", nullptr));
        utl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_8->setText(QCoreApplication::translate("PSM", "connectPoint:", nullptr));
        cpl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_9->setText(QCoreApplication::translate("PSM", "preutterance:", nullptr));
        prl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_10->setText(QCoreApplication::translate("PSM", "startTime:", nullptr));
        srtl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_11->setText(QCoreApplication::translate("PSM", "startPoint:", nullptr));
        spl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_12->setText(QCoreApplication::translate("PSM", "endTime:", nullptr));
        etl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_13->setText(QCoreApplication::translate("PSM", "endPoint:", nullptr));
        epl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_14->setText(QCoreApplication::translate("PSM", "tailPoint:", nullptr));
        tpl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_15->setText(QCoreApplication::translate("PSM", "vowelStart:", nullptr));
        vsl->setText(QCoreApplication::translate("PSM", "-", nullptr));
        label_16->setText(QCoreApplication::translate("PSM", "vowelEnd:", nullptr));
        vel->setText(QCoreApplication::translate("PSM", "-", nullptr));
        des->setText(QCoreApplication::translate("PSM", "\345\210\240\351\231\244\346\240\207\350\256\260", nullptr));
        cos->setText(QCoreApplication::translate("PSM", "\345\244\215\345\210\266\346\240\207\350\256\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PSM: public Ui_PSM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PSM_H
