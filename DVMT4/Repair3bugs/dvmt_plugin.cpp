#include "dvmt_plugin.h"

QString* DVMT_PluInfo2()
{
    QJsonObject Infojson;
    Infojson.insert("Plugin Name","Repair3bugs");
    Infojson.insert("Plugin Info","修复DVMT3生成的dvcfg中的bug");
    Infojson.insert("Plugin Version",4.0);
    QJsonDocument jsondoc(Infojson);
    QString* out=new QString(jsondoc.toJson(QJsonDocument::Compact));
    return out;

}

PluginDialog* DVMT_PluRun2(QWidget* parent,Project* pro)
{
    return new PluginDialog(parent,pro);
}
