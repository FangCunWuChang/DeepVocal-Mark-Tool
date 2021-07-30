/********************************************************************************
** Form generated from reading UI file 'auplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUPLOT_H
#define UI_AUPLOT_H

#include <AuPlot/specplot.h>
#include <AuPlot/stip.h>
#include <AuPlot/toolbuttons.h>
#include <AuPlot/waveplot.h>
#include <AuPlot/waveview.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuPlot
{
public:
    Waveview *waveview;
    ToolButtons *tool;
    QSplitter *splitter;
    Waveplot *waveplot;
    Specplot *specplot;
    STip *stip;

    void setupUi(QWidget *AuPlot)
    {
        if (AuPlot->objectName().isEmpty())
            AuPlot->setObjectName(QString::fromUtf8("AuPlot"));
        AuPlot->resize(800, 600);
        AuPlot->setStyleSheet(QString::fromUtf8("background-color: rgb(31,31,31);"));
        waveview = new Waveview(AuPlot);
        waveview->setObjectName(QString::fromUtf8("waveview"));
        waveview->setGeometry(QRect(0, 70, 791, 80));
        waveview->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));
        tool = new ToolButtons(AuPlot);
        tool->setObjectName(QString::fromUtf8("tool"));
        tool->setGeometry(QRect(0, 0, 791, 61));
        tool->setAutoFillBackground(false);
        tool->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	\n"
"	background-color: rgb(31,31,31);\n"
"}\n"
"QToolTip{\n"
"\n"
"background-color:rgb(31,31,31);\n"
"color: rgb(214,236,240);\n"
"border:1px solid rgb(22,24,35);\n"
"}"));
        splitter = new QSplitter(AuPlot);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(0, 160, 801, 421));
        splitter->setStyleSheet(QString::fromUtf8("background-color: rgb(31,31,31);"));
        splitter->setOrientation(Qt::Vertical);
        waveplot = new Waveplot(splitter);
        waveplot->setObjectName(QString::fromUtf8("waveplot"));
        waveplot->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 74, 135);"));
        splitter->addWidget(waveplot);
        specplot = new Specplot(splitter);
        specplot->setObjectName(QString::fromUtf8("specplot"));
        specplot->setStyleSheet(QString::fromUtf8("background-color: rgb(31,31,31);"));
        splitter->addWidget(specplot);
        stip = new STip(AuPlot);
        stip->setObjectName(QString::fromUtf8("stip"));
        stip->setGeometry(QRect(450, 60, 120, 80));

        retranslateUi(AuPlot);

        QMetaObject::connectSlotsByName(AuPlot);
    } // setupUi

    void retranslateUi(QWidget *AuPlot)
    {
        AuPlot->setWindowTitle(QCoreApplication::translate("AuPlot", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuPlot: public Ui_AuPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUPLOT_H
