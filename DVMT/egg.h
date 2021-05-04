#ifndef EGG_H
#define EGG_H

#include <QWidget>
#include <QPainter>
#include "Version.h"
#include <QMessageBox>
#include "AuPlot/global.h"
#include <QFile>
#include "gpl.h"

namespace Ui {
class Egg;
}

class Egg : public QWidget
{
    Q_OBJECT

public:
    explicit Egg(QWidget *parent = nullptr);
    ~Egg();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_line_textChanged(const QString &arg1);

private:
    Ui::Egg *ui;
};

#endif // EGG_H
