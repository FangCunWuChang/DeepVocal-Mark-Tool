/********************************************************************************
** Form generated from reading UI file 'lockdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCKDIALOG_H
#define UI_LOCKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LockDialog
{
public:
    QLabel *label;

    void setupUi(QWidget *LockDialog)
    {
        if (LockDialog->objectName().isEmpty())
            LockDialog->setObjectName(QString::fromUtf8("LockDialog"));
        LockDialog->resize(400, 200);
        LockDialog->setMinimumSize(QSize(0, 0));
        LockDialog->setMaximumSize(QSize(16777215, 16777215));
        LockDialog->setStyleSheet(QString::fromUtf8("background-color: rgba(31,31,31,200);"));
        label = new QLabel(LockDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-1, -1, 401, 201));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(214,236,240);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(LockDialog);

        QMetaObject::connectSlotsByName(LockDialog);
    } // setupUi

    void retranslateUi(QWidget *LockDialog)
    {
        LockDialog->setWindowTitle(QCoreApplication::translate("LockDialog", "Lock", nullptr));
        label->setText(QCoreApplication::translate("LockDialog", "\345\256\214\346\210\220\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LockDialog: public Ui_LockDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCKDIALOG_H
