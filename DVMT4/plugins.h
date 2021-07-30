#ifndef PLUGINS_H
#define PLUGINS_H

#include <QDialog>
#include <QLibrary>
#include <QCoreApplication>
#include <QDir>
#include <QJsonDocument>
#include <QMessageBox>
#include "project.h"
#include "Version.h"
#include "Plugin/plugindialog.h"

namespace Ui {
class Plugins;
}

typedef QString*(*pluiF)();
typedef PluginDialog*(*pluoF)(QWidget*,Project*);

class Plugins : public QDialog
{
    Q_OBJECT

public:
    explicit Plugins(QWidget *parent = nullptr);
    ~Plugins();
    void setPro(Project *pro);
    void checkplugins();
    QStringList pluginurllist;
    QStringList pluginlist;
    QStringList plugininfolist;
    void openplugin(int id);

private slots:
    void on_plul_currentIndexChanged(int index);

    void on_okb_clicked();

private:
    Ui::Plugins *ui;
    Project *pro=nullptr;
signals:
    void prochanged(Project pro,bool pitref=false);
};

#endif // PLUGINS_H
