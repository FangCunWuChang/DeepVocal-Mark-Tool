#include "center.h"
#include "ui_center.h"

Center::Center(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Center)
{
    ui->setupUi(this);
    connect(ui->mt,&Menu::key,this,&Center::onmenukey);
    connect(ui->as,&AS::key,this,&Center::onmenukey);
    connect(pset,&Prset::prochanged,this,&Center::onspchanged);
    connect(pl,&Plugins::prochanged,this,&Center::onspchanged);
    connect(ow,&OpenWav::filechanged,this,&Center::onwavchanged);
    connect(ui->aww,&AutoWav::wavopen,this,&Center::onwavchanged);
    connect(ui->plot,&AuPlot::marks,this,&Center::onausaved);
    connect(ui->plot,&AuPlot::locked,this,&Center::onplotlocked);
    connect(ui->plot,&AuPlot::unlocked,this,&Center::onplotunlocked);
    connect(ui->plot,&AuPlot::autoed,this,&Center::onplotautoed);
    connect(ui->list,&QListWidget::currentRowChanged,this,&Center::on_list_currentRowChanged);
    connect(ui->sear,&Search::name,this,&Center::onsearname);
    connect(ui->mt,&Menu::egg,this,&Center::onsearegg);
    connect(&F_Scaner,&FileScaner::files,this,&Center::onfiles);
    connect(watcher,&QFileSystemWatcher::fileChanged,this,&Center::onwatcherchanged);
    connect(watcher,&QFileSystemWatcher::directoryChanged,this,&Center::onwatcherchanged);
    connect(&cget,&CSLget::append,this,&Center::oncgetappend,Qt::DirectConnection);
    connect(ui->plot,&AuPlot::buttonchecked,ui->ct,&CTool::setbuttonchecked);
    connect(ui->plot,&AuPlot::buttonchecked,this,&Center::setbuttonchecked);
    connect(ui->plot,&AuPlot::buttonenabled,ui->ct,&CTool::setbuttonenabled);
    connect(ui->plot,&AuPlot::buttonenabled,this,&Center::setbuttonenabled);
    connect(ui->ct,&CTool::ctb,ui->plot,&AuPlot::setctb);
    connect(ui->ct,&CTool::ctb,this,&Center::setctb);
    connect(ui->ct,&CTool::owr,this,&Center::onctowr);
    connect(ui->egg,&Egg::callow,this,&Center::oneggow);

    this->setMouseTracking(true);
    effect->setSource(QUrl::fromLocalFile(":/sounds/save.wav"));
    effect->setLoopCount(0);
    effect->setVolume(1);
    ui->mt->hide();
    ui->as->hide();
    ui->sear->hide();
    ui->egg->hide();
    ui->aww->hide();
    ui->dow->hide();
    ow->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
    pl->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
    pset->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
    pl->setPro(&this->pro);
    ui->egg->setPlugins(pl);
}

Center::~Center()
{
    if(F_Scaner.isRunning()){
        F_Scaner.terminate();
        F_Scaner.wait();
    }
    if(cget.isRunning()){
        cget.stopflag=true;
        cget.terminate();
        cget.wait();
    }
    delete watcher;
    delete effect;
    delete pset;
    delete ow;
    delete pl;
    delete ui;
}

void Center::resizeEvent(QResizeEvent *event)
{
    resize();
    QWidget::resizeEvent(event);
}

void Center::onmenuclicked()
{
    ui->sear->hide();
    ui->egg->hide();
    ui->aww->hide();
    ui->mt->Menu::show();
    ui->as->hide();
}

void Center::onanalyseclicked()
{
    ui->sear->hide();
    ui->egg->hide();
    ui->aww->hide();
    ui->mt->hide();
    ui->as->show();
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
        pl->checkplugins();
        pl->exec();
        break;
    case 6:
    {
        QMessageBox::information(this,"关于DVMT",mes);
        break;
    }
    case 7:
    {
        ui->plot->setctb("ene",false);
        break;
    }
    case 8:
    {
        ui->plot->setctb("ene",true);
        break;
    }
    case 9:
    {
        ui->plot->setctb("rptz",false);
        break;
    }
    case 10:
    {
        ui->plot->setctb("rptz",true);
        break;
    }
    case 11:
    {
        ui->plot->setctb("rea",false);
        break;
    }
    case 12:
    {
        ui->plot->setctb("cle",false);
        break;
    }
    default:
        break;
    }
}

void Center::onspchanged(Project pro,bool pitref)
{
    if(pitref){
        if(this->pro!=pro){
            this->pro=pro;
            saved=false;
        }
        if(F_Scaner.isRunning()){
            F_Scaner.terminate();
            F_Scaner.wait();
        }
        if(cget.isRunning()){
            cget.stopflag=true;
            cget.terminate();
            cget.wait();
        }
        refreshwatchpath();
        CSL=pro.getflags();
        refreshsym();
    }else{
        if(this->pro!=pro){
            QString pp=this->pro.getpitch();
            QString pn=pro.getpitch();
            this->pro=pro;
            saved=false;
            if(F_Scaner.isRunning()){
                F_Scaner.terminate();
                F_Scaner.wait();
            }
            if(cget.isRunning()){
                cget.stopflag=true;
                cget.terminate();
                cget.wait();
            }
            refreshwatchpath();
            CSL=pro.getflags();
            refreshsym();
            if(pp!=pn){
            }
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
                propath=ppt+"/未命名项目.dvmtp";
                saved=true;
                if(F_Scaner.isRunning()){
                    F_Scaner.terminate();
                    F_Scaner.wait();
                }
                if(cget.isRunning()){
                    cget.stopflag=true;
                    cget.terminate();
                    cget.wait();
                }
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
        propath=ppt+"/未命名项目.dvmtp";
        saved=true;
        if(F_Scaner.isRunning()){
            F_Scaner.terminate();
            F_Scaner.wait();
        }
        if(cget.isRunning()){
            cget.stopflag=true;
            cget.terminate();
            cget.wait();
        }
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
                        if(F_Scaner.isRunning()){
                            F_Scaner.terminate();
                            F_Scaner.wait();
                        }
                        if(cget.isRunning()){
                            cget.stopflag=true;
                            cget.terminate();
                            cget.wait();
                        }
                        refreshwatchpath();
                        CSL=pro.getflags();
                        refreshsym();

                    }else{
                        pro=pt;
                        if(F_Scaner.isRunning()){
                            F_Scaner.terminate();
                            F_Scaner.wait();
                        }
                        if(cget.isRunning()){
                            cget.stopflag=true;
                            cget.terminate();
                            cget.wait();
                        }
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
                if(F_Scaner.isRunning()){
                    F_Scaner.terminate();
                    F_Scaner.wait();
                }
                if(cget.isRunning()){
                    cget.stopflag=true;
                    cget.terminate();
                    cget.wait();
                }
                refreshwatchpath();
                CSL=pro.getflags();
                refreshsym();
                if(CSL.size()>0){
                    ui->list->setCurrentRow(0);
                }
            }else{
                pro=pt;
                if(F_Scaner.isRunning()){
                    F_Scaner.terminate();
                    F_Scaner.wait();
                }
                if(cget.isRunning()){
                    cget.stopflag=true;
                    cget.terminate();
                    cget.wait();
                }
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
        cget.stopflag=true;
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
        patht=path;
        filet=filename;
        ui->ct->setwavname(filet);
    }
}

void Center::rechecksym()
{

}

void Center::on_list_currentRowChanged(int currentRow)
{
    if(currentRow>=0&&currentRow<CSL.size()){
        if(!CSL.at(currentRow).name.isEmpty()){
            ui->aww->setsymname(CSL.at(currentRow).name);
            ui->sb->setText("当前发音符号:"+CSL.at(currentRow).name);
        }else{
            ui->aww->setsymname("");
            ui->sb->setText("未选择发音符号");
        }
        if(CSL.at(currentRow).mes!="未标记"){
            if(checkwav(CSL.at(currentRow).path,CSL.at(currentRow).file)){
                if(!(CSL.at(currentRow).path==patht&&CSL.at(currentRow).file==filet)){
                   ui->plot->WaveAnalyse(CSL.at(currentRow).path+"/"+CSL.at(currentRow).file);
                   patht=CSL.at(currentRow).path;
                   filet=CSL.at(currentRow).file;
                   ui->ct->setwavname(filet);
                }

                ui->plot->setfourlines(this->CSL.at(currentRow).isCV>0);
                ui->plot->setlines(this->CSL.at(currentRow).l1,this->CSL.at(currentRow).l2,this->CSL.at(currentRow).l3,this->CSL.at(currentRow).l4);
            }
        }else{
            ui->plot->setfourlines(this->CSL.at(currentRow).isCV>0);
            ui->plot->setlines(0,0,0,0);
        }
    }else{
        ui->aww->setsymname("");
        ui->sb->setText("未选择发音符号");
    }
}

bool Center::checkwav(QString path,QString filename)
{
    bool out=false;
    if(QWaveHandle::checkwav(path+"/"+filename,1,44100,16,2*global_sets::perp,global_sets::maxlength)){
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
        QFont font;
        font.setPixelSize(ui->list->height()*0.02);
        ui->list->item(cr)->setBackground(brush);
        ui->list->item(cr)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        ui->list->item(cr)->setFont(font);
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
}

void Center::on_list_itemSelectionChanged()
{
}

void Center::on_list_currentTextChanged(const QString &currentText)
{
    Q_UNUSED(currentText);
}

void Center::onplotlocked()
{
    ui->list->setEnabled(false);
    ui->ct->setbuttonenabled("up",false);
    ui->ct->setbuttonenabled("down",false);
    ui->ct->setbuttonenabled("more",false);
    lockflag++;
}

void Center::onplotunlocked()
{
    lockflag--;
    if(lockflag==0){
        ui->list->setEnabled(true);
        ui->ct->setbuttonenabled("up",true);
        ui->ct->setbuttonenabled("down",true);
        ui->ct->setbuttonenabled("more",true);
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

void Center::onlhbclicked(bool ok)
{
    lisshow=ok;
    resize();
}

void Center::onseaclicked()
{
    ui->sear->setsymbols(CSL);
    ui->mt->hide();
    ui->as->hide();
    ui->egg->hide();
    ui->aww->hide();
    ui->sear->show();
}

void Center::resize()
{
    ui->ct->resize(0.8*width(),0.04*height());
    ui->sb->resize(0.2*width(),0.04*height());
    ui->list->resize(0.2*width(),0.96*height());
    ui->plot->resize(0.8*width(),0.96*height());
    ui->sb->move(0,0);
    ui->list->move(0,0.04*height());
    ui->ct->move(0.2*width(),0);
    ui->plot->move(0.2*width(),0.04*height());
    ui->mt->resize(width(),height());
    ui->mt->move(0,0);
    ui->mt->raise();
    ui->as->resize(width(),height());
    ui->as->move(0,0);
    ui->as->raise();
    ui->sear->resize(width(),height());
    ui->sear->move(0,0);
    ui->sear->raise();
    ui->egg->resize(width(),height());
    ui->egg->move(0,0);
    ui->egg->raise();
    ui->aww->resize(width(),height());
    ui->aww->move(0,0);
    ui->aww->raise();
    ui->dow->resize(width(),height());
    ui->dow->move(0,0);
    ui->dow->raise();
    QFont font;
    font.setPixelSize(ui->list->height()*0.017);
    for(int i=0;i<ui->list->count();i++){
        ui->list->item(i)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
        ui->list->item(i)->setFont(font);
    }
    font.setPixelSize(ui->list->height()*0.02);
    ui->sb->setFont(font);
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
    title+=propath.rightRef(propath.length ()-first-1);
    if(!saved){
        title+="*";
    }
    emit retitled(title);
}

void Center::onsearegg()
{
    ui->mt->hide();
    ui->as->hide();
    ui->sear->hide();
    ui->egg->checkplugins();
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
                        if(F_Scaner.isRunning()){
                            F_Scaner.terminate();
                            F_Scaner.wait();
                        }
                        if(cget.isRunning()){
                            cget.stopflag=true;
                            cget.terminate();
                            cget.wait();
                        }
                        refreshwatchpath();
                        CSL=pro.getflags();
                        refreshsym();

                    }else{
                        pro=pt;
                        if(F_Scaner.isRunning()){
                            F_Scaner.terminate();
                            F_Scaner.wait();
                        }
                        if(cget.isRunning()){
                            cget.stopflag=true;
                            cget.terminate();
                            cget.wait();
                        }
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
                if(F_Scaner.isRunning()){
                    F_Scaner.terminate();
                    F_Scaner.wait();
                }
                if(cget.isRunning()){
                    cget.stopflag=true;
                    cget.terminate();
                    cget.wait();
                }
                refreshwatchpath();
                CSL=pro.getflags();
                refreshsym();
                if(CSL.size()>0){
                    ui->list->setCurrentRow(0);
                }
            }else{
                pro=pt;
                if(F_Scaner.isRunning()){
                    F_Scaner.terminate();
                    F_Scaner.wait();
                }
                if(cget.isRunning()){
                    cget.stopflag=true;
                    cget.terminate();
                    cget.wait();
                }
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
    ui->ct->setowlock(true);
    F_Scaner.setpaths(pro.getpaths());
    if(F_Scaner.isRunning()){
        F_Scaner.terminate();
        F_Scaner.wait();
    }
    F_Scaner.start();
}

void Center::onfiles(QStringList paths,QVector<QStringList> filelist)
{
    this->paths=paths;
    this->filelist=filelist;
    ui->aww->setpathes(paths,filelist);
    refreshwatchlist();
    ui->ct->setowlock(false);
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
    QFont font;
    font.setPixelSize(ui->list->height()*0.017);
    ui->list->item(ui->list->count()-1)->setBackground(brush);
    ui->list->item(ui->list->count()-1)->setSizeHint(QSize(ui->list->width()*0.9,ui->list->height()*0.025));
    ui->list->item(ui->list->count()-1)->setFont(font);
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

void Center::onawclicked()
{
    ui->mt->hide();
    ui->as->hide();
    ui->egg->hide();
    ui->sear->hide();
    if(ui->aww->isHidden()){
        ui->aww->show();
    }else{
        ui->aww->okey();
    }
}

void Center::keyPressEvent(QKeyEvent *event)
{
    if(ui->mt->isHidden()&&ui->as->isHidden()){
        if(event->modifiers()==Qt::CTRL){
            switch (event->key()) {
            case Qt::Key_N:
                newpro();
                break;
            case Qt::Key_O:
                openpro();
                break;
            case Qt::Key_S:
                savepro();
                break;
            case Qt::Key_P:
                pl->checkplugins();
                pl->exec();
                break;
            case Qt::Key_A:
                QMessageBox::information(this,"关于DVMT",mes);
                break;
            default:
                break;
            }
        }else if(event->modifiers()==Qt::ALT){
            switch (event->key()) {
            case Qt::Key_A:
                ui->ct->setkeypress("Alt+A");
                break;
            case Qt::Key_X:
                ui->ct->setkeypress("Alt+X");
                break;
            case Qt::Key_S:
                ui->ct->setkeypress("Alt+S");
                break;
            case Qt::Key_Z:
            {
                this->onawclicked();
                break;
            }
            case Qt::Key_E:
                ui->as->pushene();
                break;
            case Qt::Key_P:
                ui->as->pushrptz();
                break;
            case Qt::Key_R:
                ui->as->pushrea();
                break;
            case Qt::Key_C:
                ui->as->pushcle();
                break;
            default:
                break;
            }
        }else if(event->modifiers()==Qt::NoModifier){
            switch (event->key()) {
            case Qt::Key_F2:
                pset->setproject(pro);
                pset->exec();
                break;
            case Qt::Key_1:
                ui->ct->setkeypress("1");
                break;
            case Qt::Key_2:
                ui->ct->setkeypress("2");
                break;
            case Qt::Key_3:
                ui->ct->setkeypress("3");
                break;
            case Qt::Key_4:
                ui->ct->setkeypress("4");
                break;
            case Qt::Key_Up:
                ui->ct->setkeypress("up");
                break;
            case Qt::Key_Down:
                ui->ct->setkeypress("down");
                break;
            default:
                break;
            }
        }else{

        }

    }
}

void Center::setctb(QString button,bool checked)
{
    Q_UNUSED(checked);
    if(button=="up"){
        if(ui->list->count()>1){
            if(ui->list->currentRow()>0){
                ui->list->setCurrentRow(ui->list->currentRow()-1);
            }
        }
    }else if(button=="down"){
        if(ui->list->count()>1){
            if(ui->list->currentRow()<ui->list->count()-1){
                ui->list->setCurrentRow(ui->list->currentRow()+1);
            }
        }
    }else if(button=="more"){
        this->onmenuclicked();
    }else if(button=="analyse"){
        this->onanalyseclicked();
    }else{

    }
}

void Center::setbuttonchecked(QString button,bool checked)
{
    if(button=="ene"){
        ui->as->setene(checked);
    }else if(button=="rptz"){
        ui->as->setrptz(checked);
    }else{

    }
}

void Center::setbuttonenabled(QString button,bool enabled)
{
    if(button=="rea"){
        ui->as->setrea(enabled);
    }else if(button=="cle"){
        ui->as->setcle(enabled);
    }else{

    }
}

void Center::onctowr()
{
    this->onawclicked();
}

void Center::on_sb_clicked()
{
    this->onseaclicked();
}

void Center::oneggow()
{
    ow->setps(paths,filelist);
    ow->exec();
}
