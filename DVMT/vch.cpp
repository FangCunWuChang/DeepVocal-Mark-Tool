#include "vch.h"

VCH::VCH()
{

}

bool VCH::get(CVVCSymbol *symbol)
{
    QFile cfile(symbol->path+"/voice.dvcfg");
    if(cfile.exists()){
        if(cfile.open(QIODevice::ReadOnly|QIODevice::Text)){
            QJsonDocument jd=QJsonDocument::fromJson(cfile.readAll());
            cfile.close();
            if(jd.isObject()){
                QJsonObject jo=jd.object();
                QJsonObject jos=jo[symbol->pitch+"->"+symbol->name].toObject();
                if(symbol->isCV>0){
                    if(jos["srcType"].toString()=="CV"&&jos["pitch"].toString()==symbol->pitch&&jos["symbol"].toString()==symbol->name){
                        QWaveInfo wave;
                        if(wave.ReadFile(symbol->path+"/"+jos["wavName"].toString())){
                            symbol->file=jos["wavName"].toString();
                            int wavesize=wave.datalength;
                            int FS=wave.samplespersec;
                            double CP=jos["startTime"].toDouble()+0.06;
                            double PP=jos["preutterance"].toDouble()+CP-0.06;
                            double VSP=jos["vowelStart"].toDouble()+CP-0.06;
                            double VEP=jos["vowelEnd"].toDouble()+CP-0.06;
                            symbol->l1=(CP*FS)/wavesize;
                            symbol->l2=(PP*FS)/wavesize;
                            symbol->l3=(VSP*FS)/wavesize;
                            symbol->l4=(VEP*FS)/wavesize;
                            return true;
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else if(symbol->isCV==0){
                    if(jos["srcType"].toString()=="VX"&&jos["pitch"].toString()==symbol->pitch&&jos["symbol"].toString()==symbol->name){
                        QWaveInfo wave;
                        if(wave.ReadFile(symbol->path+"/"+jos["wavName"].toString())){
                            symbol->file=jos["wavName"].toString();
                            int wavesize=wave.datalength;
                            int FS=wave.samplespersec;
                            double SP=jos["startTime"].toDouble()+0.06;
                            double EP=jos["endTime"].toDouble();

                            symbol->l1=(SP*FS)/wavesize;
                            symbol->l2=(EP*FS)/wavesize;
                            return true;
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else{
                    if(jos["srcType"].toString()=="INDIE"&&jos["pitch"].toString()==symbol->pitch&&jos["symbol"].toString()==symbol->name){
                        QWaveInfo wave;
                        if(wave.ReadFile(symbol->path+"/"+jos["wavName"].toString())){
                            symbol->file=jos["wavName"].toString();
                            int wavesize=wave.datalength;
                            int FS=wave.samplespersec;
                            double SP=jos["startTime"].toDouble()+0.06;
                            double EP=jos["endTime"].toDouble();

                            symbol->l1=(SP*FS)/wavesize;
                            symbol->l2=(EP*FS)/wavesize;
                            return true;
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
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

bool VCH::set(CVVCSymbol *symbol)
{
    QFile cfile(symbol->path+"/voice.dvcfg");
    QJsonDocument jd;
    QJsonObject jo;
    if(cfile.exists()){
        if(cfile.open(QIODevice::ReadOnly|QIODevice::Text)){
            jd=QJsonDocument::fromJson(cfile.readAll());
            cfile.close();
            if(jd.isObject()){
                jo=jd.object();
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    QJsonObject jos;
    if(symbol->isCV>0){
        QWaveInfo wave;
        if(wave.ReadFile(symbol->path+"/"+symbol->file)){
            int wavesize=wave.datalength;
            int FS=wave.samplespersec;

            double CP=(symbol->l1*wavesize)/FS;
            double PP=(symbol->l2*wavesize)/FS;
            double VSP=(symbol->l3*wavesize)/FS;
            double VEP=(symbol->l4*wavesize)/FS;

            double cP=0.06;
            double eT=VEP+0.06;
            double pre=PP-CP+0.06;
            double sT=CP-0.06;
            double tP=VEP-CP+0.115;
            double vE=VEP-CP+0.06;
            double vS=VSP-CP+0.06;

            jos.insert("connectPoint",cP);
            jos.insert("endTime",eT);
            jos.insert("pitch",symbol->pitch);
            jos.insert("preutterance",pre);
            jos.insert("srcType","CV");
            jos.insert("startTime",sT);
            jos.insert("symbol",symbol->name);
            jos.insert("tailPoint",tP);
            QDateTime dt=QDateTime::currentDateTime();
            jos.insert("updateTime",dt.toString("yyyy-MM-dd hh:mm:ss"));
            jos.insert("vowelEnd",vE);
            jos.insert("vowelStart",vS);
            jos.insert("wavName",symbol->file);
        }else{
            return false;
        }

    }else if(symbol->isCV==0){
        QWaveInfo wave;
        if(wave.ReadFile(symbol->path+"/"+symbol->file)){
            int wavesize=wave.datalength;
            int FS=wave.samplespersec;

            double SP=(symbol->l1*wavesize)/FS;
            double EP=(symbol->l2*wavesize)/FS;

            double cP=0.06;
            double eT=EP;
            double sT=SP-0.06;
            double tP=EP-SP;

            jos.insert("connectPoint",cP);
            jos.insert("endTime",eT);
            jos.insert("pitch",symbol->pitch);
            jos.insert("srcType","VX");
            jos.insert("startTime",sT);
            jos.insert("symbol",symbol->name);
            jos.insert("tailPoint",tP);
            QDateTime dt=QDateTime::currentDateTime();
            jos.insert("updateTime",dt.toString("yyyy-MM-dd hh:mm:ss"));
            jos.insert("wavName",symbol->file);
        }else{
            return false;
        }
    }else{
        QWaveInfo wave;
        if(wave.ReadFile(symbol->path+"/"+symbol->file)){
            int wavesize=wave.datalength;
            int FS=wave.samplespersec;

            double SP=(symbol->l1*wavesize)/FS;
            double EP=(symbol->l2*wavesize)/FS;

            double cP=0.06;
            double eT=EP;
            double sT=SP-0.06;
            double tP=EP-SP;

            jos.insert("startPoint",cP);
            jos.insert("endTime",eT);
            jos.insert("pitch",symbol->pitch);
            jos.insert("srcType","INDIE");
            jos.insert("startTime",sT);
            jos.insert("symbol",symbol->name);
            jos.insert("endPoint",tP);
            QDateTime dt=QDateTime::currentDateTime();
            jos.insert("updateTime",dt.toString("yyyy-MM-dd hh:mm:ss"));
            jos.insert("wavName",symbol->file);
        }else{
            return false;
        }
    }
    jo.remove(symbol->pitch+"->"+symbol->name);
    jo.insert(symbol->pitch+"->"+symbol->name,jos);
    jd.setObject(jo);
    QByteArray da=jd.toJson(QJsonDocument::Indented);
    if(cfile.exists()){
        cfile.remove();
    }
    if(cfile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cfile.write(da);
        cfile.close();
    }else{
        return false;
    }
    return true;
}

bool VCH::set(DVSym *symbol)
{
    QFile cfile(symbol->path+"/voice.dvcfg");
    QJsonDocument jd;
    QJsonObject jo;
    if(cfile.exists()){
        if(cfile.open(QIODevice::ReadOnly|QIODevice::Text)){
            jd=QJsonDocument::fromJson(cfile.readAll());
            cfile.close();
            if(jd.isObject()){
                jo=jd.object();
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    QJsonObject jos;
    if(symbol->srcType=="CV"){

        jos.insert("connectPoint",symbol->connectPoint);
        jos.insert("endTime",symbol->endTime);
        jos.insert("pitch",symbol->pitch);
        jos.insert("preutterance",symbol->preutterance);
        jos.insert("srcType","CV");
        jos.insert("startTime",symbol->startTime);
        jos.insert("symbol",symbol->symbol);
        jos.insert("tailPoint",symbol->tailPoint);
        QDateTime dt=QDateTime::currentDateTime();
        jos.insert("updateTime",dt.toString("yyyy-MM-dd hh:mm:ss"));
        jos.insert("vowelEnd",symbol->vowelEnd);
        jos.insert("vowelStart",symbol->vowelStart);
        jos.insert("wavName",symbol->wavName);

    }else if(symbol->srcType=="VX"){

        jos.insert("connectPoint",symbol->connectPoint);
        jos.insert("endTime",symbol->endTime);
        jos.insert("pitch",symbol->pitch);
        jos.insert("srcType","VX");
        jos.insert("startTime",symbol->startTime);
        jos.insert("symbol",symbol->symbol);
        jos.insert("tailPoint",symbol->tailPoint);
        QDateTime dt=QDateTime::currentDateTime();
        jos.insert("updateTime",dt.toString("yyyy-MM-dd hh:mm:ss"));
        jos.insert("wavName",symbol->wavName);
    }else{
        jos.insert("startPoint",symbol->startPoint);
        jos.insert("endTime",symbol->endTime);
        jos.insert("pitch",symbol->pitch);
        jos.insert("srcType","INDIE");
        jos.insert("startTime",symbol->startTime);
        jos.insert("symbol",symbol->symbol);
        jos.insert("endPoint",symbol->endPoint);
        QDateTime dt=QDateTime::currentDateTime();
        jos.insert("updateTime",dt.toString("yyyy-MM-dd hh:mm:ss"));
        jos.insert("wavName",symbol->wavName);
    }
    jo.remove(symbol->pitch+"->"+symbol->symbol);
    jo.insert(symbol->pitch+"->"+symbol->symbol,jos);
    jd.setObject(jo);
    QByteArray da=jd.toJson(QJsonDocument::Indented);
    if(cfile.exists()){
        cfile.remove();
    }
    if(cfile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cfile.write(da);
        cfile.close();
    }else{
        return false;
    }
    return true;
}

bool VCH::remove(CVVCSymbol *symbol)
{
    QFile cfile(symbol->path+"/voice.dvcfg");
    QJsonDocument jd;
    QJsonObject jo;
    if(cfile.exists()){
        if(cfile.open(QIODevice::ReadOnly|QIODevice::Text)){
            jd=QJsonDocument::fromJson(cfile.readAll());
            cfile.close();
            if(jd.isObject()){
                jo=jd.object();
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    jo.remove(symbol->pitch+"->"+symbol->name);
    jd.setObject(jo);
    QByteArray da=jd.toJson(QJsonDocument::Indented);
    if(cfile.exists()){
        cfile.remove();
    }
    if(cfile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cfile.write(da);
        cfile.close();
    }else{
        return false;
    }
    return true;
}

bool VCH::remove(DVSym *symbol)
{
    QFile cfile(symbol->path+"/voice.dvcfg");
    QJsonDocument jd;
    QJsonObject jo;
    if(cfile.exists()){
        if(cfile.open(QIODevice::ReadOnly|QIODevice::Text)){
            jd=QJsonDocument::fromJson(cfile.readAll());
            cfile.close();
            if(jd.isObject()){
                jo=jd.object();
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    jo.remove(symbol->pitch+"->"+symbol->symbol);
    jd.setObject(jo);
    QByteArray da=jd.toJson(QJsonDocument::Indented);
    if(cfile.exists()){
        cfile.remove();
    }
    if(cfile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cfile.write(da);
        cfile.close();
    }else{
        return false;
    }
    return true;
}

bool VCH::get(CVVCSymbol *symbol,QString path)
{
    QFile cfile(path+"/voice.dvcfg");
    if(cfile.exists()){
        if(cfile.open(QIODevice::ReadOnly|QIODevice::Text)){
            QJsonDocument jd=QJsonDocument::fromJson(cfile.readAll());
            cfile.close();
            if(jd.isObject()){
                QJsonObject jo=jd.object();
                QJsonObject jos=jo[symbol->pitch+"->"+symbol->name].toObject();
                if(symbol->isCV>0){
                    if(jos["srcType"].toString()=="CV"&&jos["pitch"].toString()==symbol->pitch&&jos["symbol"].toString()==symbol->name){
                        QWaveInfo wave;
                        if(wave.ReadFile(path+"/"+jos["wavName"].toString())){
                            symbol->path=path;
                            symbol->file=jos["wavName"].toString();
                            int wavesize=wave.datalength;
                            int FS=wave.samplespersec;
                            double CP=jos["startTime"].toDouble()+0.06;
                            double PP=jos["preutterance"].toDouble()+CP-0.06;
                            double VSP=jos["vowelStart"].toDouble()+CP-0.06;
                            double VEP=jos["vowelEnd"].toDouble()+CP-0.06;
                            symbol->l1=(CP*FS)/wavesize;
                            symbol->l2=(PP*FS)/wavesize;
                            symbol->l3=(VSP*FS)/wavesize;
                            symbol->l4=(VEP*FS)/wavesize;
                            return true;
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else if(symbol->isCV==0){
                    if(jos["srcType"].toString()=="VX"&&jos["pitch"].toString()==symbol->pitch&&jos["symbol"].toString()==symbol->name){
                        QWaveInfo wave;
                        if(wave.ReadFile(path+"/"+jos["wavName"].toString())){
                            symbol->path=path;
                            symbol->file=jos["wavName"].toString();
                            int wavesize=wave.datalength;
                            int FS=wave.samplespersec;
                            double SP=jos["startTime"].toDouble()+0.06;
                            double EP=jos["endTime"].toDouble();

                            symbol->l1=(SP*FS)/wavesize;
                            symbol->l2=(EP*FS)/wavesize;
                            return true;
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else{
                    if(jos["srcType"].toString()=="INDIE"&&jos["pitch"].toString()==symbol->pitch&&jos["symbol"].toString()==symbol->name){
                        QWaveInfo wave;
                        if(wave.ReadFile(path+"/"+jos["wavName"].toString())){
                            symbol->path=path;
                            symbol->file=jos["wavName"].toString();
                            int wavesize=wave.datalength;
                            int FS=wave.samplespersec;
                            double SP=jos["startTime"].toDouble()+0.06;
                            double EP=jos["endTime"].toDouble();

                            symbol->l1=(SP*FS)/wavesize;
                            symbol->l2=(EP*FS)/wavesize;
                            return true;
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
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

bool VCH::getall(QVector<DVSym> *symbollist,QString path)
{
    QFile cfile(path+"/voice.dvcfg");
    if(cfile.exists()){
        if(cfile.open(QIODevice::ReadOnly|QIODevice::Text)){
            QJsonDocument jd=QJsonDocument::fromJson(cfile.readAll());
            cfile.close();
            if(jd.isObject()){
                QJsonObject jo=jd.object();
                QVariantMap vm=jo.toVariantMap();
                for(int i=0;i<vm.size();i++){
                    DVSym symbol;
                    QString jsn=vm.keys().at(i);
                    QJsonObject jos=vm.values().at(i).toJsonObject();
                    if(jsn==jos["pitch"].toString()+"->"+jos["symbol"].toString()){
                        symbol.path=path;
                        symbol.symbol=jos["symbol"].toString();
                        symbol.pitch=jos["pitch"].toString();
                        symbol.wavName=jos["wavName"].toString();
                        symbol.updateTime=QDateTime::fromString(jos["updateTime"].toString(),"yyyy-MM-dd hh:mm:ss");
                        symbol.srcType=jos["srcType"].toString();

                        if(jos["srcType"].toString()=="CV"){
                            symbol.connectPoint=jos["connectPoint"].toDouble();
                            symbol.tailPoint=jos["tailPoint"].toDouble();
                            symbol.startTime=jos["startTime"].toDouble();
                            symbol.endTime=jos["endTime"].toDouble();
                            symbol.preutterance=jos["preutterance"].toDouble();
                            symbol.vowelStart=jos["vowelStart"].toDouble();
                            symbol.vowelEnd=jos["vowelEnd"].toDouble();
                        }else if(jos["srcType"].toString()=="VX"){
                            symbol.connectPoint=jos["connectPoint"].toDouble();
                            symbol.tailPoint=jos["tailPoint"].toDouble();
                            symbol.startTime=jos["startTime"].toDouble();
                            symbol.endTime=jos["endTime"].toDouble();
                        }else{
                            symbol.startPoint=jos["startPoint"].toDouble();
                            symbol.endPoint=jos["endPoint"].toDouble();
                            symbol.startTime=jos["startTime"].toDouble();
                            symbol.endTime=jos["endTime"].toDouble();
                        }
                    }

                    symbollist->append(symbol);
                }
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
}

bool VCH::removepit(QString path,QString pit)
{
    QFile cfile(path+"/voice.dvcfg");
    QJsonDocument jd;
    QJsonObject jo;
    if(cfile.exists()){
        if(cfile.open(QIODevice::ReadOnly|QIODevice::Text)){
            jd=QJsonDocument::fromJson(cfile.readAll());
            cfile.close();
            if(jd.isObject()){
                jo=jd.object();
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    QVariantMap jom=jo.toVariantMap();
    for(int i=0;i<jom.size();){
        QJsonObject jos=jom.values().at(i).toJsonObject();
        if(jos["pitch"]==pit){
            jom.remove(jom.keys().at(i));
        }else{
            i++;
        }
    }
    jo=QJsonObject::fromVariantMap(jom);
    jd.setObject(jo);
    QByteArray da=jd.toJson(QJsonDocument::Indented);
    if(cfile.exists()){
        cfile.remove();
    }
    if(cfile.open(QIODevice::WriteOnly|QIODevice::Text)){
        cfile.write(da);
        cfile.close();
    }else{
        return false;
    }
    return true;
}

bool VCH::have(DVSym *symbol,QString path)
{
    QFile cfile(path+"/voice.dvcfg");
    if(cfile.exists()){
        if(cfile.open(QIODevice::ReadOnly|QIODevice::Text)){
            QJsonDocument jd=QJsonDocument::fromJson(cfile.readAll());
            cfile.close();
            if(jd.isObject()){
                QJsonObject jo=jd.object();
                if(jo.contains(symbol->pitch+"->"+symbol->symbol)){
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
