#ifndef LOATHREAD_H
#define LOATHREAD_H

#include <QObject>
#include <QThread>
#include <QImage>
#include "pixtemp.h"

class LoaThread : public QThread
{
    Q_OBJECT
public:
    LoaThread();
    ~LoaThread();
    void setfilepath(QString filepath);
    void setPT(PixTemp *PT);
    void rele();
private:
    QString filepath;
    PixTemp *PT=nullptr;
protected:
    void run() override;
signals:
    void lock();
    void unlock();
    void out(QVector<double> wavepixv,QVector<double> wavepixp,QVector<QVector<double>> specpix,QVector<double> v1,QVector<double> v2,QVector<double> v3,QVector<bool> v4,bool save=true);
    void tip(QString message);
};

#endif // LOATHREAD_H
