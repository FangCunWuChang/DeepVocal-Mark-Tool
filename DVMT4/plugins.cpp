#include "plugins.h"
#include "ui_plugins.h"

Plugins::Plugins(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Plugins)
{
    ui->setupUi(this);
}

Plugins::~Plugins()
{
    delete ui;
}

void Plugins::setPro(Project *pro)
{
    this->pro=pro;
}

void Plugins::checkplugins()
{
    qDebug("1");
    pluginurllist.clear();
    pluginlist.clear();
    plugininfolist.clear();
    qDebug("2");
    QDir pludir(QCoreApplication::applicationDirPath()+"/DVMT_plugins/");
    if(!pludir.exists()){
        pludir.mkdir(QCoreApplication::applicationDirPath()+"/DVMT_plugins/");
#ifdef Q_OS_WIN
        //QFile::copy(":/plugins/pluginsample1.dll",QCoreApplication::applicationDirPath()+"/DVMT_plugins/pluginsample1.dll");
        //QFile::copy(":/plugins/pluginsample2.dll",QCoreApplication::applicationDirPath()+"/DVMT_plugins/pluginsample2.dll");
#endif
#ifdef Q_OS_LINUX
#endif
#ifdef Q_OS_MAC
#endif
    }
    qDebug("3");
    pludir.setFilter(QDir::Files);
    QStringList dlllist;
    for(uint i=0;i<pludir.count();i++){
        QString filent=pludir[i];
#ifdef Q_OS_WIN
        if(filent.endsWith(".dll",Qt::CaseInsensitive)){
            dlllist.append(QCoreApplication::applicationDirPath()+"/DVMT_plugins/"+filent);
        }
#endif
#ifdef Q_OS_LINUX
        if(filent.endsWith(".so",Qt::CaseInsensitive)){
            dlllist.append(QCoreApplication::applicationDirPath()+"/DVMT_plugins/"+filent);
        }
#endif
#ifdef Q_OS_MAC
        if(filent.endsWith(".dylib",Qt::CaseInsensitive)){
            dlllist.append(QCoreApplication::applicationDirPath()+"/DVMT_plugins/"+filent);
        }
#endif
    }
    qDebug("4");
    for(int i=0;i<dlllist.size();i++){
        qDebug("5");
        qDebug("file:%s",qPrintable(dlllist.at(i)));
        QLibrary *lib=new QLibrary(dlllist.at(i));
        qDebug("6");
        if(lib->load()){
            qDebug("7");
            pluiF iF=(pluiF)lib->resolve("DVMT_PluInfo2");
            pluoF oF=(pluoF)lib->resolve("DVMT_PluRun2");
            qDebug("8");
            if(iF!=nullptr&&oF!=nullptr){
                qDebug("9");
                QString* Infoj=iF();
                qDebug("10");
                QJsonDocument Infojd=QJsonDocument::fromJson(Infoj->toUtf8());
                qDebug("11");
                qDebug("data:%s",qPrintable(*Infoj));
                delete Infoj;
                if(Infojd.isObject()){
                    qDebug("12");
                    QString PNT=Infojd["Plugin Name"].toString();
                    QString PIT=Infojd["Plugin Info"].toString();
                    double PVT=Infojd["Plugin Version"].toDouble();
                    qDebug("13");
                    if((!(PNT.isEmpty()||PIT.isEmpty()))&&PVT<=DVMT_VERSION&&Infojd.object().contains("Plugin Version")){
                        qDebug("14");
                        pluginurllist.append(dlllist.at(i));
                        pluginlist.append(PNT);
                        plugininfolist.append(PIT);
                        qDebug("15");
                    }
                    qDebug("15.1");
                }
                qDebug("15.2");
            }
            qDebug("16");
            if(!lib->unload()){
                qDebug("UnUnload");
            }
            delete lib;
            qDebug("17");
        }
    }
    qDebug("18");

    ui->plul->clear();
    ui->about->clear();
    qDebug("19");
    for(int i=0;i<pluginlist.size();i++){
        ui->plul->addItem(pluginlist.at(i));
    }
    qDebug("20");
    if(ui->plul->count()==0){
        ui->okb->setEnabled(false);
    }else{
        ui->plul->setCurrentIndex(0);
        ui->okb->setEnabled(true);
    }
    qDebug("21");
}

void Plugins::openplugin(int id)
{
    QLibrary* lib=new QLibrary(pluginurllist.at(id));
    if(lib->load()){
        pluiF iF=(pluiF)lib->resolve("DVMT_PluInfo2");
        pluoF oF=(pluoF)lib->resolve("DVMT_PluRun2");
        if(iF!=nullptr&&oF!=nullptr){

            QString* Infoj=iF();
            QJsonDocument Infojd=QJsonDocument::fromJson(Infoj->toUtf8());
            delete Infoj;
            if(Infojd.isObject()){
                QString PNT=Infojd["Plugin Name"].toString();
                QString PIT=Infojd["Plugin Info"].toString();
                if(pluginlist.at(id)==PNT&&plugininfolist.at(id)==PIT){
                    Project pro=*(this->pro);
                    PluginDialog *pludia=oF((QWidget*)this,&pro);
                    pludia->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowCloseButtonHint);
                    pludia->exec();
                    delete pludia;
                    emit prochanged(pro);
                }else{
                    QMessageBox::warning(this,"插件调用","插件未能成功载入，插件信息校验失败！");
                }
            }else{
                QMessageBox::warning(this,"插件调用","插件未能成功载入，未能读取插件信息！");
            }
        }else{
            QMessageBox::warning(this,"插件调用","插件未能成功载入，未找到插件调用入口！");
        }
        lib->unload();
    }else{
        QMessageBox::warning(this,"插件调用","插件未能成功载入，疑似损坏！");
    }
}

void Plugins::on_plul_currentIndexChanged(int index)
{
    ui->about->clear();
    if(index>=0&&index<plugininfolist.size()){
        ui->about->setPlainText(plugininfolist.at(index));
    }
}

void Plugins::on_okb_clicked()
{
    int index=ui->plul->currentIndex();
    if(index>=0&&index<pluginlist.size()){
        this->close();
        openplugin(index);
    }
}
