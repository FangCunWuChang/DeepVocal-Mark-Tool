#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include <QPainter>
#include <QFont>

namespace Ui {
class Title;
}

class Title : public QWidget
{
    Q_OBJECT

public:
    explicit Title(QWidget *parent = nullptr);
    void setTitle(QString title);
    ~Title();
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
private slots:
    void on_close_clicked();

    void on_min_clicked();

private:
    Ui::Title *ui;
signals:
    void closeb();
    void minb();
};

#endif // TITLE_H
