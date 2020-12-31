#ifndef LOATHREAD_H
#define LOATHREAD_H

#include <QObject>
#include <QThread>
#include <QPixmap>
#include "pixtemp.h"

class LoaThread : public QThread
{
    Q_OBJECT
public:
    LoaThread();
    void setfilepath(QString filepath);
    void setPT(PixTemp *PT);
private:
    QString filepath;
    PixTemp *PT=nullptr;
protected:
    void run() override;
signals:
    void lock();
    void unlock();
    void out(QPixmap wavepixv,QPixmap wavepixp,QPixmap specpix,QPixmap enepix,QPixmap rptzpix,QPixmap acfpix,QVector<double> v1,QVector<double> v2,QVector<double> v3,QVector<bool> v4,bool save=true);
    void tip(QString message);
};

#endif // LOATHREAD_H
