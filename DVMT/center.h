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
private:
    Ui::Center *ui;
    //QMenu *menu=new QMenu(this);
    Project pro;
    Prset *pset=new Prset(this);
    QString propath=QDir::currentPath()+"/未命名项目.dvmtp";
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
protected:
    void resizeEvent(QResizeEvent *event);
private slots:
    void on_menu_clicked();
    void onmenukey(int id);
    void onspchanged(Project pro);
    void onwavchanged(QString path,QString filename);
    void on_list_currentRowChanged(int currentRow);
    void onausaved(double l1,double l2,double l3,double l4);
    void on_list_itemChanged(QListWidgetItem *item);
    void on_list_itemSelectionChanged();
    void on_list_currentTextChanged(const QString &currentText);
    void onplotlocked();
    void onplotunlocked();
    void onplotautoed(bool autoed);
    void on_lhb_clicked();
    void on_lsb_clicked();
};

#endif // CENTER_H
