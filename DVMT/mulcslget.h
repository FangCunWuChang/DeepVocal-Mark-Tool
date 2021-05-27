#ifndef MulCSLget_H
#define MulCSLget_H

#include <QObject>
#include <QThread>
#include "vch.h"
#include "dvsym.h"
#include <QtMath>

class MulCSLget : public QThread
{
    Q_OBJECT
public:
    MulCSLget();
    ~MulCSLget();
    void setlist(QStringList psl);
private:
    QStringList psl;
protected:
    void run() override;
signals:
    void append(QVector<QVector<DVSym>> cstl);
};

#endif // MulCSLget_H
