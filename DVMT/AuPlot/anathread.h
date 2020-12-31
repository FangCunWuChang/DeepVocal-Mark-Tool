#ifndef ANATHREAD_H
#define ANATHREAD_H

#include <QObject>
#include <QThread>
#include "qwavehandle.h"
#include <QPixmap>
#include <QPainter>
#include "aumathlib.h"
#include <QVector2D>
#include "iplot.h"
#include "global.h"
#include <QWidget>

using namespace global;


class AnaThread : public QThread
{
    Q_OBJECT
public:
    AnaThread();
    void setwave(QWaveHandle *wave);
protected:
    void run() override;
private:
    qint32 samplespersec=44100;

    QVector<qreal> wavedataL;
    QVector<qreal> wavedataR;
    QColor getcolor(double v);
    QColor getacfcolor(double x,double max=0,double min=-70);
    QColor getacfcolor2(double x,double max=0,double min=-80);


signals:
    void lock();
    void unlock();
    void out(QPixmap wavepixv,QPixmap wavepixp,QPixmap specpix,QPixmap enepix,QPixmap rptzpix,QPixmap acfpix,QVector<double> v1,QVector<double> v2,QVector<double> v3,QVector<bool> v4,bool save=true);
    void tip(QString message);
};

#endif // ANATHREAD_H
