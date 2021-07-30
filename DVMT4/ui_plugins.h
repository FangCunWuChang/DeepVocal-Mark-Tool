/********************************************************************************
** Form generated from reading UI file 'plugins.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINS_H
#define UI_PLUGINS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Plugins
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *plul;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPlainTextEdit *about;
    QPushButton *okb;

    void setupUi(QDialog *Plugins)
    {
        if (Plugins->objectName().isEmpty())
            Plugins->setObjectName(QString::fromUtf8("Plugins"));
        Plugins->resize(550, 336);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        Plugins->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imag/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Plugins->setWindowIcon(icon);
        Plugins->setStyleSheet(QString::fromUtf8("background-color: rgb(31,31,31);"));
        formLayout = new QFormLayout(Plugins);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(Plugins);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        plul = new QComboBox(Plugins);
        plul->setObjectName(QString::fromUtf8("plul"));

        formLayout->setWidget(0, QFormLayout::FieldRole, plul);

        groupBox = new QGroupBox(Plugins);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        about = new QPlainTextEdit(groupBox);
        about->setObjectName(QString::fromUtf8("about"));
        about->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        about->setReadOnly(true);

        gridLayout->addWidget(about, 0, 0, 1, 1);


        formLayout->setWidget(1, QFormLayout::SpanningRole, groupBox);

        okb = new QPushButton(Plugins);
        okb->setObjectName(QString::fromUtf8("okb"));

        formLayout->setWidget(2, QFormLayout::SpanningRole, okb);


        retranslateUi(Plugins);

        plul->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Plugins);
    } // setupUi

    void retranslateUi(QDialog *Plugins)
    {
        Plugins->setWindowTitle(QCoreApplication::translate("Plugins", "\346\217\222\344\273\266\345\210\227\350\241\250", nullptr));
        label->setText(QCoreApplication::translate("Plugins", "\346\217\222\344\273\266\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Plugins", "\346\217\222\344\273\266\344\277\241\346\201\257", nullptr));
        about->setPlaceholderText(QCoreApplication::translate("Plugins", "\345\234\250\345\210\227\350\241\250\344\270\255\351\200\211\346\213\251\344\270\200\344\270\252\346\217\222\344\273\266", nullptr));
        okb->setText(QCoreApplication::translate("Plugins", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Plugins: public Ui_Plugins {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINS_H
