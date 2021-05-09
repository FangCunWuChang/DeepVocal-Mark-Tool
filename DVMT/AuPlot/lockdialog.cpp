#include "lockdialog.h"
#include "ui_lockdialog.h"

LockDialog::LockDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LockDialog)
{
    ui->setupUi(this);
}

LockDialog::~LockDialog()
{
    delete ui;
}

void LockDialog::resizeEvent(QResizeEvent *event)
{
    ui->label->resize(width(),height());
    ui->label->move(0,0);
    QFont font;
    font.setPixelSize(0.03*height());
    ui->label->setFont(font);
    QWidget::resizeEvent(event);
}

void LockDialog::setmsg(QString msg)
{
    ui->label->setText(msg);
}
