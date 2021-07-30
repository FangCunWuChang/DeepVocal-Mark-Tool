#include "stip.h"
#include "ui_stip.h"

STip::STip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::STip)
{
    ui->setupUi(this);
    this->hide();
}

STip::~STip()
{
    delete ui;
}

void STip::setnum(int num)
{
    ui->num->setValue(num);
    if(num<100){
        this->show();
    }else{
        this->hide();
    }
}

void STip::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(31,31,31));
    QWidget::paintEvent(event);
}
