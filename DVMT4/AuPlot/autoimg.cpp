#include "autoimg.h"

AutoImg::AutoImg()
{
    QDir dir(QCoreApplication::applicationDirPath()+"/autoimgtemp");
    if(!dir.exists()){
        dir.mkdir(QCoreApplication::applicationDirPath()+"/autoimgtemp");
    }

    dir.setFilter(QDir::Dirs);
    QStringList paths;
    for(uint i=0;i<dir.count();i++){
        paths.append(dir[i]);
        qDebug("path:%s",qPrintable(dir[i]));
    }
    for(int num=0;;num++){

        bool ok=false;
        for(int j=0;j<paths.size();j++){
            if(paths.at(j)==QString("%0").arg(num)){
                ok=true;
                break;
            }
        }

        qDebug("%d:%s",ok,qPrintable(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString("%0").arg(num)));
        if(!ok){
            dir.mkdir(QString("%0").arg(num));
            qDebug("create:%s",qPrintable(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString("%0").arg(num)));
            this->id=num;
            break;
        }
    }
    QFile warningfile(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+"AutoImg类缓存！请勿更改本文件夹下的任何内容！");
    warningfile.open(QIODevice::ReadWrite);
    warningfile.close();
    this->resize(0,0);
    prepareimag(0,0);
}

AutoImg::AutoImg(int w,int h,QImage::Format format)
{
    QDir dir(QCoreApplication::applicationDirPath()+"/autoimgtemp");
    if(!dir.exists()){
        dir.mkdir(QCoreApplication::applicationDirPath()+"/autoimgtemp");
    }

    dir.setFilter(QDir::Dirs);
    QStringList paths;
    for(uint i=0;i<dir.count();i++){
        paths.append(dir[i]);
        qDebug("path:%s",qPrintable(dir[i]));
    }
    for(int num=0;;num++){

        bool ok=false;
        for(int j=0;j<paths.size();j++){
            if(paths.at(j)==QString("%0").arg(num)){
                ok=true;
                break;
            }
        }

        qDebug("%d:%s",ok,qPrintable(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString("%0").arg(num)));
        if(!ok){
            dir.mkdir(QString("%0").arg(num));
            qDebug("create:%s",qPrintable(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString("%0").arg(num)));
            this->id=num;
            break;
        }
    }
    this->w=w;
    this->h=h;
    this->format=format;
    int xc=qMax(1,qCeil((double)w/(double)part));
    int yc=qMax(1,qCeil((double)h/(double)part));
    int wm=w-(xc-1)*part;
    int hm=h-(yc-1)*part;
    for(int i=0;i<xc;i++){
        for(int j=0;j<yc;j++){
            QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",id,i,j);
            QFile file(filename);
            if(file.exists()){
                file.remove();
            }
            int wi=part;
            int hi=part;
            if(i==xc-1){
                wi=wm;
            }
            if(j==yc-1){
                hi=hm;
            }
            QImage imag(wi,hi,format);
            imag.fill(backgroundcolor);
            imag.save(filename,"png");
        }
    }
    QFile warningfile(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+"AutoImg类缓存！请勿更改本文件夹下的任何内容！");
    warningfile.open(QIODevice::ReadWrite);
    warningfile.close();
    prepareimag(0,0);
    QFile file123456(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/0_0.png",id));
    if(!file123456.exists()){
        qDebug()<<"No 0_0!Create"<<Qt::endl;
    }else{
        qDebug()<<"Yes 0_0!Create"<<Qt::endl;
    }

}

AutoImg::~AutoImg()
{
    QDir dir(QCoreApplication::applicationDirPath()+"/autoimgtemp");
    if(dir.exists()){
        QDir tdir(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d",this->id));
        if(tdir.exists()){
            tdir.setFilter(QDir::Files);
            for(uint i=0;i<tdir.count();i++){
                QString fn=tdir.path()+"/"+tdir[i];
                QFile ft(fn);
                if(ft.exists()){
                    ft.remove();
                }
            }
            tdir.rmdir(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d",this->id));
        }
        QFile warningfile(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+"AutoImg类缓存！请勿更改本文件夹下的任何内容！");
        if(warningfile.exists()){
            warningfile.remove();
        }
    }
}

void AutoImg::draw(int x,int y,QColor color)
{
  if((x<w)&&(y<h)){
    int xid=qFloor((double)x/(double)part);
    int yid=qFloor((double)y/(double)part);
    if(prepareimag(xid,yid)){
      int xpos=x-xid*part;
      int ypos=y-yid*part;
      currentImg.setPixelColor(xpos,ypos,color);
    }
  }else{
    qDebug("index (%d,%d) out of range (%d,%d)",x,y,w,h);
  }

}

QImage AutoImg::image()
{
  int xc=qMax(1,qCeil((double)w/(double)part));
  int yc=qMax(1,qCeil((double)h/(double)part));
  savetemp();
  QImage out(w,h,format);
  for(int i=0;i<xc;i++){
    for(int j=0;j<yc;j++){
      prepareimag(i,j);
      int xpos=i*part;
      int ypos=j*part;
      imagcopy(&currentImg,&out,xpos,ypos);
    }
  }
  return out;
}

void AutoImg::setimage(QImage *image)
{
  this->format=image->format();
  clear();
  resize(image->width(),image->height());
  int xc=qMax(1,qCeil((double)w/(double)part));
  int yc=qMax(1,qCeil((double)h/(double)part));
  int wm=w-(xc-1)*part;
  int hm=h-(yc-1)*part;
  for(int i=0;i<xc;i++){
    for(int j=0;j<yc;j++){
      prepareimag(i,j);
      int xpos=i*part,ypos=j*part;
      int wn=part,hn=part;
      if(i==xc-1){
        wn=wm;
      }
      if(j==yc-1){
        hn=hm;
      }
      currentImg=image->copy(xpos,ypos,wn,hn);
    }
  }
  prepareimag(0,0);
}

QImage AutoImg::get(int sx,int sy,int sw,int sh,int pw,int ph)
{
  double scalew=(double)((double)pw/(double)sw),scaleh=(double)((double)ph/(double)sh);
  QImage out(pw,ph,format);
  int sxid=qFloor((double)sx/(double)part);
  int syid=qFloor((double)sy/(double)part);
  int sxpos=sx-sxid*part;
  int sypos=sy-syid*part;
  int ex=sx+sw-1;
  int ey=sy+sh-1;
  int exid=qFloor((double)ex/(double)part);
  int eyid=qFloor((double)ey/(double)part);
  int expos=ex-exid*part;
  int eypos=ey-eyid*part;
  for(int i=sxid;i<=exid;i++){
    for(int j=syid;j<=eyid;j++){
        if(!prepareimag(i,j)){
            qDebug()<<QString("Can't Prepare: (%0:%1,%2)").arg(id).arg(i).arg(j)<<Qt::endl;
        }


      int xsp=0,xep=part-1,ysp=0,yep=part-1;
      if(i==sxid){
        xsp=sxpos;
      }
      if(i==exid){
        xep=expos;
      }
      if(j==syid){
        ysp=sypos;
      }
      if(j==eyid){
        yep=eypos;
      }
      int wp=xep-xsp+1,hp=yep-ysp+1;
      QImage imgtemp=currentImg.copy(xsp,ysp,wp,hp).scaled(wp*scalew,hp*scaleh);
      imagcopy(&imgtemp,&out,i==sxid?0:((part-sxpos)*scalew+(i-sxid-1)*part*scalew),j==syid?0:((part-sypos)*scaleh+(j-syid-1)*part*scaleh));
    }
  }
  prepareimag(0,0);
  return out;
}

void AutoImg::scaled(int w,int h)
{
    prepareimag(0,0);
    double scalew=(double)w/(double)this->w,scaleh=(double)h/(double)this->h;
    int xco=qMax(1,qCeil((double)w/(double)part));
    int yco=qMax(1,qCeil((double)h/(double)part));
    int wmo=w-(xco-1)*part;
    int hmo=h-(yco-1)*part;
    int xcn=qMax(1,qCeil((double)this->w/(double)part));
    int ycn=qMax(1,qCeil((double)this->h/(double)part));
    int wmn=this->w-(xcn-1)*part;
    int hmn=this->h-(ycn-1)*part;



    for(int i=0;i<xco;i++){
        for(int j=0;j<yco;j++){
            int xis=qFloor((double)((double)(i*part)/(double)scalew)/part),xie=qFloor((double)((double)((i+1)*part)/(double)scalew)/part);
            int yis=qFloor((double)((double)(j*part)/(double)scaleh)/part),yie=qFloor((double)((double)((j+1)*part)/(double)scaleh)/part);
            int xps=(double)((double)(i*part)/(double)scalew)-xis*part,xpe=(double)((double)((i+1)*part)/(double)scalew)-xie*part;
            int yps=(double)((double)(j*part)/(double)scaleh)-yis*part,ype=(double)((double)((j+1)*part)/(double)scaleh)-yie*part;
            int wt=part,ht=part;
            if(i==xco-1){
                xie=xcn-1;
                xpe=wmn-1;
                wt=wmo;
            }
            if(j==yco-1){
                yie=ycn-1;
                ype=hmn-1;
                ht=hmo;
            }
            QImage imgtmp(wt,ht,format);
            for(int k=xis;k<xie;k++){
                for(int l=yis;l<yie;l++){
                    int xtps=0,xtpe=part-1,ytps=0,ytpe=part-1;
                    if(k==xis){
                        xtps=xps;
                    }
                    if(k==xie-1){
                        xtpe=xpe;
                    }
                    if(l==yis){
                        ytps=yps;
                    }
                    if(l==yie-1){
                        ytpe=ype;
                    }
                    QImage imager=readtempfile(k,l).copy(xtps,ytps,xtpe-xtps,ytpe-ytps);
                    imager.scaled((xtpe-xtps)*scalew,(ytpe-ytps)*scaleh);
                    int xopos=(k*part+xtps)*scalew,yopos=(l*part+ytps)*scaleh;
                    imagcopy(&imager,&imgtmp,xopos,yopos);
                }
            }
            savetempfile2(i,j,imgtmp);
        }
    }

    untemp2(xcn,ycn,xco,yco);
    this->w=w;
    this->h=h;
    prepareimag(0,0);
}

void AutoImg::clear()
{
  QDir dir(QCoreApplication::applicationDirPath()+"/autoimgtemp/");
  if(dir.exists()){
    QDir tdir(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/",this->id));
    if(tdir.exists()){
      tdir.setFilter(QDir::Files);
      for(uint i=0;i<tdir.count();i++){
        QString fn=tdir.path()+"/"+tdir[i];
        QFile ft(fn);
        if(ft.exists()){
          ft.remove();
        }
      }
    }
  }
  w=0;
  h=0;
  QFile warningfile(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+"AutoImg类缓存！请勿更改本文件夹下的任何内容！");
  warningfile.open(QIODevice::ReadWrite);
  warningfile.close();
  prepareimag(0,0);
}

void AutoImg::resize(int w,int h)
{
  prepareimag(0,0);
  int xco=qMax(1,qCeil((double)w/(double)part));
  int yco=qMax(1,qCeil((double)h/(double)part));
  int wmo=w-(xco-1)*part;
  int hmo=h-(yco-1)*part;
  int xcn=qMax(1,qCeil((double)this->w/(double)part));
  int ycn=qMax(1,qCeil((double)this->h/(double)part));
  int wmn=this->w-(xcn-1)*part;
  int hmn=this->h-(ycn-1)*part;

  Q_UNUSED(wmn);
  Q_UNUSED(hmn);


  bool flag[2];
  flag[0]=(xco>=xcn);
  flag[1]=(yco>=ycn);
  if(flag[0]&&flag[1]){
    for(int i=0;i<xcn-1;i++){
      QImage imgtmp(part,part,format);
      imgtmp.fill(backgroundcolor);
      QImage imgtmpn=readtempfile(i,ycn-1);
      imagcopy(&imgtmpn,&imgtmp,0,0);
      removetempfile(i,ycn-1);
      savetempfile(i,ycn-1,imgtmp);
    }//refresh border B
    for(int j=0;j<ycn-1;j++){
      QImage imgtmp(part,part,format);
      imgtmp.fill(backgroundcolor);
      QImage imgtmpn=readtempfile(xcn-1,j);
      imagcopy(&imgtmpn,&imgtmp,0,0);
      removetempfile(xcn-1,j);
      savetempfile(xcn-1,j,imgtmp);
    }//refresh border R
    QImage imgtmp(part,part,format);
    imgtmp.fill(backgroundcolor);
    QImage imgtmpn=readtempfile(xcn-1,ycn-1);
    imagcopy(&imgtmpn,&imgtmp,0,0);
    removetempfile(xcn-1,ycn-1);
    savetempfile(xcn-1,ycn-1,imgtmp);
    //refresh border BR
    for(int i=xcn;i<xco;i++){
      for(int j=0;j<ycn;j++){
        int wt=part,ht=part;
        if(i==xco-1){
          wt=wmo;
        }
        createtempfile(i,j,wt,ht);
      }
    }//create empty part R
    for(int j=ycn;j<yco;j++){
      for(int i=0;i<xcn;i++){
        int wt=part,ht=part;
        if(j==yco-1){
          ht=hmo;
        }
        createtempfile(i,j,wt,ht);
      }
    }//create empty part B
    for(int i=xcn;i<xco;i++){
      for(int j=ycn;j<yco;j++){
        int wt=part,ht=part;
        if(i==xco-1){
          wt=wmo;
        }
        if(j==yco-1){
          ht=hmo;
        }
        createtempfile(i,j,wt,ht);
      }
    }//create empty part BR
  }else if(!(flag[0]||flag[1])){

      for(int i=xco;i<xcn;i++){
          for(int j=0;j<yco;j++){
              removetempfile(i,j);
          }
      }//remove part R
      for(int j=yco;j<ycn;j++){
          for(int i=0;i<xco;i++){
              removetempfile(i,j);
          }
      }//remove part B
      for(int i=xco;i<xcn;i++){
          for(int j=yco;j<ycn;j++){
              removetempfile(i,j);
          }
      }//remove part BR

      for(int i=0;i<xco;i++){
          QImage imgtmp(part,hmo,format);
          imgtmp.fill(backgroundcolor);
          QImage imgtmpn=readtempfile(i,yco-1);
          imgtmpn=imgtmpn.copy(0,0,part,hmo);
          imagcopy(&imgtmpn,&imgtmp,0,0);
          removetempfile(i,yco-1);
          savetempfile(i,yco-1,imgtmp);
      }//refresh border B
      for(int j=0;j<yco;j++){
          QImage imgtmp(wmo,part,format);
          imgtmp.fill(backgroundcolor);
          QImage imgtmpn=readtempfile(xco-1,j);
          imgtmpn=imgtmpn.copy(0,0,wmo,part);
          imagcopy(&imgtmpn,&imgtmp,0,0);
          removetempfile(xco-1,j);
          savetempfile(xco-1,j,imgtmp);
      }//refresh border R
      QImage imgtmp(wmo,hmo,format);
      imgtmp.fill(backgroundcolor);
      QImage imgtmpn=readtempfile(xco-1,yco-1);
      imgtmpn=imgtmpn.copy(0,0,wmo,hmo);
      imagcopy(&imgtmpn,&imgtmp,0,0);
      removetempfile(xco-1,yco-1);
      savetempfile(xco-1,yco-1,imgtmp);
      //refresh border BR
  }else if(flag[0]&&(!flag[1])){
      for(int j=yco;j<ycn;j++){
          for(int i=0;i<xcn;i++){
              removetempfile(i,j);
          }
      }//remove part B
      for(int i=xcn;i<xco;i++){
        for(int j=0;j<yco;j++){
          int wt=part,ht=part;
          if(i==xco-1){
            wt=wmo;
          }
          createtempfile(i,j,wt,ht);
        }
      }//create empty part R
      for(int j=0;j<yco;j++){
        QImage imgtmp(part,part,format);
        imgtmp.fill(backgroundcolor);
        QImage imgtmpn=readtempfile(xcn-1,j);
        imagcopy(&imgtmpn,&imgtmp,0,0);
        removetempfile(xcn-1,j);
        savetempfile(xcn-1,j,imgtmp);
      }//refresh border R
      for(int i=0;i<xco;i++){
          QImage imgtmp(part,hmo,format);
          imgtmp.fill(backgroundcolor);
          QImage imgtmpn=readtempfile(i,yco-1);
          imgtmpn=imgtmpn.copy(0,0,part,hmo);
          imagcopy(&imgtmpn,&imgtmp,0,0);
          removetempfile(i,yco-1);
          savetempfile(i,yco-1,imgtmp);
      }//refresh border B
  }else{
      for(int i=xco;i<xcn;i++){
          for(int j=0;j<ycn;j++){
              removetempfile(i,j);
          }
      }//remove part R
      for(int j=ycn;j<yco;j++){
        for(int i=0;i<xco;i++){
          int wt=part,ht=part;
          if(j==yco-1){
            ht=hmo;
          }
          createtempfile(i,j,wt,ht);
        }
      }//create empty part B
      for(int i=0;i<xco;i++){
        QImage imgtmp(part,part,format);
        imgtmp.fill(backgroundcolor);
        QImage imgtmpn=readtempfile(i,ycn-1);
        imagcopy(&imgtmpn,&imgtmp,0,0);
        removetempfile(i,ycn-1);
        savetempfile(i,ycn-1,imgtmp);
      }//refresh border B
      for(int j=0;j<yco;j++){
          QImage imgtmp(wmo,part,format);
          imgtmp.fill(backgroundcolor);
          QImage imgtmpn=readtempfile(xco-1,j);
          imgtmpn=imgtmpn.copy(0,0,wmo,part);
          imagcopy(&imgtmpn,&imgtmp,0,0);
          removetempfile(xco-1,j);
          savetempfile(xco-1,j,imgtmp);
      }//refresh border R
  }
  this->w=w;
  this->h=h;
  prepareimag(0,0);
}

int AutoImg::width()
{
  return w;
}

int AutoImg::height()
{
  return h;
}

void AutoImg::fill(QColor color)
{
  int xc=qMax(1,qCeil((double)w/(double)part));
  int yc=qMax(1,qCeil((double)h/(double)part));
  for(int i=0;i<xc;i++){
    for(int j=0;j<yc;j++){
      prepareimag(i,j);
      currentImg.fill(color);
    }
  }
  prepareimag(0,0);
  QFile file123456(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/0_0.png",id));
  if(!file123456.exists()){
      qDebug()<<"No 0_0!Fill"<<Qt::endl;
  }else{
      qDebug()<<"Yes 0_0!Fill"<<Qt::endl;
  }
}

void AutoImg::fill()
{
    int xc=qMax(1,qCeil((double)w/(double)part));
    int yc=qMax(1,qCeil((double)h/(double)part));
    for(int i=0;i<xc;i++){
      for(int j=0;j<yc;j++){
        prepareimag(i,j);
        currentImg.fill(backgroundcolor);
      }
    }
    prepareimag(0,0);
    QFile file123456(QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/0_0.png",id));
    if(!file123456.exists()){
        qDebug()<<"No 0_0!Fill"<<Qt::endl;
    }else{
        qDebug()<<"Yes 0_0!Fill"<<Qt::endl;
    }
}

//tools


bool AutoImg::prepareimag(int x,int y)
{
  if(px==x&&py==y){
    return true;
  }else{
    QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",id,x,y);

    QFile file(filename);
    if(file.exists()){
      savetemp();
      px=x;
      py=y;
      return currentImg.load(filename,"png");
    }else{
      return false;
    }

  }
}

void AutoImg::savetemp()
{
  QString filenamen=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",id,px,py);
  currentImg.save(filenamen,"png");
}

void AutoImg::imagcopy(QImage *source,QImage *objective,int xpos,int ypos)
{
  if(objective->width()>=xpos+source->width()&&objective->height()>=ypos+source->height()){
    for(int i=0;i<source->width();i++){
      for(int j=0;j<source->height();j++){
        objective->setPixelColor(xpos+i,ypos+j,source->pixelColor(i,j));
      }
    }
  }else{
    qDebug("source(%d,%d) can't copy to the position(%d,%d) on the objective image(%d,%d)",source->width(),source->height(),xpos,ypos,objective->width(),objective->height());
  }
}

bool AutoImg::removetempfile(int x,int y)
{
  QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",this->id,x,y);
  return QFile::remove(filename);
}

QImage AutoImg::readtempfile(int x,int y)
{
  QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",this->id,x,y);
  QImage out;
  out.load(filename);
  return out;
}

bool AutoImg::createtempfile(int x,int y,int w,int h)
{
  QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",this->id,x,y);
  QFile file(filename);
  if(file.exists()){
      file.remove();
  }
  QImage out(w,h,format);
  out.fill(backgroundcolor);
  return out.save(filename);
}

bool AutoImg::savetempfile(int x,int y,QImage image)
{
  QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",this->id,x,y);
  return image.save(filename);
}

bool AutoImg::removetempfile2(int x,int y)
{
  QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d_t.png",this->id,x,y);
  return QFile::remove(filename);
}

QImage AutoImg::readtempfile2(int x,int y)
{
  QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d_t.png",this->id,x,y);
  QImage out;
  out.load(filename);
  return out;
}

bool AutoImg::createtempfile2(int x,int y,int w,int h)
{
  QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d_t.png",this->id,x,y);
  QFile file(filename);
  if(file.exists()){
      file.remove();
  }
  QImage out(w,h,format);
  out.fill(backgroundcolor);
  return out.save(filename);
}

bool AutoImg::savetempfile2(int x,int y,QImage image)
{
  QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d_t.png",this->id,x,y);
  return image.save(filename);
}

bool AutoImg::untemp2(int xcn,int ycn,int xco,int yco)
{
    bool out=true;
    for(int i=0;i<xcn;i++){
        for(int j=0;j<ycn;j++){
            out=(out&&removetempfile(i,j));
        }
    }
    for(int i=0;i<xco;i++){
        for(int j=0;j<yco;j++){
            QString filename=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",this->id,i,j);
            QString filename2=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d_t.png",this->id,i,j);
            out=(out&&QFile::copy(filename2,filename));
        }
    }
    for(int i=0;i<xco;i++){
        for(int j=0;j<yco;j++){
            out=(out&&removetempfile2(i,j));
        }
    }
    return out;
}


int AutoImg::__test_getid()
{
    return id;
}

QImage AutoImg::__test_gettemp(int x,int y)
{
    return readtempfile(x,y);
}

int AutoImg::__test_getpart()
{
    return part;
}

QImage::Format AutoImg::__test_getformat()
{
    return format;
}

QColor AutoImg::__test_getbackgroundcolor()
{
    return backgroundcolor;
}

AutoImg& AutoImg::operator=(const AutoImg& arg)
{
    if(this!=&arg){
        this->clear();
        this->format=arg.format;
        this->px=arg.px;
        this->py=arg.py;
        this->h=arg.h;
        this->w=arg.w;
        this->currentImg=arg.currentImg;
        int xc=qMax(1,qCeil((double)arg.w/(double)arg.part));
        int yc=qMax(1,qCeil((double)arg.h/(double)arg.part));
        for(int i=0;i<xc;i++){
            for(int j=0;j<yc;j++){
                QString argtemp=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",arg.id,i,j);
                QString outtemp=QCoreApplication::applicationDirPath()+"/autoimgtemp/"+QString::asprintf("%d/%d_%d.png",this->id,i,j);
                if(!QFile::copy(argtemp,outtemp)){
                    qDebug()<<"Can't copy: "<<argtemp<<" to: "<<outtemp<<Qt::endl;
                }
            }
        }
    }
    return *this;
}
