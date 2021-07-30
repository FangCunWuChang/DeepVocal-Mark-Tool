#include "mulcslget.h"

MulCSLget::MulCSLget() : QThread()
{

}

MulCSLget::~MulCSLget()
{
    if(this->isRunning()){
        this->terminate();
        this->wait();
    }
}

void MulCSLget::run()
{
    QVector<DVSym> maincstl;
    for(int i=0;i<psl.size();i++){
        VCH::getall(&maincstl,psl.at(i));
    }
    QVector<QVector<DVSym>> cstl;
    for(int k=0;k<120;k++){
        QString pit="C4";
        int pnc=qFloor((double)((double)k/(double)12));
        switch (k%12) {
        case 0:
            pit=QString::asprintf("C%d",pnc);
            break;
        case 1:
            pit=QString::asprintf("C#%d",pnc);
            break;
        case 2:
            pit=QString::asprintf("D%d",pnc);
            break;
        case 3:
            pit=QString::asprintf("D#%d",pnc);
            break;
        case 4:
            pit=QString::asprintf("E%d",pnc);
            break;
        case 5:
            pit=QString::asprintf("F%d",pnc);
            break;
        case 6:
            pit=QString::asprintf("F#%d",pnc);
            break;
        case 7:
            pit=QString::asprintf("G%d",pnc);
            break;
        case 8:
            pit=QString::asprintf("G#%d",pnc);
            break;
        case 9:
            pit=QString::asprintf("A%d",pnc);
            break;
        case 10:
            pit=QString::asprintf("A#%d",pnc);
            break;
        case 11:
            pit=QString::asprintf("B%d",pnc);
            break;
        default:
            pit="C4";
            break;
        }
        QVector<DVSym> subcstl;
        for(int i=0;i<maincstl.size();){
            if(maincstl.at(i).pitch==pit){
                subcstl.append(maincstl.at(i));
                maincstl.remove(i);
            }else{
                i++;
            }
        }
        cstl.append(subcstl);
    }
    emit append(cstl);
    quit();
    return;
}

void MulCSLget::setlist(QStringList psl)
{
    if(this->isRunning()){
        this->terminate();
        this->wait();
    }
    this->psl=psl;
}
