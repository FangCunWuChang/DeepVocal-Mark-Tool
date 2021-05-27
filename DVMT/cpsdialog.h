#ifndef CPSDIALOG_H
#define CPSDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class CPSDialog;
}

class CPSDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CPSDialog(QWidget *parent = nullptr);
    ~CPSDialog();
    void setpl(QStringList psl);
    QString path="";
    QString pit="C4";
    bool acceptflag=false;
private slots:
    void on_P1_currentTextChanged(const QString &arg1);

    void on_P2_currentTextChanged(const QString &arg1);

    void on_cancel_clicked();

    void on_enter_clicked();

private:
    Ui::CPSDialog *ui;

};

#endif // CPSDIALOG_H
