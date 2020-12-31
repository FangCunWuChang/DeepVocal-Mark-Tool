#ifndef PRSET_H
#define PRSET_H

#include <QDialog>
#include "symbolcheck.h"
#include "project.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

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

private slots:
    void on_cancel_clicked();

    void on_dic_textChanged();

    void on_enter_clicked();

    void on_remove_clicked();

    void on_add_clicked();

private:
    Ui::Prset *ui;
    void Error(QString mes);
    void Accept(QString mes);
signals:
    void prochanged(Project pro);
};

#endif // PRSET_H
