/********************************************************************************
** Form generated from reading UI file 'egg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EGG_H
#define UI_EGG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Egg
{
public:
    QLineEdit *line;

    void setupUi(QWidget *Egg)
    {
        if (Egg->objectName().isEmpty())
            Egg->setObjectName(QString::fromUtf8("Egg"));
        Egg->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Egg->setWindowIcon(icon);
        Egg->setStyleSheet(QString::fromUtf8("QToolTip{\n"
"\n"
"background-color:rgb(31,31,31);\n"
"color: rgb(211, 215, 207);\n"
"border:1px solid rgb(31,31,31);\n"
"}\n"
"\n"
"QWidget{\n"
"	background-color: rgb(31,31,31);\n"
"	color: rgb(211, 215, 207);\n"
"}"));
        line = new QLineEdit(Egg);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(50, 20, 331, 25));

        retranslateUi(Egg);

        QMetaObject::connectSlotsByName(Egg);
    } // setupUi

    void retranslateUi(QWidget *Egg)
    {
        Egg->setWindowTitle(QCoreApplication::translate("Egg", "\345\275\251\350\233\213", nullptr));
        line->setPlaceholderText(QCoreApplication::translate("Egg", "\345\234\250\350\277\231\351\207\214\350\276\223\345\205\245\344\272\233\344\273\200\344\271\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Egg: public Ui_Egg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EGG_H
