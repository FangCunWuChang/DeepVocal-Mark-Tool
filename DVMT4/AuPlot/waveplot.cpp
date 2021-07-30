#include "waveplot.h"
#include "ui_waveplot.h"

Waveplot::Waveplot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Waveplot)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    pm2->fill(Qt::black);//图片默认背景：黑
}

Waveplot::~Waveplot()
{

    delete pm2;
    delete ui;
}

void Waveplot::pixchange()
{
    pm2->fill(Qt::black);//图片背景：黑
    pm2->scaled(width()*scaletimes_wp*0.975,height()*scaletimes_wp);
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

    int sp=hs*pt.size();
    int ep=he*pt.size();

    QPolygon poly;
    poly.append(QPoint(-1,(double)((double)(pm2->height())/(double)2)));

    for(int i=sp;i<ep;i++){
        poly.append(g_poi(i,pt.at(i)));
    }
    poly.append(QPoint((pm2->width())+1,(double)((double)pm2->height()/(double)2)));
    painter.drawPolygon(poly);
    int perp=global_sets::perp;
    QRect rectl(-hs*(double)((double)pm2->width()/(double)(he-hs)),0,(double)((double)((double)((double)qMax(perp,global_sets::step/2)/(double)pt.size())*pm2->width())/(double)(he-hs)),pm2->height());
    QRect rectr(pm2->width()+(1-he)*(double)((double)pm2->width()/(double)(he-hs))-(double)((double)((double)((double)qMax(perp,global_sets::step/2)/(double)pt.size())*pm2->width())/(double)(he-hs)),0,(double)((double)((double)((double)qMax(perp,global_sets::step/2)/(double)pt.size())*pm2->width())/(double)(he-hs)),pm2->height());
    painter.fillRect(rectl,QColor(195,33,54,100));//分析区：枣红
    painter.fillRect(rectr,QColor(195,33,54,100));//分析区：枣红
    painter.end();
}

QPoint Waveplot::g_poi(int x,double y)
{
    return QPoint(
                ((double)((double)((double)x/(double)pt.size())-hs)/(double)(he-hs))*pm2->width(),
                (pm2->height()/2)-((double)(y*(pm2->height()/2))/(double)vs)
                );
}



void Waveplot::resizeEvent(QResizeEvent *event)
{
    pixchange();
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
    pen.setColor(QColor(214,236,240,200));//主刻度网格：月白
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);

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

    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    brush.setStyle(Qt::SolidPattern);

    painter.fillRect(0,0,0.975*width(),height(),Qt::black);//主背景：黑

    painter.drawPixmap(0,0,0.975*width(),height(),*pm2);
    painter.drawPixmap(0,0,0.975*width(),height(),pixback);

    if(eneon){
        pen.setColor(QColor(255,182,30));//能量曲线：藤黄
        pen.setWidth(2);
        painter.setPen(pen);
        brush.setColor(QColor(255,182,30,100));//能量曲线填充：藤黄
        painter.setBrush(brush);
        QPolygon polyene;
        polyene.append(QPoint(trasx((0*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+0*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+global_sets::step/global_sets::times)/2),height()+1));

        for(int i=0;i<enetemp.size();i++){
            QPoint point(trasx((i*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+i*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+global_sets::step/global_sets::times)/2),height()-static_cast<double>(height()*enetemp.at(i)*2));
            polyene.append(point);

        }

        polyene.append(QPoint(trasx(((enetemp.size()-1)*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+(enetemp.size()-1)*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+global_sets::step/global_sets::times)/2),height()+1));
        painter.drawPolygon(polyene);
        polyene.clear();
    }
    if(rptzon){
        pen.setColor(QColor(42,221,156));//过零率曲线：碧绿
        pen.setWidth(2);
        painter.setPen(pen);
        brush.setColor(QColor(42,221,156,100));//过零率曲线填充：碧绿
        painter.setBrush(brush);

        QPolygon polyrptz;

        polyrptz.append(QPoint(trasx((0*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+0*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+global_sets::step/global_sets::times)/2),height()+1));
        for(int i=0;i<rptztemp.size();i++){
            QPoint point(trasx((i*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+i*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+global_sets::step/global_sets::times)/2),height()-static_cast<double>(height()*rptztemp.at(i)*2));
            polyrptz.append(point);
        }

        polyrptz.append(QPoint(trasx(((rptztemp.size()-1)*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+(rptztemp.size()-1)*global_sets::step/global_sets::times+static_cast<double>(static_cast<double>(global_sets::step-static_cast<double>(global_sets::step/global_sets::times))/2)+global_sets::step/global_sets::times)/2),height()+1));
        painter.drawPolygon(polyrptz);
        polyrptz.clear();
    }

    if(selected){
        pen.setColor(QColor(224,240,233));//选择框：素
        pen.setWidth(2);
        pen.setStyle(Qt::DashLine);
        painter.setPen(pen);
        brush.setColor(QColor(224,240,233,100));//选择框：素
        painter.setBrush(brush);
        painter.drawRect((double)((double)(ssp-hs)/(double)(he-hs))*(double)(0.975*width()),0,(double)((double)(sep-hs)/(double)(he-hs))*(double)(0.975*width())-(double)((double)(ssp-hs)/(double)(he-hs))*(double)(0.975*width()),this->height());
    }

    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    QFont font;

    font.setPointSize(height()*0.025);
    painter.setFont(font);
    brush.setColor(QColor(31,31,31));//标签底色：玄青
    painter.setBrush(brush);


    if(fourlines){
        if(l1*pt.size()>=global_sets::perp&&l1*pt.size()<=pt.size()-global_sets::perp){
            pen.setColor(QColor(75,92,196));//一线：宝蓝
            pen.setWidth(2);
            painter.setPen(pen);
            brush.setColor(QColor(75,92,196,100));//一线：宝蓝
            painter.setBrush(brush);
            QLine linel((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawRect((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.15*height()-height()*0.036,height()*0.025*4.5,height()*0.05);
            painter.drawText((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width())+0.02*height(),0.15*height()+0.003*height(),"1.CP");
        }
        if(l2*pt.size()>=global_sets::perp&&l2*pt.size()<=pt.size()-global_sets::perp){
            pen.setColor(QColor(255,140,49));//二线：杏黄
            pen.setWidth(2);
            painter.setPen(pen);
            brush.setColor(QColor(255,140,49,100));//二线：杏黄
            painter.setBrush(brush);
            QLine linel((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawRect((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.2*height()-height()*0.036,height()*0.025*4.5,height()*0.05);
            painter.drawText((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width())+0.02*height(),0.2*height()+0.003*height(),"2.PP");
        }
        if(l3*pt.size()>=global_sets::perp&&l3*pt.size()<=pt.size()-global_sets::perp){
            pen.setColor(QColor(203,58,86));//三线：茜色
            pen.setWidth(2);
            painter.setPen(pen);
            brush.setColor(QColor(203,58,86,100));//三线：茜色
            painter.setBrush(brush);
            QLine linel((double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawRect((double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width()),0.25*height()-height()*0.036,height()*0.025*5,height()*0.05);
            painter.drawText((double)((double)(l3-hs)/(double)(he-hs))*(double)(0.975*width())+0.02*height(),0.25*height()+0.003*height(),"3.VSP");
        }
        if(l4*pt.size()>=global_sets::perp&&l4*pt.size()<=pt.size()-global_sets::perp){
            pen.setColor(QColor(127,236,173));//四线：缥
            pen.setWidth(2);
            painter.setPen(pen);
            brush.setColor(QColor(127,236,173,100));//四线：缥
            painter.setBrush(brush);
            QLine linel((double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawRect((double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width()),0.3*height()-height()*0.036,height()*0.025*5,height()*0.05);
            painter.drawText((double)((double)(l4-hs)/(double)(he-hs))*(double)(0.975*width())+0.02*height(),0.3*height()+0.003*height(),"4.VEP");
        }
    }else{
        if(l1*pt.size()>=global_sets::perp&&l1*pt.size()<=pt.size()-global_sets::perp){
            pen.setColor(QColor(75,92,196));//一线：宝蓝
            pen.setWidth(2);
            painter.setPen(pen);
            brush.setColor(QColor(75,92,196,100));//一线：宝蓝
            painter.setBrush(brush);
            QLine linel((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawRect((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width()),0.15*height()-height()*0.036,height()*0.025*4.5,height()*0.05);
            painter.drawText((double)((double)(l1-hs)/(double)(he-hs))*(double)(0.975*width())+0.02*height(),0.15*height()+0.003*height(),"1.SP");
        }
        if(l2*pt.size()>=global_sets::perp&&l2*pt.size()<=pt.size()-global_sets::perp){
            pen.setColor(QColor(255,140,49));//二线：杏黄
            pen.setWidth(2);
            painter.setPen(pen);
            brush.setColor(QColor(255,140,49,100));//二线：杏黄
            painter.setBrush(brush);
            QLine linel((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.1*height(),(double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.9*height());
            painter.drawLine(linel);
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawRect((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width()),0.2*height()-height()*0.036,height()*0.025*4.5,height()*0.05);
            painter.drawText((double)((double)(l2-hs)/(double)(he-hs))*(double)(0.975*width())+0.02*height(),0.2*height()+0.003*height(),"2.EP");
        }
    }

    painter.fillRect(0.975*width(),0,width()-0.975*width(),height(),QColor(31,31,31));//右侧区域：玄青

    font.setPixelSize(0.025*width()/3);
    painter.setFont(font);
    pen.setWidth(1);
    pen.setColor(QColor(214,236,240));//右侧刻度：月白
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
        pen.setColor(QColor(201,55,86));//时间指示线：樱桃红
        painter.setPen(pen);

        painter.drawLine(QLine(xw,0,xw,height()));

        font.setPointSize(height()/30);
        painter.setFont(font);

        pen.setWidth(1);
        painter.setPen(pen);
        brush.setColor(QColor(31,31,31,100));//标签底色：玄青
        painter.setBrush(brush);




        bool ok=true;
        int index=getindex(xw,&ok);
        if(enetemp.size()>0&&ok){
            if(eneon){
                pen.setColor(QColor(255,182,30));//能量数值：藤黄
                pen.setWidth(1);
                painter.setPen(pen);
                brush.setColor(QColor(255,182,30,0));//能量数值：藤黄
                painter.setBrush(brush);
                double enen=enetemp.at(index);

                int poiyw=this->height()-2*(double)((double)enen*(double)this->height());
                painter.drawEllipse(QPointF(xw,poiyw),2,2);
                QString enestring=QString::asprintf("%.3f",enen);
                int poixw=xw;
                if(poixw+enestring.size()*font.pointSize()+(double)(0.5*font.pointSize())>width()*0.975){
                    poixw-=enestring.size()*font.pointSize()+(double)(0.5*font.pointSize());
                }else{
                    poixw+=(double)(0.5*font.pointSize());
                }
                if(poiyw-font.pointSize()<0){
                    poiyw+=font.pointSize();
                }
                brush.setColor(QColor(31,31,31,100));//标签底色：玄青
                painter.setBrush(brush);
                pen.setWidth(1);
                pen.setColor(QColor(255,182,30));//标签边框：藤黄
                painter.setPen(pen);

                painter.drawRect(0.95*width()-font.pointSize()*enestring.size()*0.9,0.1*height()+2*font.pointSize(),font.pointSize()*enestring.size()*0.9,2*font.pointSize());
                pen.setWidth(1);
                pen.setColor(QColor(255,182,30));//标签坐标：藤黄
                painter.setPen(pen);
                painter.drawText(0.95*width()-font.pointSize()*enestring.size()*0.9+0.2*font.pointSize(),0.1*height()+2*font.pointSize()-0.015*height()+2*font.pointSize(),enestring);
            }
            if(rptzon){
                pen.setColor(QColor(42,221,156));//过零率数值：碧绿
                pen.setWidth(1);
                painter.setPen(pen);
                brush.setColor(QColor(42,221,156,0));//过零率数值：碧绿
                painter.setBrush(brush);
                double rptzn=rptztemp.at(index);

                int poiyw=this->height()-2*(double)((double)rptzn*(double)this->height());
                painter.drawEllipse(QPointF(xw,poiyw),2,2);
                QString rptzstring=QString::asprintf("%.3f",rptzn);
                int poixw=xw;
                if(poixw+rptzstring.size()*font.pointSize()+(double)(0.5*font.pointSize())>width()*0.975){
                    poixw-=rptzstring.size()*font.pointSize()+(double)(0.5*font.pointSize());
                }else{
                    poixw+=(double)(0.5*font.pointSize());
                }
                if(poiyw-font.pointSize()<0){
                    poiyw+=font.pointSize();
                }
                brush.setColor(QColor(31,31,31,100));//标签底色：玄青
                painter.setBrush(brush);
                pen.setWidth(1);
                pen.setColor(QColor(42,221,156));//标签边框：碧绿
                painter.setPen(pen);

                painter.drawRect(0.95*width()-font.pointSize()*rptzstring.size()*0.9,0.1*height()+4*font.pointSize(),font.pointSize()*rptzstring.size()*0.9,2*font.pointSize());
                pen.setWidth(1);
                pen.setColor(QColor(42,221,156));//标签坐标：碧绿
                painter.setPen(pen);
                painter.drawText(0.95*width()-font.pointSize()*rptzstring.size()*0.9+0.2*font.pointSize(),0.1*height()+2*font.pointSize()-0.015*height()+4*font.pointSize(),rptzstring);
            }

        }
        pen.setColor(QColor(214,236,240));//鼠标坐标：月白
        painter.setPen(pen);

        double per1=hs+(double)((double)xw/(double)(this->width()*0.975))*(double)(he-hs);
        int poi1=(double)per1*(double)pt.size();
        double time=(double)poi1/(double)44100;

        double num=(double)((double)((double)((double)((double)height()/(double)2)-yw)/(double)((double)1/(double)vs))/(double)((double)height()/(double)2));
        if(yon){
            painter.drawEllipse(QPointF(xw,yw),2,2);
            QString labelstring=QString::asprintf("(%.2fs,%.3f)",time,num);
            int poixw=xw;
            int poiyw=yw;
            if(poixw+labelstring.size()*font.pointSize()+(double)(0.5*font.pointSize())>width()*0.975){
                poixw-=labelstring.size()*font.pointSize()+(double)(0.5*font.pointSize());
            }else{
                poixw+=(double)(0.5*font.pointSize());
            }
            if(poiyw-font.pointSize()<0){
                poiyw+=font.pointSize();
            }

            brush.setColor(QColor(31,31,31,100));//标签底色：玄青
            painter.setBrush(brush);
            pen.setWidth(1);
            pen.setColor(QColor(214,236,240));//标签边框：月白
            painter.setPen(pen);

            painter.drawRect(0.95*width()-font.pointSize()*labelstring.size()*0.75,0.1*height(),font.pointSize()*labelstring.size()*0.75,2*font.pointSize());
            pen.setWidth(1);
            pen.setColor(QColor(214,236,240));//标签坐标：月白
            painter.setPen(pen);
            painter.drawText(0.95*width()-font.pointSize()*labelstring.size()*0.75+0.2*font.pointSize(),0.1*height()+2*font.pointSize()-0.015*height(),labelstring);

        }
    }
    if(isin&&!(isxon&&yon)){
        pen.setColor(QColor(214,236,240));//鼠标位置：月白
        painter.setPen(pen);
        painter.drawEllipse(mn,2,2);
    }

    QWidget::paintEvent(event);
}

void Waveplot::setpix(QVector<double> pixmap)
{
    this->pt=pixmap;
    pixchange();
    repaint();
}

void Waveplot::wheelEvent(QWheelEvent *event)
{
    if(event->position().x()>0.975*width()){
        double nn=-event->angleDelta().y();
        if(vs+(double)((double)nn/(double)1000)>1){
            vs=1;
        }else if(vs+(double)((double)nn/(double)1000)<=0.1){
            vs=0.1;
        }else{
           vs+=(double)((double)nn/(double)1000);
        }
        pixchange();
        repaint();
    }else{
        double nn=event->angleDelta().y();
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

void Waveplot::seths(double hs,double he)
{
    this->hs=hs;
    this->he=he;
    pixchange();

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
        if(pxt*pt.size()>=global_sets::perp&&pxt*pt.size()<=pt.size()-global_sets::perp){
            emit pmove(pxt);
        }else if(pxt*pt.size()<global_sets::perp){
            emit pmove((double)((double)global_sets::perp/(double)pt.size()));
        }else{
            emit pmove((double)((double)(pt.size()-global_sets::perp)/(double)pt.size()));
        }

    }


    repaint();
    QWidget::mouseMoveEvent(event);
}

void Waveplot::enterEvent(QEnterEvent *event)
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
    int poi1=per1*pt.size();
    int index=qFloor((double)((double)(poi1-(double)((double)(global_sets::step-(double)((double)global_sets::step/(double)global_sets::times))/(double)2))*(double)global_sets::times)/(double)global_sets::step);
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
            if(pxt*pt.size()>=global_sets::perp&&pxt*pt.size()<=pt.size()-global_sets::perp){
                emit pmove(pxt);
            }else if(pxt*pt.size()<global_sets::perp){
                emit pmove((double)((double)global_sets::perp/(double)pt.size()));
            }else{
                emit pmove((double)((double)(pt.size()-global_sets::perp)/(double)pt.size()));
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
            if(pxt*pt.size()>=global_sets::perp&&pxt*pt.size()<=pt.size()-global_sets::perp){
                emit point(pxt);
            }else if(pxt*pt.size()<global_sets::perp){
                emit point((double)((double)global_sets::perp/(double)pt.size()));
            }else{
                emit point((double)((double)(pt.size()-global_sets::perp)/(double)pt.size()));
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
    }
    default:
        // 其他的事件
        break;

    }

    return QWidget::event(event);
}

int Waveplot::trasx(int x)
{
    int out=0;
    double xper=(double)((double)x/(double)pt.size());
    out=(double)((double)(xper-hs)/(double)(he-hs))*0.975*width();
    return out;
}
