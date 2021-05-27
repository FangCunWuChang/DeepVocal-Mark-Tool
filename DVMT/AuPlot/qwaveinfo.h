#ifndef QWaveInfo_H
#define QWaveInfo_H

#include <QObject>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QDialog>



class QWaveInfo
{
public:
    QWaveInfo();
    QWaveInfo(QString name);
    ~QWaveInfo();
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
    ulong datalength;
    bool ReadFile(QString Filename);
    static bool checkwav(QString Filename,uint16_t channels=1,uint32_t samplespersec=44100,uint16_t bitspersample=16,int size_min=0,int size_max=20*44100);
    void clear();


    QWaveInfo & operator=(QWaveInfo &data);

private:
protected:

};

#endif // QWaveInfo_H
