#include "dvmt_plugin.h"
#include "ui_dvmt_plugin.h"

DVMT_plugin::DVMT_plugin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DVMT_plugin)
{
    ui->setupUi(this);
}

DVMT_plugin::~DVMT_plugin()
{
    delete ui;
}

QString DVMT_PluInfo()
{
    QJsonObject Infojson;
    Infojson.insert("Plugin Name","pluginsample1");
    Infojson.insert("Plugin Info","This is a sample plugin!");
    QJsonDocument jsondoc(Infojson);
    return QString(jsondoc.toJson(QJsonDocument::Compact));
}

QDialog* DVMT_PluRun(QWidget *parent)
{
    return new DVMT_plugin(parent);
}
