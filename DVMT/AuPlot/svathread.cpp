#include "svathread.h"

SvaThread::SvaThread() : QThread()
{

}

void SvaThread::run()
{
    if(PT!=nullptr){
        emit num(0);
        PT->write(filepath,0,wavepixv);
        emit num(30);
        PT->write(filepath,1,wavepixp);
        emit num(60);
        PT->write2(filepath,2,specpix);
        emit num(90);
        PT->writev(filepath,"ene",v1);
        emit num(92);
        PT->writev(filepath,"rptz",v2);
        emit num(94);
        PT->writev(filepath,"acf",v3);
        emit num(96);
        PT->writeb(filepath,"flag",v4);
        emit num(98);
        PT->savemd5(filepath);
        emit num(100);
    }
}

void SvaThread::set(QString filepath,QVector<double> wavepixv,QVector<double> wavepixp,QVector<QVector<double>> specpix,QVector<double> v1,QVector<double> v2,QVector<double> v3,QVector<bool> v4)
{
    this->filepath=filepath;
    this->v1=v1;
    this->v2=v2;
    this->v3=v3;
    this->v4=v4;
    this->specpix=specpix;
    this->wavepixp=wavepixp;
    this->wavepixv=wavepixv;
}

void SvaThread::setpix(PixTemp *pixtemp)
{
    this->PT=pixtemp;
}
