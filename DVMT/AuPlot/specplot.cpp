#include "specplot.h"
#include "ui_specplot.h"

Specplot::Specplot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Specplot)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    //pixmap->fill(Qt::black);
    //pixacf->fill(Qt::black);
    pm2->fill(Qt::black);
}

Specplot::~Specplot()
{
    /*
    if(pixmap!=nullptr){
        delete pixmap;
        pixmap=nullptr;
    }
    if(pixacf!=nullptr){
        delete pixacf;
        pixacf=nullptr;
    }*/

    delete pm2;
    delete ui;
}

void Specplot::resizeEvent(QResizeEvent *event)
{
    pixchange();
    repaint();
    QWidget::resizeEvent(event);
}

void Specplot::pixchange()
{
    pm2->fill(Qt::black);
    pm2->scaled(width()*scaletimes_sp*0.975,height()*scaletimes_sp);


    QPainter painter(pm2);
    QPen pen;
    QBrush brush;
    pen.setWidth(0);
    pen.setColor(QColor(114,159,207));
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    brush.setColor(QColor(114,159,207,200));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);


    int prew=(double)((double)pm2->width()/(double)(he-hs))*(double)((double)(global_sets::step/2)/(double)wsize);
    int w=(double)((double)pm2->width()/(double)(he-hs))-2*prew;
    int h=(double)((double)pm2->height()/(double)vs);
    int ypos=pm2->height()-h;
    int xpos=prew-(hs*(double)((double)pm2->width()/(double)(he-hs)));

    painter.drawPixmap(xpos,ypos,w,h,pmt);
    int perp=global_sets::perp;
    QRect rectl(-hs*(double)((double)pm2->width()/(double)(he-hs)),0,(double)((double)((double)((double)qMax(perp,global_sets::step/2)/(double)wsize)*pm2->width())/(double)(he-hs)),pm2->height());
    QRect rectr(pm2->width()+(1-he)*(double)((double)pm2->width()/(double)(he-hs))-(double)((double)((double)((double)qMax(perp,global_sets::step/2)/(double)wsize)*pm2->width())/(double)(he-hs)),0,(double)((double)((double)((double)qMax(perp,global_sets::step/2)/(double)wsize)*pm2->width())/(double)(he-hs)),pm2->height());
    painter.fillRect(rectl,QColor(255,255,0,100));
    painter.fillRect(rectr,QColor(255,255,0,100));
    painter.end();
}

void Specplot::tempchange()
{
    min_Bound=0;
    max_Bound=-10000;
    for(int i=0;i<pt.size();i++){
        for(int j=0;j<global_sets::step/2;j++){
            min_Bound=qMin(pt.at(i).at(j),min_Bound);
            max_Bound=qMax(pt.at(i).at(j),max_Bound);
        }
    }
    int Bound_i=(max_Bound-min_Bound);
    max_Bound+=Bound_i*0.2;
    min_Bound-=Bound_i*-0.55;
    qDebug("max:%.3f min:%.3f",max_Bound,min_Bound);
    QPixmap pmt2(pt.size(),global_sets::step/2);
    pmt2.fill(Qt::black);
    QPainter painter(&pmt2);
    QPen pen;
    QBrush brush;
    pen.setWidth(1);
    pen.setColor(QColor(114,159,207));
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    brush.setColor(QColor(114,159,207,200));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    for(int i=0;i<pt.size();i++){
        for(int j=0;j<global_sets::step/2;j++){
            QColor pc=getcolor(pt.at(i).at(j));
            QPoint dp(i,global_sets::step/2-j-1);
            pen.setColor(pc);
            painter.setPen(pen);
            painter.drawPoint(dp);
        }
    }

    painter.end();

    this->pmt=pmt2;
}

QRect Specplot::g_poi(int x,int y)
{
    int xp=x*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2);
    int wp=global_sets::step/global_sets::times;
    int yp=(global_sets::step/2)-y-1;
    int ht=(double)((double)pm2->height()/(double)vs);
    int h=(double)((double)ht/(double)(global_sets::step/2));
    int ypos=pm2->height()-(yp*h);
    double xper=(double)((double)xp/(double)wsize);
    int xpos=(double)((double)(xper-hs)/(double)(he-hs))*pm2->width();
    int w=(double)((double)wp/(double)wsize)*(double)((double)pm2->width()/(double)(he-hs));
    /*
    qDebug("xp:%d",xp);
    qDebug("wp:%d",wp);
    qDebug("yp:%d",yp);
    qDebug("ht:%d",ht);
    qDebug("h:%d",h);
    qDebug("ypos:%d",ypos);
    qDebug("xper:%.2f",xper);
    qDebug("xpos:%d",xpos);
    qDebug("w:%d",w);*/
    return QRect(xpos,ypos,w,h);
}


void Specplot::paintEvent(QPaintEvent *event)
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


    painter.fillRect(0,0,0.975*width(),height(),Qt::black);

    //int hss=-(double)((double)((double)((double)this->width()*(double)0.975)/(double)(he-hs))*(double)hs);
    //int hsw=(double)((double)((double)this->width()*(double)0.975)/(double)(he-hs));

    painter.drawPixmap(0,0,0.975*width(),height(),*pm2);

    if(acfon){
        pen.setStyle(Qt::SolidLine);
        pen.setColor(Qt::green);
        pen.setWidth(2);
        painter.setPen(pen);

        QPolygon polyacf;
        for(int i=0;i<acftemp.size();i++){
            if(flagtemp.at(i)){
                QPoint point(trasx((i*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+i*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+global_sets::step/global_sets::times)/2),height()-((double)((double)1/(double)vs)*(static_cast<double>((double)acftemp.at(i)/(double)((double)global_sets::FS/(double)global_sets::step))))*(double)((double)height()/(double)(double)((double)global_sets::step/(double)2)));
                //qDebug("acf:%d,%.2f",i,pixacf.height()-static_cast<double>((double)acftemp.at(i)/(double)((double)samplespersec/(double)global_sets::step)));
                polyacf.append(point);

            }else{
                QPoint point(trasx((i*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+i*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+global_sets::step/global_sets::times)/2),height()+5);
                //qDebug("acf:%d,%.2f",i,pixacf.height()-static_cast<double>((double)acftemp.at(i)/(double)((double)samplespersec/(double)global_sets::step)));
                polyacf.append(point);

            }

        }

        painter.drawPolyline(polyacf);
        polyacf.clear();
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

    //double ratespec=pixmap->height()/samplerates;




    QFont font;

    font.setPointSize(height()*0.05);
    painter.setFont(font);

    if(fourlines){
        if(l1*this->wsize>=global_sets::perp&&l1*this->wsize<=this->wsize-global_sets::perp){
            pen.setColor(QColor(114,159,207));
            painter.setPen(pen);
            QLine linel((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            painter.drawText((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.15*height(),"1.CP");
        }
        if(l2*this->wsize>=global_sets::perp&&l2*this->wsize<=this->wsize-global_sets::perp){
            pen.setColor(QColor(252,233,79));
            painter.setPen(pen);
            QLine linel((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            painter.drawText((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.2*height(),"2.PP");
        }
        if(l3*this->wsize>=global_sets::perp&&l3*this->wsize<=this->wsize-global_sets::perp){
            pen.setColor(QColor(173,127,168));
            painter.setPen(pen);
            QLine linel((double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            painter.drawText((double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width()),0.25*height(),"3.VSP");
        }
        if(l4*this->wsize>=global_sets::perp&&l4*this->wsize<=this->wsize-global_sets::perp){
            pen.setColor(QColor(138,226,52));
            painter.setPen(pen);
            QLine linel((double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            painter.drawText((double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width()),0.3*height(),"4.VEP");
        }
    }else{
        if(l1*this->wsize>=global_sets::perp&&l1*this->wsize<=this->wsize-global_sets::perp){
            pen.setColor(QColor(114,159,207));
            painter.setPen(pen);
            QLine linel((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            painter.drawText((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.15*height(),"1.SP");
        }
        if(l2*this->wsize>=global_sets::perp&&l2*this->wsize<=this->wsize-global_sets::perp){
            pen.setColor(QColor(252,233,79));
            painter.setPen(pen);
            QLine linel((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            painter.drawText((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.2*height(),"2.EP");
        }
    }

    pen.setWidth(2);
    pen.setColor(QColor(136,138,133));
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    painter.fillRect(0.975*width(),0,width()-0.975*width(),height(),QColor(46,52,54));

    pen.setWidth(1);
    pen.setColor(QColor(136,138,133));
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    font.setPointSize(height()/60);
    painter.setFont(font);

    if(vs>=0.25){
        for(int i=0;i<=20;i++){
            QLine lined(0.975*width(),height()-((double)((double)1/(double)vs)*(double)((double)i/(double)20)*(height())),0.98*width(),height()-((double)((double)1/(double)vs)*(double)((double)i/(double)20)*(height())));
            painter.drawLine(lined);

            double numd=0;

            numd=(double)((double)i/(double)20)*samplerates/2;
            QString strd=QString::number(numd);

            painter.drawText(QPoint(0.985*width(),height()-((double)((double)1/(double)vs)*(double)((double)i/(double)20)*(height()))+((double)(height()/120))),strd);
        }
    }else{
        for(int i=0;i<=100;i++){
            QLine lined(0.975*width(),height()-((double)((double)1/(double)vs)*(double)((double)i/(double)100)*(height())),0.98*width(),height()-((double)((double)1/(double)vs)*(double)((double)i/(double)100)*(height())));
            painter.drawLine(lined);

            double numd=0;

            numd=(double)((double)i/(double)100)*samplerates/2;
            QString strd=QString::number(numd);

            painter.drawText(QPoint(0.985*width(),height()-((double)((double)1/(double)vs)*(double)((double)i/(double)100)*(height()))+((double)(height()/120))),strd);
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
        int poi1=(double)per1*(double)this->wsize;
        double time=(double)poi1/(double)samplerates;

        double fre=(double)((double)((double)(height()-yw)/(double)height())/(double)((double)1/(double)vs))*(double)((double)samplerates/(double)2);

        //QString labelstring="t="+QString::number(time)+"s fre="+QString::number(fre)+"Hz";
        if(yon){
            painter.drawEllipse(QPointF(xw,yw),2,2);
            QString labelstring=QString::asprintf("时间=%.2fs 频率=%.2fHz",time,fre);
            int poixw=xw;
            int poiyw=yw;
            if(poixw+labelstring.size()*font.pointSize()>width()*0.975){
                poixw-=labelstring.size()*font.pointSize();
            }
            if(poiyw-font.pointSize()<0){
                poiyw+=font.pointSize();
            }
            painter.drawText(poixw,poiyw,labelstring);

        }

        bool ok=true;
        int index=getindex(xw,&ok);
        if(acftemp.size()>0&&ok){//
            if(flagtemp.at(index)){
                if(acfon){
                    pen.setColor(Qt::green);
                    pen.setWidth(1);
                    painter.setPen(pen);
                    brush.setColor(Qt::green);
                    painter.setBrush(brush);
                    double acfn=acftemp.at(index);
                    int poiyp=(double)((double)global_sets::step/(double)2)-static_cast<double>((double)acfn/(double)((double)samplerates/(double)global_sets::step));
                    int poiyw=this->height()-(double)((double)((double)((double)((double)((double)global_sets::step/(double)2)-poiyp)/(double)(double)((double)global_sets::step/(double)2))/(double)vs)*(double)this->height());
                    painter.drawEllipse(QPointF(xw,poiyw),2,2);
                    QString acfstring=QString::asprintf("基频=%.2fHz",acfn);
                    int poixw=xw;
                    if(poixw+acfstring.size()*font.pointSize()>width()*0.975){
                        poixw-=acfstring.size()*font.pointSize();
                    }
                    if(poiyw-font.pointSize()<0){
                        poiyw+=font.pointSize();
                    }
                    painter.drawText(poixw,poiyw,acfstring);
                }

            }

        }

    }
    if(isin&&!(isxon&&yon)){
        pen.setColor(QColor(255,255,255));
        painter.setPen(pen);
        painter.drawEllipse(mn,2,2);
    }

    QWidget::paintEvent(event);
}

void Specplot::setpix(QVector<QVector<double>> pixmap,int wsize,int samplerates)
{
    pt=pixmap;
    this->samplerates=samplerates;
    this->wsize=wsize;
    tempchange();
    pixchange();
    repaint();
}

void Specplot::wheelEvent(QWheelEvent *event)
{
    if(event->pos().x()>0.975*width()){
        double nn=-event->delta();
        if(vs+(double)((double)nn/(double)5000)>1){
            vs=1;
        }else if(vs+(double)((double)nn/(double)5000)<=0.1){
            vs=0.1;
        }else{
           vs+=(double)((double)nn/(double)5000);
        }
        pixchange();
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

void Specplot::seths(double hs,double he)
{
    this->hs=hs;
    this->he=he;
    pixchange();
    repaint();
}

void Specplot::changemode(int code)
{
    switch (code) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        acfon=false;
        break;
    case 6:
        acfon=true;
        break;
    default:
        break;
    }
    repaint();
}

void Specplot::setv(QVector<double> acftemp,QVector<bool> flagtemp)
{
    this->acftemp=acftemp;
    this->flagtemp=flagtemp;
    repaint();
}

void Specplot::mouseMoveEvent(QMouseEvent *event)
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
        if(pxt*this->wsize>=global_sets::perp&&pxt*this->wsize<=this->wsize-global_sets::perp){
            emit pmove(pxt);
        }else if(pxt*this->wsize<global_sets::perp){
            emit pmove((double)((double)global_sets::perp/(double)this->wsize));
        }else{
            emit pmove((double)((double)(this->wsize-global_sets::perp)/(double)this->wsize));
        }


    }
    repaint();
    QWidget::mouseMoveEvent(event);
}

void Specplot::enterEvent(QEvent *event)
{
    this->yon=true;
    isin=true;
    repaint();
    QWidget::enterEvent(event);
}

void Specplot::leaveEvent(QEvent *event)
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

void Specplot::setxw(int xw)
{
    this->xw=xw;
    repaint();
}

void Specplot::setxon(bool xon)
{
    this->isxon=xon;
    repaint();
}

int Specplot::getindex(int xw,bool *ok)
{
    double per1=hs+(double)((double)xw/(double)(this->width()*0.975))*(double)(he-hs);
    int poi1=per1*this->wsize;
    //int index=qFloor((double)((double)(poi1-global_sets::step/2)/(double)(this->wsize-global_sets::step))*acftemp.size());

    int index=qFloor((double)((double)(poi1-(double)((double)(global_sets::step-(double)((double)global_sets::step/(double)global_sets::times))/(double)2))*(double)global_sets::times)/(double)global_sets::step);
    *ok=true;
    if(index<0){
        index=0;
        *ok=false;
    }
    if(index>=acftemp.size()){
        index=acftemp.size()-1;
        *ok=false;
    }
    //qDebug("index:%d",index);
    return index;
}

void Specplot::setselected(bool selected,double ssp,double sep)
{
    this->selected=selected;
    this->ssp=ssp;
    this->sep=sep;
    repaint();
}

void Specplot::mousePressEvent(QMouseEvent *event)
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
            if(pxt*this->wsize>=global_sets::perp&&pxt*this->wsize<=this->wsize-global_sets::perp){
                emit pmove(pxt);
            }else if(pxt*this->wsize<global_sets::perp){
                emit pmove((double)((double)global_sets::perp/(double)this->wsize));
            }else{
                emit pmove((double)((double)(this->wsize-global_sets::perp)/(double)this->wsize));
            }



        }
    }
}

void Specplot::mouseReleaseEvent(QMouseEvent *event)
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
            if(pxt*this->wsize>=global_sets::perp&&pxt*this->wsize<=this->wsize-global_sets::perp){
                emit point(pxt);
            }else if(pxt*this->wsize<global_sets::perp){
                emit point((double)((double)global_sets::perp/(double)this->wsize));
            }else{
                emit point((double)((double)(this->wsize-global_sets::perp)/(double)this->wsize));
            }

            spressed=false;


        }
    }
}

void Specplot::setlines(double l1,double l2,double l3,double l4)
{
    this->l1=l1;
    this->l2=l2;
    this->l3=l3;
    this->l4=l4;
    repaint();
}

void Specplot::setfourlines(bool fourlines)
{
    this->l1=0;
    this->l2=0;
    this->l3=0;
    this->l4=0;
    spressed=false;
    this->fourlines=fourlines;
    repaint();
}

bool Specplot::event(QEvent *event)
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
                pixchange();
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
                pixchange();
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

int Specplot::trasx(int x)
{
    int out=0;
    double xper=(double)((double)x/(double)this->wsize);
    out=(double)((double)(xper-hs)/(double)(he-hs))*0.975*width();
    return out;
}

QColor Specplot::getcolor(double v)
{
    /*
    int R=0,G=0,B=0;
    if(x<=0.03){
        R=static_cast<double>((x/0.03)*255);
        B=static_cast<double>((x/0.03)*255);
    }else if(x<=0.06){
        R=static_cast<double>(255);
        B=static_cast<double>(255-((x-0.03)/0.03)*255);
    }else{
        R=255;
        G=static_cast<double>(((x-0.06)/0.94)*255);
    }
    QColor out(R,G,B);
    return out;*/
    const double vii = (v-min_Bound)/(max_Bound-min_Bound);
    int red = 0,green = 0,blue = 0;
    if (vii>=0 && vii<0.25)
    {
        blue = vii/0.25*255;
        //red = vii/0.25*255/2;

    }

    else if (vii>=0.25 && vii<0.5 )
    {
            blue = (0.5-vii)/0.25*255;
            red =  (vii-0.25)/0.25*255;
    }
    else if (vii>=0.5 && vii<0.75 )
    {
            red =  255;
            green = (vii-0.5)/0.25*255;
    }
    else if (vii>=0.75 && vii<1)
    {
            red = 255;
            green = 255;
            blue =  (vii-0.75)/0.25*255;
    }
    else if (vii>=1)
            red = 255, blue = 255, green = 255;
    return QColor(red,green,blue);
}

QColor Specplot::getacfcolor(double x,double max,double min)
{
    double part=(double)((double)(max-min)/(double)6);
    if(x<=min+part){
        return Qt::black;
    }else if(x<=min+2*part){
        return Qt::blue;
    }else if(x<=min+3*part){
        return Qt::green;
    }
    else if(x<=min+4*part){
        return Qt::yellow;
    }
    else if(x<=min+5*part){
        return QColor(255,127,0);
    }
    else{
        return Qt::red;
    }
}

QColor Specplot::getacfcolor2(double x,double max,double min)
{
    const double vii = (x-min)/(max-min);
    int red = 0,green = 0,blue = 0;
    if (vii>=0 && vii<0.25)
    {
        blue = vii/0.25*255;
        //red = vii/0.25*255/2;

    }

    else if (vii>=0.25 && vii<0.5 )
    {
            blue = (0.5-vii)/0.25*255;
            red =  (vii-0.25)/0.25*255;
    }
    else if (vii>=0.5 && vii<0.75 )
    {
            red =  255;
            green = (vii-0.5)/0.25*255;
    }
    else if (vii>=0.75 && vii<1)
    {
            red = 255;
            green = 255;
            blue =  (vii-0.75)/0.25*255;
    }
    else if (vii>=1)
            red = 255, blue = 255, green = 255;
    return QColor(red,green,blue);

}
