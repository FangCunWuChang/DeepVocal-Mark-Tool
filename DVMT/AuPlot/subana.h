#ifndef SUBANA_H
#define SUBANA_H

#include <QObject>
#include <QThread>
#include "aumathlib.h"
#include "global.h"
#include <QCoreApplication>
#include <QQueue>

class SubAna : public QThread
{
    Q_OBJECT
public:
    SubAna();
    ~SubAna();
    QQueue<QVector<double>> parts;
    QQueue<QVector<double>> spec;
    QQueue<double> ene;
    QQueue<double> rptz;
    QQueue<bool> flag;
protected:
    void run() override;
private:

signals:

};

#endif // SUBANA_H
