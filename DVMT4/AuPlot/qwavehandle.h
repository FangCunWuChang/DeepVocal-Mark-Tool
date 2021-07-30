#ifndef QWAVEHANDLE_H
#define QWAVEHANDLE_H

#include <QObject>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QDialog>



class QWaveHandle
{
public:
    QWaveHandle();
    QWaveHandle(QString name);
    ~QWaveHandle();
    char szRIFFID[4];
    uint32_t uiRIFFsize;
    char szRIFFformat[4];
    char formatID[4];
    uint32_t formatsize;
    uint16_t formattag;
    uint16_t channels;
    uint32_t samplespersec=44100;
    uint32_t avgbytespersec;
    uint16_t blockalign;
    uint16_t bitspersample=16;
    char dataID[4];
    uint32_t datasize;
    QVector<qreal> *wavedataL=new QVector<qreal>;
    QVector<qreal> *wavedataR=new QVector<qreal>;
    ulong datalength;
    bool ReadFile(QString Filename);
    bool WriteFile(QString Filename);
    static bool checkwav(QString Filename,uint16_t channels=1,uint32_t samplespersec=44100,uint16_t bitspersample=16,int size=0,int max=qInf());
    void clear();


    QWaveHandle & operator=(QWaveHandle &data);

private:
protected:

};

#endif // QWAVEHANDLE_H
