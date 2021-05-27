#ifndef DVSYM_H
#define DVSYM_H

#include <QString>
#include <QDateTime>

class DVSym
{
public:
    DVSym();
    QString symbol;
    QString pitch="C4";
    QString srcType="CV";
    QString path;
    QString wavName;
    QDateTime updateTime=QDateTime::currentDateTime();
    double connectPoint=0.06;
    double preutterance=0;
    double startTime=0;
    double startPoint=0.06;
    double endTime=0;
    double endPoint=0;
    double tailPoint=0;
    double vowelStart=0;
    double vowelEnd=0;
    DVSym operator=(DVSym arg);
};

#endif // DVSYM_H
