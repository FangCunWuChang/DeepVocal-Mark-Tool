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
    ui->line->resize(0.9*0.60*width(),0.1*0.60*height());
    ui->slist->resize(0.9*0.60*width(),0.9*0.60*height()-0.2*height()+(0.033333)*3*0.60*height()+0.1*0.60*height());
    ui->push->resize(0.9*0.60*width(),(0.033333)*2*0.60*height());
    ui->line->move(0.20*width()+0.05*0.60*width(),0.2*height()+(0.033333)*0.60*height());
    ui->slist->move(0.20*width()+0.05*0.60*width(),0.2*height()+(0.033333)*3*0.60*height()+0.1*0.60*height());
    ui->push->move(0.20*width()+0.05*0.60*width(),0.2*height()+(0.033333)*0.60*height()+0.1*0.60*height());
    for(int i=0;i<ui->slist->count();i++){
        ui->slist->item(i)->setSizeHint(QSize(ui->slist->width()*0.9,ui->slist->height()*0.1));
    }
    repaint();
    QWidget::resizeEvent(event);
}

void Search::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(211,215,207,0));
    painter.fillRect(0.20*width(),0.20*height(),0.6*width(),0.6*height(),QColor(61,59,79));
    QWidget::paintEvent(event);
}

void Search::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->pos().x()>=0.20*width()&&event->pos().x()<=0.80*width()&&event->pos().y()>=0.20*height()&&event->pos().y()<=0.80*height())){
        this->hide();
    }
    QWidget::mouseReleaseEvent(event);
}

void Search::setsymbols(QVector<CVVCSymbol> CSL)
{
    this->CSL=CSL;
    ui->line->clear();
    ui->slist->clear();
    eggcount=0;
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
        ui->slist->item(ui->slist->count()-1)->setSizeHint(QSize(ui->slist->width()*0.9,ui->slist->height()*0.1));
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
            ui->slist->item(ui->slist->count()-1)->setSizeHint(QSize(ui->slist->width()*0.9,ui->slist->height()*0.1));
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
            ui->slist->item(ui->slist->count()-1)->setSizeHint(QSize(ui->slist->width()*0.9,ui->slist->height()*0.1));
        }
    }
}

void Search::on_push_clicked()
{
    eggcount++;
    if(eggcount==10){
        eggcount=0;
        this->hide();
        emit egg();
    }
}

void Search::on_slist_itemPressed(QListWidgetItem *item)
{
    if(!item->text().isEmpty()){
        this->hide();
        emit name(item->text());
    }
}
