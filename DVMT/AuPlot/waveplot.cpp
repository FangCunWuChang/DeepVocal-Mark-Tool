#include "waveplot.h"
#include "ui_waveplot.h"

Waveplot::Waveplot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Waveplot)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
}

Waveplot::~Waveplot()
{
    delete pixmap;
    pixmap=nullptr;
    delete pixene;
    pixene=nullptr;
    delete pixrptz;
    pixrptz=nullptr;
    delete ui;
}

void Waveplot::resizeEvent(QResizeEvent *event)
{
    repaint();
    QWidget::resizeEvent(event);
}

void Waveplot::paintEvent(QPaintEvent *event)
{
    QPixmap pixback(0.975*this->width(),this->height());
    pixback.fill(QColor(255,255,255,0));
    QPainter painter(&pixback);
    QPen pen;
    QBrush brush;
    pen.setWidth(1);
    pen.setColor(QColor(136,138,133,150));
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    brush.setColor(QColor(85,87,83));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    if(vs>=0.5){
        for(int i=0;i<=10;i++){
            QLine lined(0,height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2)),width(),height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2)));
            painter.drawLine(lined);
            QLine lineu(0,height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2)),width(),height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2)));
            painter.drawLine(lineu);

        }
    }else{
        for(int i=0;i<=50;i++){
            QLine lined(0,height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2)),width(),height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2)));
            painter.drawLine(lined);
            QLine lineu(0,height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2)),width(),height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2)));
            painter.drawLine(lineu);
        }

    }

    painter.end();
    painter.begin(this);

    pen.setWidth(1);
    pen.setColor(QColor(136,138,133));
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    brush.setColor(QColor(85,87,83));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.fillRect(0,0,0.975*width(),height(),Qt::black);

    int hss=-(double)((double)((double)((double)this->width()*(double)0.975)/(double)(he-hs))*(double)hs);
    int hsw=(double)((double)((double)this->width()*(double)0.975)/(double)(he-hs));

    if(pixmap!=nullptr){
        painter.drawPixmap(hss,(double)((double)height()/(double)2)-(double)((double)1/(double)vs)*(double)((double)height()/(double)2),hsw,(double)((double)1/(double)vs)*(double)height(),*pixmap);
        painter.drawPixmap(0,0,0.975*width(),height(),pixback);
    }
    if(pixene!=nullptr){
        if(eneon){
            painter.drawPixmap(hss,0,hsw,height(),*pixene);
        }

    }
    if(pixrptz!=nullptr){
        if(rptzon){
            painter.drawPixmap(hss,0,hsw,height(),*pixrptz);
        }

    }

    if(selected){
        pen.setColor(Qt::gray);
        pen.setWidth(2);
        pen.setStyle(Qt::DashLine);
        painter.setPen(pen);
        brush.setColor(QColor(255,255,255,100));
        painter.setBrush(brush);
        painter.drawRect((double)((double)(ssp-hs)/(double)(he-hs))*(double)(0.975*width()),0,(double)((double)(sep-hs)/(double)(he-hs))*(double)(0.975*width())-(double)((double)(ssp-hs)/(double)(he-hs))*(double)(0.975*width()),this->height());
    }

    pen.setWidth(2);
    pen.setColor(QColor(136,138,133));
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    painter.fillRect(0.975*width(),0,0.025*width(),height(),QColor(46,52,54));
    //painter.drawRect(QRect(0,0,width()-1,height()-1));

    QFont font;

    font.setPointSize(height()*0.05);
    painter.setFont(font);

    if(pixmap!=nullptr){
        if(fourlines){
            //qDebug("l1%.2f",l1*pixmap->width());
            if(l1*pixmap->width()>=global::sets::perp&&l1*pixmap->width()<=pixmap->width()-global::sets::perp){
                pen.setColor(QColor(114,159,207));
                painter.setPen(pen);
                QLine linel((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
                painter.drawLine(linel);
                painter.drawText((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.15*height(),"1.CP");
            }
            if(l2*pixmap->width()>=global::sets::perp&&l2*pixmap->width()<=pixmap->width()-global::sets::perp){
                pen.setColor(QColor(252,233,79));
                painter.setPen(pen);
                QLine linel((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
                painter.drawLine(linel);
                painter.drawText((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.2*height(),"2.PP");
            }
            if(l3*pixmap->width()>=global::sets::perp&&l3*pixmap->width()<=pixmap->width()-global::sets::perp){
                pen.setColor(QColor(173,127,168));
                painter.setPen(pen);
                QLine linel((double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
                painter.drawLine(linel);
                painter.drawText((double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width()),0.25*height(),"3.VSP");
            }
            if(l4*pixmap->width()>=global::sets::perp&&l4*pixmap->width()<=pixmap->width()-global::sets::perp){
                pen.setColor(QColor(138,226,52));
                painter.setPen(pen);
                QLine linel((double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
                painter.drawLine(linel);
                painter.drawText((double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width()),0.3*height(),"4.VEP");
            }
        }else{
            if(l1*pixmap->width()>=global::sets::perp&&l1*pixmap->width()<=pixmap->width()-global::sets::perp){
                pen.setColor(QColor(114,159,207));
                painter.setPen(pen);
                QLine linel((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
                painter.drawLine(linel);
                painter.drawText((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.15*height(),"1.SP");
            }
            if(l2*pixmap->width()>=global::sets::perp&&l2*pixmap->width()<=pixmap->width()-global::sets::perp){
                pen.setColor(QColor(252,233,79));
                painter.setPen(pen);
                QLine linel((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
                painter.drawLine(linel);
                painter.drawText((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.2*height(),"2.EP");
            }
        }

    }

    font.setPointSize(height()/50);
    painter.setFont(font);
    pen.setWidth(1);
    pen.setColor(QColor(136,138,133));
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    if(vs>=0.5){
        for(int i=0;i<=10;i++){
            QLine lined(0.975*width(),height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2)),0.98*width(),height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2)));
            painter.drawLine(lined);
            QLine lineu(0.975*width(),height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2)),0.98*width(),height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2)));
            painter.drawLine(lineu);
            double numu=0,numd=0;
            numu=(double)((double)i/(double)10);
            numd=-(double)((double)i/(double)10);
            QString stru=QString::number(numu),strd=QString::number(numd);
            painter.drawText(QPoint(0.985*width(),height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2))+((double)(height()/100))),stru);
            painter.drawText(QPoint(0.985*width(),height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)10)*(height()/2))+((double)(height()/100))),strd);
        }
    }else{
        for(int i=0;i<=50;i++){
            QLine lined(0.975*width(),height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2)),0.98*width(),height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2)));
            painter.drawLine(lined);
            QLine lineu(0.975*width(),height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2)),0.98*width(),height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2)));
            painter.drawLine(lineu);
            double numu=0,numd=0;
            numu=(double)((double)i/(double)50);
            numd=-(double)((double)i/(double)50);
            QString stru=QString::number(numu),strd=QString::number(numd);
            painter.drawText(QPoint(0.985*width(),height()/2-((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2))+((double)(height()/100))),stru);
            painter.drawText(QPoint(0.985*width(),height()/2+((double)((double)1/(double)vs)*(double)((double)i/(double)50)*(height()/2))+((double)(height()/100))),strd);
        }
    }

    if(isxon){
        pen.setWidth(2);
        pen.setColor(Qt::red);
        painter.setPen(pen);

        painter.drawLine(QLine(xw,0,xw,height()));

        font.setPointSize(height()/30);
        painter.setFont(font);
        pen.setColor(QColor(255,255,255));
        painter.setPen(pen);

        double per1=hs+(double)((double)xw/(double)(this->width()*0.975))*(double)(he-hs);
        int poi1=(double)per1*(double)pixmap->width();
        double time=(double)poi1/(double)44100;

        double num=(double)((double)((double)((double)((double)height()/(double)2)-yw)/(double)((double)1/(double)vs))/(double)((double)height()/(double)2));
        //QString labelstring="t="+QString::number(time)+"s fre="+QString::number(fre)+"Hz";
        if(yon){
            painter.drawEllipse(QPointF(xw,yw),2,2);
            QString labelstring=QString::asprintf("时间=%.2fs 数值=%.3f",time,num);
            painter.drawText(xw,yw,labelstring);

        }


        bool ok=true;
        int index=getindex(xw,&ok);
        if(enetemp.size()>0&&ok){
            if(eneon){
                pen.setColor(Qt::yellow);
                pen.setWidth(1);
                painter.setPen(pen);
                brush.setColor(Qt::yellow);
                painter.setBrush(brush);
                double enen=enetemp.at(index);

                int poiyw=this->height()-2*(double)((double)enen*(double)this->height());
                painter.drawEllipse(QPointF(xw,poiyw),2,2);
                QString enestring=QString::asprintf("短时能量=%.3f",enen);
                painter.drawText(xw,poiyw,enestring);
            }
            if(rptzon){
                pen.setColor(Qt::green);
                pen.setWidth(1);
                painter.setPen(pen);
                brush.setColor(Qt::green);
                painter.setBrush(brush);
                double rptzn=rptztemp.at(index);

                int poiyw=this->height()-2*(double)((double)rptzn*(double)this->height());
                painter.drawEllipse(QPointF(xw,poiyw),2,2);
                QString rptzstring=QString::asprintf("短时过零率=%.3f",rptzn);
                painter.drawText(xw,poiyw,rptzstring);
            }
            /*
            pen.setColor(Qt::green);
            pen.setWidth(1);
            painter.setPen(pen);
            brush.setColor(Qt::green);
            painter.setBrush(brush);
            double acfn=acftemp.at(index);
            int poiyp=pixacf->height()-static_cast<double>((double)acfn/(double)((double)samplerates/(double)global::sets::step));
            int poiyw=this->height()-(double)((double)((double)((double)(pixacf->height()-poiyp)/(double)pixacf->height())/(double)vs)*(double)this->height());
            painter.drawEllipse(QPointF(xw,poiyw),2,2);
            QString acfstring=QString::asprintf("base=%.2fHz",acfn);
            painter.drawText(xw,poiyw,acfstring);*/

        }
    }
    if(isin&&!(isxon&&yon)){
        pen.setColor(QColor(255,255,255));
        painter.setPen(pen);
        painter.drawEllipse(mn,2,2);
    }

    QWidget::paintEvent(event);
}

void Waveplot::setpix(QPixmap pixmap,QPixmap pixene,QPixmap pixrptz)
{
    *(this->pixmap)=pixmap;
    *(this->pixene)=pixene;
    *(this->pixrptz)=pixrptz;
    repaint();
}

void Waveplot::wheelEvent(QWheelEvent *event)
{
    if(event->pos().x()>0.975*width()){
        double nn=-event->delta();
        if(vs+(double)((double)nn/(double)1000)>1){
            vs=1;
        }else if(vs+(double)((double)nn/(double)1000)<=0.1){
            vs=0.1;
        }else{
           vs+=(double)((double)nn/(double)1000);
        }
        repaint();
    }else{
        double nn=event->delta();
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

void Waveplot::seths(double hs,double he)
{
    this->hs=hs;
    this->he=he;
    repaint();
}

void Waveplot::changemode(int code)
{
    switch (code) {
    case 1:
        eneon=false;
        break;
    case 2:
        eneon=true;
        break;
    case 3:
        rptzon=false;
        break;
    case 4:
        rptzon=true;
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }
    repaint();
}

void Waveplot::setv(QVector<double> enetemp,QVector<double> rptztemp)
{
    this->enetemp=enetemp;
    this->rptztemp=rptztemp;
    repaint();
}

void Waveplot::mouseMoveEvent(QMouseEvent *event)
{
    mn=event->pos();
    int xw=event->pos().x();
    if(xw>=0&&xw<=this->width()*0.975){
        this->isxon=true;
        this->yon=true;
        emit xon(true);
        this->xw=xw;
        this->yw=event->pos().y();
        emit xmoved(xw);

    }else{
        this->isxon=false;
        emit xon(false);
    }
    if(rpressed){
        double sxt0=sxt;
        if(event->pos().x()>=0&&event->pos().x()<=this->width()*0.975){
            sxt0=hs+(double)((double)event->pos().x()/(double)(this->width()*0.975))*(he-hs);
        }else{
            if(event->pos().x()>=this->width()*0.975){
                double xc=he+(double)((double)(event->pos().x()-this->width()*0.975)/(double)(this->width()*0.975))*(he-hs);
                if(xc>1){
                    xc=1;
                }if(xc<hs+0.001){
                    xc=hs+0.001;
                }
                emit hschanged(hs,xc);
                sxt0=xc;
            }else{
                double xc=hs-(double)((double)(0-event->pos().x())/(double)(this->width()*0.975))*(he-hs);
                if(xc>he-0.001){
                    xc=he-0.001;
                }if(xc<0){
                    xc=0;
                }
                emit hschanged(xc,he);
                sxt0=xc;
            }
        }

        emit changesp(true,qMin(sxt,sxt0),qMax(sxt,sxt0));

    }
    if(spressed){
        double pxt=hs+(double)((double)event->pos().x()/(double)(this->width()*0.975))*(he-hs);
        if(event->pos().x()>=0&&event->pos().x()<=this->width()*0.975){
            pxt=hs+(double)((double)event->pos().x()/(double)(this->width()*0.975))*(he-hs);
        }else{
            if(event->pos().x()>=this->width()*0.975){
                double xc=he+(double)((double)(event->pos().x()-this->width()*0.975)/(double)(this->width()*0.975))*(he-hs);
                if(xc>1){
                    xc=1;
                }if(xc<hs+0.001){
                    xc=hs+0.001;
                }
                emit hschanged(hs,xc);
                pxt=xc;
            }else{
                double xc=hs-(double)((double)(0-event->pos().x())/(double)(this->width()*0.975))*(he-hs);
                if(xc>he-0.001){
                    xc=he-0.001;
                }if(xc<0){
                    xc=0;
                }
                emit hschanged(xc,he);
                pxt=xc;
            }
        }
        if(pxt*pixmap->width()>=global::sets::perp&&pxt*pixmap->width()<=pixmap->width()-global::sets::perp){
            emit pmove(pxt);
        }else if(pxt*pixmap->width()<global::sets::perp){
            emit pmove((double)((double)global::sets::perp/(double)pixmap->width()));
        }else{
            emit pmove((double)((double)(pixmap->width()-global::sets::perp)/(double)pixmap->width()));
        }

    }


    repaint();
    QWidget::mouseMoveEvent(event);
}

void Waveplot::enterEvent(QEvent *event)
{
    this->yon=true;
    isin=true;
    repaint();
    QWidget::enterEvent(event);
}

void Waveplot::leaveEvent(QEvent *event)
{
    rpressed=false;
    isin=false;
    sxt=0;
    this->isxon=false;
    this->yw=-30;
    this->yon=false;
    emit xon(false);
    emit prefresh();
    repaint();
    QWidget::leaveEvent(event);
}

void Waveplot::setxw(int xw)
{
    this->xw=xw;
    repaint();
}

void Waveplot::setxon(bool xon)
{
    this->isxon=xon;
    repaint();
}

int Waveplot::getindex(int xw,bool *ok)
{
    double per1=hs+(double)((double)xw/(double)(this->width()*0.975))*(double)(he-hs);
    int poi1=per1*pixmap->width();
    //int index=qFloor((double)((double)(poi1-global::sets::step/2)/(double)(pixmap->width()-global::sets::step))*enetemp.size());
    int index=qFloor((double)((double)(poi1-(double)((double)(global::sets::step-(double)((double)global::sets::step/(double)global::sets::times))/(double)2))*(double)global::sets::times)/(double)global::sets::step);
    *ok=true;
    if(index<0){
        index=0;
        *ok=false;
    }
    if(index>=enetemp.size()){
        index=enetemp.size()-1;
        *ok=false;
    }
    return index;
}

void Waveplot::setselected(bool selected,double ssp,double sep)
{
    this->selected=selected;
    this->ssp=ssp;
    this->sep=sep;
    repaint();
}

void Waveplot::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton){
        if(event->pos().x()>=0&&event->pos().x()<=this->width()*0.975){
            sxt=hs+(double)((double)event->pos().x()/(double)(this->width()*0.975))*(he-hs);
            rpressed=true;
            emit changesp(false,sxt,sxt);
        }
    }
    if(event->button()==Qt::LeftButton){
        if(event->pos().x()>=0&&event->pos().x()<=this->width()*0.975){
            spressed=true;
            double pxt=hs+(double)((double)event->pos().x()/(double)(this->width()*0.975))*(he-hs);
            if(pxt*pixmap->width()>=global::sets::perp&&pxt*pixmap->width()<=pixmap->width()-global::sets::perp){
                emit pmove(pxt);
            }else if(pxt*pixmap->width()<global::sets::perp){
                emit pmove((double)((double)global::sets::perp/(double)pixmap->width()));
            }else{
                emit pmove((double)((double)(pixmap->width()-global::sets::perp)/(double)pixmap->width()));
            }


        }
    }

}

void Waveplot::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton){
        if(rpressed){
            double sxt0=sxt;
            if(event->pos().x()>=0&&event->pos().x()<=this->width()*0.975){
                sxt0=hs+(double)((double)event->pos().x()/(double)(this->width()*0.975))*(he-hs);
            }else{
                if(event->pos().x()>=this->width()*0.975){
                    double xc=he+(double)((double)(event->pos().x()-this->width()*0.975)/(double)(this->width()*0.975))*(he-hs);
                    if(xc>1){
                        xc=1;
                    }if(xc<hs+0.001){
                        xc=hs+0.001;
                    }
                    emit hschanged(hs,xc);
                    sxt0=xc;
                }else{
                    double xc=hs-(double)((double)(0-event->pos().x())/(double)(this->width()*0.975))*(he-hs);
                    if(xc>he-0.001){
                        xc=he-0.001;
                    }if(xc<0){
                        xc=0;
                    }
                    emit hschanged(xc,he);
                    sxt0=xc;
                }
            }

            emit changesp(true,qMin(sxt,sxt0),qMax(sxt,sxt0));

            rpressed=false;
            sxt=0;
        }


    }
    if(event->button()==Qt::LeftButton){
        if(spressed){
            double pxt=hs+(double)((double)event->pos().x()/(double)(this->width()*0.975))*(he-hs);
            if(event->pos().x()>=0&&event->pos().x()<=this->width()*0.975){
                pxt=hs+(double)((double)event->pos().x()/(double)(this->width()*0.975))*(he-hs);
            }else{
                if(event->pos().x()>=this->width()*0.975){
                    double xc=he+(double)((double)(event->pos().x()-this->width()*0.975)/(double)(this->width()*0.975))*(he-hs);
                    if(xc>1){
                        xc=1;
                    }if(xc<hs+0.001){
                        xc=hs+0.001;
                    }
                    emit hschanged(hs,xc);
                    pxt=xc;
                }else{
                    double xc=hs-(double)((double)(0-event->pos().x())/(double)(this->width()*0.975))*(he-hs);
                    if(xc>he-0.001){
                        xc=he-0.001;
                    }if(xc<0){
                        xc=0;
                    }
                    emit hschanged(xc,he);
                    pxt=xc;
                }
            }
            if(pxt*pixmap->width()>=global::sets::perp&&pxt*pixmap->width()<=pixmap->width()-global::sets::perp){
                emit point(pxt);
            }else if(pxt*pixmap->width()<global::sets::perp){
                emit point((double)((double)global::sets::perp/(double)pixmap->width()));
            }else{
                emit point((double)((double)(pixmap->width()-global::sets::perp)/(double)pixmap->width()));
            }

            spressed=false;


        }
    }

}

void Waveplot::setlines(double l1,double l2,double l3,double l4)
{
    this->l1=l1;
    this->l2=l2;
    this->l3=l3;
    this->l4=l4;
    repaint();
}

void Waveplot::setfourlines(bool fourlines)
{
    this->l1=0;
    this->l2=0;
    this->l3=0;
    this->l4=0;
    spressed=false;
    this->fourlines=fourlines;
    repaint();
}

bool Waveplot::event(QEvent *event)
{
    switch( event ->type( ) )
    {
    case QEvent::TouchBegin:
    {
        auto touchEvent = static_cast<QTouchEvent *>(event);
        auto&& touchPoints = touchEvent->touchPoints();
        if (touchPoints.count() == 2)
        {
            // 有2个手指触屏
            // determine scale factor
            const auto& touchPoint0 = touchPoints.first();
            const auto& touchPoint1 = touchPoints.last();
            //double currentScaleFactor =QLineF(touchPoint0.pos(), touchPoint1.pos()).length()/ QLineF(touchPoint0.startPos(), touchPoint1.startPos()).length();
            int pcw=(touchPoint0.startPos().x()+touchPoint1.startPos().x())/2;
            if(pcw<=this->width()*0.975){
                hspt=hs;
                hept=he;
            }else{
                vst=vs;
            }

            // 计算当前的缩放比

        }
        break;
    }
    case QEvent::TouchUpdate:
    {
        auto touchEvent = static_cast<QTouchEvent *>(event);
        auto&& touchPoints = touchEvent->touchPoints();
        if (touchPoints.count() == 2)
        {
            // 有2个手指触屏
            // determine scale factor
            const auto& touchPoint0 = touchPoints.first();
            const auto& touchPoint1 = touchPoints.last();
            double currentScaleFactor =QLineF(touchPoint0.pos(), touchPoint1.pos()).length()/ QLineF(touchPoint0.startPos(), touchPoint1.startPos()).length();
            int pcw=(touchPoint0.startPos().x()+touchPoint1.startPos().x())/2;
            if(pcw<=this->width()*0.975){
                double pcp=hspt+(pcw/this->width())*(hept-hspt);
                double psn=hspt+(pcp-hspt)*(1/currentScaleFactor);
                double pen=hept-(hept-pcp)*(1/currentScaleFactor);
                emit hschanged(qMax(0.0,psn),qMin(pen,1.0));
            }else{
                if(vst*(double)(1/currentScaleFactor)>1){
                    vs=1;
                }else if(vst*(double)(1/currentScaleFactor)<=0.1){
                    vs=0.1;
                }else{
                   vs=vst*(double)(1/currentScaleFactor);
                }
                repaint();
            }

            // 计算当前的缩放比

        }
        break;
    }
    case QEvent::TouchEnd:
    {
        auto touchEvent = static_cast<QTouchEvent *>(event);
        auto&& touchPoints = touchEvent->touchPoints();
        if (touchPoints.count() == 2)
        {
            // 有2个手指触屏
            // determine scale factor
            const auto& touchPoint0 = touchPoints.first();
            const auto& touchPoint1 = touchPoints.last();
            auto currentScaleFactor =QLineF(touchPoint0.pos(), touchPoint1.pos()).length()/ QLineF(touchPoint0.startPos(), touchPoint1.startPos()).length();
            int pcw=(touchPoint0.startPos().x()+touchPoint1.startPos().x())/2;
            if(pcw<=this->width()*0.975){
                double pcp=hspt+(pcw/this->width())*(hept-hspt);
                double psn=hspt+(pcp-hspt)*(1/currentScaleFactor);
                double pen=hept-(hept-pcp)*(1/currentScaleFactor);
                emit hschanged(qMax(0.0,psn),qMin(pen,1.0));
            }else{
                if(vst*(double)(1/currentScaleFactor)>1){
                    vs=1;
                }else if(vst*(double)(1/currentScaleFactor)<=0.1){
                    vs=0.1;
                }else{
                   vs=vst*(double)(1/currentScaleFactor);
                }
                repaint();
            }

            // 计算当前的缩放比
            if (touchEvent->touchPointStates() & Qt::TouchPointReleased)
            {
                // 如果释放触点，保存上次的缩放比
                hspt=0;
                hept=0;
                vst=0;
            }
        }
        break;
        // 如果不许好后续处理
        // e ->accept( true );
    }
    default:
        // 其他的事件
        break;

    }

    return QWidget::event(event);
}
