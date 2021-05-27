#ifndef AUMATHLIB_H
#define AUMATHLIB_H

#include <QObject>
#include <QtMath>
#include <QVector>
#include "iplot.h"
#include "global.h"

class AuMathLib
{
public:
    AuMathLib();
    AuMathLib(QVector<double> data);
    void setdata(QVector<double> data);
    QVector<double> getdata();
    QVector<double> acf(double acfcut=0.3);
    static QVector<double> acf(QVector<double> data,double acfcut=0.3);
    double fre(int FS=44100,double filter=0.2);
    static double fre(QVector<double> data,int FS=44100,double filter=0.2);
    double ene();
    static double ene(QVector<double> data);
    double rptz();
    static double rptz(QVector<double> data);
    static void fft(QVector<double> *real,QVector<double> *imag=new QVector<double>);
    static void ifft(QVector<double> *real,QVector<double> *imag=new QVector<double>);
    QVector<double> ime();
    static QVector<double> ime(QVector<double> data);
    QVector<double> amp();
    static QVector<double> amp(QVector<double> data);
    static QVector<double> imelog(QVector<double> data);
    static QVector<double> imelogplus(QVector<double> data);
    static QVector<double> hanning(QVector<double> data);
    static QVector<double> GetFs(QVector<double> data,int FS=44100);
private:
    QVector<double> data;
    static int signfunction(double x);
    inline static void swap(double *a,double *b);
    static void bitrp(QVector<double> *real,QVector<double> *imag=new QVector<double>);
    constexpr static double pi=3.141592653589793238462643383279502884197169399;
    inline static bool if2_n(int n);
    inline static double Hann(int n,int N);
};

#endif // AUMATHLIB_H
