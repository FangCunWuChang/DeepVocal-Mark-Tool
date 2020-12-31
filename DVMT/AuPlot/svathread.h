#ifndef SVATHREAD_H
#define SVATHREAD_H

#include <QObject>
#include <QThread>
#include <QPixmap>
#include "pixtemp.h"

class SvaThread : public QThread
{
    Q_OBJECT
public:
    SvaThread();
    void setpix(PixTemp *pixtemp);
    void set(QString filepath,QPixmap wavepixv,QPixmap wavepixp,QPixmap specpix,QPixmap enepix,QPixmap rptzpix,QPixmap acfpix,QVector<double> v1,QVector<double> v2,QVector<double> v3,QVector<bool> v4);
private:
    PixTemp *PT=nullptr;
    QString filepath;QPixmap wavepixv;QPixmap wavepixp;QPixmap specpix;QPixmap enepix;QPixmap rptzpix;QPixmap acfpix;QVector<double> v1;QVector<double> v2;QVector<double> v3;QVector<bool> v4;
protected:
    void run() override;
signals:
    void num(int num);
};

#endif // SVATHREAD_H
