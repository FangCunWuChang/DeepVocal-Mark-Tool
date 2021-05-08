#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    void setowlock(bool lock);
    void setplace(int x,int y);

private:
    Ui::Menu *ui;
    int x=0,y=0;
    void resizeNow();
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);
signals:
    void key(int id);
    void phasemouseplace(int x,int y,int gx,int gy);
    void phasemouserel(int gx,int gy);
    void phasemousemov(int gx,int gy);
    void phaselea();
private slots:
    void on_newp_clicked();
    void on_open_clicked();
    void on_save_clicked();
    void on_sets_clicked();
    void on_read_clicked();
    void on_about_clicked();
};

#endif // MENU_H
