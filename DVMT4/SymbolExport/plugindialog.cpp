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


void PluginDialog::on_path_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        ui->okb->setEnabled(true);
    }else{
        ui->okb->setEnabled(false);
    }
}


void PluginDialog::on_explore_clicked()
{
    QString file=QFileDialog::getSaveFileName(this,"选择保存位置",QDir::currentPath(),"文本文档(*.txt)");
    if(!file.isEmpty()){
        ui->path->setText(file);
    }
}


void PluginDialog::on_okb_clicked()
{
    QStringList symboll=project->getsymbols();
    if(Symbolcheck::check(symboll)){
        QVector<CVVCSymbol> symbols=Symbolcheck::split(symboll);
        QString data;
        for(int i=0;i<symbols.size();i++){
            data+=symbols.at(i).name;
            data+="\n";
        }
        QFile file(ui->path->text());
        if(file.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text)){
            file.write(data.toUtf8());
            file.close();
            QMessageBox::information(this,"导出Symbol list","导出完成！");
        }else{
            QMessageBox::warning(this,"出错","未能导出文件");
        }
    }else{
        QMessageBox::warning(this,"出错","Symbol list存在错误");
    }

}

