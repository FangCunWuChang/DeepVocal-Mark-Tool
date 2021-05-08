#ifndef CENTER_H
#define CENTER_H

#include <QWidget>
#include <QDir>
#include <QMenu>
#include <QMessageBox>
#include "project.h"
#include "prset.h"
#include "vch.h"
#include "openwav.h"
#include "QSoundEffect"
#include <QMainWindow>
#include "Version.h"
#include <QCoreApplication>
#include <QFileSystemWatcher>
#include "AuPlot/qwaveinfo.h"
#include "filescaner.h"
#include "cslget.h"
#include <QMouseEvent>
#include <QKeyEvent>

namespace Ui {
class Center;
}

class Center : public QWidget
{
    Q_OBJECT

public:
    explicit Center(QWidget *parent = nullptr);
    ~Center();

    bool wannaclose();
    void openfile(QString file);
private:
    Ui::Center *ui;
    Project pro;
    Prset *pset=new Prset(this);
    QString propath=QCoreApplication::applicationDirPath()+"/未命名项目.dvmtp";
    QString mes="Deepvocal Mark Tool "+QString(DVMT_VERSION)+" Build "+QString(__DATE__)+"\nDVMT (C)2020-2021 Wu Chang.All rights reserved.\n声库配布时请注明使用DVMT进行标记.\nAuPlot版本："+QString(AU_VERSION)+"\nAuPlot (C)2020-2021 Wu Chang.All rights reserved.\nQt库版本："+QString(qVersion())+"\nDeepVocal 软件版权归Boxstar所有.\n文泉驿微米黑体使用GPLv3许可协议.";
    bool saved=true;
    void newpro();
    void openpro();
    void savepro();
    QVector<CVVCSymbol> CSL;
    void refreshsym();
    OpenWav *ow=new OpenWav(this);
    QString patht,filet;
    void rechecksym();
    bool checkwav(QString path,QString filename);
    int lockflag=0;
    bool autoed=true;
    void changepit(QString past,QString now);
    QSoundEffect *effect=new QSoundEffect(this);
    bool lisshow=true;
    void resize();
    void retitle();

    QFileSystemWatcher *watcher=new QFileSystemWatcher(this);
    void refreshwatchpath();
    QStringList paths;
    QVector<QStringList> filelist;
    FileScaner F_Scaner;
    void refreshwatchlist();

    CSLget cget;
    void buildmodel(int cr);
    double cbmx=0.1,cbmy=0.2;
protected:
    void resizeEvent(QResizeEvent *event);
    void keyPressEvent(QKeyEvent *event);
private slots:
    void onmenuclicked();
    void onmenukey(int id);
    void onspchanged(Project pro,bool pitref);
    void onwavchanged(QString path,QString filename);
    void on_list_currentRowChanged(int currentRow);
    void onausaved(double l1,double l2,double l3,double l4);
    void on_list_itemChanged(QListWidgetItem *item);
    void on_list_itemSelectionChanged();
    void on_list_currentTextChanged(const QString &currentText);
    void onplotlocked();
    void onplotunlocked();
    void onplotautoed(bool autoed);
    void onlhbclicked(bool ok);
    void onseaclicked();
    void onsearname(QString name);
    void onsearegg();
    void onfiles(QStringList paths,QVector<QStringList> filelist);
    void onwatcherchanged(const QString &path);
    void oncgetappend(CVVCSymbol one,bool finished=false);
    void onawclicked();
    void oncbmrp(QPoint pos);
    void onmtphasemouseplace(int x,int y,int gx,int gy);
};

#endif // CENTER_H
