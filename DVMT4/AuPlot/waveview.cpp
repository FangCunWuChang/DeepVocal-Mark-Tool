#include "waveview.h"
#include "ui_waveview.h"

Waveview::Waveview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Waveview)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    pm2->fill(Qt::black);
}

Waveview::~Waveview()
{
    delete pm2;
    delete ui;
}

void Waveview::resizeEvent(QResizeEvent *event)
{
    pixchange();
    repaint();
    QWidget::resizeEvent(event);
}

void Waveview::pixchange()
{
    pm2->fill(Qt::black);
    pm2->scaled(scaletimes_wv*width(),scaletimes_wv*height());
    QPainter painter(pm2);
    QPen pen;
    QBrush brush;
    pen.setWidth(1);
    pen.setColor(QColor(68,206,246));//波形：蓝
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    brush.setColor(QColor(68,206,246,200));//波形：蓝
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    QPolygon poly;
    poly.append(QPoint(-1,(double)((double)(pm2->height())/(double)2)));
    for(int i=0;i<pt.size();i++){
        poly.append(g_poi(i,pt.at(i)));

    }
    poly.append(QPoint((pm2->width())+1,(double)((double)pm2->height()/(double)2)));
    painter.drawPolygon(poly);
    int perp=global_sets::perp;
    QRect rectl(0,0,(double)((double)qMax(perp,global_sets::step/2)/(double)pt.size())*pm2->width(),pm2->height());
    QRect rectr(pm2->width()-(double)((double)qMax(perp,global_sets::step/2)/(double)pt.size())*pm2->width(),0,(double)((double)qMax(perp,global_sets::step/2)/(double)pt.size())*pm2->width(),pm2->height());
    painter.fillRect(rectl,QColor(195,33,54,100));//分析区：枣红
    painter.fillRect(rectr,QColor(195,33,54,100));//分析区：枣红
    painter.end();
}

QPoint Waveview::g_poi(int x,double y)
{
    return QPoint((double)((double)x/(double)pt.size())*pm2->width(),(double)((double)(pm2->height())/(double)2)-((double)((double)(pm2->height())/(double)2)*y));
}


void Waveview::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);//背景：黑色
    painter.setBrush(brush);
    painter.drawRect(QRect(0,0,width()-1,height()-1));
    painter.drawPixmap(0,0,width(),height(),*pm2);
    if(selected){
        pen.setColor(QColor(224,240,233));//选择框：素
        pen.setWidth(1);
        pen.setStyle(Qt::DashLine);
        painter.setPen(pen);
        brush.setColor(QColor(224,240,233,100));//选择框：素
        painter.setBrush(brush);
        painter.drawRect(ssp*width(),0,(sep-ssp)*width(),this->height());
    }
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    if(l1*pt.size()>=global_sets::perp&&l1*pt.size()<=pt.size()-global_sets::perp){
        pen.setColor(QColor(75,92,196));//一线：宝蓝
        painter.setPen(pen);
        QLine linel((double)l1*(double)(width()),0,(double)l1*(double)(width()),height());
        painter.drawLine(linel);

    }
    if(l2*pt.size()>=global_sets::perp&&l2*pt.size()<=pt.size()-global_sets::perp){
        pen.setColor(QColor(255,140,49));//二线：杏黄
        painter.setPen(pen);
        QLine linel((double)l2*(double)(width()),0,(double)l2*(double)(width()),height());
        painter.drawLine(linel);

    }
    if(l3*pt.size()>=global_sets::perp&&l3*pt.size()<=pt.size()-global_sets::perp){
        pen.setColor(QColor(203,58,86));//三线：茜色
        painter.setPen(pen);
        QLine linel((double)l3*(double)(width()),0,(double)l3*(double)(width()),height());
        painter.drawLine(linel);

    }
    if(l4*pt.size()>=global_sets::perp&&l4*pt.size()<=pt.size()-global_sets::perp){
        pen.setColor(QColor(127,236,173));//四线：缥
        painter.setPen(pen);
        QLine linel((double)l4*(double)(width()),0,(double)l4*(double)(width()),height());
        painter.drawLine(linel);

    }
    QRect rect(hs*width(),0,(he-hs)*width(),height());
    pen.setColor(QColor(214,236,240));//区域框：月白
    pen.setWidth(4);
    pen.setJoinStyle(Qt::RoundJoin);
    brush.setColor(QColor(214,236,240,0));//区域框：月白
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(rect);
    QWidget::paintEvent(event);
}

void Waveview::setpix(QVector<double> pixmap)
{
    pt=pixmap;
    pixchange();
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
    if(true){
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
            }else if(hst+delta<0){
                emit hschanged(0,het-hst);
            }else{
                emit hschanged(1-(het-hst),1);
            }
        }else if(modeflag==2){
            nx=event->pos().x();
            ny=event->pos().y();
            double delta=(double)((double)(nx-px)/(double)width());
            if(hst+delta>=0){
                if(het>hst+delta){
                    emit hschanged(hst+delta,het);
                }

            }else{
                if(het>0){
                    emit hschanged(0,het);
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

            }else{
                if(1>hst){
                    emit hschanged(hst,1);
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
        if(true){
            if(modeflag==1){
                nx=event->pos().x();
                ny=event->pos().y();
                double delta=(double)((double)(nx-px)/(double)width());
                if(hst+delta>=0&&het+delta<=1){
                    emit hschanged(hst+delta,het+delta);
                }else if(hst+delta<0){
                    emit hschanged(0,het-hst);
                }else{
                    emit hschanged(1-(het-hst),1);
                }

                }else if(modeflag==2){
                nx=event->pos().x();
                ny=event->pos().y();
                double delta=(double)((double)(nx-px)/(double)width());
                if(hst+delta>=0){
                    if(het>hst+delta){
                        emit hschanged(hst+delta,het);
                    }

                }else{
                    if(het>0){
                        emit hschanged(0,het);
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

                }else{
                    if(1>hst){
                        emit hschanged(hst,1);
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
    if((double)((double)event->position().x()/(double)width())>=hs+0.005&&(double)((double)event->position().x()/(double)width())<=he-0.005){
        double nn=-event->angleDelta().y();
        double np=hs+(double)((double)event->position().x()/(double)width())*(double)(he-hs);
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
