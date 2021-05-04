#include "copthread.h"

CopThread::CopThread() : QThread()
{

}

CopThread::~CopThread()
{

}

void CopThread::run()
{
    bool yestoall=0;
    for(int i=0;i<slist.size();i++){
        emit percent((double)((double)i/(double)slist.size()));
        //qDebug("percent%d 0",i);
        QCoreApplication::processEvents();
        DVSym dvst;
        try{
            dvst=slist.at(i);
        }catch(...){
            qDebug("at error in round %d",i);
        }
        QString pathn=dvst.path;
        dvst.path=path;
        dvst.pitch=pit;
        //qDebug("change%d 0",i);
        bool yesthis=true;
        if(VCH::have(&dvst,path)){
            //qDebug("have%d 0",i);
            if(yestoall==0){
                //QMessageBox::StandardButton result=QMessageBox::warning(parent,"重复的标记","在路径\n"+path+"\n中已存在"+pit+"音阶的采样\""+dvst.symbol+"\"\n是否要覆盖？",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::YesToAll|QMessageBox::NoToAll|QMessageBox::Cancel),QMessageBox::Cancel);
                wannaflagchange(path,pit,dvst.symbol,pathn);
                if(result==QMessageBox::Cancel){
                    break;
                }else{
                    if(result==QMessageBox::YesToAll){
                        yestoall=1;
                        yesthis=true;
                    }else if(result==QMessageBox::Yes){
                        yesthis=true;
                    }else if(result==QMessageBox::NoToAll){
                        yestoall=-1;
                        yesthis=false;
                    }else{
                        yesthis=false;
                    }
                }
            }else if(yestoall==1){
                yesthis=true;
            }else{
                yesthis=false;
            }
        }
        //qDebug("have%d 1",i);
        if(yesthis){
            VCH::set(&dvst);
            //qDebug("set%d",i);
        }

    }
    emit percent(1);
}

void CopThread::settask(QVector<DVSym> slist,QString path,QString pit)
{
    this->slist=slist;
    this->path=path;
    this->pit=pit;
}

void CopThread::changedflag(QMessageBox::StandardButton result)
{
    if(!changeflag){
        this->result=result;
        changeflag=true;
    }
}

void CopThread::wannaflagchange(QString path,QString pit,QString symbol,QString pathn)
{
    if(changeflag){
        changeflag=false;
        this->result=QMessageBox::Cancel;
        emit flagdia(path,pit,symbol,pathn);
        while (!changeflag) {

        }
    }
}
