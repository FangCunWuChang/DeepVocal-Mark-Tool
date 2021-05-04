#ifndef GPL_H
#define GPL_H

#include <QDialog>

namespace Ui {
class GPL;
}

class GPL : public QDialog
{
    Q_OBJECT

public:
    explicit GPL(QWidget *parent = nullptr);
    ~GPL();
    void settext(QString text);

private:
    Ui::GPL *ui;
};

#endif // GPL_H
