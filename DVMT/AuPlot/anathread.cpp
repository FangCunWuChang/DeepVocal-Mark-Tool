#include "anathread.h"

AnaThread::AnaThread() : QThread()
{

}

void AnaThread::run()
{
    emit lock();

    emit tip("等待分析...");
    QPixmap pixmapw(wavedataL.size(),2001);
    QPainter painter(&pixmapw);
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
    painter.fillRect(0,0,pixmapw.width(),pixmapw.height(),Qt::black);
    QPolygon poly;
    emit tip("绘制波形...");
    poly.append(QPoint(-1,1001));
    for(int i=0;i<wavedataL.size();i++){
        poly.append(QPoint(i,1001+wavedataL.at(i)*1000));
    }
    poly.append(QPoint(wavedataL.size()+1,1001));
    painter.drawPolygon(poly);
    QRect rectl(0,0,global::sets::step/2,pixmapw.height()),rectr(pixmapw.width()-global::sets::step/2,0,global::sets::step/2,pixmapw.height());
    painter.fillRect(rectl,QColor(255,0,0,100));
    painter.fillRect(rectr,QColor(255,0,0,100));
    QRect prl(global::sets::step/2,0,global::sets::perp-global::sets::step/2,pixmapw.height()),prr(pixmapw.width()-global::sets::perp,0,global::sets::perp-global::sets::step/2,pixmapw.height());
    painter.fillRect(prl,QColor(255,255,0,100));
    painter.fillRect(prr,QColor(255,255,0,100));
    painter.end();

    QPixmap pixmapp=pixmapw;

    painter.begin(&pixmapp);
    painter.end();

    QPixmap pixspec(wavedataL.size(),global::sets::step/2);
    painter.begin(&pixspec);

    pen.setWidth(1);
    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);


    int sc=qFloor(((wavedataL.size()-global::sets::step)/(global::sets::step/global::sets::times)))+1;

    QVector<QVector<double>> temp,ftemp,fmtemp;

    for(int i=0;i<sc;i++){
        QVector<double> part;
        for(int j=0;j<global::sets::step;j++){
            part.append(wavedataL.at(i*global::sets::step/global::sets::times+j));
        }
        ftemp.append(part);
    }

    for(int i=0;i<sc;i++){
        QVector<double> imer=AuMathLib::imelog(AuMathLib::hanning(ftemp.at(i)));
        temp.append(imer);
        emit tip(QString::asprintf("FFT分析(%d/%d)...",i,sc));
    }

    QVector<double> etemp;
    for(int i=0;i<sc;i++){
        etemp.append(AuMathLib::ene(ftemp.at(i)));
        emit tip(QString::asprintf("短时能量分析(%d/%d)...",i,sc));
    }

    QVector<double> rptztemp;
    for(int i=0;i<sc;i++){
        rptztemp.append(AuMathLib::rptz(ftemp.at(i)));
        emit tip(QString::asprintf("短时过零率分析(%d/%d)...",i,sc));
    }

    QVector<double> acftemp,sptemp;//,f1temp,f2temp,f3temp,f4temp;
    for(int i=0;i<sc;i++){
        acftemp.append(AuMathLib::fre(ftemp.at(i),samplespersec));
        sptemp=temp.at(i);
        double minseed=-100;
        for(int j=0;j<sptemp.size();j++){
            minseed=qMin(minseed,sptemp.at(j));
        }
        for(int j=0;j<sptemp.size();j++){
            sptemp.replace(j,sptemp.at(j)-minseed+1);
        }
        QVector<double> imagtemp;
        imagtemp.resize(sptemp.size());
        AuMathLib::fft(&sptemp,&imagtemp);
        for(int j=0;j<(sptemp.size()/2);j++){
            if(j>(double)((double)((double)sptemp.size()/(double)2)*(double)global::sets::speccut)){
                sptemp.replace(j,0);
                sptemp.replace(sptemp.size()-j+1,0);
                imagtemp.replace(j,0);
                imagtemp.replace(imagtemp.size()-j+1,0);
            }

        }
        AuMathLib::ifft(&sptemp,&imagtemp);
        for(int j=0;j<sptemp.size();j++){
            sptemp.replace(j,sqrt(sptemp.at(j)*sptemp.at(j)+imagtemp.at(j)*imagtemp.at(j)));
        }
        for(int j=0;j<sptemp.size();j++){
            sptemp.replace(j,sptemp.at(j)+minseed-1);
        }
        fmtemp.append(sptemp);
        /*
        if(i==10){
            IPlot plot(nullptr,&sptemp);
            plot.plot();
            plot.show();
            while(!plot.isHidden()){

            }
        }*/
        //QVector<double> fstemp=AuMathLib::GetFs(sptemp,samplespersec);
        //f1temp.append(fstemp.at(0));
        //f2temp.append(fstemp.at(1));
        //f3temp.append(fstemp.at(2));
        //f4temp.append(fstemp.at(3));
        emit tip(QString::asprintf("频率分析(%d/%d)...",i,sc));
    }
    QVector<bool> flagtemp;
    for(int i=0;i<sc;i++){
        if(etemp.at(i)>=global::sets::enebound&&rptztemp.at(i)<global::sets::rptzbound){
            flagtemp.append(true);
        }else{
            flagtemp.append(false);
        }
    }
/*
    QVector<QVector<double>> temp2;

    for(int i=0;i<sc;i++){
        if(sc>1){
            QVector<double> vt;
            if(i==0){
                for(int j=0;j<qMin(temp.at(i).size(),temp.at(i+1).size());j++){
                    vt.append((temp.at(i).at(j)+temp.at(i+1).at(j))/2);

                }
            }else if(i==sc-1){
                for(int j=0;j<qMin(temp.at(i).size(),temp.at(i-1).size());j++){
                    vt.append((temp.at(i-1).at(j)+temp.at(i).at(j))/2);

                }

            }else{
                for(int j=0;j<qMin(qMin(temp.at(i).size(),temp.at(i-1).size()),temp.at(i+1).size());j++){
                    vt.append((temp.at(i-1).at(j)+temp.at(i).at(j)+temp.at(i+1).at(j))/3);

                }
            }
            temp2.append(vt);
        }

    }
*/

    emit tip(QString::asprintf("语谱图绘制..."));
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp.at(i).size();j++){
            pen.setColor(getcolor(temp.at(i).at(j)));
            painter.setPen(pen);
            QLine line(i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2),pixspec.height()-j,i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times,pixspec.height()-j);
            painter.drawLine(line);
        }

    }

    painter.fillRect(rectl,QColor(255,0,0,100));
    painter.fillRect(rectr,QColor(255,0,0,100));
    painter.fillRect(prl,QColor(255,255,0,100));
    painter.fillRect(prr,QColor(255,255,0,100));

    painter.end();

    emit tip(QString::asprintf("曲线绘制..."));

    QPixmap pixene(wavedataL.size(),2001),pixrptz(wavedataL.size(),2001),pixacf(wavedataL.size(),global::sets::step/2);

    pixene.fill(QColor(255,255,255,0));
    pixrptz.fill(QColor(255,255,255,0));
    pixacf.fill(QColor(255,255,255,0));

    painter.begin(&pixene);

    pen.setColor(Qt::yellow);
    pen.setWidth(5);
    painter.setPen(pen);
    brush.setColor(QColor(255,255,0,100));
    painter.setBrush(brush);

    QPolygon polyene;
    polyene.append(QPoint((0*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+0*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixene.height()+1));

    for(int i=0;i<etemp.size();i++){
        QPoint point((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixene.height()-static_cast<double>(pixene.height()*etemp.at(i)*2));
        polyene.append(point);
    }

    polyene.append(QPoint(((etemp.size()-1)*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+(etemp.size()-1)*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixene.height()+1));
    painter.drawPolygon(polyene);

    painter.end();
    painter.begin(&pixrptz);

    pen.setColor(Qt::green);
    pen.setWidth(5);
    painter.setPen(pen);
    brush.setColor(QColor(0,255,0,100));
    painter.setBrush(brush);

    QPolygon polyrptz;

    polyrptz.append(QPoint((0*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+0*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixrptz.height()+1));
    for(int i=0;i<rptztemp.size();i++){
        QPoint point((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixene.height()-static_cast<double>(pixene.height()*rptztemp.at(i)*2));
        polyrptz.append(point);
    }

    polyrptz.append(QPoint(((rptztemp.size()-1)*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+(rptztemp.size()-1)*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixrptz.height()+1));
    painter.drawPolygon(polyrptz);

    painter.end();
    painter.begin(&pixacf);

    double maxfm=-100,minfm=100;

    for(int i=0;i<fmtemp.size();i++){
        for(int j=0;j<fmtemp.at(i).size();j++){
            maxfm=qMax(maxfm,fmtemp.at(i).at(j));
            minfm=qMin(minfm,fmtemp.at(i).at(j));
        }
    }

    //maxfm=0;
    for(int i=0;i<fmtemp.size();i++){
        for(int j=0;j<fmtemp.at(i).size();j++){
            if(flagtemp.at(i)){
                //int colornum=255-255*(double)((double)(fmtemp.at(i).at(j)-minfm)/(double)(maxfm-minfm));
                //pen.setColor(QColor(colornum,colornum,colornum,200));
                pen.setColor(getacfcolor2(fmtemp.at(i).at(j)));
                painter.setPen(pen);
                QLine line(i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2),pixspec.height()-j,i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times,pixspec.height()-j);
                painter.drawLine(line);
            }

        }

    }

    pen.setColor(Qt::green);
    pen.setWidth(1);
    painter.setPen(pen);

    QPolygon polyacf;//,polyf1,polyf2,polyf3,polyf4;
    for(int i=0;i<acftemp.size();i++){
        if(flagtemp.at(i)){
            QPoint point((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()-static_cast<double>((double)acftemp.at(i)/(double)((double)samplespersec/(double)global::sets::step)));
            //qDebug("acf:%d,%.2f",i,pixacf.height()-static_cast<double>((double)acftemp.at(i)/(double)((double)samplespersec/(double)global::sets::step)));
            polyacf.append(point);
            //QPoint point1((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()-static_cast<double>((double)f1temp.at(i)/(double)((double)samplespersec/(double)global::sets::step)));
            //QPoint point2((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()-static_cast<double>((double)f2temp.at(i)/(double)((double)samplespersec/(double)global::sets::step)));
            //QPoint point3((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()-static_cast<double>((double)f3temp.at(i)/(double)((double)samplespersec/(double)global::sets::step)));
            //QPoint point4((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()-static_cast<double>((double)f4temp.at(i)/(double)((double)samplespersec/(double)global::sets::step)));
            //polyf1.append(point1);
            //polyf2.append(point2);
            //polyf3.append(point3);
            //polyf4.append(point4);
        }else{
            QPoint point((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()+1);
            //qDebug("acf:%d,%.2f",i,pixacf.height()-static_cast<double>((double)acftemp.at(i)/(double)((double)samplespersec/(double)global::sets::step)));
            polyacf.append(point);
            //QPoint point1((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()+1);
            //QPoint point2((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()+1);
            //QPoint point3((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()+1);
            //QPoint point4((i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+i*global::sets::step/global::sets::times+static_cast<double>(static_cast<double>(global::sets::step-static_cast<double>(global::sets::step/global::sets::times))/2)+global::sets::step/global::sets::times)/2,pixacf.height()+1);
            //polyf1.append(point1);
            //polyf2.append(point2);
            //polyf3.append(point3);
            //polyf4.append(point4);
        }

    }

    painter.drawPolyline(polyacf);
    //pen.setColor(QColor(255,0,255));
    /*
    pen.setWidth(3);
    pen.setColor(QColor(255,255,255));
    painter.setPen(pen);
    painter.drawPoints(polyf1);
    pen.setColor(QColor(255,255,255));
    painter.setPen(pen);
    painter.drawPoints(polyf2);
    pen.setColor(QColor(255,255,255));
    painter.setPen(pen);
    painter.drawPoints(polyf3);
    pen.setColor(QColor(255,255,255));
    painter.setPen(pen);
    //painter.drawPolyline(polyf4);
*/
    painter.end();

    emit tip("写入缓存...");

    emit out(pixmapw,pixmapp,pixspec,pixene,pixrptz,pixacf,etemp,rptztemp,acftemp,flagtemp,true);

    emit tip("完成!");

    emit unlock();
}

void AnaThread::setwave(QWaveHandle *wave)
{
    this->wavedataL=*wave->wavedataL;
    this->wavedataR=*wave->wavedataR;
    this->samplespersec=wave->samplespersec;
}

QColor AnaThread::getcolor(double v)
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
    const double vii = (v-global::sets::m_minBound)/(global::sets::m_maxBound-global::sets::m_minBound);
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

QColor AnaThread::getacfcolor(double x,double max,double min)
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

QColor AnaThread::getacfcolor2(double x,double max,double min)
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
