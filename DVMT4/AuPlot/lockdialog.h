#ifndef LOCKDIALOG_H
#define LOCKDIALOG_H

#include <QDialog>

namespace Ui {
class LockDialog;
}

class LockDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LockDialog(QWidget *parent = nullptr);
    ~LockDialog();
    void setmsg(QString msg);

private:
    Ui::LockDialog *ui;
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // LOCKDIALOG_H
