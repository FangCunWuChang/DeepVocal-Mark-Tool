/********************************************************************************
** Form generated from reading UI file 'waveview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEVIEW_H
#define UI_WAVEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Waveview
{
public:

    void setupUi(QWidget *Waveview)
    {
        if (Waveview->objectName().isEmpty())
            Waveview->setObjectName(QString::fromUtf8("Waveview"));
        Waveview->resize(400, 300);

        retranslateUi(Waveview);

        QMetaObject::connectSlotsByName(Waveview);
    } // setupUi

    void retranslateUi(QWidget *Waveview)
    {
        Waveview->setWindowTitle(QCoreApplication::translate("Waveview", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Waveview: public Ui_Waveview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEVIEW_H
