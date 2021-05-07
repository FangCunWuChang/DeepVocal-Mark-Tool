#ifndef WAVEVIEW_H
#define WAVEVIEW_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QWheelEvent>
#include "global.h"
#include "autoimg.h"

namespace Ui {
class Waveview;
}

#define scaletimes_wv 20

class Waveview : public QWidget
{
    Q_OBJECT

public:
    explicit Waveview(QWidget *parent = nullptr);
    ~Waveview();
    void setpix(QVector<double> pixmap);
    void setlines(double l1,double l2,double l3,double l4);
    void setselected(bool selected,double ssp,double sep);

private:
    Ui::Waveview *ui;
    QPixmap *pm2=new QPixmap(width()*scaletimes_wv,height()*scaletimes_wv);
    QVector<double> pt;
    double hs=0,he=1;
    int modeflag=0;
    int px=0,py=0,nx=0,ny=0;
    double hst=0,het=0;
    double l1=0,l2=0,l3=0,l4=0;
    bool selected=false;
    double ssp=0,sep=0;
    void pixchange();
    QPoint g_poi(int x,double y);
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
public slots:
    void seths(double hs=0,double he=1);
signals:
    void hschanged(double hs=0,double he=1);
};

#endif // WAVEVIEW_H
