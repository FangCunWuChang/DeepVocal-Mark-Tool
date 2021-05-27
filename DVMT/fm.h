#ifndef FM_H
#define FM_H

#include <QDialog>
#include "project.h"
#include "vch.h"
#include "cvvcsymbol.h"
#include "mulcslget.h"
#include "dvsym.h"
#include <QMessageBox>
#include "cpsdialog.h"
#include "copthread.h"
#include "rundialog.h"
#include "psm.h"

namespace Ui {
class FM;
}

class FM : public QDialog
{
    Q_OBJECT

public:
    explicit FM(QWidget *parent = nullptr);
    ~FM();
    void setpro(Project pro);

private:
    Ui::FM *ui;
    QVector<QVector<DVSym>> cstl;
    MulCSLget MCG;
    QStringList psl;
    CPSDialog *cpsd=new CPSDialog(this);
    CopThread cot;
    RunDialog *rud=new RunDialog(this);
    void lockdia(bool ok);
private slots:
    void onappend(QVector<QVector<DVSym>> cstl);
    void on_pitl_currentRowChanged(int currentRow);
    void on_clem_clicked();
    void on_copm_clicked();
    void on_edim_clicked();
    void onpercent(double percent);
    void onthrcopenddia();
    void oncopflagdia(QString path,QString pit,QString symbol,QString pathn);
signals:
    void thrcopenddia();
};

#endif // FM_H
