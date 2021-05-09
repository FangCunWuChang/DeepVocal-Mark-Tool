#include "autowav.h"
#include "ui_autowav.h"

AutoWav::AutoWav(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AutoWav)
{
    ui->setupUi(this);
}

AutoWav::~AutoWav()
{
    delete ui;
}

void AutoWav::resizeEvent(QResizeEvent *event)
{
    ui->name->resize(0.9*0.60*width(),0.1*0.60*height());
    ui->olist->resize(0.9*0.60*width(),0.9*0.60*height()-0.2*height()+(0.033333)*3*0.60*height()+0.1*0.60*height());

    ui->name->move(0.20*width()+0.05*0.60*width(),0.2*height()+(0.033333)*0.60*height());
    ui->olist->move(0.20*width()+0.05*0.60*width(),0.2*height()+(0.033333)*3*0.60*height()+0.1*0.60*height());

    QFont font;
    font.setPixelSize(ui->olist->height()*0.05);
    for(int i=0;i<ui->olist->count();i++){
        ui->olist->item(i)->setSizeHint(QSize(ui->olist->width()*0.9,ui->olist->height()*0.1));
        ui->olist->item(i)->setFont(font);
    }
    repaint();
    QWidget::resizeEvent(event);
}

void AutoWav::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(61,59,79,200));
    painter.fillRect(0.20*width(),0.20*height(),0.6*width(),0.6*height(),QColor(61,59,79));
    QWidget::paintEvent(event);
}

void AutoWav::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->pos().x()>=0.20*width()&&event->pos().x()<=0.80*width()&&event->pos().y()>=0.20*height()&&event->pos().y()<=0.80*height())){
        this->hide();
    }
    QWidget::mouseReleaseEvent(event);
}

void AutoWav::setpathes(QStringList paths,QVector<QStringList> filelist)
{
    this->paths=paths;
    this->filelist=filelist;
    slovelist();
}

void AutoWav::setsymname(QString symname)
{
    this->symname=symname;
    slovelist();
}

void AutoWav::slovelist()
{
    ui->name->clear();
    ui->olist->clear();
    if(!symname.isEmpty()){

        QStringList searchlist;
        if(symname.contains("_")){
            searchlist.append(symname);
            QString snt=symname,snt1=symname;
            snt1.replace('_','-');
            searchlist.append(snt1);
            snt.replace('_',' ');
            searchlist.append(snt);
        }else if(symname.at(0)=='-'){
            QString snt=symname;
            snt.remove('-');
            searchlist.append(snt);
            searchlist.append(symname);
        }else{
            searchlist.append(symname);
        }

        QStringList listht;
        for(int k=0;k<searchlist.size();k++){
            for(int i=0;i<paths.size();i++){
                for(int j=0;j<filelist.at(i).size();j++){

                    if(filelist.at(i).at(j)==searchlist.at(k)+".wav"){
                        if(!listht.contains(filelist.at(i).at(j))){
                            listht.append(filelist.at(i).at(j));
                            ui->olist->addItem(filelist.at(i).at(j));
                            ui->olist->item(ui->olist->count()-1)->setToolTip(paths.at(i));
                        }

                    }
                }
            }
            for(int i=0;i<paths.size();i++){
                for(int j=0;j<filelist.at(i).size();j++){
                    QString slt=filelist.at(i).at(j);
                    slt.remove(".wav",Qt::CaseInsensitive);
                    slt.remove(searchlist.at(k),Qt::CaseSensitive);
                    slt.remove(' ');
                    slt.remove('_');
                    slt.remove('-');
                    if(slt.isEmpty()){
                        if(!listht.contains(filelist.at(i).at(j))){
                            listht.append(filelist.at(i).at(j));
                            ui->olist->addItem(filelist.at(i).at(j));
                            ui->olist->item(ui->olist->count()-1)->setToolTip(paths.at(i));
                        }

                    }
                }
            }
            for(int i=0;i<paths.size();i++){
                for(int j=0;j<filelist.at(i).size();j++){
                    QString slt=filelist.at(i).at(j);
                    slt.remove(".wav",Qt::CaseInsensitive);
                    if(slt.contains(searchlist.at(k),Qt::CaseInsensitive)){
                        if(!listht.contains(filelist.at(i).at(j))){
                            listht.append(filelist.at(i).at(j));
                            ui->olist->addItem(filelist.at(i).at(j));
                            ui->olist->item(ui->olist->count()-1)->setToolTip(paths.at(i));
                        }
                    }
                }
            }
        }
    }

    if(ui->olist->count()==0){
        for(int i=0;i<paths.size();i++){
            for(int j=0;j<filelist.at(i).size();j++){
                ui->olist->addItem(filelist.at(i).at(j));
                ui->olist->item(ui->olist->count()-1)->setToolTip(paths.at(i));
            }
        }
    }

    for(int i=0;i<ui->olist->count();i++){
        ui->olist->item(i)->setSizeHint(QSize(ui->olist->width()*0.9,ui->olist->height()*0.1));
    }
    ui->olist->setCurrentRow(0);
}

void AutoWav::on_olist_itemDoubleClicked(QListWidgetItem *item)
{
    emit wavopen(item->toolTip(),item->text());
    this->hide();
}

void AutoWav::on_name_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        slovelist();
    }else{
        ui->olist->clear();
        for(int i=0;i<paths.size();i++){
            for(int j=0;j<filelist.at(i).size();j++){
                QString slt=filelist.at(i).at(j);
                slt.remove(".wav",Qt::CaseInsensitive);
                if(slt.contains(arg1,Qt::CaseInsensitive)){
                    ui->olist->addItem(filelist.at(i).at(j));
                    ui->olist->item(ui->olist->count()-1)->setToolTip(paths.at(i));
                }
            }
        }
        for(int i=0;i<ui->olist->count();i++){
            ui->olist->item(i)->setSizeHint(QSize(ui->olist->width()*0.9,ui->olist->height()*0.1));
        }
        ui->olist->setCurrentRow(0);
    }
}

void AutoWav::okey()
{
    if(ui->olist->count()>0){
        emit wavopen(ui->olist->currentItem()->toolTip(),ui->olist->currentItem()->text());
    }
    this->hide();
}
