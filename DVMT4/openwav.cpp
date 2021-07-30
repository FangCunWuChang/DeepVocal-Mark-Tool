#include "openwav.h"
#include "ui_openwav.h"

OpenWav::OpenWav(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenWav)
{
    ui->setupUi(this);
    ui->la->hide();
    OWError("请选择一个文件");
}

OpenWav::~OpenWav()
{
    delete ui;
}

void OpenWav::OWError(QString mes)
{
    ui->le->setText(mes);
    ui->la->setText("正确");
    ui->la->hide();
    ui->le->show();
    ui->enter->setEnabled(false);
}

void OpenWav::OWAccept(QString mes)
{
    ui->la->setText(mes);
    ui->le->setText("错误");
    ui->le->hide();
    ui->la->show();
    ui->enter->setEnabled(true);
}

void OpenWav::setps(QStringList paths,QVector<QStringList> filelist)
{
    path="";
    file="";
    ps.clear();
    fv.clear();
    this->ps=paths;
    QString pshow;
    int pi=0;
    while(pi<ps.size()){
        QStringList pl;
        for(int i=0;i<filelist.at(pi).size();i++){
            QString ft=filelist.at(pi).at(i);
            QString slt=ft;
            slt.remove(".wav",Qt::CaseInsensitive);
            if(ui->name->text().isEmpty()){
                pl.append(ft);
            }else{
                if(slt.contains(ui->name->text(),Qt::CaseInsensitive)){
                    pl.append(ft);
                }
            }

        }
        pshow+=ps.at(pi)+"\n";
        fv.append(pl);
        pi++;
    }
    ui->plist->clear();
    ui->plist->setText(pshow);
    while(ui->olist->count()>0){

        QListWidgetItem *it=ui->olist->takeItem(0);
        delete it;
    }
    for(int i=0;i<fv.size();i++){
        for(int j=0;j<fv.at(i).size();j++){
            ui->olist->addItem(fv.at(i).at(j));
            ui->olist->item(ui->olist->count()-1)->setToolTip(ps.at(i));
        }
    }

    if(!(path.isEmpty()||file.isEmpty())){
        OWAccept("正确");
    }else{
        OWError("请选择一个文件");
    }
}
void OpenWav::on_cancel_clicked()
{
    this->close();
}

void OpenWav::on_enter_clicked()
{
    if(!(path.isEmpty()||file.isEmpty())){
        OWAccept("正确");
        emit filechanged(path,file);
        this->close();
    }else{
        OWError("请选择一个文件");
    }


}

void OpenWav::on_name_textChanged(const QString &arg1)
{
    while(ui->olist->count()>0){
        QListWidgetItem *it=ui->olist->takeItem(0);
        delete it;
    }
    for(int i=0;i<fv.size();i++){
        for(int j=0;j<fv.at(i).size();j++){
            if(!arg1.isEmpty()){
                QString slt=fv.at(i).at(j);
                slt.remove(".wav",Qt::CaseInsensitive);
                if(slt.contains(arg1,Qt::CaseInsensitive)){
                    ui->olist->addItem(fv.at(i).at(j));
                    ui->olist->item(ui->olist->count()-1)->setToolTip(ps.at(i));
                }
            }else{
                ui->olist->addItem(fv.at(i).at(j));
                ui->olist->item(ui->olist->count()-1)->setToolTip(ps.at(i));
            }

        }
    }
    path="";
    file="";
    if(!(path.isEmpty()||file.isEmpty())){
        OWAccept("正确");
    }else{
        OWError("请选择一个文件");
    }
}

void OpenWav::on_olist_itemPressed(QListWidgetItem *item)
{
    if(ui->olist->count()>0){
        path=item->toolTip();
        file=item->text();
        if(!(path.isEmpty()||file.isEmpty())){
            OWAccept("正确");
        }else{
            OWError("请选择一个文件");
        }
    }
}
