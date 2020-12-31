#ifndef PIXTEMP_H
#define PIXTEMP_H

#include <QObject>
#include <QPixmap>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariantMap>
#include "global.h"
#include <QCryptographicHash>
using namespace global;

class PixTemp
{
public:
    PixTemp();
    ~PixTemp();
    bool check(QString name);
    void write(QString name,int num,QPixmap data);
    QPixmap read(QString name,int num);
    QVector<double> readv(QString name,QString vname);
    void writev(QString name,QString vname,QVector<double> data);
    QVector<bool> readb(QString name,QString vname);
    void writeb(QString name,QString vname,QVector<bool> data);
    void clear();
    bool checkmd5(QString name);
    void savemd5(QString name);
private:
    int countid=0;

};

#endif // PIXTEMP_H
