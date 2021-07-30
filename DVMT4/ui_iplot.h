/********************************************************************************
** Form generated from reading UI file 'iplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPLOT_H
#define UI_IPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IPlot
{
public:

    void setupUi(QWidget *IPlot)
    {
        if (IPlot->objectName().isEmpty())
            IPlot->setObjectName(QString::fromUtf8("IPlot"));
        IPlot->resize(400, 300);

        retranslateUi(IPlot);

        QMetaObject::connectSlotsByName(IPlot);
    } // setupUi

    void retranslateUi(QWidget *IPlot)
    {
        IPlot->setWindowTitle(QCoreApplication::translate("IPlot", "IPlot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IPlot: public Ui_IPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPLOT_H
