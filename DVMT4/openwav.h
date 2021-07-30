#ifndef OPENWAV_H
#define OPENWAV_H

#include <QDialog>
#include <QDir>
#include <QStringList>
#include "AuPlot/qwavehandle.h"
#include <QVector>
#include "AuPlot/global.h"
#include <QListWidgetItem>

namespace Ui {
class OpenWav;
}

class OpenWav : public QDialog
{
    Q_OBJECT

public:
    explicit OpenWav(QWidget *parent = nullptr);
    ~OpenWav();
    void setps(QStringList paths,QVector<QStringList> filelist);

private:
    Ui::OpenWav *ui;
    QStringList ps;
    void OWError(QString mes);
    void OWAccept(QString mes);
    QVector<QStringList> fv;
    QString path,file;
signals:
    void filechanged(QString path,QString filename);
private slots:
    void on_cancel_clicked();
    void on_enter_clicked();
    void on_name_textChanged(const QString &arg1);
    void on_olist_itemPressed(QListWidgetItem *item);
};

#endif // OPENWAV_H
