#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->title,&Title::closeb,this,&MainWindow::oncloseb);
    connect(ui->title,&Title::minb,this,&MainWindow::onminb);
    connect(ui->cen,&Center::retitled,this,&MainWindow::onretitle);
    this->setWindowState(Qt::WindowMaximized);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window);
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

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    this->setWindowState(Qt::WindowMaximized);
    ui->title->resize(width(),0.025*height());
    ui->cen->QWidget::resize(width(),0.975*height());
    ui->title->move(0,0);
    ui->cen->move(0,0.025*height());
}

void MainWindow::oncloseb()
{
    this->close();
}

void MainWindow::onminb()
{
    this->setWindowState(Qt::WindowMinimized);
}

void MainWindow::onretitle(QString title)
{
    this->setWindowTitle(title);
    ui->title->setTitle(title);
}
