#ifndef AUPLOT_H
#define AUPLOT_H

#include <QWidget>
#include "aumathlib.h"
#include "qwavehandle.h"
#include <QPainter>
#include "lockdialog.h"
#include "anathread.h"
#include "pixtemp.h"
#include <QMessageBox>
#include "loathread.h"
#include <QMediaPlayer>
#include <QSoundEffect>
#include "global.h"
#include "svathread.h"
#include "autoimg.h"

namespace Ui {
class AuPlot;
}

class AuPlot : public QWidget
{
    Q_OBJECT

public:
    explicit AuPlot(QWidget *parent = nullptr);
    ~AuPlot();

    void WaveAnalyse(QString filepath,bool repaint=false);
    bool islock();
    void setfourlines(bool fourlines);
    void setlines(double l1,double l2,double l3,double l4);



private:
    Ui::AuPlot *ui;
    LockDialog *ld=new LockDialog(this);
    AnaThread *athr=new AnaThread;
    LoaThread *lthr= new LoaThread;
    SvaThread *sthr=new SvaThread;
    bool lockf=false;
    QString filepath;
    PixTemp pixtemp;
    QSoundEffect se;
    double hs=0,he=1;

    bool selected=false;
    double ssp=0,sep=0;
    bool fourlines=true;
    double l1=0,l2=0,l3=0,l4=0;
    int lineid=1;

    double tsizeg=global_sets::tempsgate;
    void checktemps();
protected:
    void resizeEvent(QResizeEvent *event);
public slots:
    void lock();
    void unlock();
    void tip(QString msg);
    void setctb(QString button,bool checked);
private slots:
    void draw(QVector<double> wavepixv,QVector<double> wavepixp,QVector<QVector<double>> specpix,QVector<double> v1,QVector<double> v2,QVector<bool> v4,bool save=true);
    void onhschanged(double hs=0,double he=1);
    void onbuttonchanged(int code);
    void plotplay(bool play);
    void onsestop();
    void onspchanged(bool selected,double ssp,double sep);
    void onpmove(double px);
    void onpoint(double px);
    void onprefresh();
    void onlinechanged(int id);
    void onsaved();
    void onsvanum(int num);
signals:
    void marks(double l1,double l2,double l3,double l4);
    void locked();
    void unlocked();
    void autoed(bool autoed);
    void buttonchecked(QString button,bool checked);
    void buttonenabled(QString button,bool enabled);

};

#endif // AUPLOT_H
