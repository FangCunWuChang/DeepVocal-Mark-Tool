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
        bool yesthis=true;
        if(VCH::have(&dvst,path)){
            if(yestoall==0){
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
        if(yesthis){
            VCH::set(&dvst);
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
