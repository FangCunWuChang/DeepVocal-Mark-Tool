#include "loathread.h"

LoaThread::LoaThread()
{

}

void LoaThread::run()
{
    if(PT!=nullptr){
        if(!filepath.isEmpty()){
            emit tip("载入缓存...");
            emit lock();
            emit out(PT->read(filepath,0),PT->read(filepath,1),PT->read(filepath,2),PT->read(filepath,3),PT->read(filepath,4),PT->read(filepath,5),PT->readv(filepath,"ene"),PT->readv(filepath,"rptz"),PT->readv(filepath,"acf"),PT->readb(filepath,"flag"),false);
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
