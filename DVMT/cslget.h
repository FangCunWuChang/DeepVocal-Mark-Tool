#ifndef CSLGET_H
#define CSLGET_H

#include <QObject>
#include <QThread>
#include "vch.h"
#include "cvvcsymbol.h"

class CSLget : public QThread
{
    Q_OBJECT
public:
    CSLget();
    ~CSLget();
    void setlist(QVector<CVVCSymbol> list,QString pitch,QStringList psl);
private:
    QVector<CVVCSymbol> list;
    QString pitch="C4";
    QStringList psl;
protected:
    void run() override;
signals:
    void append(CVVCSymbol one,bool finished=false);
};

#endif // CSLGET_H
