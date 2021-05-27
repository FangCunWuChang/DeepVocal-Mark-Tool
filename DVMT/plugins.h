#ifndef PLUGINS_H
#define PLUGINS_H

#include <QDialog>
#include <QLibrary>
#include <QCoreApplication>
#include <QDir>
#include <QJsonDocument>
#include <QMessageBox>

namespace Ui {
class Plugins;
}

class Plugins : public QDialog
{
    Q_OBJECT

public:
    explicit Plugins(QWidget *parent = nullptr);
    ~Plugins();

private slots:
    void on_plul_currentIndexChanged(int index);

    void on_okb_clicked();

private:
    Ui::Plugins *ui;
    QStringList pluginurllist;
    QStringList pluginlist;
    QStringList plugininfolist;
    void checkplugins();
    void openplugin(int id);
};

#endif // PLUGINS_H
