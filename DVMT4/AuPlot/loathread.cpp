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
            QVector<double> p1=PT->read(filepath,0);
            QVector<double> p2=PT->read(filepath,1);
            QVector<QVector<double>> p3=PT->read2(filepath,2);
            QVector<double> v1=PT->readv(filepath,"ene");
            QVector<double> v2=PT->readv(filepath,"rptz");
            QVector<bool> b1=PT->readb(filepath,"flag");
            emit out(p1,p2,p3,v1,v2,b1,false);
            emit tip("完成!");
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
