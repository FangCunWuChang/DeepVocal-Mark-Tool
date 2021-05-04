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
#include "AuPlot/qwaveinfo.h"
#include <QDateTime>
#include <QVariantMap>
#include "dvsym.h"

class VCH
{
public:
    VCH();
    static bool get(CVVCSymbol *symbol);
    static bool set(CVVCSymbol *symbol);
    static bool set(DVSym *symbol);
    static bool remove(CVVCSymbol *symbol);
    static bool remove(DVSym *symbol);
    static bool get(CVVCSymbol *symbol,QString path);
    static bool have(DVSym *symbol,QString path);
    static bool getall(QVector<DVSym> *symbollist,QString path);
    static bool removepit(QString path,QString pit="C4");
};

#endif // VCH_H
