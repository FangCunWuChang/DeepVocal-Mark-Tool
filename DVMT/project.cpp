#include "project.h"

Project::Project()
{
    QJsonArray symbolarray;
    data.insert("symbols",symbolarray);
    QJsonArray patharray;
    data.insert("paths",patharray);
    data.insert("pitch","C4");
    data.insert("editor","DVMT");
    QJsonArray flagarray;
    data.insert("flags",flagarray);
}

QStringList Project::getsymbols()
{
    QJsonArray symbolarray=data["symbols"].toArray();
    QStringList out;
    for(int i=0;i<symbolarray.size();i++){
        out.append(symbolarray.at(i).toString());
    }
    return out;
}

void Project::setsymbols(QStringList symbols)
{
    QJsonArray symbolarray;
    for(int i=0;i<symbols.size();i++){
        symbolarray.append(symbols.at(i));
    }
    data.insert("symbols",symbolarray);
}

QVector<CVVCSymbol> Project::getflags()
{
    QJsonArray flagarray=data["flags"].toArray();
    QVector<CVVCSymbol> out;
    for(int i=0;i<flagarray.size();i++){
        QJsonObject fo=flagarray.at(i).toObject();
        CVVCSymbol fs;
        fs.name=fo["name"].toString();
        fs.isCV=fo["isCV"].toInt();
        out.append(fs);
    }
    return out;
}

void Project::setflags(QVector<CVVCSymbol> flags)
{
    QJsonArray flagarray;
    for(int i=0;i<flags.size();i++){
        QJsonObject fo;
        fo.insert("name",flags.at(i).name);
        fo.insert("isCV",flags.at(i).isCV);
        flagarray.append(fo);
    }
    data.insert("flags",flagarray);
}

QStringList Project::getpaths()
{
    QJsonArray patharray=data["paths"].toArray();
    QStringList out;
    for(int i=0;i<patharray.size();i++){
        out.append(patharray.at(i).toString());
    }
    return out;
}

void Project::setpaths(QStringList paths)
{
    QJsonArray patharray;
    for(int i=0;i<paths.size();i++){
        patharray.append(paths.at(i));
    }
    data.insert("paths",patharray);
}

QString Project::getpitch()
{
    return data["pitch"].toString();
}

void Project::setpitch(QString pitch)
{
    data.insert("pitch",pitch);
}

bool Project::writefile(QString filepath)
{
    QFile file(filepath);
    if(file.exists()){
        file.remove();
    }
    if(file.open(QIODevice::Text|QIODevice::WriteOnly)){
        QJsonDocument jd(data);
        file.write(jd.toJson(QJsonDocument::Indented));
        file.close();
        return true;
    }else{
        return false;
    }
}

bool Project::readfile(QString filepath)
{
    QFile file(filepath);
    if(file.open(QIODevice::Text|QIODevice::ReadOnly)){
        QByteArray dbai=file.readAll();

        file.close();

        QJsonDocument jd=QJsonDocument::fromJson(dbai);
        if(jd.isObject()){
            if(jd["editor"].toString()=="DVMT"){
                data=jd.object();
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

void Project::clear()
{
    QJsonArray symbolarray;
    data.insert("symbols",symbolarray);
    QJsonArray patharray;
    data.insert("paths",patharray);
    data.insert("pitch","C4");
    QJsonArray flagarray;
    data.insert("flags",flagarray);
}

Project Project::operator=(Project pro)
{
    this->data=pro.data;
    return *this;
}

bool Project::operator==(Project pro){
    bool out=true;
    if(out){
        QJsonArray saa=pro.data["symbols"].toArray();
        QJsonArray san=this->data["symbols"].toArray();
        if(saa.size()!=san.size()){
            out=false;
        }
        if(out){
            for(int i=0;i<saa.size();i++){
                if(saa.at(i).toString()!=san.at(i).toString()){
                    out=false;
                    break;
                }
            }
        }
    }
    if(out){
        QJsonArray paa=pro.data["paths"].toArray();
        QJsonArray pan=this->data["paths"].toArray();
        if(paa.size()!=pan.size()){
            out=false;
        }
        if(out){
            for(int i=0;i<paa.size();i++){
                if(paa.at(i).toString()!=pan.at(i).toString()){
                    out=false;
                    break;
                }
            }
        }
    }
    if(out){
        if(pro.data["pitch"].toString()!=this->data["pitch"].toString()){
            out=false;
        }
    }
    if(out){
        QJsonArray faa=pro.data["flags"].toArray();
        QJsonArray fan=this->data["flags"].toArray();
        if(faa.size()!=fan.size()){
            out=false;
        }
        if(out){
            for(int i=0;i<faa.size();i++){
                if(faa.at(i).toString()!=fan.at(i).toString()){
                    out=false;
                    break;
                }
            }
        }
    }
    return out;
}

bool Project::operator!=(Project pro){
    bool out=true;
    if(out){
        QJsonArray saa=pro.data["symbols"].toArray();
        QJsonArray san=this->data["symbols"].toArray();
        if(saa.size()!=san.size()){
            out=false;
        }
        if(out){
            for(int i=0;i<saa.size();i++){
                if(saa.at(i).toString()!=san.at(i).toString()){
                    out=false;
                    break;
                }
            }
        }
    }
    if(out){
        QJsonArray paa=pro.data["paths"].toArray();
        QJsonArray pan=this->data["paths"].toArray();
        if(paa.size()!=pan.size()){
            out=false;
        }
        if(out){
            for(int i=0;i<paa.size();i++){
                if(paa.at(i).toString()!=pan.at(i).toString()){
                    out=false;
                    break;
                }
            }
        }
    }
    if(out){
        if(pro.data["pitch"].toString()!=this->data["pitch"].toString()){
            out=false;
        }
    }
    if(out){
        QJsonArray faa=pro.data["flags"].toArray();
        QJsonArray fan=this->data["flags"].toArray();
        if(faa.size()!=fan.size()){
            out=false;
        }
        if(out){
            for(int i=0;i<faa.size();i++){
                if(faa.at(i).toString()!=fan.at(i).toString()){
                    out=false;
                    break;
                }
            }
        }
    }
    return !out;
}
