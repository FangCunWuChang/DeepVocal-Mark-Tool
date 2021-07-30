/********************************************************************************
** Form generated from reading UI file 'prset.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRSET_H
#define UI_PRSET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Prset
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *remove;
    QListWidget *path;
    QPushButton *add;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QComboBox *P1;
    QComboBox *P2;
    QPushButton *flagm;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *dic;
    QLabel *la;
    QLabel *le;

    void setupUi(QDialog *Prset)
    {
        if (Prset->objectName().isEmpty())
            Prset->setObjectName(QString::fromUtf8("Prset"));
        Prset->resize(761, 508);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Prset->setWindowIcon(icon);
        Prset->setStyleSheet(QString::fromUtf8("QToolTip{\n"
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
        gridLayout = new QGridLayout(Prset);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Prset);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(31,31,31);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        remove = new QPushButton(groupBox);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setStyleSheet(QString::fromUtf8(""));
        remove->setAutoDefault(false);

        gridLayout_2->addWidget(remove, 1, 0, 1, 1);

        path = new QListWidget(groupBox);
        path->setObjectName(QString::fromUtf8("path"));
        path->setStyleSheet(QString::fromUtf8("\n"
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

        gridLayout_2->addWidget(path, 0, 0, 1, 2);

        add = new QPushButton(groupBox);
        add->setObjectName(QString::fromUtf8("add"));
        add->setStyleSheet(QString::fromUtf8(""));
        add->setAutoDefault(false);

        gridLayout_2->addWidget(add, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        P1 = new QComboBox(groupBox_2);
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->addItem(QString());
        P1->setObjectName(QString::fromUtf8("P1"));
        P1->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(P1, 0, 0, 1, 1);

        P2 = new QComboBox(groupBox_2);
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->addItem(QString());
        P2->setObjectName(QString::fromUtf8("P2"));
        P2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(P2, 0, 1, 1, 1);

        flagm = new QPushButton(groupBox_2);
        flagm->setObjectName(QString::fromUtf8("flagm"));
        flagm->setStyleSheet(QString::fromUtf8(""));
        flagm->setAutoDefault(false);

        gridLayout_3->addWidget(flagm, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dic = new QPlainTextEdit(tab_2);
        dic->setObjectName(QString::fromUtf8("dic"));
        dic->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
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

        verticalLayout_2->addWidget(dic);

        la = new QLabel(tab_2);
        la->setObjectName(QString::fromUtf8("la"));
        la->setStyleSheet(QString::fromUtf8("color: rgb(138, 226, 52);"));

        verticalLayout_2->addWidget(la);

        le = new QLabel(tab_2);
        le->setObjectName(QString::fromUtf8("le"));
        le->setStyleSheet(QString::fromUtf8("color: rgb(239, 41, 41);"));

        verticalLayout_2->addWidget(le);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Prset);

        tabWidget->setCurrentIndex(0);
        P2->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Prset);
    } // setupUi

    void retranslateUi(QDialog *Prset)
    {
        Prset->setWindowTitle(QCoreApplication::translate("Prset", "\351\241\271\347\233\256\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Prset", "\351\237\263\351\242\221\350\267\257\345\276\204", nullptr));
        remove->setText(QCoreApplication::translate("Prset", "\347\247\273\351\231\244", nullptr));
        add->setText(QCoreApplication::translate("Prset", "\346\267\273\345\212\240", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Prset", "\345\243\260\345\272\223\351\237\263\351\253\230", nullptr));
        P1->setItemText(0, QCoreApplication::translate("Prset", "C", nullptr));
        P1->setItemText(1, QCoreApplication::translate("Prset", "C#", nullptr));
        P1->setItemText(2, QCoreApplication::translate("Prset", "D", nullptr));
        P1->setItemText(3, QCoreApplication::translate("Prset", "D#", nullptr));
        P1->setItemText(4, QCoreApplication::translate("Prset", "E", nullptr));
        P1->setItemText(5, QCoreApplication::translate("Prset", "F", nullptr));
        P1->setItemText(6, QCoreApplication::translate("Prset", "F#", nullptr));
        P1->setItemText(7, QCoreApplication::translate("Prset", "G", nullptr));
        P1->setItemText(8, QCoreApplication::translate("Prset", "G#", nullptr));
        P1->setItemText(9, QCoreApplication::translate("Prset", "A", nullptr));
        P1->setItemText(10, QCoreApplication::translate("Prset", "A#", nullptr));
        P1->setItemText(11, QCoreApplication::translate("Prset", "B", nullptr));

        P2->setItemText(0, QCoreApplication::translate("Prset", "0", nullptr));
        P2->setItemText(1, QCoreApplication::translate("Prset", "1", nullptr));
        P2->setItemText(2, QCoreApplication::translate("Prset", "2", nullptr));
        P2->setItemText(3, QCoreApplication::translate("Prset", "3", nullptr));
        P2->setItemText(4, QCoreApplication::translate("Prset", "4", nullptr));
        P2->setItemText(5, QCoreApplication::translate("Prset", "5", nullptr));
        P2->setItemText(6, QCoreApplication::translate("Prset", "6", nullptr));
        P2->setItemText(7, QCoreApplication::translate("Prset", "7", nullptr));
        P2->setItemText(8, QCoreApplication::translate("Prset", "8", nullptr));
        P2->setItemText(9, QCoreApplication::translate("Prset", "9", nullptr));

        flagm->setText(QCoreApplication::translate("Prset", "\346\240\207\350\256\260\347\256\241\347\220\206\357\274\210\345\256\236\351\252\214\345\212\237\350\203\275\357\274\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Prset", "\351\241\271\347\233\256", nullptr));
        dic->setPlaceholderText(QCoreApplication::translate("Prset", "\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\345\255\227\345\205\270", nullptr));
        la->setText(QCoreApplication::translate("Prset", "\346\255\243\347\241\256", nullptr));
        le->setText(QCoreApplication::translate("Prset", "\351\224\231\350\257\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Prset", "\345\255\227\345\205\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Prset: public Ui_Prset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRSET_H
