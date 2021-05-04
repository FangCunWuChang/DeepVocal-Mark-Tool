#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QFontDatabase>
#include <QDir>
#include <QFile>
#include "cvvcsymbol.h"
#include "dvsym.h"
#include <QSystemSemaphore>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling,true);
    QApplication a(argc, argv);
    qRegisterMetaType<QVector<double>>("QVector<double>");
    qRegisterMetaType<QVector<QVector<double>>>("QVector<QVector<double>>");
    qRegisterMetaType<QVector<bool>>("QVector<bool>");
    qRegisterMetaType<QVector<QStringList>>("QVector<QStringList>");
    qRegisterMetaType<CVVCSymbol>("CVVCSymbol");
    qRegisterMetaType<QVector<QVector<CVVCSymbol>>>("QVector<QVector<CVVCSymbol>>");
    qRegisterMetaType<QVector<QVector<DVSym>>>("QVector<QVector<DVSym>>");
    if(QFile::exists(QCoreApplication::applicationDirPath()+"/SourceHanSans.ttc")){
      int fontId = QFontDatabase::addApplicationFont(QCoreApplication::applicationDirPath()+"/SourceHanSans.ttc");
      qDebug("fontFile = %s",qPrintable(QCoreApplication::applicationDirPath()+"/SourceHanSans.ttc"));
      qDebug("fontId = %d",fontId);
      QString msyh = QFontDatabase::applicationFontFamilies(fontId).at(17);
      //0 Source Han Sans ExtraLight
      //1 Source Han Sans K ExtraLight
      //2 Source Han Sans SC ExtraLight
      //3 Source Han Sans TC ExtraLight
      //4 Source Han Sans HC ExtraLight
      //5 Source Han Sans Light
      //6 Source Han Sans K Light
      //7 Source Han Sans SC Light
      //8 Source Han Sans TC Light
      //9 Source Han Sans HC Light
      //10 Source Han Sans Normal
      //11 Source Han Sans K Normal
      //12 Source Han Sans SC Normal
      //13 Source Han Sans TC Normal
      //14 Source Han Sans HC Normal
      //15 Source Han Sans Medium
      //16 Source Han Sans K Medium
      //17 Source Han Sans SC Medium
      //18 Source Han Sans TC Medium
      //19 Source Han Sans HC Medium
      //20 Source Han Sans Heavy
      //21 Source Han Sans K Heavy
      //22 Source Han Sans SC Heavy
      //23 Source Han Sans TC Heavy
      //24 Source Han Sans HC Heavy
      //25 Source Han Sans
      //26 Source Han Sans K
      //27 Source Han Sans SC
      //28 Source Han Sans TC
      //29 Source Han Sans HC
      //30 Source Han Sans HW
      //31 Source Han Sans HW K
      //32 Source Han Sans HW SC
      //33 Source Han Sans HW TC
      //34 Source Han Sans HW HC
      //35 Source Han Sans
      //36 Source Han Sans K
      //37 Source Han Sans SC
      //38 Source Han Sans TC
      //39 Source Han Sans HC
      //40 Source Han Sans HW
      //41 Source Han Sans HW K
      //42 Source Han Sans HW SC
      //43 Source Han Sans HW TC
      //44 Source Han Sans HW HC
      qDebug("msyh = %s",qPrintable(msyh));
      QFont font(msyh);
      QApplication::setFont(font);
    }else{
      qDebug("未找到字体：%s",qPrintable(QCoreApplication::applicationDirPath()+"/SourceHanSans.ttc"));
    }


    int ret=1;
    MainWindow w;

    // 信号量的意义，把操作共享内存的代码锁住。因为有可能同时点击2次APP, 防止并发
        QSystemSemaphore sema("SingleDVMT Key", 1, QSystemSemaphore::Open);
        sema.acquire();

    #ifdef Q_OS_LINUX
        /* Windows平台上不存在应用程序崩溃后，共享内存段还存在的情况
         * LINUX应用程序崩溃后,共享内存段不会自动销毁,则该程序再次运行会出问题
         * 所以程序启动时先去检查是否有程序崩溃后还存留的共享内存段，如果有，先销毁,再创建
         */
        QSharedMemory mem("SingleDVMT");
        // 尝试将进程附加到共享内存段
        if (mem.attach()) {
            // 将共享内存与主进程分离, 如果此进程是附加到共享存储器段的最后一个进程，则系统释放共享存储器段，即销毁内容
            mem.detach();
        }
    #endif
        /*
         * 每个App打开的时候，获取一次共享内存。
         * 如果获取失败，说明是第一个启动的APP，直接创建共享内存就好了。
         * 如果获取成功，说明不是第一个，直接退出就好了。
         * 保证App在系统里只能打开一个。
         */
        QSharedMemory unimem("SingleDVMT");
        bool isRunning = false;
        if (unimem.attach()) {
            isRunning = true;
        } else {
            unimem.create(1);
            isRunning = false;
        }

        sema.release();

        if (isRunning) {
            QMessageBox::warning(&w,"DVMT提示","DVMT已经在运行!");
            ret=-1;
        } else {
            w.show();
            ret=a.exec();
        }
    return ret;
}
