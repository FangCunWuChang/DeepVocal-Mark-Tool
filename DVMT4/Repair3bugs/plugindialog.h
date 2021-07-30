#ifndef PLUGINDIALOG_H
#define PLUGINDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include "project.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include "vch.h"

namespace Ui {
class PluginDialog;
}

class PluginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PluginDialog(QWidget *parent = nullptr);
    explicit PluginDialog(QWidget *parent,Project *pro);
    ~PluginDialog();

private slots:
    void on_repair_clicked();

private:
    Ui::PluginDialog *ui;
    Project *project=nullptr;
};

#endif // PLUGINDIALOG_H
