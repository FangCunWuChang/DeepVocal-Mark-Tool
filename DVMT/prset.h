#ifndef PRSET_H
#define PRSET_H

#include <QDialog>
#include "symbolcheck.h"
#include "project.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include "fm.h"
#include <QCloseEvent>

namespace Ui {
class Prset;
}

class Prset : public QDialog
{
    Q_OBJECT

public:
    explicit Prset(QWidget *parent = nullptr);
    ~Prset();
    void setproject(Project pro);
    FM *fmd=new FM(this);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_dic_textChanged();

    void on_remove_clicked();

    void on_add_clicked();

    void on_flagm_clicked();

private:
    Ui::Prset *ui;
    void Error(QString mes);
    void Accept(QString mes);
    Project pro;
    bool canenter=false;
signals:
    void prochanged(Project pro,bool pitref=false);
};

#endif // PRSET_H
