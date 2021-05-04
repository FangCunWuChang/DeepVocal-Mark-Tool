#include "gpl.h"
#include "ui_gpl.h"

GPL::GPL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GPL)
{
    ui->setupUi(this);
}

GPL::~GPL()
{
    delete ui;
}

void GPL::settext(QString text)
{
    ui->text->setPlainText(text);
}
