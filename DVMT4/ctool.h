#ifndef CTOOL_H
#define CTOOL_H

#include <QWidget>
#include <QPainter>
#include <QVariantMap>
#include <QMouseEvent>

namespace Ui {
class CTool;
}

class CTool : public QWidget
{
    Q_OBJECT

public:
    explicit CTool(QWidget *parent = nullptr);
    ~CTool();
    void setwavname(QString wavname);
    void setowlock(bool ok);
public slots:
    void setbuttonchecked(QString button,bool checked);
    void setbuttonenabled(QString button,bool enabled);
    void setkeypress(QString key);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);


private:
    Ui::CTool *ui;
    QString wavname="";

    bool lpressed=false;
    bool inRect(QPoint pos,QRect rect);
    void phasebutton(QString button);

    //flags:0正常1选中2覆盖3按下4禁用
    QVariantMap flags,buttonflags;

    QRect geticonrect1(QRect button,QPixmap icon,double scale=1);
    QRect geticonrect2(QRect button,QPixmap icon,double scale=1);
    QPoint gettextpoint(QRect button,QString text,double scale=1);
    QPoint gettextpoint3(QRect button,QString text,double scale=1);
    void drawbutton1(QPainter *painter,QRect button,QString name,double scale=0.7);
    void drawbutton2(QPainter *painter,QRect button,QString name,QString text="",double scale=0.5);
    void drawbutton3(QPainter *painter,QRect button,QString name,QString text="",double scale=0.7);

signals:
    void ctb(QString button,bool checked);
    void owr();
private slots:
    void on_wavname_clicked();
};

#endif // CTOOL_H
