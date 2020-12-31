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
    ui->newp->resize(0.46*width(),height()/14);
    ui->open->resize(0.46*width(),height()/14);
    ui->save->resize(0.46*width(),height()/14);
    ui->sets->resize(0.46*width(),height()/14);
    ui->read->resize(0.46*width(),height()/14);
    ui->about->resize(0.46*width(),height()/14);
    ui->newp->move(0.27*width(),0.25*height()+0*(height()/14)+1*(height()/98));
    ui->open->move(0.27*width(),0.25*height()+1*(height()/14)+2*(height()/98));
    ui->save->move(0.27*width(),0.25*height()+2*(height()/14)+3*(height()/98));
    ui->sets->move(0.27*width(),0.25*height()+3*(height()/14)+4*(height()/98));
    ui->read->move(0.27*width(),0.25*height()+4*(height()/14)+5*(height()/98));
    ui->about->move(0.27*width(),0.25*height()+5*(height()/14)+6*(height()/98));
    repaint();
    QWidget::resizeEvent(event);
}

void Menu::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(211,215,207,100));
    painter.fillRect(0.20*width(),0.20*height(),0.6*width(),0.6*height(),QColor(85,87,83));
    QWidget::paintEvent(event);
}

void Menu::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->pos().x()>=0.20*width()&&event->pos().x()<=0.80*width()&&event->pos().y()>=0.20*height()&&event->pos().y()<=0.80*height())){
        this->hide();
    }
    QWidget::mouseReleaseEvent(event);
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
