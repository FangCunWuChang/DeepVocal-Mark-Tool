#include "openwav.h"
#include "ui_openwav.h"

OpenWav::OpenWav(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenWav)
{
    ui->setupUi(this);
    ui->la->hide();
    Error("请选择一个文件");
}

OpenWav::~OpenWav()
{
    delete ui;
}

void OpenWav::Error(QString mes)
{
    ui->le->setText(mes);
    ui->la->setText("正确");
    ui->la->hide();
    ui->le->show();
    ui->enter->setEnabled(false);
}

void OpenWav::Accept(QString mes)
{
    ui->la->setText(mes);
    ui->le->setText("错误");
    ui->le->hide();
    ui->la->show();
    ui->enter->setEnabled(true);
}

void OpenWav::setps(QStringList paths)
{
    path="";
    file="";
    ps.clear();
    fv.clear();
    this->ps=paths;
    QString pshow;
    //qDebug("1");
    int pi=0;
    while(pi<ps.size()){
        QDir dir(ps.at(pi));
        if(dir.exists()){
            dir.setFilter(QDir::Files);
            QStringList pl;
            for(uint i=0;i<dir.count();i++){
                QString ft=dir[i];
                if(ft.endsWith(".wav",Qt::CaseInsensitive)){
                    if(ui->name->text().isEmpty()){
                        //qDebug("%s",qPrintable(ft));
                        if(QWaveHandle::checkwav(ps.at(pi)+"/"+ft,1,44100,16,2*global::sets::perp)){
                            pl.append(ft);
                        }
                    }else{
                        if(ft.contains(ui->name->text(),Qt::CaseInsensitive)){
                            //qDebug("%s",qPrintable(ft));
                            if(QWaveHandle::checkwav(ps.at(pi)+"/"+ft,1,44100,16,2*global::sets::perp)){
                                pl.append(ft);
                            }
                        }
                    }
                }

            }
            pshow+=ps.at(pi)+"\n";
            fv.append(pl);
            pi++;
        }else{
            ps.removeAt(pi);
        }
    }
    //qDebug("2");
    ui->plist->clear();
    ui->plist->setText(pshow);
    //qDebug("3");
    //ui->list->clear();
    while(ui->list->count()>0){

        QListWidgetItem *it=ui->list->takeItem(0);
        delete it;
    }
    //qDebug("3.1");
    for(int i=0;i<fv.size();i++){
        for(int j=0;j<fv.at(i).size();j++){
            ui->list->addItem(fv.at(i).at(j));
            ui->list->item(ui->list->count()-1)->setToolTip(ps.at(i));
        }
    }

    if(!(path.isEmpty()||file.isEmpty())){
        Accept("正确");
    }else{
        Error("请选择一个文件");
    }
    //qDebug("4");
}
void OpenWav::on_cancel_clicked()
{
    this->close();
}

void OpenWav::on_enter_clicked()
{
    if(!(path.isEmpty()||file.isEmpty())){
        Accept("正确");
        emit filechanged(path,file);
        this->close();
    }else{
        Error("请选择一个文件");
    }


}

void OpenWav::on_name_textChanged(const QString &arg1)
{
    //ui->list->clear();
    while(ui->list->count()>0){
        QListWidgetItem *it=ui->list->takeItem(0);
        delete it;
    }
    for(int i=0;i<fv.size();i++){
        for(int j=0;j<fv.at(i).size();j++){
            if(!arg1.isEmpty()){
                if(fv.at(i).at(j).contains(arg1,Qt::CaseInsensitive)){
                    ui->list->addItem(fv.at(i).at(j));
                    ui->list->item(ui->list->count()-1)->setToolTip(ps.at(i));
                }
            }else{
                ui->list->addItem(fv.at(i).at(j));
                ui->list->item(ui->list->count()-1)->setToolTip(ps.at(i));
            }

        }
    }
    path="";
    file="";
    if(!(path.isEmpty()||file.isEmpty())){
        Accept("正确");
    }else{
        Error("请选择一个文件");
    }
}

/*
void OpenWav::on_list_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    Q_UNUSED(previous);
    if(ui->list->count()>0){
        path=current->toolTip();
        file=current->text();
        if(!(path.isEmpty()||file.isEmpty())){
            Accept("正确");
        }else{
            Error("请选择一个文件");
        }
    }

}
*/
void OpenWav::on_list_itemPressed(QListWidgetItem *item)
{
    if(ui->list->count()>0){
        path=item->toolTip();
        file=item->text();
        if(!(path.isEmpty()||file.isEmpty())){
            Accept("正确");
        }else{
            Error("请选择一个文件");
        }
    }
}
