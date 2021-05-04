#ifndef RUNDIALOG_H
#define RUNDIALOG_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class RunDialog;
}

class RunDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RunDialog(QWidget *parent = nullptr);
    ~RunDialog();
    void setText(QString text);
    void setpercent(double percent);
protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::RunDialog *ui;
};

#endif // RUNDIALOG_H
