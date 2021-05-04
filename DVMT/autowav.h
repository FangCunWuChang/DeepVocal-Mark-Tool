#ifndef AUTOWAV_H
#define AUTOWAV_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QListWidgetItem>

namespace Ui {
class AutoWav;
}

class AutoWav : public QWidget
{
    Q_OBJECT

public:
    explicit AutoWav(QWidget *parent = nullptr);
    void setpathes(QStringList paths,QVector<QStringList> filelist);
    void setsymname(QString symname);
    void okey();
    ~AutoWav();

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_olist_itemDoubleClicked(QListWidgetItem *item);

    void on_name_textChanged(const QString &arg1);

private:
    Ui::AutoWav *ui;
    QStringList paths;
    QVector<QStringList> filelist;
    QString symname="";
    void slovelist();
signals:
    void wavopen(QString path,QString file);
};

#endif // AUTOWAV_H
