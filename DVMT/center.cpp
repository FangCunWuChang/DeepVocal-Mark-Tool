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
    connect(ui->aww,&AutoWav::wavopen,this,&Center::onwavchanged);
    connect(ui->plot,&AuPlot::marks,this,&Center::onausaved);
    connect(ui->plot,&AuPlot::locked,this,&Center::onplotlocked);
    connect(ui->plot,&AuPlot::unlocked,this,&Center::onplotunlocked);
    connect(ui->plot,&AuPlot::autoed,this,&Center::onplotautoed);
    connect(ui->list,&QListWidget::currentRowChanged,this,&Center::on_list_currentRowChanged);
    connect(ui->sear,&Search::name,this,&Center::onsearname);
    connect(ui->sear,&Search::egg,this,&Center::onsearegg);
    connect(&F_Scaner,&FileScaner::files,this,&Center::onfiles);
    connect(watcher,&QFileSystemWatcher::fileChanged,this,&Center::onwatcherchanged);
    connect(watcher,&QFileSystemWatcher::directoryChanged,this,&Center::onwatcherchanged);
    connect(&cget,&CSLget::append,this,&Center::oncgetappend);
    effect->setSource(QUrl::fromLocalFile(":/sounds/save.wav"));
    effect->setLoopCount(0);
    effect->setVolume(1);
    //retitle();
    //ui->menu->setMenu(menu);
    //ui->plot->WaveAnalyse(QCoreApplication::applicationDirPath()+"/ai.wav");
}

Center::~Center()
{
    //delete menu;
    if(F_Scaner.isRunning()){
        F_Scaner.terminate();
        F_Scaner.wait();
    }
    if(cget.isRunning()){
        cget.terminate();
        cget.wait();
    }
    delete watcher;
    delete effect;
    delete pset;
    delete ow;
    delete ui;
}

void Center::resizeEvent(QResizeEvent *event)
{
    resize();

    //ui->list->setBatchSize(0.1*ui->list->height());
    QWidget::resizeEvent(event);
}

void Center::on_menu_clicked()
{
    ui->sear->hide();
    ui->egg->hide();
    ui->aww->hide();
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
        ow->setps(paths,filelist);
        ow->exec();
        break;
    case 6:
    {
        QString mes="Deepvocal Mark Tool "+QString(DVMT_VERSION)+" Build "+QString(__DATE__)+"\nDVMT (C)2020-2021 Wu Chang.All rights reserved.\n声库配布时请注明使用DVMT进行标记.\nAuPlot版本："+QString(AU_VERSION)+"\nAuPlot (C)2020-2021 Wu Chang.All rights reserved.\nQt库版本："+QString(qVersion())+"\nDeepVocal 软件版权归Boxstar所有.\n思源黑体版权归Adobe所有.";
        QMessageBox::information(this,"关于DVMT",mes);
        break;
    }
    default:
        break;
    }
}

void Center::onspchanged(Project pro,bool pitref)
{
    if(pitref){
        this->pro=pro;
        saved=false;
        refreshwatchpath();
        CSL=pro.getflags();
        refreshsym();
    }else{
        if(this->pro!=pro){
            QString pp=this->pro.getpitch();//
            QString pn=pro.getpitch();//
            this->pro=pro;
            saved=false;
            refreshwatchpath();
            CSL=pro.getflags();
            refreshsym();
            if(pp!=pn){//
                //
            }//
        }
    }

    retitle();
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
                int first=propath.lastIndexOf ("/"); //从后面查找"/"位置
                QString ppt=propath.left(first);
                //qDebug("propath:%s",qPrintable(propath));
                propath=ppt+"/未命名项目.dvmtp";
                //qDebug("propath:%s",qPrintable(propath));
                saved=true;
                refreshwatchpath();
                CSL=pro.getflags();
                refreshsym();
            }else{
                QMessageBox::warning(this,"错误","未能保存文件："+propath);
            }

        }else{
            return;
        }
    }else{
        pro.clear();
        int first=propath.lastIndexOf ("/"); //从后面查找"/"位置
        QString ppt=propath.left(first);
        //qDebug("propath:%s",qPrintable(propath));
        propath=ppt+"/未命名项目.dvmtp";
        //qDebug("propath:%s",qPrintable(propath));
        saved=true;
        refreshwatchpath();
        CSL=pro.getflags();
        refreshsym();
    }
    retitle();
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
                        refreshwatchpath();
                        CSL=pro.getflags();
                        refreshsym();

                    }else{
                        pro=pt;
                        refreshwatchpath();
                        CSL=pro.getflags();
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
                refreshwatchpath();
                CSL=pro.getflags();
                refreshsym();
                if(CSL.size()>0){
                    ui->list->setCurrentRow(0);
                }
            }else{
                pro=pt;
                refreshwatchpath();
                CSL=pro.getflags();
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
    retitle();
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
    retitle();
}

void Center::refreshsym()
{
    rechecksym();
    if(cget.isRunning()){
        cget.terminate();
        cget.wait();
    }
    cget.setlist(this->CSL,pro.getpitch(),pro.getpaths());
    ui->list->clear();
    this->CSL.clear();
    cget.start();
}

void Center::onwavchanged(QString path,QString filename)
{
    ui->plot->WaveAnalyse(path+"/"+filename);
    int row=ui->list->currentRow();
    if(row>=0){
        ui->plot->setfourlines(this->CSL.at(row).isCV>0);
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

}

void Center::on_list_currentRowChanged(int currentRow)
{
    //qDebug("Row:%d",currentRow);
    if(currentRow>=0&&currentRow<CSL.size()){
        if(!CSL.at(currentRow).name.isEmpty()){
            ui->lsb->setText("当前符号："+CSL.at(currentRow).name);
            ui->aww->setsymname(CSL.at(currentRow).name);
        }else{
            ui->lsb->setText("当前符号为空");
            ui->aww->setsymname("");
        }
        if(CSL.at(currentRow).mes!="未标记"){
            if(checkwav(CSL.at(currentRow).path,CSL.at(currentRow).file)){
                if(!(CSL.at(currentRow).path==patht&&CSL.at(currentRow).file==filet)){
                   ui->plot->WaveAnalyse(CSL.at(currentRow).path+"/"+CSL.at(currentRow).file);
                   patht=CSL.at(currentRow).path;
                   filet=CSL.at(currentRow).file;
                }

                ui->plot->setfourlines(this->CSL.at(currentRow).isCV>0);
                ui->plot->setlines(this->CSL.at(currentRow).l1,this->CSL.at(currentRow).l2,this->CSL.at(currentRow).l3,this->CSL.at(currentRow).l4);
            }
        }else{
            ui->plot->setfourlines(this->CSL.at(currentRow).isCV>0);
            ui->plot->setlines(this->CSL.at(currentRow).l1,this->CSL.at(currentRow).l2,this->CSL.at(currentRow).l3,this->CSL.at(currentRow).l4);
        }
    }else{
        ui->lsb->setText("当前无符号");
        ui->aww->setsymname("");
    }
}

bool Center::checkwav(QString path,QString filename)
{
    bool out=false;
    if(QWaveHandle::checkwav(path+"/"+filename,1,44100,16,2*global_sets::perp)){
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
            CST.mes="正确";
        }else{
            bool havef=false;
            for(int i=0;i<psl.size();i++){
                if(VCH::get(&CSTT,psl.at(i))){
                    havef=true;
                }
            }
            if(havef){
                CST.mes="未写入voice.dvcfg";
            }else{
                CST.mes="未标记";
            }
        }

        int cr=ui->list->currentRow();
        CSL.replace(cr,CST);
        ui->list->item(cr)->setToolTip(CST.mes);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        if(CST.mes=="正确"){
            brush.setColor(QColor(0,255,0,0));
        }else if(CST.mes=="未标记"){
            brush.setColor(QColor(255,0,0,70));
        }else{
            brush.setColor(QColor(255,255,0,70));
        }
        ui->list->item(cr)->setBackground(brush);
        ui->list->item(cr)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        if(autoed){
            if(cr<ui->list->count()-1){
                ui->list->setCurrentRow(cr+1);
            }else{
                ui->list->setCurrentRow(0);
            }
        }else{
            ui->list->setCurrentRow(cr);
        }

        buildmodel(cr);

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
    ui->sea->setEnabled(false);
    ui->aw->setEnabled(false);
    lockflag++;
}

void Center::onplotunlocked()
{
    lockflag--;
    if(lockflag==0){
        ui->menu->setEnabled(true);
        ui->list->setEnabled(true);
        ui->sea->setEnabled(true);
        ui->aw->setEnabled(true);
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
    resize();
}

void Center::on_lsb_clicked()
{
    lisshow=true;
    resize();
}

void Center::on_sea_clicked()
{
    ui->sear->setsymbols(CSL);
    ui->mt->hide();
    ui->egg->hide();
    ui->aww->hide();
    ui->sear->show();
}

void Center::resize()
{
    if(lisshow){
        ui->sea->show();
        ui->lhb->show();
        ui->aw->show();
        ui->lsb->hide();
        ui->lhb->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->sea->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->resize(3*qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->aw->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lhb->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->aw->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),0.1*height()+3*qMin(0.05*width(),0.05*height()));
        ui->sea->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->move(qMin(0.05*width(),0.05*height())/2,0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->list->resize(0.2*width(),height());
        ui->plot->resize(0.8*width(),height());
        ui->list->move(0,0);
        ui->plot->move(0.2*width(),0);
        ui->menu->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->menu->move(0.2*width()-qMin(0.05*width(),0.05*height())/2-qMin(0.05*width(),0.05*height()),height()-qMin(0.05*width(),0.05*height())-qMin(0.05*width(),0.05*height())/4);
        ui->menu->raise();

        ui->lhb->raise();
        ui->sea->raise();
        ui->lsb->raise();
        ui->aw->raise();
        ui->mt->resize(width(),height());
        ui->mt->move(0,0);
        ui->mt->raise();
        ui->mt->hide();
        ui->sear->resize(width(),height());
        ui->sear->move(0,0);
        ui->sear->raise();
        ui->sear->hide();
        ui->egg->resize(width(),height());
        ui->egg->move(0,0);
        ui->egg->raise();
        ui->egg->hide();
        ui->aww->resize(width(),height());
        ui->aww->move(0,0);
        ui->aww->raise();
        ui->aww->hide();
        for(int i=0;i<ui->list->count();i++){
            ui->list->item(i)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        }
    }else{
        ui->sea->hide();
        ui->lhb->hide();
        ui->aw->show();
        ui->lsb->show();
        ui->lhb->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->sea->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->resize(3*qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->aw->resize(3*qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->lsb->move(0.5*qMin(0.05*width(),0.05*height()),0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->lhb->move(0.5*qMin(0.05*width(),0.05*height()),0.1*height()+qMin(0.05*width(),0.05*height()));
        ui->aw->move(0.5*qMin(0.05*width(),0.05*height()),0.1*height()+3*qMin(0.05*width(),0.05*height()));
        ui->sea->move(qMin(0.05*width(),0.05*height())/2,qMin(0.05*width(),0.05*height()));
        ui->list->resize(0.2*width(),height());
        ui->plot->resize(width(),height());
        ui->list->move(0,0);
        ui->plot->move(0,0);
        ui->plot->raise();
        ui->menu->resize(qMin(0.05*width(),0.05*height()),qMin(0.05*width(),0.05*height()));
        ui->menu->move(qMin(0.05*width(),0.05*height())/2,height()-qMin(0.05*width(),0.05*height())-qMin(0.05*width(),0.05*height())/4);
        ui->menu->raise();
        ui->lhb->raise();
        ui->sea->raise();
        ui->lsb->raise();
        ui->aw->raise();
        ui->mt->resize(width(),height());
        ui->mt->move(0,0);
        ui->mt->raise();
        ui->mt->hide();
        ui->sear->resize(width(),height());
        ui->sear->move(0,0);
        ui->sear->raise();
        ui->sear->hide();
        ui->egg->resize(width(),height());
        ui->egg->move(0,0);
        ui->egg->raise();
        ui->egg->hide();
        ui->aww->resize(width(),height());
        ui->aww->move(0,0);
        ui->aww->raise();
        ui->aww->hide();
        for(int i=0;i<ui->list->count();i++){
            ui->list->item(i)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        }
    }
}

void Center::onsearname(QString name)
{
    for(int i=0;i<ui->list->count();i++){
        if(ui->list->item(i)->text()==name){
            ui->list->setCurrentRow(i);
            break;
        }
    }
}

void Center::retitle()
{
    QString title;
    title+="DeepVocal Mark Tool";
    title+=" - ";
    int first=propath.lastIndexOf ("/"); //从后面查找"/"位置
    title+=propath.right (propath.length ()-first-1);
    if(!saved){
        title+="*";
    }
    QMainWindow *mw=static_cast<QMainWindow *>(parent());
    mw->setWindowTitle(title);
}

void Center::onsearegg()
{
    ui->mt->hide();
    ui->sear->hide();
    ui->egg->show();
}

void Center::openfile(QString file)
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
                QString opath=file;
                if(!opath.isEmpty()){
                    Project pt=pro;
                    if(pro.readfile(opath)){
                        propath=opath;
                        saved=true;
                        refreshwatchpath();
                        CSL=pro.getflags();
                        refreshsym();

                    }else{
                        pro=pt;
                        refreshwatchpath();
                        CSL=pro.getflags();
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
        QString opath=file;
        if(!opath.isEmpty()){
            Project pt=pro;
            if(pro.readfile(opath)){
                propath=opath;
                saved=true;
                refreshwatchpath();
                CSL=pro.getflags();
                refreshsym();
                if(CSL.size()>0){
                    ui->list->setCurrentRow(0);
                }
            }else{
                pro=pt;
                refreshwatchpath();
                CSL=pro.getflags();
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
    retitle();
}

void Center::refreshwatchpath()
{
    ui->mt->setowlock(true);
    ui->aw->setEnabled(false);
    F_Scaner.setpaths(pro.getpaths());
    if(F_Scaner.isRunning()){
        F_Scaner.terminate();
        F_Scaner.wait();
    }
    F_Scaner.start();
}

void Center::onfiles(QStringList paths,QVector<QStringList> filelist)
{
    //qDebug("onfiles");
    this->paths=paths;
    this->filelist=filelist;
    ui->aww->setpathes(paths,filelist);
    refreshwatchlist();
    ui->mt->setowlock(false);
    ui->aw->setEnabled(true);
}

void Center::refreshwatchlist()
{
    watcher->removePaths(watcher->files());
    watcher->removePaths(watcher->directories());
    QStringList wps;
    for(int i=0;i<paths.size();i++){
        wps.append(paths.at(i));
        for(int j=0;j<filelist.at(i).size();j++){
            wps.append(paths.at(i)+"/"+filelist.at(i).at(j));
        }
    }
    watcher->addPaths(wps);
}

void Center::onwatcherchanged(const QString &path)
{
    Q_UNUSED(path);
    refreshwatchpath();
}

void Center::oncgetappend(CVVCSymbol one,bool finished)
{
    CSL.append(one);
    ui->list->addItem(one.name);
    ui->list->item(ui->list->count()-1)->setToolTip(one.mes);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if(one.mes=="正确"){
        brush.setColor(QColor(0,255,0,0));
    }else if(one.mes=="未标记"){
        brush.setColor(QColor(255,0,0,70));
    }else{
        brush.setColor(QColor(255,255,0,70));
    }
    ui->list->item(ui->list->count()-1)->setBackground(brush);
    ui->list->item(ui->list->count()-1)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
    if(CSL.size()==1){
        ui->list->setCurrentRow(0);
    }
    if(finished){

    }
}

void Center::buildmodel(int cr)
{
    CVVCSymbol cst=CSL.at(cr);

}

void Center::on_aw_clicked()
{
    ui->mt->hide();
    ui->egg->hide();
    ui->sear->hide();
    if(ui->aww->isHidden()){
        ui->aww->show();
    }else{
        ui->aww->okey();
    }
}
