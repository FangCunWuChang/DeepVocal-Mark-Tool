/********************************************************************************
** Form generated from reading UI file 'waveplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEPLOT_H
#define UI_WAVEPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Waveplot
{
public:

    void setupUi(QWidget *Waveplot)
    {
        if (Waveplot->objectName().isEmpty())
            Waveplot->setObjectName(QString::fromUtf8("Waveplot"));
        Waveplot->resize(400, 300);
        Waveplot->setCursor(QCursor(Qt::BlankCursor));
        Waveplot->setMouseTracking(true);

        retranslateUi(Waveplot);

        QMetaObject::connectSlotsByName(Waveplot);
    } // setupUi

    void retranslateUi(QWidget *Waveplot)
    {
        Waveplot->setWindowTitle(QCoreApplication::translate("Waveplot", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Waveplot: public Ui_Waveplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEPLOT_H
