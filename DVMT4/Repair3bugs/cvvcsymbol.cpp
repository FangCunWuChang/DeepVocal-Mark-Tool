#include "cvvcsymbol.h"

CVVCSymbol::CVVCSymbol()
{

}

CVVCSymbol CVVCSymbol::operator=(CVVCSymbol arg)
{
    this->name=arg.name;
    this->isCV=arg.isCV;
    this->l1=arg.l1;
    this->l2=arg.l2;
    this->l3=arg.l3;
    this->l4=arg.l4;
    this->path=arg.path;
    this->file=arg.file;
    this->pitch=arg.pitch;
    this->mes=arg.mes;
    return *this;
}
