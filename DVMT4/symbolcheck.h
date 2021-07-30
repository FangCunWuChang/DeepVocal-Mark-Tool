#ifndef SYMBOLCHECK_H
#define SYMBOLCHECK_H

#include <QString>
#include <QStringList>
#include <QVector>
#include "cvvcsymbol.h"


class Symbolcheck
{
public:
    Symbolcheck();
    static bool check(QStringList in);
    static QString error(QStringList in);
    static QVector<CVVCSymbol> split(QStringList in);
};

#endif // SYMBOLCHECK_H
