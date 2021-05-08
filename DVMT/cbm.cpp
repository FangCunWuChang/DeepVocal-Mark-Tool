#include "cbm.h"
#include "ui_cbm.h"

CBM::CBM(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CBM)
{
    ui->setupUi(this);
}

CBM::~CBM()
{
    delete ui;
}

void CBM::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    ui->sname->resize(width(),0.3*height());
    ui->sname->move(0,0);
    ui->lhb->resize(0.5*width(),0.35*height());
    ui->lhb->move(0,0.3*height());
    ui->aw->resize(0.5*width(),0.35*height());
    ui->aw->move(0.5*width(),0.3*height());
    ui->menu->resize(0.5*width(),0.35*height());
    ui->menu->move(0,0.65*height());
    ui->sea->resize(0.5*width(),0.35*height());
    ui->sea->move(0.5*width(),0.65*height());
    repaint();
}

void CBM::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    pen.setWidth(4);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setColor(QColor(117,138,153));
    painter.setPen(pen);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(61,59,79));
    painter.setBrush(brush);
    painter.drawRect(0,0,width(),height());
    painter.end();
}

void CBM::setText(QString text)
{
    ui->sname->setText(text);
}

void CBM::setmenuenabled(bool ok)
{
    ui->menu->setEnabled(ok);
}

void CBM::setseaenabled(bool ok)
{
    ui->sea->setEnabled(ok);
}

void CBM::setawenabled(bool ok)
{
    ui->aw->setEnabled(ok);
}

void CBM::on_lhb_clicked(bool checked)
{
    emit lhbclicked(checked);
}

void CBM::on_aw_clicked()
{
    emit awclicked();
}

void CBM::on_sea_clicked()
{
    emit seaclicked();
}

void CBM::on_menu_clicked()
{
    emit menuclicked();
}


void CBM::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        m_bDrag=true;
        mouseStartPoint=event->globalPos();
        windowTopLeftPoint=this->frameGeometry().topLeft();
    }
}

void CBM::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        QPoint distance=event->globalPos()-mouseStartPoint;
        QPoint pos=windowTopLeftPoint+distance;
        pos.setX(qBound(0,pos.x(),parentWidget()->width()-width()));
        pos.setY(qBound(0,pos.y(),parentWidget()->height()-height()));
        this->move(pos);
        emit rp(pos);
    }
}

void CBM::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton&&m_bDrag)
    {
        QPoint distance=event->globalPos()-mouseStartPoint;
        QPoint pos=windowTopLeftPoint+distance;
        pos.setX(qBound(0,pos.x(),parentWidget()->width()-width()));
        pos.setY(qBound(0,pos.y(),parentWidget()->height()-height()));
        this->move(pos);
        emit rp(pos);
        m_bDrag=false;
    }
}

void CBM::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    if(m_bDrag)
    {
        m_bDrag=false;
    }
}

void CBM::outclick(int x,int y)
{
    m_bDrag=true;
    mouseStartPoint=QPoint(x,y);
    windowTopLeftPoint=this->frameGeometry().topLeft();
}

void CBM::outmove(int x,int y)
{
    if(m_bDrag)
    {
        QPoint distance=QPoint(x,y)-mouseStartPoint;
        QPoint pos=windowTopLeftPoint+distance;
        pos.setX(qBound(0,pos.x(),parentWidget()->width()-width()));
        pos.setY(qBound(0,pos.y(),parentWidget()->height()-height()));
        this->move(pos);
        emit rp(pos);
    }
}

void CBM::outrelease(int x,int y)
{
    if(m_bDrag)
    {
        QPoint distance=QPoint(x,y)-mouseStartPoint;
        QPoint pos=windowTopLeftPoint+distance;
        pos.setX(qBound(0,pos.x(),parentWidget()->width()-width()));
        pos.setY(qBound(0,pos.y(),parentWidget()->height()-height()));
        this->move(pos);
        emit rp(pos);
        m_bDrag=false;
    }
}

void CBM::outleave()
{
    if(m_bDrag)
    {
        m_bDrag=false;
    }
}
