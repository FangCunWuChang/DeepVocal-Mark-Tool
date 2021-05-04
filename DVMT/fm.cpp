#include "fm.h"
#include "ui_fm.h"

FM::FM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FM)
{
    ui->setupUi(this);
    this->cstl.resize(120);
    rud->setAttribute(Qt::WA_DeleteOnClose,false);
    connect(&MCG,&MulCSLget::append,this,&FM::onappend);
    connect(&cot,&CopThread::percent,this,&FM::onpercent,Qt::DirectConnection);
    connect(this,&FM::thrcopenddia,this,&FM::onthrcopenddia,Qt::QueuedConnection);
    connect(&cot,&CopThread::flagdia,this,&FM::oncopflagdia,Qt::QueuedConnection);
}

FM::~FM()
{
    if(cot.isRunning()){
        cot.terminate();
        cot.wait();
    }
    if(MCG.isRunning()){
        MCG.terminate();
        MCG.wait();
    }
    if(!cpsd->isHidden()){
        cpsd->close();
    }
    if(!rud->isHidden()){
        rud->close();
    }
    delete rud;
    delete cpsd;
    delete ui;
}

void FM::setpro(Project pro)
{
    if(MCG.isRunning()){
        MCG.terminate();
        MCG.wait();
    }
    this->psl=pro.getpaths();
    MCG.setlist(psl);
    this->lockdia(false);
    MCG.start();
}

void FM::onappend(QVector<QVector<DVSym>> cstl)
{
    this->cstl=cstl;
    for(int i=0;i<120;i++){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        if(cstl.at(i).size()>0){
            brush.setColor(QColor(0,255,0,70));
        }else{
            brush.setColor(QColor(0,0,0,0));
        }
        ui->pitl->item(i)->setBackground(brush);
    }
    int currentRow=ui->pitl->currentRow();
    ui->pit->setText(ui->pitl->item(currentRow)->text());
    ui->all->setText(QString::number(cstl.at(currentRow).size()));
    int cvc=0,vxc=0,indiec=0;
    for(int i=0;i<cstl.at(currentRow).size();i++){
        if(cstl.at(currentRow).at(i).srcType=="CV"){
            cvc++;
        }else if(cstl.at(currentRow).at(i).srcType=="VX"){
            vxc++;
        }else{
            indiec++;
        }
    }
    ui->cvm->setText(QString::number(cvc));
    ui->vxm->setText(QString::number(vxc));
    ui->indiem->setText(QString::number(indiec));
    this->lockdia(true);
}
void FM::on_pitl_currentRowChanged(int currentRow)
{
    ui->pit->setText(ui->pitl->item(currentRow)->text());
    ui->all->setText(QString::number(cstl.at(currentRow).size()));
    int cvc=0,vxc=0,indiec=0;
    for(int i=0;i<cstl.at(currentRow).size();i++){
        if(cstl.at(currentRow).at(i).srcType=="CV"){
            cvc++;
        }else if(cstl.at(currentRow).at(i).srcType=="VX"){
            vxc++;
        }else{
            indiec++;
        }
    }
    ui->cvm->setText(QString::number(cvc));
    ui->vxm->setText(QString::number(vxc));
    ui->indiem->setText(QString::number(indiec));
}

void FM::on_clem_clicked()
{
    QString pit=ui->pitl->currentItem()->text();
    QMessageBox::StandardButton result=QMessageBox::warning(this,"删除标记","删除"+pit+"音阶的全部标记吗？",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No),QMessageBox::No);
    if(result==QMessageBox::Yes){
        for(int i=0;i<psl.size();i++){
            VCH::removepit(psl.at(i),pit);
        }
    }
    if(MCG.isRunning()){
        MCG.terminate();
        MCG.wait();
    }
    MCG.setlist(psl);
    this->lockdia(false);
    MCG.start();
    QMessageBox::information(this,"删除标记","已删除"+pit+"音阶的全部标记");

}

void FM::on_copm_clicked()
{
    QString pit=ui->pitl->currentItem()->text();
    cpsd->setpl(psl);
    cpsd->exec();
    if((!cpsd->path.isEmpty())&&cpsd->acceptflag){
        if(cot.isRunning()){
            cot.terminate();
            cot.wait();
        }
        rud->setText("复制中");
        rud->setpercent(0);
        cot.settask(cstl.at(ui->pitl->currentRow()),cpsd->path,cpsd->pit);
        cot.start();
        rud->exec();
    }

}

void FM::on_edim_clicked()
{
    PSM *psm=new PSM(this);
    psm->setPitch(cstl.at(ui->pitl->currentRow()));
    psm->exec();
    if(MCG.isRunning()){
        MCG.terminate();
        MCG.wait();
    }
    MCG.setlist(psl);
    this->lockdia(false);
    MCG.start();
}

void FM::onpercent(double percent)
{
    rud->setpercent(percent);
    if(percent==1){
        qDebug("Close copdia 0");
        try{
            rud->close();
        }catch(...){
            qDebug("rud dialog threw an error!");
        }

        qDebug("Close copdia 1");

        if(MCG.isRunning()){
            MCG.terminate();
            MCG.wait();
        }
        qDebug("Close copdia 2");
        MCG.setlist(psl);
        qDebug("Close copdia 3");
        this->lockdia(false);
        qDebug("Close copdia 4");
        MCG.start();
        qDebug("Close copdia 5");
        emit thrcopenddia();
        qDebug("Close copdia 6");
    }
}

void FM::onthrcopenddia()
{
    qDebug("copend dia 0");
    QMessageBox::information(this,"复制标记","标记复制完成！");
    qDebug("copend dia 1");
}

void FM::lockdia(bool ok)
{
    ui->pitl->setEnabled(ok);
    ui->copm->setEnabled(ok);
    ui->clem->setEnabled(ok);
    ui->edim->setEnabled(ok);
}

void FM::oncopflagdia(QString path,QString pit,QString symbol,QString pathn)
{
    QMessageBox::StandardButton result=QMessageBox::warning(this,"重复的标记","在路径\n"+path+"\n中已存在"+pit+"音阶的采样\""+symbol+"\"\n是否要覆盖？\n源位置："+pathn+"\n",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::YesToAll|QMessageBox::NoToAll|QMessageBox::Cancel),QMessageBox::Cancel);
    cot.changedflag(result);
}
