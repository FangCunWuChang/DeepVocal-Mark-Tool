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

private:
    Ui::Menu *ui;
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void key(int id);
private slots:
    void on_newp_clicked();
    void on_open_clicked();
    void on_save_clicked();
    void on_sets_clicked();
    void on_read_clicked();
    void on_about_clicked();
};

#endif // MENU_H
