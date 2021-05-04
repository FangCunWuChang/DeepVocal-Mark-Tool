#include "loathread.h"

LoaThread::LoaThread()
{

}

LoaThread::~LoaThread()
{
    this->rele();
}

void LoaThread::rele()
{

}

void LoaThread::run()
{
    if(PT!=nullptr){
        if(!filepath.isEmpty()){
            emit tip("载入缓存...");
            emit lock();
            //qDebug("get1");
            QVector<double> p1=PT->read(filepath,0);
            //qDebug("get2");
            QVector<double> p2=PT->read(filepath,1);
            //qDebug("get3");
            QVector<QVector<double>> p3=PT->read2(filepath,2);
            //qDebug("get4");
            //qDebug("get5");
            QVector<double> v1=PT->readv(filepath,"ene");
            //qDebug("get6");
            QVector<double> v2=PT->readv(filepath,"rptz");
            //qDebug("get7");
            QVector<double> v3=PT->readv(filepath,"acf");
            //qDebug("get8");
            QVector<bool> b1=PT->readb(filepath,"flag");
            //qDebug("get9");
            emit out(p1,p2,p3,v1,v2,v3,b1,false);
            emit tip("完成!");
            //qDebug("get10");
            emit unlock();
        }
    }

}

void LoaThread::setfilepath(QString filepath)
{
    this->filepath=filepath;
}

void LoaThread::setPT(PixTemp *PT)
{
    this->PT=PT;
}
