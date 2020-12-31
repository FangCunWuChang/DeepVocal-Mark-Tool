#include "waveview.h"
#include "ui_waveview.h"

Waveview::Waveview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Waveview)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
}

Waveview::~Waveview()
{
    delete pixmap;
    pixmap=nullptr;
    delete ui;
}

void Waveview::resizeEvent(QResizeEvent *event)
{
    repaint();
    QWidget::resizeEvent(event);
}

void Waveview::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    pen.setWidth(1);
    pen.setColor(QColor(136,138,133));
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    brush.setColor(QColor(85,87,83));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    brush.setColor(Qt::black);
    painter.setBrush(brush);
    painter.drawRect(QRect(0,0,width()-1,height()-1));
    if(pixmap!=nullptr){
        painter.drawPixmap(0,0,width(),height(),*pixmap);
    }
    if(selected){
        pen.setColor(Qt::gray);
        pen.setWidth(1);
        pen.setStyle(Qt::DashLine);
        painter.setPen(pen);
        brush.setColor(QColor(255,255,255,100));
        painter.setBrush(brush);
        painter.drawRect(ssp*width(),0,(sep-ssp)*width(),this->height());
    }
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    if(pixmap!=nullptr){
        if(l1*pixmap->width()>=global::sets::perp&&l1*pixmap->width()<=pixmap->width()-global::sets::perp){
            pen.setColor(QColor(114,159,207));
            painter.setPen(pen);
            QLine linel((double)l1*(double)(0.975*width()),0,(double)l1*(double)(0.975*width()),height());
            painter.drawLine(linel);

        }
        if(l2*pixmap->width()>=global::sets::perp&&l2*pixmap->width()<=pixmap->width()-global::sets::perp){
            pen.setColor(QColor(252,233,79));
            painter.setPen(pen);
            QLine linel((double)l2*(double)(0.975*width()),0,(double)l2*(double)(0.975*width()),height());
            painter.drawLine(linel);

        }
        if(l3*pixmap->width()>=global::sets::perp&&l3*pixmap->width()<=pixmap->width()-global::sets::perp){
            pen.setColor(QColor(173,127,168));
            painter.setPen(pen);
            QLine linel((double)l3*(double)(0.975*width()),0,(double)l3*(double)(0.975*width()),height());
            painter.drawLine(linel);

        }
        if(l4*pixmap->width()>=global::sets::perp&&l4*pixmap->width()<=pixmap->width()-global::sets::perp){
            pen.setColor(QColor(138,226,52));
            painter.setPen(pen);
            QLine linel((double)l4*(double)(0.975*width()),0,(double)l4*(double)(0.975*width()),height());
            painter.drawLine(linel);

        }


    }
    QRect rect(hs*width(),0,(he-hs)*width(),height());
    pen.setColor(Qt::white);
    pen.setWidth(4);
    pen.setJoinStyle(Qt::RoundJoin);
    brush.setColor(QColor(255,255,255,0));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(rect);
    QWidget::paintEvent(event);
}

void Waveview::setpix(QPixmap pixmap)
{
    *(this->pixmap)=pixmap;
    repaint();
}

void Waveview::seths(double hs,double he)
{
    this->hs=hs;
    this->he=he;
    repaint();
}

void Waveview::mouseMoveEvent(QMouseEvent *event)
{
    if(event->pos().x()>=0&&event->pos().x()<=width()){
        if(modeflag==0){
            if((double)((double)event->pos().x()/(double)width())>=hs+0.005&&(double)((double)event->pos().x()/(double)width())<=he-0.005){
                this->setCursor(Qt::OpenHandCursor);
            }else if((double)((double)event->pos().x()/(double)width())>=hs-0.005&&(double)((double)event->pos().x()/(double)width())<hs+0.005){
                this->setCursor(Qt::SplitHCursor);
            }else if((double)((double)event->pos().x()/(double)width())<=he+0.005&&(double)((double)event->pos().x()/(double)width())>he-0.005){
                this->setCursor(Qt::SplitHCursor);
            }else{
                this->setCursor(Qt::ArrowCursor);
            }
        }else if(modeflag==1){
            nx=event->pos().x();
            ny=event->pos().y();
            double delta=(double)((double)(nx-px)/(double)width());
            if(hst+delta>=0&&het+delta<=1){
                emit hschanged(hst+delta,het+delta);
            }
        }else if(modeflag==2){
            nx=event->pos().x();
            ny=event->pos().y();
            double delta=(double)((double)(nx-px)/(double)width());
            if(hst+delta>=0){
                if(het>hst+delta){
                    emit hschanged(hst+delta,het);
                }

            }
        }else if(modeflag==3){
            nx=event->pos().x();
            ny=event->pos().y();
            double delta=(double)((double)(nx-px)/(double)width());
            if(het+delta<=1){
                if(het+delta>hst){
                    emit hschanged(hst,het+delta);
                }

            }
        }else{

        }
    }

    QWidget::mouseMoveEvent(event);
}

void Waveview::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(event->pos().x()>=0&&event->pos().x()<=width()){
            if(modeflag==0){
                if((double)((double)event->pos().x()/(double)width())>=hs+0.005&&(double)((double)event->pos().x()/(double)width())<=he-0.005){
                    this->setCursor(Qt::ClosedHandCursor);
                    px=event->pos().x();
                    py=event->pos().y();
                    hst=hs;
                    het=he;
                    modeflag=1;
                }else if((double)((double)event->pos().x()/(double)width())>=hs-0.005&&(double)((double)event->pos().x()/(double)width())<hs+0.005){
                    this->setCursor(Qt::SplitHCursor);
                    px=event->pos().x();
                    py=event->pos().y();
                    hst=hs;
                    het=he;
                    modeflag=2;
                }else if((double)((double)event->pos().x()/(double)width())<=he+0.005&&(double)((double)event->pos().x()/(double)width())>he-0.005){
                    this->setCursor(Qt::SplitHCursor);
                    px=event->pos().x();
                    py=event->pos().y();
                    hst=hs;
                    het=he;
                    modeflag=3;
                }else{
                    this->setCursor(Qt::ArrowCursor);
                }
        }

        }
    }

    QWidget::mousePressEvent(event);
}

void Waveview::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if((double)((double)event->pos().x()/(double)width())>=hs+0.005&&(double)((double)event->pos().x()/(double)width())<=he-0.005){
            this->setCursor(Qt::OpenHandCursor);
        }else if((double)((double)event->pos().x()/(double)width())>=hs-0.005&&(double)((double)event->pos().x()/(double)width())<hs+0.005){
            this->setCursor(Qt::SplitHCursor);
        }else if((double)((double)event->pos().x()/(double)width())<=he+0.005&&(double)((double)event->pos().x()/(double)width())>he-0.005){
            this->setCursor(Qt::SplitHCursor);
        }else{
            this->setCursor(Qt::ArrowCursor);
        }
        if(event->pos().x()>=0&&event->pos().x()<=width()){
            if(modeflag==1){
                nx=event->pos().x();
                ny=event->pos().y();
                double delta=(double)((double)(nx-px)/(double)width());
                if(hst+delta>=0&&het+delta<=1){
                    emit hschanged(hst+delta,het+delta);
                }

                }else if(modeflag==2){
                nx=event->pos().x();
                ny=event->pos().y();
                double delta=(double)((double)(nx-px)/(double)width());
                if(hst+delta>=0){
                    if(het>hst+delta){
                        emit hschanged(hst+delta,het);
                    }

                }
                }else if(modeflag==3){
                nx=event->pos().x();
                ny=event->pos().y();
                double delta=(double)((double)(nx-px)/(double)width());
                if(het+delta<=1){
                    if(het+delta>hst){
                        emit hschanged(hst,het+delta);
                    }

                }
                }else{

                }

            hst=0;
            het=0;
            px=0;
            py=0;
            nx=0;
            ny=0;
            modeflag=0;
        }
        }


    QWidget::mouseReleaseEvent(event);
}

void Waveview::wheelEvent(QWheelEvent *event)
{
    if((double)((double)event->pos().x()/(double)width())>=hs+0.005&&(double)((double)event->pos().x()/(double)width())<=he-0.005){
        double nn=-event->delta();
        double np=hs+(double)((double)event->pos().x()/(double)width())*(double)(he-hs);
        double hsn=hs+(np-hs)*(nn/1000);
        double hen=he-(he-np)*(nn/1000);
        if(hsn<0){
           hsn=0;
        }
        if(hen>1){
            hen=1;
        }
        emit hschanged(hsn,hen);
    }
    QWidget::wheelEvent(event);
}

void Waveview::setlines(double l1,double l2,double l3,double l4)
{
    this->l1=l1;
    this->l2=l2;
    this->l3=l3;
    this->l4=l4;
    repaint();
}

void Waveview::setselected(bool selected,double ssp,double sep)
{
    this->selected=selected;
    this->ssp=ssp;
    this->sep=sep;
    repaint();
}
