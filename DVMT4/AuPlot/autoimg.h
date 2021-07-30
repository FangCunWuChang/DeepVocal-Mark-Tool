#ifndef AUTOIMG_H
#define AUTOIMG_H

#include <QImage>
#include <QFile>
#include <QColor>
#include <QDir>
#include <QDataStream>
#include <QtMath>
#include <QFileInfo>
#include <QCoreApplication>
#include <QUrl>
#include <QDebug>

class AutoImg
{
public:
    AutoImg();
    AutoImg(int w,int h,QImage::Format format=QImage::Format_RGB16);
    ~AutoImg();
    void setsize(int w,int h);
    void draw(int x,int y,QColor color);
    void setimage(QImage *image);
    QImage image();
    QImage get(int sx,int sy,int sw,int sh,int pw,int ph);
    void clear();
    void resize(int w,int h);
    void scaled(int w,int h);
    int width();
    int height();
    void fill(QColor color);
    void fill();
    int __test_getid();
    int __test_getpart();
    QImage::Format __test_getformat();
    QColor __test_getbackgroundcolor();
    QImage __test_gettemp(int x,int y);
    AutoImg& operator=(const AutoImg& arg);
private:
    int id=0;
    int w=0,h=0;
    QImage::Format format=QImage::Format_RGB16;
    int px=0,py=0;
    QImage currentImg;
    const int part=1000;
    const QColor backgroundcolor=Qt::black;
protected:
    bool prepareimag(int x,int y);
    void savetemp();
    void imagcopy(QImage *source,QImage *objective,int xpos,int ypos);
    bool removetempfile(int x,int y);
    QImage readtempfile(int x,int y);
    bool createtempfile(int x,int y,int w,int h);
    bool savetempfile(int x,int y,QImage image);
    bool removetempfile2(int x,int y);
    QImage readtempfile2(int x,int y);
    bool createtempfile2(int x,int y,int w,int h);
    bool savetempfile2(int x,int y,QImage image);
    bool untemp2(int xcn,int ycn,int xco,int yco);
};

#endif // AUTOIMG_H
