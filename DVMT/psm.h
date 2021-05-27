#ifndef PSM_H
#define PSM_H

#include <QDialog>
#include "dvsym.h"
#include "vch.h"
#include <QInputDialog>

namespace Ui {
class PSM;
}

class PSM : public QDialog
{
    Q_OBJECT

public:
    explicit PSM(QWidget *parent = nullptr);
    ~PSM();
    void setPitch(QVector<DVSym> symlist);

private slots:
    void on_des_clicked();

    void on_cos_clicked();

    void on_pslist_currentRowChanged(int currentRow);

private:
    Ui::PSM *ui;
    QVector<DVSym> symlist;
    void refreshlist();
};

#endif // PSM_H
