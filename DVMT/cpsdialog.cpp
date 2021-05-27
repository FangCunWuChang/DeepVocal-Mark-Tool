#include "cpsdialog.h"
#include "ui_cpsdialog.h"

CPSDialog::CPSDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CPSDialog)
{
    ui->setupUi(this);
}

CPSDialog::~CPSDialog()
{
    delete ui;
}

void CPSDialog::setpl(QStringList psl)
{
    ui->lcb->clear();
    for(int i=0;i<psl.size();i++){
        ui->lcb->addItem(psl.at(i));
    }
    acceptflag=false;
}

void CPSDialog::on_P1_currentTextChanged(const QString &arg1)
{
    pit=arg1+ui->P2->currentText();
}

void CPSDialog::on_P2_currentTextChanged(const QString &arg1)
{
    pit=ui->P1->currentText()+arg1;
}

void CPSDialog::on_cancel_clicked()
{
    acceptflag=false;
    this->close();
}

void CPSDialog::on_enter_clicked()
{
    path=ui->lcb->currentText();
    acceptflag=true;
    this->close();
}
