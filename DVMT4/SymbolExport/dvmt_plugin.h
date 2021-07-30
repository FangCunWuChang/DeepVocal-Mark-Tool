#ifndef DVMT_PLUGIN_H
#define DVMT_PLUGIN_H

#include "DVMT_Plugin_global.h"
#include "plugindialog.h"
#include <QString>
#include <QWidget>
#include "project.h"

extern "C" QString* DVMT_PLUGIN_EXPORT DVMT_PluInfo2();
extern "C" PluginDialog* DVMT_PLUGIN_EXPORT DVMT_PluRun2(QWidget* parent,Project* pro);

#endif // DVMT_PLUGIN_H
