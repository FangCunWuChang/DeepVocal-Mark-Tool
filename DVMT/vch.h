#ifndef VCH_H
#define VCH_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "cvvcsymbol.h"
#include "AuPlot/qwavehandle.h"
#include <QDateTime>

class VCH
{
public:
    VCH();
    static bool get(CVVCSymbol *symbol);
    static bool set(CVVCSymbol *symbol);
    static bool remove(CVVCSymbol *symbol);
    static bool get(CVVCSymbol *symbol,QString path);
};

#endif // VCH_H
