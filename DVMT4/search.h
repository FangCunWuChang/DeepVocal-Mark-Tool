#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "cvvcsymbol.h"
#include <QListWidgetItem>

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();
    void setsymbols(QVector<CVVCSymbol> CSL);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::Search *ui;
    QVector<CVVCSymbol> CSL;
signals:
    void name(QString name);
private slots:
    void on_line_textChanged(const QString &arg1);
    void on_slist_itemPressed(QListWidgetItem *item);
};

#endif // SEARCH_H
