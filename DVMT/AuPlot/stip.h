#ifndef STIP_H
#define STIP_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class STip;
}

class STip : public QWidget
{
    Q_OBJECT

public:
    explicit STip(QWidget *parent = nullptr);
    ~STip();
public slots:
    void setnum(int num);

private:
    Ui::STip *ui;
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // STIP_H
