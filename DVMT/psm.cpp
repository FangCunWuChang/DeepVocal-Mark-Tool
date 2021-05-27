#include "psm.h"
#include "ui_psm.h"

PSM::PSM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PSM)
{
    ui->setupUi(this);
}

PSM::~PSM()
{
    delete ui;
}

void PSM::on_des_clicked()
{
    if(ui->pslist->currentRow()>=0&&ui->pslist->currentRow()<symlist.size()){
        DVSym symt=symlist.at(ui->pslist->currentRow());
        QMessageBox::StandardButton result=QMessageBox::warning(this,"删除标记","删除标记"+symt.symbol+"吗？",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No),QMessageBox::No);
        if(result==QMessageBox::Yes){
            if(VCH::remove(&symt)){
                QMessageBox::information(this,"删除标记","已删除标记:"+symt.symbol);
                symlist.remove(ui->pslist->currentRow());
                refreshlist();
            }else{
                QMessageBox::information(this,"删除标记","未能删除标记:"+symt.symbol);
            }
        }

    }
}

void PSM::on_cos_clicked()
{
    if(ui->pslist->currentRow()>=0&&ui->pslist->currentRow()<symlist.size()){
        DVSym symt=symlist.at(ui->pslist->currentRow());
        QString oname=QInputDialog::getText(this,"复制标记"+symt.symbol+"至","输入目标名称：");
        if(!oname.isEmpty()){

            bool nameok=true;
            if(symt.srcType=="CV"){
                if(oname.contains("_")){
                    nameok=false;
                }
            }else if(symt.srcType=="VX"){
                int numc=0;
                for(int i=0;i<oname.size();i++){
                    if(oname.at(i)=='_'){
                        numc++;
                    }
                }
                if(numc!=1){
                    nameok=false;
                }
            }else{
                if(oname.contains("_")){
                    nameok=false;
                }
            }

            if(nameok){
                QString nname=symt.symbol;
                bool cflag=false;
                int cid=-1;
                for(int i=0;i<symlist.size();i++){
                    if(symlist.at(i).symbol==oname){
                        cflag=true;
                        cid=i;
                        break;
                    }
                }
                if(cflag){
                    QMessageBox::StandardButton result=QMessageBox::warning(this,"复制标记","目标标记"+oname+"已存在，覆盖吗？",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No),QMessageBox::No);
                    if(result==QMessageBox::Yes){
                        symt.symbol=oname;
                        if(VCH::set(&symt)){
                            QMessageBox::information(this,"复制标记","已复制标记"+nname+"至"+symt.symbol);
                            symlist.replace(cid,symt);
                            refreshlist();
                        }else{
                            QMessageBox::information(this,"复制标记","未能复制标记"+nname+"至"+symt.symbol);
                        }

                    }
                }else{
                    symt.symbol=oname;
                    if(VCH::set(&symt)){
                        QMessageBox::information(this,"复制标记","已复制标记"+nname+"至"+symt.symbol);
                        symlist.append(symt);
                        refreshlist();
                    }else{
                        QMessageBox::information(this,"复制标记","未能复制标记"+nname+"至"+symt.symbol);
                    }
                }
            }else{
                QMessageBox::warning(this,"复制标记","出错！非法的标记名："+oname);
            }


        }else{
            QMessageBox::warning(this,"复制标记","出错！目标标记不可为空！");
        }
    }
}

void PSM::setPitch(QVector<DVSym> symlist)
{
    this->symlist=symlist;
    refreshlist();
}

void PSM::refreshlist()
{
    ui->pslist->clear();
    for(int i=0;i<symlist.size();i++){
        ui->pslist->addItem(symlist.at(i).symbol);
    }
    if(symlist.size()>0){
        ui->pslist->setCurrentRow(0);
    }
}

void PSM::on_pslist_currentRowChanged(int currentRow)
{
    if(currentRow>=0&&currentRow<symlist.size()){
        DVSym symt=symlist.at(currentRow);
        if(symt.srcType=="CV"){
            ui->sl->setText(symt.symbol);//symbol
            ui->pl->setText(symt.path);//path
            ui->ptl->setText(symt.pitch);//pitch
            ui->stl->setText(symt.srcType);//srcType
            ui->wnl->setText(symt.wavName);//wavName
            ui->utl->setText(symt.updateTime.toString("yyyy-MM-dd hh:mm:ss"));//updateTime
            ui->cpl->setText(QString::number(symt.connectPoint));//connectPoint
            ui->prl->setText(QString::number(symt.preutterance));//preutterance
            ui->srtl->setText(QString::number(symt.startTime));//startTime
            ui->spl->setText("-");//startPoint
            ui->etl->setText(QString::number(symt.endTime));//endTime
            ui->epl->setText("-");//endPoint
            ui->tpl->setText(QString::number(symt.tailPoint));//tailPoint
            ui->vsl->setText(QString::number(symt.vowelStart));//vowelStart
            ui->vel->setText(QString::number(symt.vowelEnd));//vowelEnd
        }else if(symt.srcType=="VX"){
            ui->sl->setText(symt.symbol);//symbol
            ui->pl->setText(symt.path);//path
            ui->ptl->setText(symt.pitch);//pitch
            ui->stl->setText(symt.srcType);//srcType
            ui->wnl->setText(symt.wavName);//wavName
            ui->utl->setText(symt.updateTime.toString("yyyy-MM-dd hh:mm:ss"));//updateTime
            ui->cpl->setText(QString::number(symt.connectPoint));//connectPoint
            ui->prl->setText("-");//preutterance
            ui->srtl->setText(QString::number(symt.startTime));//startTime
            ui->spl->setText("-");//startPoint
            ui->etl->setText(QString::number(symt.endTime));//endTime
            ui->epl->setText("-");//endPoint
            ui->tpl->setText(QString::number(symt.tailPoint));//tailPoint
            ui->vsl->setText("-");//vowelStart
            ui->vel->setText("-");//vowelEnd
        }else{
            ui->sl->setText(symt.symbol);//symbol
            ui->pl->setText(symt.path);//path
            ui->ptl->setText(symt.pitch);//pitch
            ui->stl->setText(symt.srcType);//srcType
            ui->wnl->setText(symt.wavName);//wavName
            ui->utl->setText(symt.updateTime.toString("yyyy-MM-dd hh:mm:ss"));//updateTime
            ui->cpl->setText("-");//connectPoint
            ui->prl->setText("-");//preutterance
            ui->srtl->setText(QString::number(symt.startTime));//startTime
            ui->spl->setText(QString::number(symt.startPoint));//startPoint
            ui->etl->setText(QString::number(symt.endTime));//endTime
            ui->epl->setText(QString::number(symt.endPoint));//endPoint
            ui->tpl->setText("-");//tailPoint
            ui->vsl->setText("-");//vowelStart
            ui->vel->setText("-");//vowelEnd
        }
    }else{
        ui->sl->setText("-");//symbol
        ui->pl->setText("-");//path
        ui->ptl->setText("-");//pitch
        ui->stl->setText("-");//srcType
        ui->wnl->setText("-");//wavName
        ui->utl->setText("-");//updateTime
        ui->cpl->setText("-");//connectPoint
        ui->prl->setText("-");//preutterance
        ui->srtl->setText("-");//startTime
        ui->spl->setText("-");//startPoint
        ui->etl->setText("-");//endTime
        ui->epl->setText("-");//endPoint
        ui->tpl->setText("-");//tailPoint
        ui->vsl->setText("-");//vowelStart
        ui->vel->setText("-");//vowelEnd
    }
}
