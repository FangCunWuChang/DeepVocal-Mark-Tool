#include "dvmt_plugin.h"

QString* DVMT_PluInfo2()
{
    QJsonObject Infojson;
    Infojson.insert("Plugin Name","pluginsample1");
    Infojson.insert("Plugin Info","This is a sample plugin!");
    Infojson.insert("Plugin Version",4.0);
    QJsonDocument jsondoc(Infojson);
    QString* out=new QString(jsondoc.toJson(QJsonDocument::Compact));
    return out;

}

PluginDialog* DVMT_PluRun2(QWidget* parent,Project* pro)
{
    return new PluginDialog(parent,pro);
}
