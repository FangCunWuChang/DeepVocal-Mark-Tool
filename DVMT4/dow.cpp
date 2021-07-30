#include "dow.h"
#include "ui_dow.h"

DoW::DoW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoW)
{
    ui->setupUi(this);
}

DoW::~DoW()
{
    delete ui;
}

void DoW::resizeEvent(QResizeEvent *event)
{
    repaint();
    QWidget::resizeEvent(event);
}

void DoW::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(31,31,31,0*255));
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setWidth(1);
    pen.setColor(QColor(255,255,255,0.6*255));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(0,0,0,0.4*255));
    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawRect(0.2*width()+2*0.04*height(),0.04*height(),4*0.04*height(),5*0.04*height());
    painter.drawRect(0.2*width()+8.25*0.04*height(),0.04*height(),6*0.04*height(),10*0.04*height());
    painter.drawRect(width()-4*0.04*height(),0.04*height(),4*0.04*height(),8*0.04*height());
}
