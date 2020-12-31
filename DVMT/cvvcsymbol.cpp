#include "cvvcsymbol.h"

CVVCSymbol::CVVCSymbol()
{

}

CVVCSymbol CVVCSymbol::operator=(CVVCSymbol arg)
{
    CVVCSymbol out;
    out.name=arg.name;
    out.isCV=arg.isCV;
    out.l1=arg.l1;
    out.l2=arg.l2;
    out.l3=arg.l3;
    out.l4=arg.l4;
    out.path=arg.path;
    out.file=arg.file;
    out.pitch=arg.pitch;
    out.mes=arg.mes;
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
    return out;
}
