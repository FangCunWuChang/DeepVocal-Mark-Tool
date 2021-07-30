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
#include <QTextCodec>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<QVector<double>>("QVector<double>");
    qRegisterMetaType<QVector<QVector<double>>>("QVector<QVector<double>>");
    qRegisterMetaType<QVector<bool>>("QVector<bool>");
    qRegisterMetaType<QVector<QStringList>>("QVector<QStringList>");
    qRegisterMetaType<CVVCSymbol>("CVVCSymbol");
    qRegisterMetaType<QVector<QVector<CVVCSymbol>>>("QVector<QVector<CVVCSymbol>>");
    qRegisterMetaType<QVector<QVector<DVSym>>>("QVector<QVector<DVSym>>");
    if(QFile::exists(":/type/wqy-microhei.ttc")){
      int fontId = QFontDatabase::addApplicationFont(":/type/wqy-microhei.ttc");
      qDebug("fontFile = %s",qPrintable(":/type/wqy-microhei.ttc"));
      qDebug("fontId = %d",fontId);
      QString msyh = QFontDatabase::applicationFontFamilies(fontId).at(0);
      qDebug("msyh = %s",qPrintable(msyh));
      QFont font(msyh);
      QApplication::setFont(font);
    }else{
      qDebug("未找到字体：%s",qPrintable(":/type/wqy-microhei.ttc"));
    }

    QPixmap spixmap(":/imag/Splash.png");
    QSplashScreen splash(spixmap);
    splash.show();

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
            splash.finish(&w);
            ret=-1;
        } else {
            QString filestr1;
            if(argc>1){
#ifdef Q_OS_WIN
                QTextCodec *codec = QTextCodec::codecForName("GBK");
#else
                QTextCodec *codec = QTextCodec::codecForName("UTF8");
#endif
                QByteArray sarray(argv[1]);
                filestr1 = codec->toUnicode(sarray);

                //如果是直接双击exe打开本程序，那么程序获取到的参数个数为1，argv[0]里面是本exe文件所在的全路径
                //如果是通过双击项目文件之后，系统打开本程序，那么程序获取到的参数个数为2，argv[0]里面是本exe文件所在的全路径，argv[1]里面是本项目文件的全路径
            }
            w.show();
            if(!filestr1.isEmpty()){
                w.openfile(filestr1);
            }
            splash.finish(&w);
            ret=a.exec();
        }
    return ret;
}
