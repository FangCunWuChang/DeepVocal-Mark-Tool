#ifndef ANATHREAD_H
#define ANATHREAD_H

#include <QObject>
#include <QThread>
#include "qwavehandle.h"
#include <QImage>
#include <QPainter>
#include "aumathlib.h"
#include <QVector2D>
#include "iplot.h"
#include "global.h"
#include <QWidget>
#include "autoimg.h"
#include "subana.h"
#include <QMutex>
#include <QCoreApplication>




class AnaThread : public QThread
{
    Q_OBJECT
public:
    AnaThread();
    ~AnaThread();
    void setwave(QWaveHandle *wave);
    void rele();
protected:
    void run() override;
private:
    qint32 samplespersec=44100;

    QVector<qreal> wavedataL;
    QVector<qreal> wavedataR;
    QColor getcolor(double v);

    QVector<QVector<double>> spectemp;//频谱
    QVector<double> wavetemp;//波形
    QVector<double> etemp;//短时能量曲线
    QVector<double> rptztemp;//短时过零率曲线
    QVector<bool> flagtemp;//发音位置

    int sc=0;
    QObjectList sublist;

signals:
    void lock();
    void unlock();
    void out(QVector<double> wavepixv,QVector<double> wavepixp,QVector<QVector<double>> specpix,QVector<double> v1,QVector<double> v2,QVector<bool> v4,bool save=true);
    void tip(QString message);
private slots:
};

#endif // ANATHREAD_H
