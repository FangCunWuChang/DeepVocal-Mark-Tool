#ifndef DVMT_PLUGIN_H
#define DVMT_PLUGIN_H

#include "DVMT_plugin_global.h"
#include <QDialog>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class DVMT_plugin;
}

class DVMT_PLUGIN_EXPORT DVMT_plugin : public QDialog
{
    Q_OBJECT

public:
    explicit DVMT_plugin(QWidget *parent = nullptr);
    ~DVMT_plugin();

private:
    Ui::DVMT_plugin *ui;
};

extern "C" QString DVMT_PLUGIN_EXPORT DVMT_PluInfo();
extern "C" QDialog* DVMT_PLUGIN_EXPORT DVMT_PluRun(QWidget *parent);

#endif // DVMT_PLUGIN_H
