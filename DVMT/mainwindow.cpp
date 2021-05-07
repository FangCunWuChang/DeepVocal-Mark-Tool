#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(ui->cen->wannaclose()){
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if((event->mimeData()->urls().size()==1)&&(!event->mimeData()->urls()[0].fileName().right(5).compare("dvmtp"))){
        event->acceptProposedAction();
    }else{
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasUrls()){
        QList<QUrl> urls = mimeData->urls();
        QString fileName = urls.at(0).toLocalFile();
        ui->cen->openfile(fileName);
    }
}

void MainWindow::openfile(QString filename)
{
    ui->cen->openfile(filename);
}
