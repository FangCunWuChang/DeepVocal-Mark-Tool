#include "title.h"
#include "ui_title.h"

Title::Title(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Title)
{
    ui->setupUi(this);
}

Title::~Title()
{
    delete ui;
}

void Title::setTitle(QString title)
{
    ui->title->setText(title);
    repaint();
}

void Title::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(31,31,31));

}

void Title::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    ui->title->resize(width(),height());
    ui->title->move(0,0);
    QFont font=ui->title->font();
    font.setPixelSize(0.5*height());
    ui->title->setFont(font);
    ui->close->setFont(font);
    ui->min->setFont(font);
    ui->close->resize(2*height(),height());
    ui->min->resize(2*height(),height());
    ui->close->move(width()-2*height(),0);
    ui->min->move(width()-4*height(),0);
    ui->close->raise();
    ui->min->raise();
    repaint();
}

void Title::on_close_clicked()
{
    emit closeb();
}

void Title::on_min_clicked()
{
    emit minb();
}
