#ifndef SPECPLOT_H
#define SPECPLOT_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QWheelEvent>
#include <QMouseEvent>
#include "global.h"
#include <QtMath>
#include <QTouchEvent>
#include "autoimg.h"

namespace Ui {
class Specplot;
}

#define scaletimes_sp 5

class Specplot : public QWidget
{
    Q_OBJECT

public:
    explicit Specplot(QWidget *parent = nullptr);
    ~Specplot();
    void setpix(QVector<QVector<double>> pixmap,int wsize,int samplerates=44100);
    void changemode(int code);
    void setv(QVector<bool> flagtemp);
    void setselected(bool selected,double ssp,double sep);
    void setlines(double l1,double l2,double l3,double l4);
    void setfourlines(bool fourlines);

private:
    Ui::Specplot *ui;
    QPixmap *pm2=new QPixmap(width()*scaletimes_sp*0.975,height()*scaletimes_sp);
    QPixmap pmt;
    QVector<QVector<double>> pt;
    int wsize=0;
    double vs=0.5;
    int samplerates=44100;
    double hs=0,he=1;
    QVector<bool> flagtemp;
    bool isxon=false;
    bool yon=false;
    int xw=0,yw=-30;
    int getindex(int xw,bool *ok);

    bool rpressed=false;
    bool selected=false;
    double ssp=0,sep=0;
    double sxt=0;
    double l1=0,l2=0,l3=0,l4=0;
    bool fourlines=true;


    bool spressed=false;
    double hspt=0,hept=0;
    double vst=0;

    QPointF mn;
    bool isin=false;

    double min_Bound=global_sets::m_minBound,max_Bound=global_sets::m_maxBound;

    int trasx(int x);

    void pixchange();
    void tempchange();
    QRect g_poi(int x,int y);
    QColor getcolor(double v);
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool event(QEvent *event);
public slots:
    void seths(double hs=0,double he=1);
    void setxw(int xw);
    void setxon(bool xon);
signals:
    void hschanged(double hs=0,double he=1);
    void xmoved(int xw);
    void xon(bool on);
    void changesp(bool selected,double ssp,double sep);
    void linechanged(double line);
    void point(double px);
    void pmove(double px);
    void prefresh();
};

#endif // SPECPLOT_H
