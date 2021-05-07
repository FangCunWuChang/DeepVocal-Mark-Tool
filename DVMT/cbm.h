#ifndef CBM_H
#define CBM_H

#include <QWidget>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class CBM;
}

class CBM : public QWidget
{
    Q_OBJECT

public:
    explicit CBM(QWidget *parent = nullptr);
    ~CBM();
    void setText(QString text);
    void setmenuenabled(bool ok);
    void setseaenabled(bool ok);
    void setawenabled(bool ok);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);
private:
    Ui::CBM *ui;
    bool m_bDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;
signals:
    void menuclicked();
    void lhbclicked(bool ok);
    void seaclicked();
    void awclicked();
    void rp(QPoint pos);
private slots:
    void on_lhb_clicked(bool checked);
    void on_aw_clicked();
    void on_sea_clicked();
    void on_menu_clicked();
};

#endif // CBM_H
