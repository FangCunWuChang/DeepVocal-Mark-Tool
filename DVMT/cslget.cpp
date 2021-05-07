#include "cslget.h"

CSLget::CSLget() : QThread()
{

}

CSLget::~CSLget()
{
    if(this->isRunning()){
        this->terminate();
        this->wait();
    }
}

void CSLget::run()
{
    stopflag=false;
    for(int i=0;i<list.size();i++){
        CVVCSymbol CVST=list.at(i);
        CVST.pitch=pitch;
        int cou=0;
        for(int j=psl.size()-1;j>=0;j--){
            if(VCH::get(&CVST,psl.at(j))){
                QString wavurl=CVST.path+"/"+CVST.file;
                if(QWaveInfo::checkwav(wavurl,1,44100,16,2*global_sets::perp,global_sets::maxlength)){
                   cou++;
                }
            }
        }
        if(cou==1){
            CVST.mes="正确";
        }else if(cou==0){
            CVST.mes="未标记";
        }else{
            CVST.mes="标记重复，请检查标记或重新标记";
        }
        if(stopflag){
            stopflag=false;
            break;
        }
        emit append(CVST,i==list.size()-1);
    }
    quit();
    return;
}

void CSLget::setlist(QVector<CVVCSymbol> list,QString pitch,QStringList psl)
{
    if(this->isRunning()){
        this->terminate();
        this->wait();
    }
    stopflag=false;
    this->list.clear();
    this->pitch=pitch;
    this->psl=psl;
    this->list=list;
}
