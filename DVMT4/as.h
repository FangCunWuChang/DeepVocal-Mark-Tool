#ifndef AS_H
#define AS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class AS;
}

class AS : public QWidget
{
    Q_OBJECT

public:
    explicit AS(QWidget *parent = nullptr);
    ~AS();
    void setene(bool ok);
    void setrptz(bool ok);
    void setrea(bool ok);
    void setcle(bool ok);
    void pushene();
    void pushrptz();
    void pushrea();
    void pushcle();

private:
    Ui::AS *ui;
    void resizeNow();
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void key(int id);
private slots:
    void on_ene_clicked(bool checked);
    void on_rptz_clicked(bool checked);
    void on_rea_clicked();
    void on_cle_clicked();
};

#endif // AS_H
