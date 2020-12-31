#include "pixtemp.h"

PixTemp::PixTemp()
{
    //qDebug("%s",qPrintable(QDir::currentPath()));
    QDir dir(QDir::currentPath()+"/temp/");
    if(!dir.exists()){
        dir.mkdir(QDir::currentPath()+"/temp/");
    }
    QFile file(QDir::currentPath()+"/temp/temp.json");
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
    QDir dir(QDir::currentPath()+"/temp/");
    dir.setFilter(QDir::Files);
    int dircount=dir.count();
    for(int i=0;i<dircount;i++){
        dir.remove(dir[i]);
    }
}

bool PixTemp::check(QString name)
{
    QFile file(QDir::currentPath()+"/temp/temp.json");
    file.open(QIODevice::Text|QIODevice::ReadWrite);
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
            for(int i=0;i<global::sets::num;i++){
                QString filename=QDir::currentPath()+"/temp/"+QString::number(flag2)+"-"+QString::number(i)+".png";
                QFile file2(filename);
                if(!file2.exists()){
                    flag3=false;
                }
            }
            if(flag3){
                QFile vtempf(QDir::currentPath()+"/temp/"+QString::number(flag2)+".json");
                if(vtempf.exists()){
                    vtempf.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);

                    QJsonDocument jdv=QJsonDocument::fromJson(vtempf.readAll());
                    vtempf.close();
                    if(jdv.isObject()){
                        QJsonObject jov=jdv.object();
                        QJsonArray ja1=jov["ene"].toArray();
                        QJsonArray ja2=jov["rptz"].toArray();
                        QJsonArray ja3=jov["acf"].toArray();
                        QJsonArray ja4=jov["flag"].toArray();
                        if(ja1.size()==ja2.size()&&ja2.size()==ja3.size()&&ja4.size()==ja3.size()){
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


        }else{
            return false;
        }
    }else{
        return false;
    }
}

void PixTemp::write(QString name,int num,QPixmap datapix)
{
    if(num<global::sets::num){

            QFile file(QDir::currentPath()+"/temp/temp.json");
            file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
                    QString filename=QDir::currentPath()+"/temp/"+QString::number(flag2)+"-"+QString::number(num)+".png";
                    QFile file2(filename);
                    if(file2.exists()){
                        file2.remove();
                    }
                    datapix.save(filename);

                }else{
                    QFile file(QDir::currentPath()+"/temp/temp.json");
                    file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
                        file.open(QIODevice::ReadWrite|QIODevice::Text);
                        file.write(jd.toJson(QJsonDocument::Indented));
                        file.close();

                        QString filename=QDir::currentPath()+"/temp/"+QString::number(count)+"-"+QString::number(num)+".png";
                        QFile file2(filename);
                        if(file2.exists()){
                            file2.remove();
                        }
                        datapix.save(filename);


                     }
                }
        }



    }
}

QPixmap PixTemp::read(QString name,int num)
{
    QPixmap out;
    if(check(name)&&num<global::sets::num){
        QFile file(QDir::currentPath()+"/temp/temp.json");
        file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
                QString filename=QDir::currentPath()+"/temp/"+QString::number(flag2)+"-"+QString::number(num)+".png";
                QFile file2(filename);
                if(file2.exists()){
                    out.load(filename);
                }

            }
        }
    }
    return out;
}

void PixTemp::clear()
{
    QFile file(QDir::currentPath()+"/temp/temp.json");
    QDir dir(QDir::currentPath()+"/temp/");
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
        QFile file(QDir::currentPath()+"/temp/temp.json");
        file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
                QString filename=QDir::currentPath()+"/temp/"+QString::number(flag2)+".json";
                QFile vtempf(filename);
                if(vtempf.exists()){
                    vtempf.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);

                    QJsonDocument jdv=QJsonDocument::fromJson(vtempf.readAll());
                    vtempf.close();
                    if(jdv.isObject()){
                        QJsonObject jov=jdv.object();
                        QJsonArray ja=jov[vname].toArray();
                        for(int i=0;i<ja.size();i++){
                            out.append(ja.at(i).toDouble());
                        }
                    }

                }


            }
        }
    }
    return out;
}

void PixTemp::writev(QString name,QString vname,QVector<double> datav)
{
    QFile file(QDir::currentPath()+"/temp/temp.json");
    file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
            QString filename=QDir::currentPath()+"/temp/"+QString::number(flag2)+".json";
            QFile vtempf(filename);
            vtempf.open(QIODevice::Text|QIODevice::ReadWrite);

            QJsonDocument jdv=QJsonDocument::fromJson(vtempf.readAll());
            vtempf.close();
            QJsonObject jov=jdv.object();
            QJsonArray ja;
            for(int i=0;i<datav.size();i++){
                ja.append(datav.at(i));
            }
            jov.insert(vname,ja);
            jdv.setObject(jov);

            if(vtempf.exists()){
                vtempf.remove();
            }

            vtempf.open(QIODevice::Text|QIODevice::ReadWrite);
            vtempf.write(jdv.toJson(QJsonDocument::Indented));
            vtempf.close();



        }else{
            QFile file(QDir::currentPath()+"/temp/temp.json");
            file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
                file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
                file.write(jd.toJson(QJsonDocument::Indented));
                file.close();

                QJsonDocument jdv;

                QJsonObject jov;
                QJsonArray jav;
                for(int i=0;i<datav.size();i++){
                    jav.append(datav.at(i));
                }
                jov.insert(vname,jav);
                jdv.setObject(jov);

                QString filename=QDir::currentPath()+"/temp/"+QString::number(flag2)+".json";
                QFile vtempf(filename);

                if(vtempf.exists()){
                    vtempf.remove();
                }

                vtempf.open(QIODevice::Text|QIODevice::ReadWrite);
                vtempf.write(jdv.toJson(QJsonDocument::Indented));
                vtempf.close();


             }
        }
    }


}

QVector<bool> PixTemp::readb(QString name,QString vname)
{
    QVector<bool> out;
    if(check(name)){
        QFile file(QDir::currentPath()+"/temp/temp.json");
        file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
                QString filename=QDir::currentPath()+"/temp/"+QString::number(flag2)+".json";
                QFile vtempf(filename);
                if(vtempf.exists()){
                    vtempf.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);

                    QJsonDocument jdv=QJsonDocument::fromJson(vtempf.readAll());
                    vtempf.close();
                    if(jdv.isObject()){
                        QJsonObject jov=jdv.object();
                        QJsonArray ja=jov[vname].toArray();
                        for(int i=0;i<ja.size();i++){
                            out.append(ja.at(i).toBool());
                        }
                    }

                }


            }
        }
    }
    return out;
}

void PixTemp::writeb(QString name,QString vname,QVector<bool> datav)
{
    QFile file(QDir::currentPath()+"/temp/temp.json");
    file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
            QString filename=QDir::currentPath()+"/temp/"+QString::number(flag2)+".json";
            QFile vtempf(filename);
            vtempf.open(QIODevice::Text|QIODevice::ReadWrite);

            QJsonDocument jdv=QJsonDocument::fromJson(vtempf.readAll());
            vtempf.close();
            QJsonObject jov=jdv.object();
            QJsonArray ja;
            for(int i=0;i<datav.size();i++){
                ja.append(datav.at(i));
            }
            jov.remove(vname);
            jov.insert(vname,ja);
            jdv.setObject(jov);

            if(vtempf.exists()){
                vtempf.remove();
            }

            vtempf.open(QIODevice::Text|QIODevice::ReadWrite);
            vtempf.write(jdv.toJson(QJsonDocument::Indented));
            vtempf.close();



        }else{
            QFile file(QDir::currentPath()+"/temp/temp.json");
            file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
                file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
                file.write(jd.toJson(QJsonDocument::Indented));
                file.close();

                QJsonDocument jdv;

                QJsonObject jov;
                QJsonArray jav;
                for(int i=0;i<datav.size();i++){
                    jav.append(datav.at(i));
                }
                jov.insert(vname,jav);
                jdv.setObject(jov);

                QString filename=QDir::currentPath()+"/temp/"+QString::number(flag2)+".json";
                QFile vtempf(filename);

                if(vtempf.exists()){
                    vtempf.remove();
                }

                vtempf.open(QIODevice::Text|QIODevice::ReadWrite);
                vtempf.write(jdv.toJson(QJsonDocument::Indented));
                vtempf.close();


             }
        }
    }


}

bool PixTemp::checkmd5(QString name)
{
    if(this->check(name)){
        QFile file(QDir::currentPath()+"/temp/temp.json");
        file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
        QFile file(QDir::currentPath()+"/temp/temp.json");
        file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
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
                file.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Text);
                file.write(jd.toJson(QJsonDocument::Indented));
                file.close();


            }
        }
    }
}
