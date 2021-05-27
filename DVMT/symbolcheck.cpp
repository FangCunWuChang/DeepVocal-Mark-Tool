#include "symbolcheck.h"

Symbolcheck::Symbolcheck()
{

}

bool Symbolcheck::check(QStringList in)
{
    QString tt=error(in);
    if(tt=="正确"){
        return true;
    }else{
        return false;
    }
}

QString Symbolcheck::error(QStringList in)
{
    QString out="正确";
    QStringList sltc1,sltc3,slts,slte,sltn,sltt;
    for(int i=0;i<in.size();i++){
        QString slt=in.at(i);
        int flags=slt.size();
        if(slt.contains('#')){
            flags=slt.indexOf('#');
        }
        slt=slt.left(flags);
        slt.remove(' ');
        in.replace(i,slt);
    }
    for(int i=0;i<in.size();i++){
        if(!in.at(i).isEmpty()){
            QStringList slt=in.at(i).split(",",QString::KeepEmptyParts);

            if(!(slt.size()==1||slt.size()==3)){
                out=QString::asprintf("(第%d条)句法有误：",i+1)+in.at(i);
                break;
            }

            if(slt.size()==3){
                bool ref=false;
                for(int j=0;j<sltn.size();j++){
                    if(ref){
                        break;
                    }
                    if(sltn.at(j)==slt.at(0)){
                        ref=true;
                        out=QString::asprintf("(第%d条)句法有误：",i+1)+in.at(i)+":\""+slt.at(0)+"\"CV标记重复";
                        break;
                    }
                }
                for(int j=0;j<sltc1.size();j++){
                    if(ref){
                        break;
                    }
                    if(sltc1.at(j)==slt.at(0)){
                        ref=true;
                        out=QString::asprintf("(第%d条)句法有误：",i+1)+in.at(i)+":\""+slt.at(0)+"\"已是一个VX标记";
                        break;
                    }
                }
                if(ref){
                    break;
                }else{
                    sltn.append(slt.at(0));
                }

                if(ref){
                    break;
                }
                if(slt.at(1)=="-"){
                    ref=true;
                    out=QString::asprintf("(第%d条)句法有误：",i+1)+in.at(i)+":\""+slt.at(1)+"\"与固有标记(\"-\")重复";
                    break;
                }
                if(ref){
                    break;
                }else{
                    bool cf=false;
                    for(int j=0;j<slts.size();j++){
                        if(slts.at(j)==slt.at(1)){
                            cf=true;
                            break;
                        }
                    }
                    if(!cf){
                        slts.append(slt.at(1));
                    }

                }


                if(ref){
                    break;
                }else{
                    bool cf=false;
                    for(int j=0;j<slte.size();j++){
                        if(slte.at(j)==slt.at(2)){
                            cf=true;
                            break;
                        }
                    }
                    if(!cf){
                        slte.append(slt.at(2));
                    }
                }
            }else{
                if(slt.at(0).at(0)!='%'){
                    bool ref=false;
                    for(int j=0;j<sltn.size();j++){
                        if(ref){
                            break;
                        }
                        if(sltn.at(j)==slt.at(0)){
                            ref=true;
                            out=QString::asprintf("(第%d条)句法有误：",i+1)+in.at(i)+":\""+slt.at(0)+"\"已是一个CV标记";
                            break;
                        }
                    }

                    if(ref){
                        break;
                    }else{

                    }
                }else{

                    bool ref=false;
                    if(slt.at(0).size()<2){
                        ref=true;
                        out=QString::asprintf("(第%d条)句法有误：",i+1)+in.at(i)+":\""+slt.at(0)+"\"空的尾音符号";
                    }
                    QString slttt;
                    for(int j=1;j<slt.at(0).size();j++){
                        slttt.append(slt.at(0).at(j));
                    }
                    for(int j=0;j<slts.size();j++){
                        if(ref){
                            break;
                        }
                        if(slts.at(j)==slttt){
                            ref=true;
                            out=QString::asprintf("(第%d条)句法有误：",i+1)+in.at(i)+":\""+slttt+"\"已是一个起始符号";
                            break;
                        }
                    }

                    if(ref){
                        break;
                    }else{
                        bool cf=false;
                        for(int j=0;j<sltt.size();j++){
                            if(sltt.at(j)==slttt){
                                cf=true;
                                break;
                            }
                        }
                        if(!cf){
                            sltt.append(slttt);
                        }
                    }



                }




            }

            bool rede=false;
            for(int j=0;j<sltc1.size();j++){
                if(rede){
                    break;
                }
                if(in.at(i)==sltc1.at(j)){
                    rede=true;
                    break;
                }
            }
            for(int j=0;j<sltc3.size();j++){
                if(rede){
                    break;
                }
                if(in.at(i)==sltc3.at(j)){
                    rede=true;
                    break;
                }
            }
            if(rede){
                out=QString::asprintf("(第%d条)重复：",i+1)+in.at(i);
                break;
            }else{
                if(slt.size()==1){
                    sltc1.append(in.at(i));
                }else{
                    sltc3.append(in.at(i));
                }

            }

        }


    }
    return out;

}

QVector<CVVCSymbol> Symbolcheck::split(QStringList in)
{
    QVector<CVVCSymbol> out;
    if(check(in)){
        QStringList symcl,sl,el,symvl,tl;
        for(int i=0;i<in.size();i++){
            QString slt=in.at(i);
            int flags=slt.size();
            if(slt.contains('#')){
                flags=slt.indexOf('#');
            }
            slt=slt.left(flags);
            slt.remove(' ');
            in.replace(i,slt);
        }
        for(int i=0;i<in.size();i++){
            if(!in.at(i).isEmpty()){
                QStringList slt=in.at(i).split(",",QString::KeepEmptyParts);
                if(slt.size()==3){
                    bool cfsymc=false;
                    for(int j=0;j<symcl.size();j++){
                        if(symcl.at(j)==slt.at(0)){
                            cfsymc=true;
                            break;
                        }
                    }
                    if(!cfsymc){
                        symcl.append(slt.at(0));
                    }
                    bool cfs=false;
                    for(int j=0;j<sl.size();j++){
                        if(sl.at(j)==slt.at(1)){
                            cfs=true;
                            break;
                        }
                    }
                    if(!cfs){
                        sl.append(slt.at(1));
                    }
                    bool cfe=false;
                    for(int j=0;j<el.size();j++){
                        if(el.at(j)==slt.at(2)){
                            cfe=true;
                            break;
                        }
                    }
                    if(!cfe){
                        el.append(slt.at(2));
                    }
                }else{
                    if(slt.at(0).at(0)!='%'){
                        bool cfsymv=false;
                        for(int j=0;j<symvl.size();j++){
                            if(symvl.at(j)==slt.at(0)){
                                cfsymv=true;
                                break;
                            }
                        }
                        if(!cfsymv){
                            symvl.append(slt.at(0));
                        }
                    }else{
                        bool cftl=false;
                        QString slttt;
                        for(int j=1;j<slt.at(0).size();j++){
                            slttt.append(slt.at(0).at(j));
                        }
                        for(int j=0;j<tl.size();j++){
                            if(tl.at(j)==slttt){
                                cftl=true;
                                break;
                            }
                        }
                        if(!cftl){
                            tl.append(slttt);
                        }
                    }

                }

            }
        }

        for(int i=0;i<symcl.size();i++){
            CVVCSymbol CT,CTS;
            QString namet=symcl.at(i);
            CT.name=namet;
            CTS.name="-"+namet;
            CT.isCV=1;
            CTS.isCV=1;
            out.append(CT);
            out.append(CTS);
        }
        for(int i=0;i<el.size();i++){
            QString nameet=el.at(i);
            for(int j=0;j<sl.size();j++){
                QString namest=sl.at(j);
                CVVCSymbol LT;
                LT.name=nameet+"_"+namest;
                LT.isCV=0;
                out.append(LT);
            }
            for(int j=0;j<tl.size();j++){
                QString namett=tl.at(j);
                CVVCSymbol TT;
                TT.name=nameet+"_"+namett;
                TT.isCV=0;
                out.append(TT);
            }
            CVVCSymbol ET;
            ET.name=nameet+"_-";
            ET.isCV=0;
            out.append(ET);

        }
        for(int i=0;i<symvl.size();i++){
            QString namet=symvl.at(i);
            CVVCSymbol VT;
            VT.name=namet;
            VT.isCV=-1;
            out.append(VT);
        }

    }
    return out;
}
