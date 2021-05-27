#include "ctool.h"
#include "ui_ctool.h"

CTool::CTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CTool)
{
    ui->setupUi(this);
    flags.insert("up_enabled",true);
    flags.insert("up_covered",false);
    flags.insert("up_pressed",false);
    flags.insert("up_checked",false);
    flags.insert("up_checkable",false);
    flags.insert("down_enabled",true);
    flags.insert("down_covered",false);
    flags.insert("down_pressed",false);
    flags.insert("down_checked",false);
    flags.insert("down_checkable",false);
    flags.insert("analyse_enabled",true);
    flags.insert("analyse_covered",false);
    flags.insert("analyse_pressed",false);
    flags.insert("analyse_checked",false);
    flags.insert("analyse_checkable",false);
    flags.insert("play_enabled",false);
    flags.insert("play_covered",false);
    flags.insert("play_pressed",false);
    flags.insert("play_checked",false);
    flags.insert("play_checkable",true);
    flags.insert("auto_enabled",true);
    flags.insert("auto_covered",false);
    flags.insert("auto_pressed",false);
    flags.insert("auto_checked",true);
    flags.insert("auto_checkable",true);
    flags.insert("1_enabled",true);
    flags.insert("1_covered",false);
    flags.insert("1_pressed",false);
    flags.insert("1_checked",true);
    flags.insert("1_checkable",false);
    flags.insert("2_enabled",true);
    flags.insert("2_covered",false);
    flags.insert("2_pressed",false);
    flags.insert("2_checked",false);
    flags.insert("2_checkable",false);
    flags.insert("3_enabled",true);
    flags.insert("3_covered",false);
    flags.insert("3_pressed",false);
    flags.insert("3_checked",false);
    flags.insert("3_checkable",false);
    flags.insert("4_enabled",true);
    flags.insert("4_covered",false);
    flags.insert("4_pressed",false);
    flags.insert("4_checked",false);
    flags.insert("4_checkable",false);
    flags.insert("save_enabled",false);
    flags.insert("save_covered",false);
    flags.insert("save_pressed",false);
    flags.insert("save_checked",false);
    flags.insert("save_checkable",false);
    flags.insert("more_enabled",true);
    flags.insert("more_covered",false);
    flags.insert("more_pressed",false);
    flags.insert("more_checked",false);
    flags.insert("more_checkable",false);

    buttonflags.insert("up",QRect(0,0,height(),height()));
    buttonflags.insert("down",QRect(height(),0,height(),height()));
    buttonflags.insert("analyse",QRect(2*height(),0,3*height(),height()));
    buttonflags.insert("play",QRect(5*height(),0,3*height(),height()));
    buttonflags.insert("more",QRect(width()-height(),0,height(),height()));
    buttonflags.insert("save",QRect(width()-4*height(),0,3*height(),height()));
    buttonflags.insert("4",QRect(width()-5.25*height(),0,height(),height()));
    buttonflags.insert("3",QRect(width()-6.25*height(),0,height(),height()));
    buttonflags.insert("2",QRect(width()-7.25*height(),0,height(),height()));
    buttonflags.insert("1",QRect(width()-8.25*height(),0,height(),height()));
    buttonflags.insert("auto",QRect(width()-11.5*height(),0,3*height(),height()));

    this->setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
}

CTool::~CTool()
{
    delete ui;
}

void CTool::resizeEvent(QResizeEvent *event)
{
    buttonflags.insert("up",QRect(0,0,height(),height()));
    buttonflags.insert("down",QRect(height(),0,height(),height()));
    buttonflags.insert("analyse",QRect(2*height(),0,3*height(),height()));
    buttonflags.insert("play",QRect(5*height(),0,3*height(),height()));
    buttonflags.insert("more",QRect(width()-height(),0,height(),height()));
    buttonflags.insert("save",QRect(width()-4*height(),0,3*height(),height()));
    buttonflags.insert("4",QRect(width()-5.25*height(),0,height(),height()));
    buttonflags.insert("3",QRect(width()-6.25*height(),0,height(),height()));
    buttonflags.insert("2",QRect(width()-7.25*height(),0,height(),height()));
    buttonflags.insert("1",QRect(width()-8.25*height(),0,height(),height()));
    buttonflags.insert("auto",QRect(width()-11.5*height(),0,3*height(),height()));
    ui->wavname->resize(6.5*height(),0.8*height());
    ui->wavname->move(8.25*height(),0.1*height());
    repaint();
    QWidget::resizeEvent(event);
}

void CTool::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(31,31,31));
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setWidth(1);
    pen.setColor(QColor(255,255,255));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(0,0,0,0.4*255));
    painter.setPen(pen);
    painter.setBrush(brush);
    QFont font;
    font.setPixelSize(0.4*height());
    painter.setFont(font);

    painter.drawRect(8.25*height(),0.1*height(),6.5*height(),0.8*height());//filename

    this->drawbutton1(&painter,buttonflags["up"].toRect(),"up");
    this->drawbutton1(&painter,buttonflags["down"].toRect(),"down");
    this->drawbutton2(&painter,buttonflags["analyse"].toRect(),"analyse","音频分析");
    this->drawbutton2(&painter,buttonflags["play"].toRect(),"play",flags["play_checked"].toBool()?"停止":"播放");

    this->drawbutton1(&painter,buttonflags["more"].toRect(),"more");
    this->drawbutton2(&painter,buttonflags["save"].toRect(),"save","保存标记");
    this->drawbutton3(&painter,buttonflags["4"].toRect(),"4","4");
    this->drawbutton3(&painter,buttonflags["3"].toRect(),"3","3");
    this->drawbutton3(&painter,buttonflags["2"].toRect(),"2","2");
    this->drawbutton3(&painter,buttonflags["1"].toRect(),"1","1");
    this->drawbutton2(&painter,buttonflags["auto"].toRect(),"auto","自动切换");
}

QRect CTool::geticonrect1(QRect button,QPixmap icon,double scale)
{
    double sizemin=qMin((double)((double)button.height()/(double)icon.width()),(double)((double)button.height()/(double)icon.height()));
    sizemin*=scale;

    int poix=button.x()+button.width()/2-icon.width()*sizemin/2;
    int poiy=button.y()+button.height()/2-icon.height()*sizemin/2;
    int w=icon.width()*sizemin;
    int h=icon.height()*sizemin;
    return QRect(poix,poiy,w,h);
}

QRect CTool::geticonrect2(QRect button,QPixmap icon,double scale)
{
    double sizemin=(double)((double)button.height()/(double)icon.height());
    sizemin*=scale;

    int poix=button.x()+button.width()*0.2-icon.width()*sizemin/2;
    int poiy=button.y()+button.height()/2-icon.height()*sizemin/2;
    int w=icon.width()*sizemin;
    int h=icon.height()*sizemin;
    return QRect(poix,poiy,w,h);
}

QPoint CTool::gettextpoint(QRect button,QString text,double scale)
{
    Q_UNUSED(text);
    int h=0.4*button.height()*scale;
    int y=button.y()+button.height()/2+h/2-button.height()*0.06;
    int x=button.x()+button.width()*0.2+button.height()/2-button.width()*0.04;
    return QPoint(x,y);
}

QPoint CTool::gettextpoint3(QRect button,QString text,double scale)
{
    Q_UNUSED(text);
    int h=0.4*button.height()*scale;
    int y=button.y()+button.height()/2+h/2-button.height()*0.06;
    int x=button.x()+button.width()/2-0.4*button.height()/2+button.width()*0.1;
    return QPoint(x,y);
}

void CTool::drawbutton1(QPainter *painter,QRect button,QString name,double scale)
{
    if(flags[name+"_enabled"].toBool()){
        if(flags[name+"_pressed"].toBool()){
            painter->fillRect(button,QColor(255,255,255));
        }else if(flags[name+"_covered"].toBool()){
            painter->fillRect(button,QColor(119,119,119,150));
        }else{
            if(flags[name+"_checked"].toBool()){
                painter->fillRect(button,QColor(119,119,119));
            }
        }
        QPixmap pm(":/icons/icons/"+name+".png");
        QRect icon=geticonrect1(button,pm,scale);
        painter->drawPixmap(icon,pm);
    }else{
        QPixmap pm(":/icons/icons/"+name+".png");
        QRect icon=geticonrect1(button,pm,scale);
        painter->drawPixmap(icon,pm);
        painter->fillRect(button,QColor(31,31,31,150));
    }
}

void CTool::drawbutton2(QPainter *painter,QRect button,QString name,QString text,double scale)
{
    if(flags[name+"_enabled"].toBool()){
        if(flags[name+"_pressed"].toBool()){
            painter->fillRect(button,QColor(255,255,255));
        }else if(flags[name+"_covered"].toBool()){
            painter->fillRect(button,QColor(119,119,119,150));
        }else{
            if(flags[name+"_checked"].toBool()){
                painter->fillRect(button,QColor(119,119,119));
            }
        }
        QPixmap pm(":/icons/icons/"+name+".png");
        QRect icon=geticonrect2(button,pm,scale);
        painter->drawPixmap(icon,pm);
        painter->drawText(gettextpoint(button,text),text);
    }else{
        QPixmap pm(":/icons/icons/"+name+".png");
        QRect icon=geticonrect2(button,pm,scale);
        painter->drawPixmap(icon,pm);
        painter->drawText(gettextpoint(button,text),text);
        painter->fillRect(button,QColor(31,31,31,150));
    }
}

void CTool::drawbutton3(QPainter *painter,QRect button,QString name,QString text,double scale)
{
    Q_UNUSED(scale);
    if(flags[name+"_enabled"].toBool()){
        if(flags[name+"_pressed"].toBool()){
            painter->fillRect(button,QColor(255,255,255));
        }else if(flags[name+"_covered"].toBool()){
            painter->fillRect(button,QColor(119,119,119,150));
        }else{
            if(flags[name+"_checked"].toBool()){
                painter->fillRect(button,QColor(119,119,119));
            }
        }
        painter->drawText(gettextpoint3(button,text),text);
    }else{
        painter->drawText(gettextpoint3(button,text),text);
        painter->fillRect(button,QColor(31,31,31,150));
    }
}

void CTool::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        lpressed=true;
        for(int i=0;i<buttonflags.size();i++){
            if(inRect(event->pos(),buttonflags.values().at(i).toRect())){
                flags.insert(buttonflags.keys().at(i)+"_pressed",true);
            }else{
                flags.insert(buttonflags.keys().at(i)+"_pressed",false);
            }
        }
    }
    repaint();
}

void CTool::mouseMoveEvent(QMouseEvent *event)
{
    if(lpressed){

    }else{
        for(int i=0;i<buttonflags.size();i++){
            if(inRect(event->pos(),buttonflags.values().at(i).toRect())){
                flags.insert(buttonflags.keys().at(i)+"_covered",true);
            }else{
                flags.insert(buttonflags.keys().at(i)+"_covered",false);
            }
        }
    }
    repaint();
}

void CTool::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(lpressed){
            lpressed=false;
            for(int i=0;i<buttonflags.size();i++){
                if(flags[buttonflags.keys().at(i)+"_pressed"].toBool()){
                    phasebutton(buttonflags.keys().at(i));
                }
                flags.insert(buttonflags.keys().at(i)+"_pressed",false);
            }
        }
    }
    repaint();
}

void CTool::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    lpressed=false;
    for(int i=0;i<buttonflags.size();i++){
        flags.insert(buttonflags.keys().at(i)+"_covered",false);
        flags.insert(buttonflags.keys().at(i)+"_pressed",false);
    }
    repaint();
}

bool CTool::inRect(QPoint pos,QRect rect)
{
    return (pos.x()>rect.x())&&(pos.x()<rect.x()+rect.width())&&(pos.y()>rect.y())&&(pos.y()<rect.y()+rect.height());
}

void CTool::phasebutton(QString button)
{
    if(flags[button+"_enabled"].toBool()){
        if(flags[button+"_checkable"].toBool()){
            flags.insert(button+"_checked",!flags[button+"_checked"].toBool());
            repaint();
        }
        emit ctb(button,flags[button+"_checked"].toBool());
    }

}

void CTool::setbuttonchecked(QString button,bool checked)
{
    if(buttonflags.keys().contains(button)){
        flags.insert(button+"_checked",checked);
    }
    repaint();
}

void CTool::setbuttonenabled(QString button,bool enabled)
{
    if(buttonflags.keys().contains(button)){
        flags.insert(button+"_enabled",enabled);
    }
    repaint();
}

void CTool::setkeypress(QString key)
{
    if(key=="Alt+A"){
        phasebutton("auto");
    }else if(key=="Alt+X"){
        phasebutton("play");
    }else if(key=="Alt+S"){
        phasebutton("save");
    }else if(key=="1"){
        phasebutton("1");
    }else if(key=="2"){
        phasebutton("2");
    }else if(key=="3"){
        phasebutton("3");
    }else if(key=="4"){
        phasebutton("4");
    }else if(key=="up"){
        phasebutton("up");
    }else if(key=="down"){
        phasebutton("down");
    }else{

    }
}

void CTool::setwavname(QString wavname)
{
    ui->wavname->setText(wavname);
    this->wavname=wavname;
}

void CTool::setowlock(bool ok)
{
    ui->wavname->setEnabled(!ok);
}

void CTool::on_wavname_clicked()
{
    emit owr();
}
