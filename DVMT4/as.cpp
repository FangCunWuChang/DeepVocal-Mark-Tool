#include "as.h"
#include "ui_as.h"

AS::AS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AS)
{
    ui->setupUi(this);
}

AS::~AS()
{
    delete ui;
}

void AS::resizeEvent(QResizeEvent *event)
{
    resizeNow();
    QWidget::resizeEvent(event);
}

void AS::resizeNow()
{
    ui->ene->resize(0.1*width(),0.15*height()/5);
    ui->rptz->resize(0.1*width(),0.15*height()/5);
    ui->rea->resize(0.1*width(),0.15*height()/5);
    ui->cle->resize(0.1*width(),0.15*height()/5);
    ui->ene->move(0.2*width()+2*0.04*height(),0.04*height()+0*0.15*height()/5);
    ui->rptz->move(0.2*width()+2*0.04*height(),0.04*height()+1*0.15*height()/5);
    ui->rea->move(0.2*width()+2*0.04*height(),0.04*height()+3*0.15*height()/5);
    ui->cle->move(0.2*width()+2*0.04*height(),0.04*height()+4*0.15*height()/5);
    QFont font;
    font.setPixelSize(0.1*height()/7);
    ui->ene->setFont(font);
    ui->rptz->setFont(font);
    ui->rea->setFont(font);
    ui->cle->setFont(font);
    repaint();
}

void AS::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setColor(QColor(255,255,255,0.2*255));
    painter.setPen(pen);
    painter.fillRect(0.2*width()+2*0.04*height(),0.04*height(),0.1*width(),0.15*height(),QColor(31,31,31));
    painter.drawLine(0.2*width()+2*0.04*height()+0.01*width(),0.04*height()+2*0.15*height()/5+0.075*height()/5,0.2*width()+2*0.04*height()+0.09*width(),0.04*height()+2*0.15*height()/5+0.075*height()/5);
    if(ui->ene->isChecked()){
        QPixmap icon(":/icons/icons/ok.png");
        double sizemin=(double)((double)(0.02*width())/(double)icon.width());
        sizemin*=0.5;

        int poix=0.2*width()+2*0.04*height()+0.01*width()-icon.width()*sizemin/2;
        int poiy=(0.04*height()+0*0.15*height()/5)+(0.15*height()/5)/2-icon.height()*sizemin/2;
        int w=icon.width()*sizemin;
        int h=icon.height()*sizemin;
        painter.drawPixmap(poix,poiy,w,h,icon);
    }
    if(ui->rptz->isChecked()){
        QPixmap icon(":/icons/icons/ok.png");
        double sizemin=(double)((double)(0.02*width())/(double)icon.width());
        sizemin*=0.5;

        int poix=0.2*width()+2*0.04*height()+0.01*width()-icon.width()*sizemin/2;
        int poiy=(0.04*height()+1*0.15*height()/5)+(0.15*height()/5)/2-icon.height()*sizemin/2;
        int w=icon.width()*sizemin;
        int h=icon.height()*sizemin;
        painter.drawPixmap(poix,poiy,w,h,icon);
    }
    QWidget::paintEvent(event);
}

void AS::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->pos().x()>0.2*width()+2*0.04*height()&&event->pos().x()<=0.2*width()+2*0.04*height()+0.1*width()&&event->pos().y()>=0.04*height()&&event->pos().y()<=0.04*height()+0.15*height())){
        this->hide();
    }
    QWidget::mouseReleaseEvent(event);
}

void AS::on_ene_clicked(bool checked)
{
    emit key(7+checked);
    repaint();
}

void AS::on_rptz_clicked(bool checked)
{
    emit key(9+checked);
    repaint();
}

void AS::on_rea_clicked()
{
    this->hide();
    emit key(11);
}

void AS::on_cle_clicked()
{
    this->hide();
    emit key(12);
}

void AS::setene(bool ok)
{
    ui->ene->setChecked(ok);
    repaint();
}

void AS::setrptz(bool ok)
{
    ui->rptz->setChecked(ok);
    repaint();
}

void AS::setrea(bool ok)
{
    ui->rea->setEnabled(ok);
}

void AS::setcle(bool ok)
{
    ui->cle->setEnabled(ok);
}

void AS::pushene()
{
    ui->ene->setChecked(!ui->ene->isChecked());
    emit key(7+ui->ene->isChecked());
    repaint();
}

void AS::pushrptz()
{
    ui->rptz->setChecked(!ui->rptz->isChecked());
    emit key(9+ui->rptz->isChecked());
    repaint();
}

void AS::pushrea()
{
    this->hide();
    emit key(11);
}

void AS::pushcle()
{
    this->hide();
    emit key(12);
}
