#ifndef IPLOT_H
#define IPLOT_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class IPlot;
}

class IPlot : public QWidget
{
    Q_OBJECT

public:
    explicit IPlot(QWidget *parent = nullptr);
    explicit IPlot(QWidget *parent = nullptr,QVector<double> *data=new QVector<double>);
    ~IPlot();

    static void plotdata(QWidget *parent = nullptr,QVector<double> *data=new QVector<double>);
    void plot(QVector<double> data);
    void plot();
    void setdata(QVector<double> data);


private:
    Ui::IPlot *ui;
    QVector<double> data;
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // IPLOT_H
