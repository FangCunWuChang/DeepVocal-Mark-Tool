#include "pixtemp.h"

PixTemp::PixTemp()
{
    //qDebug("%s",qPrintable(QCoreApplication::applicationDirPath()));
    QDir dir(QCoreApplication::applicationDirPath()+"/temp/");
    if(!dir.exists()){
        dir.mkdir(QCoreApplication::applicationDirPath()+"/temp/");
    }
    QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
    if(file.exists()){
        file.remove();
    }
    QJsonObject jo;
    QJsonArray ja;
    jo.insert("data",ja);
    QJsonDocument jd(jo);
    QString data=jd.toJson(QJsonDocument::Indented);
    file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
    file.write(data.toUtf8());
    file.close();
}

PixTemp::~PixTemp()
{
    QDir dir(QCoreApplication::applicationDirPath()+"/temp/");
    dir.setFilter(QDir::Files);
    int dircount=dir.count();
    for(int i=0;i<dircount;i++){
        dir.remove(dir[i]);
    }
}

bool PixTemp::check(QString name)
{
    QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
    if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
      qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
    }else{
      qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
    }

    QString data=file.readAll();
    file.close();
    QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
    if(jd.isObject()){
        QJsonObject jo=jd.object();
        QJsonArray ja=jo["data"].toArray();
        bool flag1=false;
        int flag2=0;
        for(int i=0;i<ja.size();i++){
            QJsonObject jot=ja.at(i).toObject();
            if(jot["name"].toString()==name){
                flag1=true;
                flag2=jot["id"].toInt();
                break;
            }
        }
        if(flag1){
            bool flag3=true;
            for(int i=0;i<global_sets::num;i++){
                QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"-"+QString::number(i)+".dvmttemp";
                QFile file2(filename);
                if(!file2.exists()){
                    flag3=false;
                }
            }
            if(flag3){
                QFile vtempfe(QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_ene.dvmttemp");
                QFile vtempfr(QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_rptz.dvmttemp");
                QFile vtempfa(QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_acf.dvmttemp");
                QFile vtempff(QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_flag.dvmttemp");
                if(vtempfe.exists()&&vtempfr.exists()&&vtempfa.exists()&&vtempff.exists()){

                    return true;




                }else{
                    return false;
                }
            }else{
                return false;
            }


        }else{
            return false;
        }
    }else{
        return false;
    }
}

void PixTemp::write(QString name,int num,QVector<double> datapix)
{
    if(num<global_sets::num){

            QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");

            if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
              qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
            }else{
              qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
            }
            QString data=file.readAll();
            file.close();
            QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
            if(jd.isObject()){
                QJsonObject jo=jd.object();
                QJsonArray ja=jo["data"].toArray();
                bool flag1=false;
                int flag2=0;
                for(int i=0;i<ja.size();i++){
                    QJsonObject jot=ja.at(i).toObject();
                    if(jot["name"].toString()==name){
                        flag1=true;
                        flag2=jot["id"].toInt();
                        break;
                    }
                }
                if(flag1){
                    QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"-"+QString::number(num)+".dvmttemp";
                    QFile file2(filename);
                    if(file2.exists()){
                        file2.remove();
                    }
                    if(!WQV(&datapix,filename)){
                      qDebug("无法缓存：%s",qPrintable(filename));
                    }else{
                      qDebug("已缓存：%s",qPrintable(filename));
                    }


                }else{
                    QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
                    if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
                      qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                    }else{
                      qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                    }
                    QString data=file.readAll();
                    file.close();
                    QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
                    if(jd.isObject()){
                        QJsonObject jo=jd.object();
                        QJsonArray ja=jo["data"].toArray();
                        QJsonObject jot;
                        jot.insert("name",name);
                        int count=countid++;
                        jot.insert("id",count);
                        ja.append(jot);
                        jo.remove("data");
                        jo.insert("data",ja);
                        jd.setObject(jo);



                        if(file.exists()){
                            file.remove();
                        }
                        if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
                          qDebug("写入时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                        }else{
                          qDebug("写入缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                        }
                        file.write(jd.toJson(QJsonDocument::Indented));
                        file.close();

                        QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(count)+"-"+QString::number(num)+".dvmttemp";
                        QFile file2(filename);
                        if(file2.exists()){
                            file2.remove();
                        }
                        if(!WQV(&datapix,filename)){
                          qDebug("无法缓存：%s",qPrintable(filename));
                        }else{
                          qDebug("已缓存：%s",qPrintable(filename));
                        }


                     }
                }
        }



    }
}

QVector<double> PixTemp::read(QString name,int num)
{
    //qDebug("read1");
    QVector<double> out;
    if(check(name)&&num<global_sets::num){
        QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
        if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
          qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }else{
          qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }
        QString data=file.readAll();
        file.close();
        //qDebug("read2");
        QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
        if(jd.isObject()){
            QJsonObject jo=jd.object();
            QJsonArray ja=jo["data"].toArray();
            bool flag1=false;
            int flag2=0;
            for(int i=0;i<ja.size();i++){
                QJsonObject jot=ja.at(i).toObject();
                if(jot["name"].toString()==name){
                    flag1=true;
                    flag2=jot["id"].toInt();
                    break;
                }
            }
            //qDebug("read3");
            if(flag1){
                QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"-"+QString::number(num)+".dvmttemp";
                QFile file2(filename);
                //qDebug("read3.1");
                if(file2.exists()){
                    if(!RQV(&out,filename)){
                      qDebug("无法读取缓存：%s",qPrintable(filename));
                    }else{
                      qDebug("已读取缓存：%s",qPrintable(filename));
                    }
                    //qDebug("read3.2");

                }

            }
            //qDebug("read4");
        }
    }
    return out;//qDebug("read1");
}

void PixTemp::write2(QString name,int num,QVector<QVector<double>> datapix)
{
    if(num<global_sets::num){

            QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");

            if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
              qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
            }else{
              qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
            }
            QString data=file.readAll();
            file.close();
            QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
            if(jd.isObject()){
                QJsonObject jo=jd.object();
                QJsonArray ja=jo["data"].toArray();
                bool flag1=false;
                int flag2=0;
                for(int i=0;i<ja.size();i++){
                    QJsonObject jot=ja.at(i).toObject();
                    if(jot["name"].toString()==name){
                        flag1=true;
                        flag2=jot["id"].toInt();
                        break;
                    }
                }
                if(flag1){
                    QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"-"+QString::number(num)+".dvmttemp";
                    QFile file2(filename);
                    if(file2.exists()){
                        file2.remove();
                    }
                    if(!WQV2(&datapix,filename)){
                      qDebug("无法缓存：%s",qPrintable(filename));
                    }else{
                      qDebug("已缓存：%s",qPrintable(filename));
                    }


                }else{
                    QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
                    if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
                      qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                    }else{
                      qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                    }
                    QString data=file.readAll();
                    file.close();
                    QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
                    if(jd.isObject()){
                        QJsonObject jo=jd.object();
                        QJsonArray ja=jo["data"].toArray();
                        QJsonObject jot;
                        jot.insert("name",name);
                        int count=countid++;
                        jot.insert("id",count);
                        ja.append(jot);
                        jo.remove("data");
                        jo.insert("data",ja);
                        jd.setObject(jo);



                        if(file.exists()){
                            file.remove();
                        }
                        if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
                          qDebug("写入时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                        }else{
                          qDebug("写入缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                        }
                        file.write(jd.toJson(QJsonDocument::Indented));
                        file.close();

                        QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(count)+"-"+QString::number(num)+".dvmttemp";
                        QFile file2(filename);
                        if(file2.exists()){
                            file2.remove();
                        }
                        if(!WQV2(&datapix,filename)){
                          qDebug("无法缓存：%s",qPrintable(filename));
                        }else{
                          qDebug("已缓存：%s",qPrintable(filename));
                        }


                     }
                }
        }



    }
}

QVector<QVector<double>> PixTemp::read2(QString name,int num)
{
    //qDebug("readii1");
    QVector<QVector<double>> out;
    //qDebug("readii2");
    if(check(name)&&num<global_sets::num){
        QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
        if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
          qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }else{
          qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }
        QString data=file.readAll();
        file.close();
        //qDebug("readii3");
        QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
        if(jd.isObject()){
            QJsonObject jo=jd.object();
            QJsonArray ja=jo["data"].toArray();
            bool flag1=false;
            int flag2=0;
            for(int i=0;i<ja.size();i++){
                QJsonObject jot=ja.at(i).toObject();
                if(jot["name"].toString()==name){
                    flag1=true;
                    flag2=jot["id"].toInt();
                    break;
                }
            }
            //qDebug("readii4");
            if(flag1){
                QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"-"+QString::number(num)+".dvmttemp";
                QFile file2(filename);
                if(file2.exists()){
                    if(!RQV2(&out,filename)){
                      qDebug("无法读取缓存：%s",qPrintable(filename));
                    }else{
                      qDebug("已读取缓存：%s",qPrintable(filename));
                    }

                }

            }
            //qDebug("readii5");
        }
    }
    return out;
}

void PixTemp::clear()
{
    QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
    QDir dir(QCoreApplication::applicationDirPath()+"/temp/");
    dir.setFilter(QDir::Files);
    int dircount=dir.count();
    for(int i=0;i<dircount;i++){
        dir.remove(dir[i]);
    }
    QJsonObject jo;
    QJsonArray ja;
    jo.insert("data",ja);
    QJsonDocument jd(jo);
    QString data=jd.toJson(QJsonDocument::Indented);
    file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
    file.write(data.toUtf8());
    file.close();
    this->countid=0;
}

QVector<double> PixTemp::readv(QString name,QString vname)
{
    QVector<double> out;
    if(check(name)){
        QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
        if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
          qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }else{
          qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }
        QString data=file.readAll();
        file.close();
        QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
        if(jd.isObject()){
            QJsonObject jo=jd.object();
            QJsonArray ja=jo["data"].toArray();
            bool flag1=false;
            int flag2=0;
            for(int i=0;i<ja.size();i++){
                QJsonObject jot=ja.at(i).toObject();
                if(jot["name"].toString()==name){
                    flag1=true;
                    flag2=jot["id"].toInt();
                    break;
                }
            }
            if(flag1){
                QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_"+vname+".dvmttemp";
                if(!RQV(&out,filename)){
                  qDebug("无法打开参数缓存：%s",qPrintable(filename));
                }else{
                  qDebug("打开参数缓存：%s",qPrintable(filename));
                }



            }
        }
    }
    return out;
}

void PixTemp::writev(QString name,QString vname,QVector<double> datav)
{
    QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
    if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
      qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
    }else{
      qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
    }
    QString data=file.readAll();
    file.close();
    QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
    if(jd.isObject()){
        QJsonObject jo=jd.object();
        QJsonArray ja=jo["data"].toArray();
        bool flag1=false;
        int flag2=0;
        for(int i=0;i<ja.size();i++){
            QJsonObject jot=ja.at(i).toObject();
            if(jot["name"].toString()==name){
                flag1=true;
                flag2=jot["id"].toInt();
                break;
            }
        }
        if(flag1){
            QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_"+vname+".dvmttemp";
            if(!WQV(&datav,filename)){
              qDebug("无法写入参数缓存：%s",qPrintable(filename));
            }else{
              qDebug("写入参数缓存：%s",qPrintable(filename));
            }



        }else{
            QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
            if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
              qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
            }else{
              qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
            }
            QString data=file.readAll();
            file.close();
            QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
            if(jd.isObject()){
                QJsonObject jo=jd.object();
                QJsonArray ja=jo["data"].toArray();
                QJsonObject jot;
                jot.insert("name",name);
                int count=countid++;
                jot.insert("id",count);
                ja.append(jot);
                jo.remove("data");
                jo.insert("data",ja);
                jd.setObject(jo);



                if(file.exists()){
                    file.remove();
                }
                if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
                  qDebug("写入时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                }else{
                  qDebug("写入缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                }
                file.write(jd.toJson(QJsonDocument::Indented));
                file.close();



                QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_"+vname+".dvmttemp";
                if(!WQV(&datav,filename)){
                  qDebug("无法写入参数缓存：%s",qPrintable(filename));
                }else{
                  qDebug("写入参数缓存：%s",qPrintable(filename));
                }


             }
        }
    }


}

QVector<bool> PixTemp::readb(QString name,QString vname)
{
    QVector<bool> out;
    if(check(name)){
        QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
        if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
          qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }else{
          qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }
        QString data=file.readAll();
        file.close();
        QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
        if(jd.isObject()){
            QJsonObject jo=jd.object();
            QJsonArray ja=jo["data"].toArray();
            bool flag1=false;
            int flag2=0;
            for(int i=0;i<ja.size();i++){
                QJsonObject jot=ja.at(i).toObject();
                if(jot["name"].toString()==name){
                    flag1=true;
                    flag2=jot["id"].toInt();
                    break;
                }
            }
            if(flag1){
                QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_"+vname+".dvmttemp";
                if(!RQB(&out,filename)){
                  qDebug("无法读取参数缓存：%s",qPrintable(filename));
                }else{
                  qDebug("读取参数缓存：%s",qPrintable(filename));
                }


            }
        }
    }
    return out;
}

void PixTemp::writeb(QString name,QString vname,QVector<bool> datav)
{
    QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
    if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
      qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
    }else{
      qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
    }
    QString data=file.readAll();
    file.close();
    QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
    if(jd.isObject()){
        QJsonObject jo=jd.object();
        QJsonArray ja=jo["data"].toArray();
        bool flag1=false;
        int flag2=0;
        for(int i=0;i<ja.size();i++){
            QJsonObject jot=ja.at(i).toObject();
            if(jot["name"].toString()==name){
                flag1=true;
                flag2=jot["id"].toInt();
                break;
            }
        }
        if(flag1){
            QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_"+vname+".dvmttemp";
            if(!WQB(&datav,filename)){
              qDebug("无法写入参数缓存：%s",qPrintable(filename));
            }else{
              qDebug("写入参数缓存：%s",qPrintable(filename));
            }




        }else{
            QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
            if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
              qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
            }else{
              qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
            }
            QString data=file.readAll();
            file.close();
            QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
            if(jd.isObject()){
                QJsonObject jo=jd.object();
                QJsonArray ja=jo["data"].toArray();
                QJsonObject jot;
                jot.insert("name",name);
                int count=countid++;
                jot.insert("id",count);
                ja.append(jot);
                jo.remove("data");
                jo.insert("data",ja);
                jd.setObject(jo);



                if(file.exists()){
                    file.remove();
                }
                if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
                  qDebug("写入时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                }else{
                  qDebug("写入缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                }
                file.write(jd.toJson(QJsonDocument::Indented));
                file.close();



                QString filename=QCoreApplication::applicationDirPath()+"/temp/"+QString::number(flag2)+"_"+vname+".dvmttemp";


                if(!WQB(&datav,filename)){
                  qDebug("无法写入参数缓存：%s",qPrintable(filename));
                }else{
                  qDebug("写入参数缓存：%s",qPrintable(filename));
                }



             }
        }
    }


}

bool PixTemp::checkmd5(QString name)
{
    if(this->check(name)){
        QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
        if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
          qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }else{
          qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }
        QString data=file.readAll();
        file.close();
        QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
        if(jd.isObject()){
            QJsonObject jo=jd.object();
            QJsonArray ja=jo["data"].toArray();
            bool flag1=false;

            QJsonObject jottemp;
            for(int i=0;i<ja.size();i++){
                QJsonObject jot=ja.at(i).toObject();
                if(jot["name"].toString()==name){
                    flag1=true;

                    jottemp=jot;
                    break;
                }
            }
            if(flag1){
                QString md5t=jottemp["md5"].toString();
                QFile wavefile(name);
                wavefile.open(QIODevice::ReadOnly|QIODevice::Text);
                QString md5n(QCryptographicHash::hash(wavefile.readAll(),QCryptographicHash::Md5));
                wavefile.close();
                if(md5t==md5n){
                    return true;
                }else{
                    return false;
                }

            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void PixTemp::savemd5(QString name)
{
    if(this->check(name)){
        QFile file(QCoreApplication::applicationDirPath()+"/temp/temp.json");
        if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
          qDebug("读取时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }else{
          qDebug("读取缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
        }
        QString data=file.readAll();
        file.close();
        QJsonDocument jd=QJsonDocument::fromJson(data.toUtf8());
        if(jd.isObject()){
            QJsonObject jo=jd.object();
            QJsonArray ja=jo["data"].toArray();
            bool flag1=false;
            int flag2=0;

            for(int i=0;i<ja.size();i++){
                QJsonObject jot=ja.at(i).toObject();
                if(jot["name"].toString()==name){
                    flag1=true;
                    flag2=i;
                    break;
                }
            }
            if(flag1){

                QFile wavefile(name);
                wavefile.open(QIODevice::ReadOnly|QIODevice::Text);
                QString md5n(QCryptographicHash::hash(wavefile.readAll(),QCryptographicHash::Md5));
                wavefile.close();


                QJsonObject jomt=ja.at(flag2).toObject();
                ja.removeAt(flag2);

                jomt.remove("md5");
                jomt.insert("md5",md5n);

                ja.append(jomt);

                jo.remove("data");
                jo.insert("data",ja);

                jd.setObject(jo);



                if(file.exists()){
                    file.remove();
                }
                if(!file.open(QIODevice::Text|QIODevice::ReadWrite)){
                  qDebug("写入时无法打开缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                }else{
                  qDebug("写入缓存列表：%s",qPrintable(QCoreApplication::applicationDirPath()+"/temp/temp.json"));
                }
                file.write(jd.toJson(QJsonDocument::Indented));
                file.close();


            }
        }
    }
}

bool PixTemp::WQV(QVector<double> *data,QString filename)
{
    bool out=true;
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QDataStream stream(&file);
#if Q_BYTE_ORDER==Q_LITTLE_ENDIAN
        stream.setByteOrder(QDataStream::LittleEndian);
#else
        stream.setByteOrder(QDataStream::BigEndian);
#endif
        int size=data->size();
        out=stream.writeRawData((char*)&size,sizeof (int))>-1;
        for(int i=0;i<data->size();i++){
            double temp=data->at(i);
            out=(stream.writeRawData((char*)&temp,sizeof (double))>-1)&&out;
        }

        file.close();
    }else{
        out=false;
    }
    return out;
}

bool PixTemp::RQV(QVector<double> *data,QString filename)
{
    //qDebug("rv1");
    bool out=true;
    QFile file(filename);
    //qDebug("rv2");
    if(file.open(QIODevice::ReadOnly)){
        QDataStream stream(&file);
#if Q_BYTE_ORDER==Q_LITTLE_ENDIAN
        stream.setByteOrder(QDataStream::LittleEndian);
#else
        stream.setByteOrder(QDataStream::BigEndian);
#endif
        //qDebug("rv3");
        int size=0;
        out=stream.readRawData((char*)&size,sizeof (int))>-1;
        //qDebug("rv4");
        //out=(size==(int)((file.size()-sizeof (int))/sizeof (double)))&&out;

        data->clear();

        //qDebug("rv5");
        for(int i=0;i<size;i++){
            double temp;
            out=(stream.readRawData((char*)&temp,sizeof (double))>-1)&&out;
            data->append(temp);
        }

        //qDebug("rv6");

        //qDebug("rv7");
        file.close();
    }else{
        out=false;
    }
    return out;
}

bool PixTemp::WQV2(QVector<QVector<double>> *data,QString filename)
{
    bool out=true;
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QDataStream stream(&file);
#if Q_BYTE_ORDER==Q_LITTLE_ENDIAN
        stream.setByteOrder(QDataStream::LittleEndian);
#else
        stream.setByteOrder(QDataStream::BigEndian);
#endif
        int msize=data->size();
        out=stream.writeRawData((char*)&msize,sizeof (int))>-1;
        for(int i=0;i<data->size();i++){


            for(int j=0;j<global_sets::step/2;j++){
                double temp=data->at(i).at(j);
                out=(stream.writeRawData((char*)&temp,sizeof (double))>-1)&&out;
            }

        }

        file.close();
    }else{
        out=false;
    }
    return out;
}

bool PixTemp::RQV2(QVector<QVector<double>> *data,QString filename)
{
    //qDebug("rvii1");
    bool out=true;
    QFile file(filename);
    //qDebug("rvii2");
    if(file.open(QIODevice::ReadOnly)){
        QDataStream stream(&file);
#if Q_BYTE_ORDER==Q_LITTLE_ENDIAN
        stream.setByteOrder(QDataStream::LittleEndian);
#else
        stream.setByteOrder(QDataStream::BigEndian);
#endif
        int msize=0;
        out=stream.readRawData((char*)&msize,sizeof (int))>-1;
        //qDebug("rvii3");
        data->clear();
        for(int i=0;i<msize;i++){

            QVector<double> datat;
            for(int j=0;j<global_sets::step/2;j++){
                double temp;
                out=(stream.readRawData((char*)&temp,sizeof (double))>-1)&&out;
                datat.append(temp);
            }


            //qDebug("rvii5[%d/%d]",i,msize);

            data->append(datat);
        }
        //qDebug("rvii6");

        file.close();
    }else{
        out=false;
    }
    return out;
}

bool PixTemp::WQB(QVector<bool> *data,QString filename)
{
    bool out=true;
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QDataStream stream(&file);
#if Q_BYTE_ORDER==Q_LITTLE_ENDIAN
        stream.setByteOrder(QDataStream::LittleEndian);
#else
        stream.setByteOrder(QDataStream::BigEndian);
#endif
        int size=data->size();
        out=stream.writeRawData((char*)&size,sizeof (int))>-1;
        for(int i=0;i<data->size();i++){
            bool temp=data->at(i);
            out=(stream.writeRawData((char*)&temp,sizeof (bool))>-1)&&out;
        }

        file.close();
    }else{
        out=false;
    }
    return out;
}

bool PixTemp::RQB(QVector<bool> *data,QString filename)
{
    bool out=true;
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)){
        QDataStream stream(&file);
#if Q_BYTE_ORDER==Q_LITTLE_ENDIAN
        stream.setByteOrder(QDataStream::LittleEndian);
#else
        stream.setByteOrder(QDataStream::BigEndian);
#endif
        int size=0;
        out=stream.readRawData((char*)&size,sizeof (int))>-1;
        //out=(size==static_cast<int>((file.size()-sizeof (int))/sizeof (bool)))&&out;

        data->clear();
        for(int i=0;i<size;i++){
            bool temp;
            out=(stream.readRawData((char*)&temp,sizeof (bool))>-1)&&out;
            data->append(temp);
        }
        file.close();
    }else{
        out=false;
    }
    return out;
}
