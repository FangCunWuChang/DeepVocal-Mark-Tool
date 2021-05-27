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
    ui->newp->resize(0.1*width(),0.2*height()/7);
    ui->open->resize(0.1*width(),0.2*height()/7);
    ui->save->resize(0.1*width(),0.2*height()/7);
    ui->push->resize(0.1*width(),0.2*height()/7);
    ui->sets->resize(0.1*width(),0.2*height()/7);
    ui->read->resize(0.1*width(),0.2*height()/7);
    ui->about->resize(0.1*width(),0.2*height()/7);
    ui->newp->move(width()-0.1*width(),0.04*height()+0*0.2*height()/7);
    ui->open->move(width()-0.1*width(),0.04*height()+1*0.2*height()/7);
    ui->save->move(width()-0.1*width(),0.04*height()+2*0.2*height()/7);
    ui->push->move(width()-0.1*width(),0.04*height()+3*0.2*height()/7);
    ui->sets->move(width()-0.1*width(),0.04*height()+4*0.2*height()/7);
    ui->read->move(width()-0.1*width(),0.04*height()+5*0.2*height()/7);
    ui->about->move(width()-0.1*width(),0.04*height()+6*0.2*height()/7);
    QFont font;
    font.setPixelSize(0.1*height()/6);
    ui->newp->setFont(font);
    ui->open->setFont(font);
    ui->save->setFont(font);
    ui->push->setFont(font);
    ui->sets->setFont(font);
    ui->read->setFont(font);
    ui->about->setFont(font);
    repaint();
}

void Menu::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setColor(QColor(255,255,255,0.2*255));
    painter.setPen(pen);
    painter.fillRect(width()-0.1*width(),0.04*height(),0.1*width(),0.2*height(),QColor(31,31,31));
    painter.drawLine(width()-0.09*width(),0.04*height()+3*0.2*height()/7+0.1*height()/7,width()-0.01*width(),0.04*height()+3*0.2*height()/7+0.1*height()/7);
    QWidget::paintEvent(event);
}

void Menu::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->pos().x()>=width()-0.1*width()&&event->pos().x()<=width()&&event->pos().y()>=0.04*height()&&event->pos().y()<=0.04*height()+0.2*height())){
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


void Menu::on_push_clicked()
{
    eggcount++;
    if(eggcount==10){
        eggcount=0;
        this->hide();
        emit egg();
    }
}

void Menu::show()
{
    eggcount=0;
    QWidget::show();
}
