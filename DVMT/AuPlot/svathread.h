#ifndef SVATHREAD_H
#define SVATHREAD_H

#include <QObject>
#include <QThread>
#include <QImage>
#include "pixtemp.h"

class SvaThread : public QThread
{
    Q_OBJECT
public:
    SvaThread();
    void setpix(PixTemp *pixtemp);
    void set(QString filepath,QVector<double> wavepixv,QVector<double> wavepixp,QVector<QVector<double>> acfpix,QVector<double> v1,QVector<double> v2,QVector<double> v3,QVector<bool> v4);
private:
    PixTemp *PT=nullptr;
    QString filepath;QVector<double> wavepixv;QVector<double> wavepixp;QVector<QVector<double>> specpix;QVector<double> v1;QVector<double> v2;QVector<double> v3;QVector<bool> v4;
protected:
    void run() override;
signals:
    void num(int num);
};

#endif // SVATHREAD_H
