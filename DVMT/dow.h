#ifndef DOW_H
#define DOW_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class DoW;
}

class DoW : public QWidget
{
    Q_OBJECT

public:
    explicit DoW(QWidget *parent = nullptr);
    ~DoW();
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::DoW *ui;
};

#endif // DOW_H
