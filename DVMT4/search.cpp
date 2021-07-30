#include "search.h"
#include "ui_search.h"

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::resizeEvent(QResizeEvent *event)
{
    ui->line->resize(0.2*width(),0.04*height());
    ui->slist->resize(0.2*width(),0.96*height());
    ui->line->move(0,0);
    ui->slist->move(0,0.04*height());
    QFont font;
    font.setPixelSize(ui->slist->height()*0.017);
    for(int i=0;i<ui->slist->count();i++){
        ui->slist->item(i)->setSizeHint(QSize(ui->slist->width()*0.9,ui->slist->height()*0.025));
        ui->slist->item(i)->setFont(font);
    }
    repaint();
    QWidget::resizeEvent(event);
}

void Search::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(31,31,31,150));
    QWidget::paintEvent(event);
}

void Search::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->pos().x()>=0&&event->pos().x()<=0.2*width()&&event->pos().y()>=0.04*height()&&event->pos().y()<=height())){
        this->hide();
    }
    QWidget::mouseReleaseEvent(event);
}

void Search::setsymbols(QVector<CVVCSymbol> CSL)
{
    this->CSL=CSL;
    ui->line->clear();
    ui->slist->clear();
    for(int i=0;i<CSL.size();i++){
        ui->slist->addItem(CSL.at(i).name);
        ui->slist->item(ui->slist->count()-1)->setToolTip(CSL.at(i).mes);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        if(CSL.at(i).mes=="正确"){
            brush.setColor(QColor(0,255,0,0));
        }else if(CSL.at(i).mes=="未标记"){
            brush.setColor(QColor(255,0,0,70));
        }else{
            brush.setColor(QColor(255,255,0,70));
        }
        ui->slist->item(ui->slist->count()-1)->setBackground(brush);
        QFont font;
        font.setPixelSize(ui->slist->height()*0.017);
        ui->slist->item(ui->slist->count()-1)->setFont(font);
        ui->slist->item(ui->slist->count()-1)->setSizeHint(QSize(ui->slist->width()*0.9,ui->slist->height()*0.025));
    }
}

void Search::on_line_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->slist->clear();
        for(int i=0;i<CSL.size();i++){
            ui->slist->addItem(CSL.at(i).name);
            ui->slist->item(ui->slist->count()-1)->setToolTip(CSL.at(i).mes);
            QBrush brush;
            brush.setStyle(Qt::SolidPattern);
            if(CSL.at(i).mes=="正确"){
                brush.setColor(QColor(0,255,0,0));
            }else if(CSL.at(i).mes=="未标记"){
                brush.setColor(QColor(255,0,0,70));
            }else{
                brush.setColor(QColor(255,255,0,70));
            }
            ui->slist->item(ui->slist->count()-1)->setBackground(brush);
            QFont font;
            font.setPixelSize(ui->slist->height()*0.017);
            ui->slist->item(ui->slist->count()-1)->setFont(font);
            ui->slist->item(ui->slist->count()-1)->setSizeHint(QSize(ui->slist->width()*0.9,ui->slist->height()*0.025));
        }
    }else{
        QVector<CVVCSymbol> CSLT;
        for(int i=0;i<CSL.size();i++){
            if(CSL.at(i).name.contains(arg1,Qt::CaseSensitive)){
                CSLT.append(CSL.at(i));
            }
        }
        ui->slist->clear();
        for(int i=0;i<CSLT.size();i++){
            ui->slist->addItem(CSLT.at(i).name);
            ui->slist->item(ui->slist->count()-1)->setToolTip(CSLT.at(i).mes);
            QBrush brush;
            brush.setStyle(Qt::SolidPattern);
            if(CSLT.at(i).mes=="正确"){
                brush.setColor(QColor(0,255,0,0));
            }else if(CSLT.at(i).mes=="未标记"){
                brush.setColor(QColor(255,0,0,70));
            }else{
                brush.setColor(QColor(255,255,0,70));
            }
            ui->slist->item(ui->slist->count()-1)->setBackground(brush);
            QFont font;
            font.setPixelSize(ui->slist->height()*0.017);
            ui->slist->item(ui->slist->count()-1)->setFont(font);
            ui->slist->item(ui->slist->count()-1)->setSizeHint(QSize(ui->slist->width()*0.9,ui->slist->height()*0.025));
        }
    }
}

void Search::on_slist_itemPressed(QListWidgetItem *item)
{
    if(!item->text().isEmpty()){
        this->hide();
        emit name(item->text());
    }
}
