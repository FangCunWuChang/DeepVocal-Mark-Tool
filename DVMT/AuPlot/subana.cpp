#include "subana.h"

SubAna::SubAna() : QThread()
{

}

SubAna::~SubAna()
{
    if(this->isRunning()){
        this->terminate();
        this->wait();
    }
    parts.clear();
    spec.clear();
    ene.clear();
    rptz.clear();
    flag.clear();
}

void SubAna::run()
{
    spec.clear();

    while (parts.size()>0) {
        QVector<double> part=parts.dequeue();
        QVector<double> imer=AuMathLib::imelog(AuMathLib::hanning(part));
        imer.resize(global_sets::step/2);
        spec.enqueue(imer);
        imer.clear();

        double et=AuMathLib::ene(part);
        ene.enqueue(et);

        double rt=AuMathLib::rptz(part);
        rptz.enqueue(rt);

        if(et>=global_sets::enebound&&rt<global_sets::rptzbound){
            flag.enqueue(true);
        }else{
            flag.enqueue(false);
        }
    }
    quit();
    return ;
}
