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
    repaint();
    ui->name->resize(6.5*height()*0.04,0.8*height()*0.04);
    ui->olist->resize(6.5*height()*0.04,10*0.04*height());

    ui->name->move(0.2*width()+8.25*0.04*height(),0.1*height()*0.04);
    ui->olist->move(0.2*width()+8.25*0.04*height(),0.04*height());

    QFont font;
    font.setPixelSize(ui->olist->height()*0.05);
    for(int i=0;i<ui->olist->count();i++){
        ui->olist->item(i)->setSizeHint(QSize(ui->olist->width()*0.9,ui->olist->height()*0.1));
        ui->olist->item(i)->setFont(font);
    }

    QWidget::resizeEvent(event);
}

void AutoWav::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0.2*width()+8.25*0.04*height()-1,0.1*height()*0.04,6.5*height()*0.04+1,0.8*height()*0.04+1,QColor(0,0,0));
    QWidget::paintEvent(event);
}

void AutoWav::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->pos().x()>=0.2*width()+8.25*0.04*height()&&event->pos().x()<=0.2*width()+8.25*0.04*height()+6.5*height()*0.04&&event->pos().y()>=0.04*height()&&event->pos().y()<=0.04*height()+10*0.04*height())){
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
    QFont font;
    font.setPixelSize(ui->olist->height()*0.05);
    for(int i=0;i<ui->olist->count();i++){
        ui->olist->item(i)->setFont(font);
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
        QFont font;
        font.setPixelSize(ui->olist->height()*0.05);
        for(int i=0;i<ui->olist->count();i++){
            ui->olist->item(i)->setFont(font);
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

void AutoWav::setwavnow(QString wavname)
{
    ui->name->setText(wavname);
}
