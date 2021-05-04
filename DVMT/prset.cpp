#include "prset.h"
#include "ui_prset.h"

Prset::Prset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prset)
{
    ui->setupUi(this);
    //connect(ui->enterbut,&QPushButton::toggled,this,&Prset::on_enterbut_toggled,Qt::UniqueConnection);
    //connect(ui->cancelbut,&QPushButton::toggled,this,&Prset::on_cancelbut_toggled,Qt::UniqueConnection);
    ui->la->hide();
}

Prset::~Prset()
{
    fmd->close();
    delete fmd;
    delete ui;
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
    this->canenter=false;
}

void Prset::Accept(QString mes)
{
    ui->la->setText(mes);
    ui->le->setText("错误");
    ui->le->hide();
    ui->la->show();
    this->canenter=true;
}

void Prset::setproject(Project pro)
{
    this->pro=pro;
    fmd->setpro(pro);
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
    QString path=QFileDialog::getExistingDirectory(this,"添加目录",QCoreApplication::applicationDirPath());
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

void Prset::on_flagm_clicked()
{
    QMessageBox::StandardButton result = QMessageBox::warning(this,"警告！","该功能为实验功能，可能无法稳定运行。\n功能中存在的漏洞可能会导致程序崩溃。\n确定要使用此功能嘛？",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No),QMessageBox::No);
    if(result==QMessageBox::Yes){
        fmd->exec();
        emit prochanged(this->pro,true);
    }

}
/*
void Prset::on_enterbut_toggled(bool checked)
{
    Q_UNUSED(checked);
    if(canenter){
        qDebug("Enter 0");
        Project pro;
        QString data=ui->dic->toPlainText();
        if(!data.isEmpty()){
            QStringList dl=data.split("\n",QString::SkipEmptyParts);
            pro.setsymbols(dl);
        }
        qDebug("Enter 1");
        QString ps=ui->P1->currentText()+ui->P2->currentText();
        pro.setpitch(ps);
        qDebug("Enter 2");
        QStringList pl;
        for(int i=0;i<ui->path->count();i++){
            pl.append(ui->path->item(i)->text());
        }
        qDebug("Enter 3");
        pro.setpaths(pl);
        qDebug("Enter 4");
        pro.setflags(Symbolcheck::split(pro.getsymbols()));
        qDebug("Enter 5");
        emit prochanged(pro,false);
        qDebug("Enter 6");
        this->pro=pro;
        this->close();
        qDebug("Enter 7");
    }

}

void Prset::on_cancelbut_toggled(bool checked)
{
    Q_UNUSED(checked);
    this->close();
}
*/

void Prset::closeEvent(QCloseEvent *event)
{
    if(canenter){
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
        pro.setflags(Symbolcheck::split(pro.getsymbols()));
        if(pro!=this->pro){
            QMessageBox::StandardButton result=QMessageBox::information(this,"项目变化","项目设置已修改，是否保留修改？",QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel),QMessageBox::Cancel);
            if(result==QMessageBox::Yes){
                emit prochanged(pro,false);
                this->pro=pro;
                event->accept();
            }else if(result==QMessageBox::No){
                event->accept();
            }else{
                event->ignore();
            }
        }else{
            event->accept();
        }

    }else{
        event->accept();
    }
}
