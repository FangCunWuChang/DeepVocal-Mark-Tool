#include "dvsym.h"

DVSym::DVSym()
{

}

DVSym DVSym::operator=(DVSym arg)
{
    this->path=arg.path;
    this->pitch=arg.pitch;
    this->symbol=arg.symbol;
    this->endTime=arg.endTime;
    this->srcType=arg.srcType;
    this->wavName=arg.wavName;
    this->endPoint=arg.endPoint;
    this->vowelEnd=arg.vowelEnd;
    this->startTime=arg.startTime;
    this->tailPoint=arg.tailPoint;
    this->startPoint=arg.startPoint;
    this->updateTime=arg.updateTime;
    this->vowelStart=arg.vowelStart;
    this->connectPoint=arg.connectPoint;
    this->preutterance=arg.preutterance;
    return *this;
}
