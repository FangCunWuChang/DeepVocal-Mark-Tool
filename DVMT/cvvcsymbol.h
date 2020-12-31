#ifndef CVVCSYMBOL_H
#define CVVCSYMBOL_H

#include <QString>

class CVVCSymbol
{
public:
    CVVCSymbol();
    QString name;
    bool isCV=true;
    double l1=0,l2=0,l3=0,l4=0;
    QString path;
    QString file;
    QString pitch="C4";
    QString mes="未标记";
    CVVCSymbol operator=(CVVCSymbol arg);
};

#endif // CVVCSYMBOL_H
