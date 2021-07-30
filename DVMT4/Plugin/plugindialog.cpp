#include "plugindialog.h"
#include "ui_plugindialog.h"

PluginDialog::PluginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PluginDialog)
{
    ui->setupUi(this);
}

PluginDialog::PluginDialog(QWidget *parent,Project *pro):
    QDialog(parent),
    ui(new Ui::PluginDialog),
    project(pro)
{
    ui->setupUi(this);
}

PluginDialog::~PluginDialog()
{
    delete ui;
}

