#ifndef PIXTEMP_H
#define PIXTEMP_H

#include <QObject>
#include <QImage>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariantMap>
#include "global.h"
#include <QCryptographicHash>
#include "autoimg.h"


class PixTemp
{
public:
    PixTemp();
    ~PixTemp();
    bool check(QString name);
    void write2(QString name,int num,QVector<QVector<double>> data);
    QVector<QVector<double>> read2(QString name,int num);
    void write(QString name,int num,QVector<double> data);
    QVector<double> read(QString name,int num);
    QVector<double> readv(QString name,QString vname);
    void writev(QString name,QString vname,QVector<double> data);
    QVector<bool> readb(QString name,QString vname);
    void writeb(QString name,QString vname,QVector<bool> data);
    void clear();
    bool checkmd5(QString name);
    void savemd5(QString name);
    bool WQV(QVector<double> *data,QString file);
    bool RQV(QVector<double> *data,QString file);
    bool WQB(QVector<bool> *data,QString file);
    bool RQB(QVector<bool> *data,QString file);
    bool WQV2(QVector<QVector<double>> *data,QString file);
    bool RQV2(QVector<QVector<double>> *data,QString file);
    double size();
private:
    int countid=0;

};

#endif // PIXTEMP_H
