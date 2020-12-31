#include "center.h"
#include "ui_center.h"

Center::Center(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Center)
{
    ui->setupUi(this);
    connect(ui->mt,&Menu::key,this,&Center::onmenukey);
    connect(pset,&Prset::prochanged,this,&Center::onspchanged);
    connect(ow,&OpenWav::filechanged,this,&Center::onwavchanged);
    connect(ui->plot,&AuPlot::marks,this,&Center::onausaved);
    connect(ui->plot,&AuPlot::locked,this,&Center::onplotlocked);
    connect(ui->plot,&AuPlot::unlocked,this,&Center::onplotunlocked);
    connect(ui->plot,&AuPlot::autoed,this,&Center::onplotautoed);
    connect(ui->list,&QListWidget::currentRowChanged,this,&Center::on_list_currentRowChanged);
    effect->setSource(QUrl::fromLocalFile(":/sounds/save.wav"));
    effect->setLoopCount(0);
    effect->setVolume(1);
    //ui->menu->setMenu(menu);
    //ui->plot->WaveAnalyse(QDir::currentPath()+"/ai.wav");
}

Center::~Center()
{
    //delete menu;
    delete effect;
    delete pset;
    delete ow;
    delete ui;
}

void Center::resizeEvent(QResizeEvent *event)
{
    if(lisshow){
        ui->lhb->show();
        ui->lsb->hide();
        ui->lhb->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->resize(3*qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lhb->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->lsb->move(qMin(0.05*width(),0.05*height())/2,0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->list->resize(0.2*width(),height());
        ui->plot->resize(0.8*width(),height());
        ui->list->move(0,0);
        ui->plot->move(0.2*width(),0);
        ui->menu->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->menu->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),height()-qMin(0.05*width(),0.05*height())-qMin(0.05*width(),0.05*height())/4);
        ui->menu->raise();
        ui->lhb->raise();
        ui->lsb->raise();
        ui->mt->resize(width(),height());
        ui->mt->move(0,0);
        ui->mt->raise();
        ui->mt->hide();
        for(int i=0;i<ui->list->count();i++){
            ui->list->item(i)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        }
    }else{
        ui->lhb->hide();
        ui->lsb->show();
        ui->lhb->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->resize(3*qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lhb->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->lsb->move(qMin(0.05*width(),0.05*height())/2,0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->list->resize(0.2*width(),height());
        ui->plot->resize(width(),height());
        ui->list->move(0,0);
        ui->plot->move(0,0);
        ui->plot->raise();
        ui->menu->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->menu->move(qMin(0.05*width(),0.05*height())/2,height()-qMin(0.05*width(),0.05*height())-qMin(0.05*width(),0.05*height())/4);
        ui->menu->raise();
        ui->lhb->raise();
        ui->lsb->raise();
        ui->mt->resize(width(),height());
        ui->mt->move(0,0);
        ui->mt->raise();
        ui->mt->hide();
        for(int i=0;i<ui->list->count();i++){
            ui->list->item(i)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        }
    }

    //ui->list->setBatchSize(0.1*ui->list->height());
    QWidget::resizeEvent(event);
}

void Center::on_menu_clicked()
{
    ui->mt->show();
}

void Center::onmenukey(int id)
{
    switch (id) {
    case 1:
        newpro();
        break;
    case 2:
        openpro();
        break;
    case 3:
        savepro();
        break;
    case 4:
        pset->setproject(pro);
        pset->exec();
        break;
    case 5:
        ow->setps(pro.getpaths());
        ow->exec();
        break;
    case 6:
        QMessageBox::information(this,"关于DVMT","Deepvocal Mark Tool v0.2.0 alpha Build 20201230\nDVMT (C)2020 Wu Chang.All rights reserved.\nAuPlot版本：v2.3.0 alpha\nAuPlot (C)2020 Wu Chang.All rights reserved.\nQt库版本：5.14.1\nDeepVocal 软件版权归Boxstar所有.");
        break;
    default:
        break;
    }
}

void Center::onspchanged(Project pro)
{
    if(this->pro!=pro){
        QString pp=this->pro.getpitch();
        QString pn=pro.getpitch();
        this->pro=pro;
        saved=false;
        CSL=Symbolcheck::split(pro.getsymbols());
        if(pp!=pn){
            changepit(pp,pn);
        }
        refreshsym();
    }
}

bool Center::wannaclose()
{
    bool out=false;
    if(!saved){
        bool ok=true;
        QMessageBox::StandardButtons result=QMessageBox::question(this,"未保存项目","当前项目尚未保存，是否保存？",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel),QMessageBox::Cancel);
        if(result==QMessageBox::Yes){
            QString filepath=QFileDialog::getSaveFileName(this,"保存文件",propath,"DVMT项目文件(*.dvmtp);;所有文件(*.*)");
            if(!filepath.isEmpty()){
                propath=filepath;
                ok=pro.writefile(filepath);
            }else{
                return false;
            }
        }
        if(result==QMessageBox::Yes||result==QMessageBox::No){
            if(ok){
                out=true;
            }else{
                QMessageBox::warning(this,"错误","未能保存文件："+propath);
            }
        }else{
            return false;
        }
    }else{
        out=true;
    }
    return out;
}

void Center::newpro()
{
    if(!saved){
        bool ok=true;
        QMessageBox::StandardButtons result=QMessageBox::question(this,"未保存项目","当前项目尚未保存，是否保存？",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel),QMessageBox::Cancel);
        if(result==QMessageBox::Yes){
            QString filepath=QFileDialog::getSaveFileName(this,"保存文件",propath,"DVMT项目文件(*.dvmtp);;所有文件(*.*)");
            if(!filepath.isEmpty()){
                propath=filepath;
                ok=pro.writefile(filepath);
            }else{
                return;
            }
        }
        if(result==QMessageBox::Yes||result==QMessageBox::No){
            if(ok){
                pro.clear();
                saved=true;
                CSL=Symbolcheck::split(pro.getsymbols());
                refreshsym();
            }else{
                QMessageBox::warning(this,"错误","未能保存文件："+propath);
            }

        }else{
            return;
        }
    }else{
        pro.clear();
        saved=true;
        CSL=Symbolcheck::split(pro.getsymbols());
        refreshsym();
    }
}

void Center::openpro()
{
    if(!saved){
        bool ok=true;
        QMessageBox::StandardButtons result=QMessageBox::question(this,"未保存项目","当前项目尚未保存，是否保存？",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel),QMessageBox::Cancel);
        if(result==QMessageBox::Yes){
            QString filepath=QFileDialog::getSaveFileName(this,"保存文件",propath,"DVMT项目文件(*.dvmtp);;所有文件(*.*)");
            if(!filepath.isEmpty()){
                propath=filepath;
                ok=pro.writefile(filepath);
            }else{
                return;
            }
        }
        if(result==QMessageBox::Yes||result==QMessageBox::No){
            if(ok){
                QString opath=QFileDialog::getOpenFileName(this,"打开文件",propath,"DVMT项目文件(*.dvmtp);;所有文件(*.*)");
                if(!opath.isEmpty()){
                    Project pt=pro;
                    if(pro.readfile(opath)){
                        propath=opath;
                        saved=true;
                        CSL=Symbolcheck::split(pro.getsymbols());
                        refreshsym();

                    }else{
                        pro=pt;
                        CSL=Symbolcheck::split(pro.getsymbols());
                        refreshsym();

                        QMessageBox::warning(this,"错误","未能读取文件："+opath);
                    }
                }else{
                    return;
                }

            }else{
                QMessageBox::warning(this,"错误","未能保存文件："+propath);
            }

        }else{
            return;
        }
    }else{
        QString opath=QFileDialog::getOpenFileName(this,"打开文件",propath,"DVMT项目文件(*.dvmtp);;所有文件(*.*)");
        if(!opath.isEmpty()){
            Project pt=pro;
            if(pro.readfile(opath)){
                propath=opath;
                saved=true;
                CSL=Symbolcheck::split(pro.getsymbols());
                refreshsym();
                if(CSL.size()>0){
                    ui->list->setCurrentRow(0);
                }
            }else{
                pro=pt;
                CSL=Symbolcheck::split(pro.getsymbols());
                refreshsym();
                if(CSL.size()>0){
                    ui->list->setCurrentRow(0);
                }
                QMessageBox::warning(this,"错误","未能读取文件："+opath);
            }
        }else{
            return;
        }
    }
}

void Center::savepro()
{
    bool ok=true;
    QString filepath=QFileDialog::getSaveFileName(this,"保存文件",propath,"DVMT项目文件(*.dvmtp);;所有文件(*.*)");
    if(!filepath.isEmpty()){
        propath=filepath;
        ok=pro.writefile(filepath);
    }else{
        return;
    }
    if(ok){
        saved=true;
    }else{
        QMessageBox::warning(this,"错误","未能保存文件："+propath);
    }
}

void Center::refreshsym()
{
    rechecksym();
    ui->list->clear();
    for(int i=0;i<CSL.size();i++){
        ui->list->addItem(CSL.at(i).name);
        ui->list->item(ui->list->count()-1)->setToolTip(CSL.at(i).mes);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        if(CSL.at(i).mes=="正确"){
            brush.setColor(QColor(0,255,0,50));
        }else if(CSL.at(i).mes=="未标记"){
            brush.setColor(QColor(255,0,0,50));
        }else{
            brush.setColor(QColor(255,255,0,50));
        }
        ui->list->item(ui->list->count()-1)->setBackground(brush);
        ui->list->item(ui->list->count()-1)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
    }

}

void Center::onwavchanged(QString path,QString filename)
{
    ui->plot->WaveAnalyse(path+"/"+filename);
    int row=ui->list->currentRow();
    if(row>=0){
        ui->plot->setfourlines(this->CSL.at(row).isCV);
        if(path==this->CSL.at(row).path&&filename==this->CSL.at(row).file){
            ui->plot->setlines(this->CSL.at(row).l1,this->CSL.at(row).l2,this->CSL.at(row).l3,this->CSL.at(row).l4);
        }
        /*
        CVVCSymbol ct=this->CSL.at(row);
        ct.path=path;
        ct.file=filename;
        this->CSL.replace(row,ct);
*/
        patht=path;
        filet=filename;
    }
}

void Center::rechecksym()
{
    for(int i=0;i<CSL.size();i++){
        CVVCSymbol CST=CSL.at(i);
        CST.pitch=pro.getpitch();
        QStringList psl=pro.getpaths();
        int cou=0;
        for(int j=psl.size()-1;j>=0;j--){

            if(VCH::get(&CST,psl.at(j))){
                //qDebug("check:%s:%sfalse",qPrintable(CST.name),qPrintable(psl.at(j)));
                cou++;
            }
        }
        if(cou==1){
            CST.mes="正确";
        }else if(cou==0){
            CST.mes="未标记";
        }else{
            CST.mes="标记重复，请检查标记或重新标记";
        }
        CSL.replace(i,CST);
    }
}

void Center::on_list_currentRowChanged(int currentRow)
{
    //qDebug("Row:%d",currentRow);
    if(currentRow>=0&&currentRow<CSL.size()){
        if(!CSL.at(currentRow).name.isEmpty()){
            ui->lsb->setText("当前符号："+CSL.at(currentRow).name);
        }else{
            ui->lsb->setText("当前符号为空");
        }
        if(CSL.at(currentRow).mes!="未标记"){
            if(checkwav(CSL.at(currentRow).path,CSL.at(currentRow).file)){
                if(!(CSL.at(currentRow).path==patht&&CSL.at(currentRow).file==filet)){
                   ui->plot->WaveAnalyse(CSL.at(currentRow).path+"/"+CSL.at(currentRow).file);
                   patht=CSL.at(currentRow).path;
                   filet=CSL.at(currentRow).file;
                }

                ui->plot->setfourlines(this->CSL.at(currentRow).isCV);
                ui->plot->setlines(this->CSL.at(currentRow).l1,this->CSL.at(currentRow).l2,this->CSL.at(currentRow).l3,this->CSL.at(currentRow).l4);
            }
        }else{
            ui->plot->setfourlines(this->CSL.at(currentRow).isCV);
            ui->plot->setlines(this->CSL.at(currentRow).l1,this->CSL.at(currentRow).l2,this->CSL.at(currentRow).l3,this->CSL.at(currentRow).l4);
        }
    }else{
        ui->lsb->setText("当前无符号");
    }
}

bool Center::checkwav(QString path,QString filename)
{
    bool out=false;
    if(QWaveHandle::checkwav(path+"/"+filename,1,44100,16,2*global::sets::perp)){
        out=true;
    }
    return out;
}

void Center::onausaved(double l1,double l2,double l3,double l4)
{
    if(ui->list->currentRow()>=0&&ui->list->currentRow()<CSL.size()){
        CVVCSymbol CST=CSL.at(ui->list->currentRow());
        CST.path=patht;
        CST.file=filet;
        CST.l1=l1;
        CST.l2=l2;
        CST.l3=l3;
        CST.l4=l4;
        CVVCSymbol CSTT=CST;
        QStringList psl=pro.getpaths();
        for(int i=0;i<psl.size();i++){
            if(VCH::get(&CSTT,psl.at(i))){
                VCH::remove(&CSTT);
                CSTT=CST;
            }
        }
        if(VCH::set(&CST)){
            effect->play();
        }
        int cr=ui->list->currentRow();
        refreshsym();
        if(autoed){
            if(cr<ui->list->count()-1){
                ui->list->setCurrentRow(cr+1);
            }else{
                ui->list->setCurrentRow(0);
            }
        }else{
            ui->list->setCurrentRow(cr);
        }

    }

}

void Center::on_list_itemChanged(QListWidgetItem *item)
{
    Q_UNUSED(item);
    //qDebug("Row:%d",ui->list->currentRow());
    //qDebug("Index:%d",ui->list->currentIndex().row());
}

void Center::on_list_itemSelectionChanged()
{
    //qDebug("Row:%d",ui->list->currentRow());
    //qDebug("Index:%d",ui->list->currentIndex().row());
}

void Center::on_list_currentTextChanged(const QString &currentText)
{
    Q_UNUSED(currentText);
    //qDebug("Row:%d",ui->list->currentRow());
    //qDebug("Index:%d",ui->list->currentIndex().row());
}

void Center::onplotlocked()
{

    ui->menu->setEnabled(false);
    ui->list->setEnabled(false);
    lockflag++;
}

void Center::onplotunlocked()
{
    lockflag--;
    if(lockflag==0){
        ui->menu->setEnabled(true);
        ui->list->setEnabled(true);
    }
}

void Center::onplotautoed(bool autoed)
{
    this->autoed=autoed;
}

void Center::changepit(QString past,QString now)
{
    QStringList psl=pro.getpaths();
    for(int i=0;i<psl.size();i++){
        for(int j=0;j<CSL.size();j++){
            CVVCSymbol CT=CSL.at(j);
            CT.pitch=past;
            CT.path=psl.at(i);
            if(VCH::get(&CT,psl.at(i))){
                VCH::remove(&CT);
                CT.pitch=now;
                VCH::set(&CT);
            }
        }
    }
}

void Center::on_lhb_clicked()
{
    lisshow=false;
    if(lisshow){
        ui->lhb->show();
        ui->lsb->hide();
        ui->lhb->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->resize(3*qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lhb->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->lsb->move(qMin(0.05*width(),0.05*height())/2,0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->list->resize(0.2*width(),height());
        ui->plot->resize(0.8*width(),height());
        ui->list->move(0,0);
        ui->plot->move(0.2*width(),0);
        ui->menu->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->menu->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),height()-qMin(0.05*width(),0.05*height())-qMin(0.05*width(),0.05*height())/4);
        ui->menu->raise();
        ui->lhb->raise();
        ui->lsb->raise();
        ui->mt->resize(width(),height());
        ui->mt->move(0,0);
        ui->mt->raise();
        ui->mt->hide();
        for(int i=0;i<ui->list->count();i++){
            ui->list->item(i)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        }
    }else{
        ui->lhb->hide();
        ui->lsb->show();
        ui->lhb->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->resize(3*qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lhb->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->lsb->move(qMin(0.05*width(),0.05*height())/2,0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->list->resize(0.2*width(),height());
        ui->plot->resize(width(),height());
        ui->list->move(0,0);
        ui->plot->move(0,0);
        ui->plot->raise();
        ui->menu->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->menu->move(qMin(0.05*width(),0.05*height())/2,height()-qMin(0.05*width(),0.05*height())-qMin(0.05*width(),0.05*height())/4);
        ui->menu->raise();
        ui->lhb->raise();
        ui->lsb->raise();
        ui->mt->resize(width(),height());
        ui->mt->move(0,0);
        ui->mt->raise();
        ui->mt->hide();
        for(int i=0;i<ui->list->count();i++){
            ui->list->item(i)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        }
    }
}

void Center::on_lsb_clicked()
{
    lisshow=true;
    if(lisshow){
        ui->lhb->show();
        ui->lsb->hide();
        ui->lhb->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->resize(3*qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lhb->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->lsb->move(qMin(0.05*width(),0.05*height())/2,0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->list->resize(0.2*width(),height());
        ui->plot->resize(0.8*width(),height());
        ui->list->move(0,0);
        ui->plot->move(0.2*width(),0);
        ui->menu->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->menu->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),height()-qMin(0.05*width(),0.05*height())-qMin(0.05*width(),0.05*height())/4);
        ui->menu->raise();
        ui->lhb->raise();
        ui->lsb->raise();
        ui->mt->resize(width(),height());
        ui->mt->move(0,0);
        ui->mt->raise();
        ui->mt->hide();
        for(int i=0;i<ui->list->count();i++){
            ui->list->item(i)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        }
    }else{
        ui->lhb->hide();
        ui->lsb->show();
        ui->lhb->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->resize(3*qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lhb->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->lsb->move(qMin(0.05*width(),0.05*height())/2,0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->list->resize(0.2*width(),height());
        ui->plot->resize(width(),height());
        ui->list->move(0,0);
        ui->plot->move(0,0);
        ui->plot->raise();
        ui->menu->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->menu->move(qMin(0.05*width(),0.05*height())/2,height()-qMin(0.05*width(),0.05*height())-qMin(0.05*width(),0.05*height())/4);
        ui->menu->raise();
        ui->lhb->raise();
        ui->lsb->raise();
        ui->mt->resize(width(),height());
        ui->mt->move(0,0);
        ui->mt->raise();
        ui->mt->hide();
        for(int i=0;i<ui->list->count();i++){
            ui->list->item(i)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        }
    }
}
