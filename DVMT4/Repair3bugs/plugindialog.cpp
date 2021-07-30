#include "plugindialog.h"
#include "ui_plugindialog.h"

PluginDialog::PluginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PluginDialog)
{
    ui->setupUi(this);
}

PluginDialog::PluginDialog(QWidget *parent,Project *pro):
    QDialog(parent),
    ui(new Ui::PluginDialog),
    project(pro)
{
    ui->setupUi(this);
}

PluginDialog::~PluginDialog()
{
    delete ui;
}


void PluginDialog::on_repair_clicked()
{
    QString path=QFileDialog::getExistingDirectory(this,"选择dvcfg所在的目录",QDir::currentPath());
    if(!path.isEmpty()){
        QVector<DVSym> symbollist;
        if(!VCH::getall(&symbollist,path)){
            QMessageBox::warning(this,"出错","未能读取dvcfg文件");
            return;
        }

        QFile file(path+"/voice.dvcfg");
        if(!file.copy(path+"/voice.dvcfg.old")){
            QMessageBox::warning(this,"出错","未能备份dvcfg文件");
            return;
        }
        for(int i=0;i<symbollist.size();i++){
            DVSym sym=symbollist.at(i);
            if(sym.srcType=="VX"||sym.srcType=="INDIE"){
                sym.tailPoint+=0.06;
                if(!VCH::set(&sym)){
                    QMessageBox::warning(this,"出错","未能写入标记："+sym.symbol);
                }
            }
        }
        QMessageBox::information(this,"bug修正","完成！");
    }
}

