#ifndef COPTHREAD_H
#define COPTHREAD_H

#include <QObject>
#include <QThread>
#include "dvsym.h"
#include "vch.h"
#include <QMessageBox>
#include <QWidget>
#include <QCoreApplication>

class CopThread : public QThread
{
    Q_OBJECT
public:
    CopThread();
    ~CopThread();
    void settask(QVector<DVSym> slist,QString path,QString pit);
    void changedflag(QMessageBox::StandardButton result);
protected:
    void run() override;
private:
    QVector<DVSym> slist;
    QString path;
    QString pit;
    QWidget *parent=nullptr;
    QMessageBox::StandardButton result=QMessageBox::Cancel;
    bool changeflag=true;
    void wannaflagchange(QString path,QString pit,QString symbol,QString pathn);
signals:
    void percent(double percent);
    void flagdia(QString path,QString pit,QString symbol,QString pathn);
};

#endif // COPTHREAD_H
