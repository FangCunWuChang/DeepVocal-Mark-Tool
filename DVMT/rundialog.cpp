#include "rundialog.h"
#include "ui_rundialog.h"

RunDialog::RunDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RunDialog)
{
    ui->setupUi(this);
}

RunDialog::~RunDialog()
{
    delete ui;
}

void RunDialog::setText(QString text)
{
    this->setWindowTitle(text);
    ui->label->setText(text);
}

void RunDialog::setpercent(double percent)
{
    ui->num->setValue(100*percent);
}

void RunDialog::closeEvent(QCloseEvent *event)
{
    if(ui->num->value()==100){
        event->accept();
    }else{
        event->ignore();
    }
}
