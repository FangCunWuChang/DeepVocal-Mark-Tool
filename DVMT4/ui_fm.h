/********************************************************************************
** Form generated from reading UI file 'fm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_H
#define UI_FM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FM
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *pitl;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *pit;
    QLabel *label_2;
    QLineEdit *all;
    QLabel *label_3;
    QLineEdit *cvm;
    QLabel *label_4;
    QLineEdit *vxm;
    QLabel *label_5;
    QLineEdit *indiem;
    QPushButton *clem;
    QPushButton *copm;
    QPushButton *edim;

    void setupUi(QDialog *FM)
    {
        if (FM->objectName().isEmpty())
            FM->setObjectName(QString::fromUtf8("FM"));
        FM->resize(729, 524);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FM->setWindowIcon(icon);
        FM->setStyleSheet(QString::fromUtf8("QToolTip{\n"
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
        horizontalLayout = new QHBoxLayout(FM);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pitl = new QListWidget(FM);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        new QListWidgetItem(pitl);
        pitl->setObjectName(QString::fromUtf8("pitl"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pitl->sizePolicy().hasHeightForWidth());
        pitl->setSizePolicy(sizePolicy);
        pitl->setStyleSheet(QString::fromUtf8("\n"
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
        pitl->setLayoutMode(QListView::SinglePass);
        pitl->setModelColumn(0);

        horizontalLayout->addWidget(pitl);

        groupBox = new QGroupBox(FM);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pit = new QLineEdit(groupBox);
        pit->setObjectName(QString::fromUtf8("pit"));
        pit->setReadOnly(true);

        gridLayout->addWidget(pit, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        all = new QLineEdit(groupBox);
        all->setObjectName(QString::fromUtf8("all"));
        all->setReadOnly(true);

        gridLayout->addWidget(all, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cvm = new QLineEdit(groupBox);
        cvm->setObjectName(QString::fromUtf8("cvm"));
        cvm->setReadOnly(true);

        gridLayout->addWidget(cvm, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        vxm = new QLineEdit(groupBox);
        vxm->setObjectName(QString::fromUtf8("vxm"));
        vxm->setReadOnly(true);

        gridLayout->addWidget(vxm, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        indiem = new QLineEdit(groupBox);
        indiem->setObjectName(QString::fromUtf8("indiem"));
        indiem->setReadOnly(true);

        gridLayout->addWidget(indiem, 4, 1, 1, 1);

        clem = new QPushButton(groupBox);
        clem->setObjectName(QString::fromUtf8("clem"));
        clem->setStyleSheet(QString::fromUtf8(""));
        clem->setAutoDefault(false);

        gridLayout->addWidget(clem, 5, 0, 1, 2);

        copm = new QPushButton(groupBox);
        copm->setObjectName(QString::fromUtf8("copm"));
        copm->setStyleSheet(QString::fromUtf8(""));
        copm->setAutoDefault(false);

        gridLayout->addWidget(copm, 6, 0, 1, 2);

        edim = new QPushButton(groupBox);
        edim->setObjectName(QString::fromUtf8("edim"));
        edim->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(edim, 7, 0, 1, 2);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(FM);

        pitl->setCurrentRow(48);
        edim->setDefault(true);


        QMetaObject::connectSlotsByName(FM);
    } // setupUi

    void retranslateUi(QDialog *FM)
    {
        FM->setWindowTitle(QCoreApplication::translate("FM", "\346\240\207\350\256\260\347\256\241\347\220\206\357\274\210\345\256\236\351\252\214\345\212\237\350\203\275\357\274\211", nullptr));

        const bool __sortingEnabled = pitl->isSortingEnabled();
        pitl->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = pitl->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("FM", "C0", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = pitl->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("FM", "C#0", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = pitl->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("FM", "D0", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = pitl->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("FM", "D#0", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = pitl->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("FM", "E0", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = pitl->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("FM", "F0", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = pitl->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("FM", "F#0", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = pitl->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("FM", "G0", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = pitl->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("FM", "G#0", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = pitl->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("FM", "A0", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = pitl->item(10);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("FM", "A#0", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = pitl->item(11);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("FM", "B0", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = pitl->item(12);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("FM", "C1", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = pitl->item(13);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("FM", "C#1", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = pitl->item(14);
        ___qlistwidgetitem14->setText(QCoreApplication::translate("FM", "D1", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = pitl->item(15);
        ___qlistwidgetitem15->setText(QCoreApplication::translate("FM", "D#1", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = pitl->item(16);
        ___qlistwidgetitem16->setText(QCoreApplication::translate("FM", "E1", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = pitl->item(17);
        ___qlistwidgetitem17->setText(QCoreApplication::translate("FM", "F1", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = pitl->item(18);
        ___qlistwidgetitem18->setText(QCoreApplication::translate("FM", "F#1", nullptr));
        QListWidgetItem *___qlistwidgetitem19 = pitl->item(19);
        ___qlistwidgetitem19->setText(QCoreApplication::translate("FM", "G1", nullptr));
        QListWidgetItem *___qlistwidgetitem20 = pitl->item(20);
        ___qlistwidgetitem20->setText(QCoreApplication::translate("FM", "G#1", nullptr));
        QListWidgetItem *___qlistwidgetitem21 = pitl->item(21);
        ___qlistwidgetitem21->setText(QCoreApplication::translate("FM", "A1", nullptr));
        QListWidgetItem *___qlistwidgetitem22 = pitl->item(22);
        ___qlistwidgetitem22->setText(QCoreApplication::translate("FM", "A#1", nullptr));
        QListWidgetItem *___qlistwidgetitem23 = pitl->item(23);
        ___qlistwidgetitem23->setText(QCoreApplication::translate("FM", "B1", nullptr));
        QListWidgetItem *___qlistwidgetitem24 = pitl->item(24);
        ___qlistwidgetitem24->setText(QCoreApplication::translate("FM", "C2", nullptr));
        QListWidgetItem *___qlistwidgetitem25 = pitl->item(25);
        ___qlistwidgetitem25->setText(QCoreApplication::translate("FM", "C#2", nullptr));
        QListWidgetItem *___qlistwidgetitem26 = pitl->item(26);
        ___qlistwidgetitem26->setText(QCoreApplication::translate("FM", "D2", nullptr));
        QListWidgetItem *___qlistwidgetitem27 = pitl->item(27);
        ___qlistwidgetitem27->setText(QCoreApplication::translate("FM", "D#2", nullptr));
        QListWidgetItem *___qlistwidgetitem28 = pitl->item(28);
        ___qlistwidgetitem28->setText(QCoreApplication::translate("FM", "E2", nullptr));
        QListWidgetItem *___qlistwidgetitem29 = pitl->item(29);
        ___qlistwidgetitem29->setText(QCoreApplication::translate("FM", "F2", nullptr));
        QListWidgetItem *___qlistwidgetitem30 = pitl->item(30);
        ___qlistwidgetitem30->setText(QCoreApplication::translate("FM", "F#2", nullptr));
        QListWidgetItem *___qlistwidgetitem31 = pitl->item(31);
        ___qlistwidgetitem31->setText(QCoreApplication::translate("FM", "G2", nullptr));
        QListWidgetItem *___qlistwidgetitem32 = pitl->item(32);
        ___qlistwidgetitem32->setText(QCoreApplication::translate("FM", "G#2", nullptr));
        QListWidgetItem *___qlistwidgetitem33 = pitl->item(33);
        ___qlistwidgetitem33->setText(QCoreApplication::translate("FM", "A2", nullptr));
        QListWidgetItem *___qlistwidgetitem34 = pitl->item(34);
        ___qlistwidgetitem34->setText(QCoreApplication::translate("FM", "A#2", nullptr));
        QListWidgetItem *___qlistwidgetitem35 = pitl->item(35);
        ___qlistwidgetitem35->setText(QCoreApplication::translate("FM", "B2", nullptr));
        QListWidgetItem *___qlistwidgetitem36 = pitl->item(36);
        ___qlistwidgetitem36->setText(QCoreApplication::translate("FM", "C3", nullptr));
        QListWidgetItem *___qlistwidgetitem37 = pitl->item(37);
        ___qlistwidgetitem37->setText(QCoreApplication::translate("FM", "C#3", nullptr));
        QListWidgetItem *___qlistwidgetitem38 = pitl->item(38);
        ___qlistwidgetitem38->setText(QCoreApplication::translate("FM", "D3", nullptr));
        QListWidgetItem *___qlistwidgetitem39 = pitl->item(39);
        ___qlistwidgetitem39->setText(QCoreApplication::translate("FM", "D#3", nullptr));
        QListWidgetItem *___qlistwidgetitem40 = pitl->item(40);
        ___qlistwidgetitem40->setText(QCoreApplication::translate("FM", "E3", nullptr));
        QListWidgetItem *___qlistwidgetitem41 = pitl->item(41);
        ___qlistwidgetitem41->setText(QCoreApplication::translate("FM", "F3", nullptr));
        QListWidgetItem *___qlistwidgetitem42 = pitl->item(42);
        ___qlistwidgetitem42->setText(QCoreApplication::translate("FM", "F#3", nullptr));
        QListWidgetItem *___qlistwidgetitem43 = pitl->item(43);
        ___qlistwidgetitem43->setText(QCoreApplication::translate("FM", "G3", nullptr));
        QListWidgetItem *___qlistwidgetitem44 = pitl->item(44);
        ___qlistwidgetitem44->setText(QCoreApplication::translate("FM", "G#3", nullptr));
        QListWidgetItem *___qlistwidgetitem45 = pitl->item(45);
        ___qlistwidgetitem45->setText(QCoreApplication::translate("FM", "A3", nullptr));
        QListWidgetItem *___qlistwidgetitem46 = pitl->item(46);
        ___qlistwidgetitem46->setText(QCoreApplication::translate("FM", "A#3", nullptr));
        QListWidgetItem *___qlistwidgetitem47 = pitl->item(47);
        ___qlistwidgetitem47->setText(QCoreApplication::translate("FM", "B3", nullptr));
        QListWidgetItem *___qlistwidgetitem48 = pitl->item(48);
        ___qlistwidgetitem48->setText(QCoreApplication::translate("FM", "C4", nullptr));
        QListWidgetItem *___qlistwidgetitem49 = pitl->item(49);
        ___qlistwidgetitem49->setText(QCoreApplication::translate("FM", "C#4", nullptr));
        QListWidgetItem *___qlistwidgetitem50 = pitl->item(50);
        ___qlistwidgetitem50->setText(QCoreApplication::translate("FM", "D4", nullptr));
        QListWidgetItem *___qlistwidgetitem51 = pitl->item(51);
        ___qlistwidgetitem51->setText(QCoreApplication::translate("FM", "D#4", nullptr));
        QListWidgetItem *___qlistwidgetitem52 = pitl->item(52);
        ___qlistwidgetitem52->setText(QCoreApplication::translate("FM", "E4", nullptr));
        QListWidgetItem *___qlistwidgetitem53 = pitl->item(53);
        ___qlistwidgetitem53->setText(QCoreApplication::translate("FM", "F4", nullptr));
        QListWidgetItem *___qlistwidgetitem54 = pitl->item(54);
        ___qlistwidgetitem54->setText(QCoreApplication::translate("FM", "F#4", nullptr));
        QListWidgetItem *___qlistwidgetitem55 = pitl->item(55);
        ___qlistwidgetitem55->setText(QCoreApplication::translate("FM", "G4", nullptr));
        QListWidgetItem *___qlistwidgetitem56 = pitl->item(56);
        ___qlistwidgetitem56->setText(QCoreApplication::translate("FM", "G#4", nullptr));
        QListWidgetItem *___qlistwidgetitem57 = pitl->item(57);
        ___qlistwidgetitem57->setText(QCoreApplication::translate("FM", "A4", nullptr));
        QListWidgetItem *___qlistwidgetitem58 = pitl->item(58);
        ___qlistwidgetitem58->setText(QCoreApplication::translate("FM", "A#4", nullptr));
        QListWidgetItem *___qlistwidgetitem59 = pitl->item(59);
        ___qlistwidgetitem59->setText(QCoreApplication::translate("FM", "B4", nullptr));
        QListWidgetItem *___qlistwidgetitem60 = pitl->item(60);
        ___qlistwidgetitem60->setText(QCoreApplication::translate("FM", "C5", nullptr));
        QListWidgetItem *___qlistwidgetitem61 = pitl->item(61);
        ___qlistwidgetitem61->setText(QCoreApplication::translate("FM", "C#5", nullptr));
        QListWidgetItem *___qlistwidgetitem62 = pitl->item(62);
        ___qlistwidgetitem62->setText(QCoreApplication::translate("FM", "D5", nullptr));
        QListWidgetItem *___qlistwidgetitem63 = pitl->item(63);
        ___qlistwidgetitem63->setText(QCoreApplication::translate("FM", "D#5", nullptr));
        QListWidgetItem *___qlistwidgetitem64 = pitl->item(64);
        ___qlistwidgetitem64->setText(QCoreApplication::translate("FM", "E5", nullptr));
        QListWidgetItem *___qlistwidgetitem65 = pitl->item(65);
        ___qlistwidgetitem65->setText(QCoreApplication::translate("FM", "F5", nullptr));
        QListWidgetItem *___qlistwidgetitem66 = pitl->item(66);
        ___qlistwidgetitem66->setText(QCoreApplication::translate("FM", "F#5", nullptr));
        QListWidgetItem *___qlistwidgetitem67 = pitl->item(67);
        ___qlistwidgetitem67->setText(QCoreApplication::translate("FM", "G5", nullptr));
        QListWidgetItem *___qlistwidgetitem68 = pitl->item(68);
        ___qlistwidgetitem68->setText(QCoreApplication::translate("FM", "G#5", nullptr));
        QListWidgetItem *___qlistwidgetitem69 = pitl->item(69);
        ___qlistwidgetitem69->setText(QCoreApplication::translate("FM", "A5", nullptr));
        QListWidgetItem *___qlistwidgetitem70 = pitl->item(70);
        ___qlistwidgetitem70->setText(QCoreApplication::translate("FM", "A#5", nullptr));
        QListWidgetItem *___qlistwidgetitem71 = pitl->item(71);
        ___qlistwidgetitem71->setText(QCoreApplication::translate("FM", "B5", nullptr));
        QListWidgetItem *___qlistwidgetitem72 = pitl->item(72);
        ___qlistwidgetitem72->setText(QCoreApplication::translate("FM", "C6", nullptr));
        QListWidgetItem *___qlistwidgetitem73 = pitl->item(73);
        ___qlistwidgetitem73->setText(QCoreApplication::translate("FM", "C#6", nullptr));
        QListWidgetItem *___qlistwidgetitem74 = pitl->item(74);
        ___qlistwidgetitem74->setText(QCoreApplication::translate("FM", "D6", nullptr));
        QListWidgetItem *___qlistwidgetitem75 = pitl->item(75);
        ___qlistwidgetitem75->setText(QCoreApplication::translate("FM", "D#6", nullptr));
        QListWidgetItem *___qlistwidgetitem76 = pitl->item(76);
        ___qlistwidgetitem76->setText(QCoreApplication::translate("FM", "E6", nullptr));
        QListWidgetItem *___qlistwidgetitem77 = pitl->item(77);
        ___qlistwidgetitem77->setText(QCoreApplication::translate("FM", "F6", nullptr));
        QListWidgetItem *___qlistwidgetitem78 = pitl->item(78);
        ___qlistwidgetitem78->setText(QCoreApplication::translate("FM", "F#6", nullptr));
        QListWidgetItem *___qlistwidgetitem79 = pitl->item(79);
        ___qlistwidgetitem79->setText(QCoreApplication::translate("FM", "G6", nullptr));
        QListWidgetItem *___qlistwidgetitem80 = pitl->item(80);
        ___qlistwidgetitem80->setText(QCoreApplication::translate("FM", "G#6", nullptr));
        QListWidgetItem *___qlistwidgetitem81 = pitl->item(81);
        ___qlistwidgetitem81->setText(QCoreApplication::translate("FM", "A6", nullptr));
        QListWidgetItem *___qlistwidgetitem82 = pitl->item(82);
        ___qlistwidgetitem82->setText(QCoreApplication::translate("FM", "A#6", nullptr));
        QListWidgetItem *___qlistwidgetitem83 = pitl->item(83);
        ___qlistwidgetitem83->setText(QCoreApplication::translate("FM", "B6", nullptr));
        QListWidgetItem *___qlistwidgetitem84 = pitl->item(84);
        ___qlistwidgetitem84->setText(QCoreApplication::translate("FM", "C7", nullptr));
        QListWidgetItem *___qlistwidgetitem85 = pitl->item(85);
        ___qlistwidgetitem85->setText(QCoreApplication::translate("FM", "C#7", nullptr));
        QListWidgetItem *___qlistwidgetitem86 = pitl->item(86);
        ___qlistwidgetitem86->setText(QCoreApplication::translate("FM", "D7", nullptr));
        QListWidgetItem *___qlistwidgetitem87 = pitl->item(87);
        ___qlistwidgetitem87->setText(QCoreApplication::translate("FM", "D#7", nullptr));
        QListWidgetItem *___qlistwidgetitem88 = pitl->item(88);
        ___qlistwidgetitem88->setText(QCoreApplication::translate("FM", "E7", nullptr));
        QListWidgetItem *___qlistwidgetitem89 = pitl->item(89);
        ___qlistwidgetitem89->setText(QCoreApplication::translate("FM", "F7", nullptr));
        QListWidgetItem *___qlistwidgetitem90 = pitl->item(90);
        ___qlistwidgetitem90->setText(QCoreApplication::translate("FM", "F#7", nullptr));
        QListWidgetItem *___qlistwidgetitem91 = pitl->item(91);
        ___qlistwidgetitem91->setText(QCoreApplication::translate("FM", "G7", nullptr));
        QListWidgetItem *___qlistwidgetitem92 = pitl->item(92);
        ___qlistwidgetitem92->setText(QCoreApplication::translate("FM", "G#7", nullptr));
        QListWidgetItem *___qlistwidgetitem93 = pitl->item(93);
        ___qlistwidgetitem93->setText(QCoreApplication::translate("FM", "A7", nullptr));
        QListWidgetItem *___qlistwidgetitem94 = pitl->item(94);
        ___qlistwidgetitem94->setText(QCoreApplication::translate("FM", "A#7", nullptr));
        QListWidgetItem *___qlistwidgetitem95 = pitl->item(95);
        ___qlistwidgetitem95->setText(QCoreApplication::translate("FM", "B7", nullptr));
        QListWidgetItem *___qlistwidgetitem96 = pitl->item(96);
        ___qlistwidgetitem96->setText(QCoreApplication::translate("FM", "C8", nullptr));
        QListWidgetItem *___qlistwidgetitem97 = pitl->item(97);
        ___qlistwidgetitem97->setText(QCoreApplication::translate("FM", "C#8", nullptr));
        QListWidgetItem *___qlistwidgetitem98 = pitl->item(98);
        ___qlistwidgetitem98->setText(QCoreApplication::translate("FM", "D8", nullptr));
        QListWidgetItem *___qlistwidgetitem99 = pitl->item(99);
        ___qlistwidgetitem99->setText(QCoreApplication::translate("FM", "D#8", nullptr));
        QListWidgetItem *___qlistwidgetitem100 = pitl->item(100);
        ___qlistwidgetitem100->setText(QCoreApplication::translate("FM", "E8", nullptr));
        QListWidgetItem *___qlistwidgetitem101 = pitl->item(101);
        ___qlistwidgetitem101->setText(QCoreApplication::translate("FM", "F8", nullptr));
        QListWidgetItem *___qlistwidgetitem102 = pitl->item(102);
        ___qlistwidgetitem102->setText(QCoreApplication::translate("FM", "F#8", nullptr));
        QListWidgetItem *___qlistwidgetitem103 = pitl->item(103);
        ___qlistwidgetitem103->setText(QCoreApplication::translate("FM", "G8", nullptr));
        QListWidgetItem *___qlistwidgetitem104 = pitl->item(104);
        ___qlistwidgetitem104->setText(QCoreApplication::translate("FM", "G#8", nullptr));
        QListWidgetItem *___qlistwidgetitem105 = pitl->item(105);
        ___qlistwidgetitem105->setText(QCoreApplication::translate("FM", "A8", nullptr));
        QListWidgetItem *___qlistwidgetitem106 = pitl->item(106);
        ___qlistwidgetitem106->setText(QCoreApplication::translate("FM", "A#8", nullptr));
        QListWidgetItem *___qlistwidgetitem107 = pitl->item(107);
        ___qlistwidgetitem107->setText(QCoreApplication::translate("FM", "B8", nullptr));
        QListWidgetItem *___qlistwidgetitem108 = pitl->item(108);
        ___qlistwidgetitem108->setText(QCoreApplication::translate("FM", "C9", nullptr));
        QListWidgetItem *___qlistwidgetitem109 = pitl->item(109);
        ___qlistwidgetitem109->setText(QCoreApplication::translate("FM", "C#9", nullptr));
        QListWidgetItem *___qlistwidgetitem110 = pitl->item(110);
        ___qlistwidgetitem110->setText(QCoreApplication::translate("FM", "D9", nullptr));
        QListWidgetItem *___qlistwidgetitem111 = pitl->item(111);
        ___qlistwidgetitem111->setText(QCoreApplication::translate("FM", "D#9", nullptr));
        QListWidgetItem *___qlistwidgetitem112 = pitl->item(112);
        ___qlistwidgetitem112->setText(QCoreApplication::translate("FM", "E9", nullptr));
        QListWidgetItem *___qlistwidgetitem113 = pitl->item(113);
        ___qlistwidgetitem113->setText(QCoreApplication::translate("FM", "F9", nullptr));
        QListWidgetItem *___qlistwidgetitem114 = pitl->item(114);
        ___qlistwidgetitem114->setText(QCoreApplication::translate("FM", "F#99", nullptr));
        QListWidgetItem *___qlistwidgetitem115 = pitl->item(115);
        ___qlistwidgetitem115->setText(QCoreApplication::translate("FM", "G9", nullptr));
        QListWidgetItem *___qlistwidgetitem116 = pitl->item(116);
        ___qlistwidgetitem116->setText(QCoreApplication::translate("FM", "G#9", nullptr));
        QListWidgetItem *___qlistwidgetitem117 = pitl->item(117);
        ___qlistwidgetitem117->setText(QCoreApplication::translate("FM", "A9", nullptr));
        QListWidgetItem *___qlistwidgetitem118 = pitl->item(118);
        ___qlistwidgetitem118->setText(QCoreApplication::translate("FM", "A#9", nullptr));
        QListWidgetItem *___qlistwidgetitem119 = pitl->item(119);
        ___qlistwidgetitem119->setText(QCoreApplication::translate("FM", "B9", nullptr));
        pitl->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QCoreApplication::translate("FM", "\351\237\263\351\230\266\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("FM", "\351\237\263\351\230\266\357\274\232", nullptr));
        pit->setText(QCoreApplication::translate("FM", "C4", nullptr));
        label_2->setText(QCoreApplication::translate("FM", "\346\200\273\346\240\207\350\256\260\346\225\260\357\274\232", nullptr));
        all->setText(QCoreApplication::translate("FM", "0", nullptr));
        label_3->setText(QCoreApplication::translate("FM", "CV\346\240\207\350\256\260\346\225\260\357\274\232", nullptr));
        cvm->setText(QCoreApplication::translate("FM", "0", nullptr));
        label_4->setText(QCoreApplication::translate("FM", "VX\346\240\207\350\256\260\346\225\260\357\274\232", nullptr));
        vxm->setText(QCoreApplication::translate("FM", "0", nullptr));
        label_5->setText(QCoreApplication::translate("FM", "INDIE\346\240\207\350\256\260\346\225\260\357\274\232", nullptr));
        indiem->setText(QCoreApplication::translate("FM", "0", nullptr));
        clem->setText(QCoreApplication::translate("FM", "\346\270\205\351\231\244\346\240\207\350\256\260", nullptr));
        copm->setText(QCoreApplication::translate("FM", "\345\244\215\345\210\266\351\237\263\351\230\266\350\207\263\357\274\210\346\274\217\346\264\236\345\212\237\350\203\275\357\274\214\350\257\267\350\260\250\346\205\216\344\275\277\347\224\250\357\274\211", nullptr));
        edim->setText(QCoreApplication::translate("FM", "\347\274\226\350\276\221\346\240\207\350\256\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FM: public Ui_FM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_H
