#ifndef FILESCANER_H
#define FILESCANER_H

#include <QObject>
#include <QThread>
#include <QStringList>
#include <QDir>
#include "AuPlot/qwaveinfo.h"
#include "AuPlot/global.h"

class FileScaner : public QThread
{
    Q_OBJECT
public:
    FileScaner();
    void setpaths(QStringList paths);
private:
    QStringList paths;
    QVector<QStringList> filelist;
protected:
    void run() override;
signals:
    void files(QStringList paths,QVector<QStringList> filelist);
};

#endif // FILESCANER_H
