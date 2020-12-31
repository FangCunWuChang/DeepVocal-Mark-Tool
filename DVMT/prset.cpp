#include "prset.h"
#include "ui_prset.h"

Prset::Prset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prset)
{
    ui->setupUi(this);
    ui->la->hide();
}

Prset::~Prset()
{
    delete ui;
}

void Prset::on_cancel_clicked()
{
    this->close();
}

void Prset::on_dic_textChanged()
{
    QString data=ui->dic->toPlainText();
    if(!data.isEmpty()){
        QStringList dl=data.split("\n",QString::SkipEmptyParts);
        QString error=Symbolcheck::error(dl);
        if(dl.size()>0){
            if(error=="正确"){
                Accept(error);
            }else{
                Error(error);
            }
        }else{
            Error("字典不可为空");
        }

    }else{
        Error("字典不可为空");
    }

}

void Prset::Error(QString mes)
{
    ui->le->setText(mes);
    ui->la->setText("正确");
    ui->la->hide();
    ui->le->show();
    ui->enter->setEnabled(false);
}

void Prset::Accept(QString mes)
{
    ui->la->setText(mes);
    ui->le->setText("错误");
    ui->le->hide();
    ui->la->show();
    ui->enter->setEnabled(true);
}

void Prset::setproject(Project pro)
{
    QStringList dl=pro.getsymbols();
    QString dict;
    for(int i=0;i<dl.size();i++){
        dict+=dl.at(i);
        if(i!=dl.size()-1){
            dict+="\n";
        }
    }
    ui->dic->clear();
    ui->dic->setPlainText(dict);
    QString error=Symbolcheck::error(dl);
    if(dl.size()>0){
        if(error=="正确"){
            Accept(error);
        }else{
            Error(error);
        }
    }else{
        Error("字典不可为空");
    }
    QString ps=pro.getpitch();
    QString p1="C",p2="5";
    if(ps.size()==2){
        p1.clear();
        p1.append(ps.at(0));
        p2.clear();
        p2.append(ps.at(1));
    }else if(ps.size()==3){
        p1.clear();
        p1.append(ps.at(0));
        p1.append(ps.at(1));
        p2.clear();
        p2.append(ps.at(2));
    }else{

    }
    ui->P1->setCurrentText(p1);
    ui->P2->setCurrentText(p2);
    QStringList pl=pro.getpaths();
    ui->path->clear();
    for(int i=0;i<pl.size();i++){
        ui->path->addItem(pl.at(i));
    }
}

void Prset::on_enter_clicked()
{
    Project pro;
    QString data=ui->dic->toPlainText();
    if(!data.isEmpty()){
        QStringList dl=data.split("\n",QString::SkipEmptyParts);
        pro.setsymbols(dl);
    }
    QString ps=ui->P1->currentText()+ui->P2->currentText();
    pro.setpitch(ps);
    QStringList pl;
    for(int i=0;i<ui->path->count();i++){
        pl.append(ui->path->item(i)->text());
    }
    pro.setpaths(pl);
    emit prochanged(pro);
    this->close();
}

void Prset::on_remove_clicked()
{
    if(ui->path->count()>0){
        int cr=ui->path->currentRow();
        QStringList pl;
        for(int i=0;i<ui->path->count();i++){
            pl.append(ui->path->item(i)->text());
        }
        pl.removeAt(cr);
        ui->path->clear();
        for(int i=0;i<pl.size();i++){
            ui->path->addItem(pl.at(i));
        }
    }

}

void Prset::on_add_clicked()
{
    QString path=QFileDialog::getExistingDirectory(this,"添加目录",QDir::currentPath());
    if(!path.isEmpty()){
        bool flag=false;
        int row=0;
        for(int i=0;i<ui->path->count();i++){
            if(ui->path->item(i)->text()==path){
                flag=true;
                row=i;
                break;
            }
        }
        if(!flag){
            ui->path->addItem(path);
            ui->path->setCurrentRow(ui->path->count()-1);
        }else{
            ui->path->setCurrentRow(row);
            QMessageBox::warning(this,"提示","列表中已有路径："+path);
        }
    }
}
