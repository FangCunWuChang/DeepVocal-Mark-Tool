/********************************************************************************
** Form generated from reading UI file 'specplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECPLOT_H
#define UI_SPECPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Specplot
{
public:

    void setupUi(QWidget *Specplot)
    {
        if (Specplot->objectName().isEmpty())
            Specplot->setObjectName(QString::fromUtf8("Specplot"));
        Specplot->resize(400, 300);
        Specplot->setCursor(QCursor(Qt::BlankCursor));
        Specplot->setMouseTracking(true);

        retranslateUi(Specplot);

        QMetaObject::connectSlotsByName(Specplot);
    } // setupUi

    void retranslateUi(QWidget *Specplot)
    {
        Specplot->setWindowTitle(QCoreApplication::translate("Specplot", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Specplot: public Ui_Specplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECPLOT_H
