#include "anathread.h"

AnaThread::AnaThread() : QThread()
{

}

AnaThread::~AnaThread()
{
    if(this->isRunning()){
        this->terminate();
        this->wait();
    }
    this->rele();
}

void AnaThread::rele()
{
    wavetemp.clear();
    spectemp.clear();
    etemp.clear();
    rptztemp.clear();
    flagtemp.clear();
    for(int i=0;i<sublist.size();i++){
        if(((SubAna*)sublist.at(i))->isRunning()){
            ((SubAna*)sublist.at(i))->terminate();
            ((SubAna*)sublist.at(i))->wait();
        }
        delete (SubAna *)sublist.at(i);
    }
}

void AnaThread::run()
{
    emit lock();

    emit tip("等待分析...");

    emit tip("绘制波形...");

    sc=qFloor(((wavedataL.size()-global_sets::step)/(global_sets::step/global_sets::times)))+1;

    spectemp.resize(sc);
    etemp.resize(sc);
    rptztemp.resize(sc);
    flagtemp.resize(sc);

    qDebug("1");

    for(int i=0;i<global_sets::Threads;i++){
        SubAna *STptr=new SubAna;
        sublist.append(STptr);

    }


    qDebug("2");
    wavetemp=wavedataL;
    emit tip(QString::asprintf("帧分析(%d)...",sc));
    qDebug("3");
    for(int i=0;i<sc;i++){
        //截取:part
        QVector<double> part;
        for(int j=0;j<global_sets::step;j++){
            part.append(wavedataL.at(i*global_sets::step/global_sets::times+j));
        }

        int stid=i%global_sets::Threads;

        ((SubAna*)sublist.at(stid))->parts.enqueue(part);

    }

    for(int i=0;i<sublist.size();i++){
        ((SubAna*)sublist.at(i))->start();

    }

    qDebug("4");

    int nsum=0;

    do{
        nsum=0;
        for(int i=0;i<sublist.size();i++){
            nsum+=((SubAna*)sublist.at(i))->flag.size();
        }
        emit tip(QString::asprintf("帧分析(%d/%d)...",nsum,sc));
        QCoreApplication::processEvents();
    }while(nsum<sc);

    qDebug("5");

    for(int i=0;i<sc;i++){
        int stid=i%global_sets::Threads;
        spectemp.replace(i,((SubAna*)sublist.at(stid))->spec.dequeue());
        etemp.replace(i,((SubAna*)sublist.at(stid))->ene.dequeue());
        rptztemp.replace(i,((SubAna*)sublist.at(stid))->rptz.dequeue());
        flagtemp.replace(i,((SubAna*)sublist.at(stid))->flag.dequeue());
    }

    wavedataL.clear();
    wavedataR.clear();

    for(int i=0;i<sublist.size();i++){
        SubAna *STptr=(SubAna*)sublist.at(i);
        delete STptr;
    }
    sublist.clear();

    qDebug("6");


    emit tip("绘制图像...");
    qDebug("wavetemp:%lld",wavetemp.size());
    qDebug("spectemp:%lld",spectemp.size());
    //qDebug("actemp:%lld",actemp.size());
    qDebug("etemp:%lld",etemp.size());
    qDebug("rptztemp:%lld",rptztemp.size());
    qDebug("flagtemp:%lld",flagtemp.size());

    emit out(wavetemp,wavetemp,spectemp,etemp,rptztemp,flagtemp,true);

    wavetemp.clear();
    spectemp.clear();
    etemp.clear();
    rptztemp.clear();
    flagtemp.clear();

    emit tip("完成!");

    emit unlock();
}

void AnaThread::setwave(QWaveHandle *wave)
{
    this->wavedataL=*wave->wavedataL;
    this->wavedataR=*wave->wavedataR;
    this->samplespersec=wave->samplespersec;
}

QColor AnaThread::getcolor(double v)
{
    const double vii = (v-global_sets::m_minBound)/(global_sets::m_maxBound-global_sets::m_minBound);
    int red = 0,green = 0,blue = 0;
    if (vii>=0 && vii<0.25)
    {
        blue = vii/0.25*255;

    }

    else if (vii>=0.25 && vii<0.5 )
    {
            blue = (0.5-vii)/0.25*255;
            red =  (vii-0.25)/0.25*255;
    }
    else if (vii>=0.5 && vii<0.75 )
    {
            red =  255;
            green = (vii-0.5)/0.25*255;
    }
    else if (vii>=0.75 && vii<1)
    {
            red = 255;
            green = 255;
            blue =  (vii-0.75)/0.25*255;
    }
    else if (vii>=1)
            red = 255, blue = 255, green = 255;
    return QColor(red,green,blue);
}
