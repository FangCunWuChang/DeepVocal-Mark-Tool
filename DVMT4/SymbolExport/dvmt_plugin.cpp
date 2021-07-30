#include "dvmt_plugin.h"

QString DVMT_PluInfo2()
{
    QJsonObject Infojson;
    Infojson.insert("Plugin Name","Export Symbol List");
    Infojson.insert("Plugin Info","导出项目文件中的Symbol List");
    Infojson.insert("Plugin Version",4.0);
    QJsonDocument jsondoc(Infojson);
    QString out=QString(jsondoc.toJson(QJsonDocument::Compact));
    return out;

}

PluginDialog* DVMT_PluRun2(QWidget* parent,Project* pro)
{
    return new PluginDialog(parent,pro);
}
