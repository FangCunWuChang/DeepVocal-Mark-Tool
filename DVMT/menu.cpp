#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::resizeEvent(QResizeEvent *event)
{
    resizeNow();
    QWidget::resizeEvent(event);
}

void Menu::resizeNow()
{
    ui->newp->resize(0.1*width(),0.2*height()/6);
    ui->open->resize(0.1*width(),0.2*height()/6);
    ui->save->resize(0.1*width(),0.2*height()/6);
    ui->sets->resize(0.1*width(),0.2*height()/6);
    ui->read->resize(0.1*width(),0.2*height()/6);
    ui->about->resize(0.1*width(),0.2*height()/6);
    ui->newp->move(x,y+0*0.2*height()/6);
    ui->open->move(x,y+1*0.2*height()/6);
    ui->save->move(x,y+2*0.2*height()/6);
    ui->sets->move(x,y+3*0.2*height()/6);
    ui->read->move(x,y+4*0.2*height()/6);
    ui->about->move(x,y+5*0.2*height()/6);
    repaint();
}

void Menu::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(255,255,255,0));
    painter.fillRect(x,y,0.1*width(),0.2*height(),QColor(61,59,79));
    QWidget::paintEvent(event);
}

void Menu::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        emit phasemouseplace(event->pos().x(),event->pos().y(),event->globalPos().x(),event->globalPos().y());
    }
    QWidget::mousePressEvent(event);
}

void Menu::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        emit phasemouserel(event->globalPos().x(),event->globalPos().y());
    }
    if(!(event->pos().x()>=x&&event->pos().x()<=x+0.1*width()&&event->pos().y()>=y&&event->pos().y()<=y+0.2*height())){
        this->hide();
    }
    QWidget::mouseReleaseEvent(event);
}

void Menu::mouseMoveEvent(QMouseEvent *event)
{
    emit phasemousemov(event->globalPos().x(),event->globalPos().y());
    QWidget::mouseMoveEvent(event);
}

void Menu::leaveEvent(QEvent *event)
{
    emit phaselea();
    QWidget::leaveEvent(event);
}


void Menu::on_newp_clicked()
{
    this->hide();
    emit key(1);
}

void Menu::on_open_clicked()
{
    this->hide();
    emit key(2);
}

void Menu::on_save_clicked()
{
    this->hide();
    emit key(3);
}

void Menu::on_sets_clicked()
{
    this->hide();
    emit key(4);
}

void Menu::on_read_clicked()
{
    this->hide();
    emit key(5);
}

void Menu::on_about_clicked()
{
    this->hide();
    emit key(6);
}

void Menu::setowlock(bool lock)
{
    if(lock){
        ui->read->setText("正在获取波形列表...");
    }else{
        ui->read->setText("读取波形");
    }
    ui->read->setEnabled(!lock);
}

void Menu::setplace(int x,int y)
{
    this->x=x;
    this->y=y;
    resizeNow();
}
