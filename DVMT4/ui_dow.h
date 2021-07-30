/********************************************************************************
** Form generated from reading UI file 'dow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOW_H
#define UI_DOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoW
{
public:

    void setupUi(QWidget *DoW)
    {
        if (DoW->objectName().isEmpty())
            DoW->setObjectName(QString::fromUtf8("DoW"));
        DoW->resize(400, 300);

        retranslateUi(DoW);

        QMetaObject::connectSlotsByName(DoW);
    } // setupUi

    void retranslateUi(QWidget *DoW)
    {
        DoW->setWindowTitle(QCoreApplication::translate("DoW", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoW: public Ui_DoW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOW_H
