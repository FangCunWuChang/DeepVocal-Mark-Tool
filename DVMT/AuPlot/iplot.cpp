#include "iplot.h"
#include "ui_iplot.h"

IPlot::IPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IPlot)
{
    ui->setupUi(this);
}

IPlot::IPlot(QWidget *parent,QVector<double> *data) :
    QWidget(parent),
    ui(new Ui::IPlot)
{
    this->data=*data;
    repaint();
}

IPlot::~IPlot()
{
    delete ui;
}

void IPlot::plotdata(QWidget *parent,QVector<double> *data)
{
    IPlot *plot=new IPlot(parent,data);
    plot->show();
}

void IPlot::plot(QVector<double> data)
{
    this->data=data;
    repaint();
}

void IPlot::plot()
{
    repaint();
}

void IPlot::setdata(QVector<double> data)
{
    this->data=data;
}

void IPlot::resizeEvent(QResizeEvent *event)
{
    repaint();
    QWidget::resizeEvent(event);
}

void IPlot::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    pen.setWidth(1);
    pen.setColor(QColor(114,159,207));
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    brush.setColor(QColor(85,87,83));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.fillRect(0,0,width(),height(),Qt::white);
    QPolygon polygon;
    int nsize=data.size();
    //qDebug("nsize:%d",nsize);
    for(int i=0;i<nsize;i++){
        QPoint point(static_cast<double>(width()*static_cast<double>(static_cast<double>(i)/static_cast<double>(nsize))),static_cast<double>(-(data.at(i)/**static_cast<double>(height()/2)*/)));
        //qDebug("x:%d y:%d",point.x(),point.y());
        polygon.append(point);
    }
    painter.drawPolyline(polygon);
    painter.end();
    QWidget::paintEvent(event);
}
