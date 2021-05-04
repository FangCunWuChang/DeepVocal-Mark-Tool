#include "qwaveinfo.h"



QWaveInfo::QWaveInfo()
{

}

QWaveInfo::QWaveInfo(QString name)
{
    this->ReadFile(name);
}

QWaveInfo::~QWaveInfo()
{

}

bool QWaveInfo::ReadFile(QString Filename)
{
    if(Filename.isEmpty())
    {
        //QMessageBox::warning(NULL,"出错！","文件名为空！");
        return false;
    }
    QFile file(Filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        //QMessageBox::warning(NULL,"出错！","打开文件："+Filename+"失败！");
        file.close();
        return false;
    }
    QDataStream stream(&file);

#if Q_BYTE_ORDER==Q_LITTLE_ENDIAN
    stream.setByteOrder(QDataStream::LittleEndian);
#else
    stream.setByteOrder(QDataStream::BigEndian);
#endif

    clear();
    stream.readRawData((char *)&szRIFFID,4*sizeof (char));
    if(!((szRIFFID[0]=='R')&&(szRIFFID[1]=='I')&&(szRIFFID[2]=='F')&&(szRIFFID[3]=='F')))
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("是一个")+szRIFFID+("文件，不是一个RIFF文件！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&uiRIFFsize,sizeof (uint32_t));
    stream.readRawData((char *)&szRIFFformat,4*sizeof (char));
    if(!(szRIFFformat[0]=='W'&&szRIFFformat[1]=='A'&&szRIFFformat[2]=='V'&&szRIFFformat[3]=='E'))//
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("是一个")+szRIFFformat+("文件，不是一个WAVE文件！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&formatID,4*sizeof (char));
    if(!((formatID[0]=='f')&&(formatID[1]=='m')&&(formatID[2]=='t')&&(formatID[3]==' ')))
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("有一个")+formatID+("块，没有fmt块！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&formatsize,sizeof (uint32_t));
    stream.readRawData((char *)&formattag,sizeof (uint16_t));
    stream.readRawData((char *)&channels,sizeof (uint16_t));
    stream.readRawData((char *)&samplespersec,sizeof (uint32_t));
    stream.readRawData((char *)&avgbytespersec,sizeof (uint32_t));
    stream.readRawData((char *)&blockalign,sizeof (uint16_t));
    stream.readRawData((char *)&bitspersample,sizeof (uint16_t));
    if(formatsize==18)
    {
        stream.readRawData((char *)NULL,2*sizeof (char));
    }
    stream.readRawData((char *)&dataID,4*sizeof (char));
    if(!((dataID[0]=='d')&&(dataID[1]=='a')&&(dataID[2]=='t')&&(dataID[3]=='a')))
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("有一个")+dataID+("块，没有data块！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&datasize,sizeof (uint32_t));
    if(bitspersample==16)
    {
        if(channels==1){
            datalength=datasize/2;
        }
        else if(channels==2){
            datalength=datasize/2/2;
        }
        else
        {
            //QMessageBox::warning(NULL,("出错！"),Filename+("不支持的轨道数！"));
            file.close();
            return false;
        }

    }
    else if(bitspersample==8)
    {
        if(channels==1){
            datalength=datasize/1;
        }
        else if(channels==2)
        {
            datalength=datasize/1/2;
        }
        else
        {
            //QMessageBox::warning(NULL,("出错！"),Filename+("不支持的轨道数！"));
            file.close();
            return false;
        }
    }
    else
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("比特数未知！"));
        file.close();
        return false;
    }
    file.close();
    return true;
}

void QWaveInfo::clear()
{
}

QWaveInfo & QWaveInfo::operator=(QWaveInfo &data)
{
    this->clear();
    strcpy(this->szRIFFID,data.szRIFFID);
    strcpy(this->szRIFFformat,data.szRIFFformat);
    strcpy(this->formatID,data.formatID);
    strcpy(this->dataID,data.dataID);
    this->uiRIFFsize=data.uiRIFFsize;
    this->formatsize=data.formatsize;
    this->formattag=data.formattag;
    this->channels=data.channels;
    this->samplespersec=data.samplespersec;
    this->avgbytespersec=data.avgbytespersec;
    this->blockalign=data.blockalign;
    this->bitspersample=data.bitspersample;
    this->datasize=data.datasize;
    this->datalength=data.datalength;
    return *this;
}

bool QWaveInfo::checkwav(QString Filename,uint16_t channelst,uint32_t samplespersect,uint16_t bitspersamplet,int size_min,int size_max)
{
    if(Filename.isEmpty())
    {
        //QMessageBox::warning(NULL,"出错！","文件名为空！");
        return false;
    }
    QFile file(Filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        //QMessageBox::warning(NULL,"出错！","打开文件："+Filename+"失败！");
        file.close();
        return false;
    }
    QDataStream stream(&file);

#if Q_BYTE_ORDER==Q_LITTLE_ENDIAN
    stream.setByteOrder(QDataStream::LittleEndian);
#else
    stream.setByteOrder(QDataStream::BigEndian);
#endif

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
    stream.readRawData((char *)&szRIFFID,4*sizeof (char));
    if(!((szRIFFID[0]=='R')&&(szRIFFID[1]=='I')&&(szRIFFID[2]=='F')&&(szRIFFID[3]=='F')))
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("是一个")+szRIFFID+("文件，不是一个RIFF文件！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&uiRIFFsize,sizeof (uint32_t));
    stream.readRawData((char *)&szRIFFformat,4*sizeof (char));
    if(!(szRIFFformat[0]=='W'&&szRIFFformat[1]=='A'&&szRIFFformat[2]=='V'&&szRIFFformat[3]=='E'))//
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("是一个")+szRIFFformat+("文件，不是一个WAVE文件！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&formatID,4*sizeof (char));
    if(!((formatID[0]=='f')&&(formatID[1]=='m')&&(formatID[2]=='t')&&(formatID[3]==' ')))
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("有一个")+formatID+("块，没有fmt块！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&formatsize,sizeof (uint32_t));
    stream.readRawData((char *)&formattag,sizeof (uint16_t));
    stream.readRawData((char *)&channels,sizeof (uint16_t));
    if(channels!=channelst){
        file.close();
        return false;
    }
    stream.readRawData((char *)&samplespersec,sizeof (uint32_t));
    if(samplespersec!=samplespersect){
        file.close();
        return false;
    }
    stream.readRawData((char *)&avgbytespersec,sizeof (uint32_t));
    stream.readRawData((char *)&blockalign,sizeof (uint16_t));
    stream.readRawData((char *)&bitspersample,sizeof (uint16_t));
    if(bitspersample!=bitspersamplet){
        file.close();
        return false;
    }
    if(formatsize==18)
    {
        stream.readRawData((char *)NULL,2*sizeof (char));
    }
    stream.readRawData((char *)&dataID,4*sizeof (char));
    if(!((dataID[0]=='d')&&(dataID[1]=='a')&&(dataID[2]=='t')&&(dataID[3]=='a')))
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("有一个")+dataID+("块，没有data块！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&datasize,sizeof (uint32_t));
    if(bitspersample==16)
    {
        if(channels==1){
            int datalength=datasize/2;
            if(datalength<size_min||datalength>size_max){
                file.close();
                return false;
            }
        }
        else if(channels==2){
            int datalength=datasize/2/2;
            if(datalength<size_min||datalength>size_max){
                file.close();
                return false;
            }
        }
        else
        {
            //QMessageBox::warning(NULL,("出错！"),Filename+("不支持的轨道数！"));
            file.close();
            return false;
        }

    }
    else if(bitspersample==8)
    {
        if(channels==1){
            int datalength=datasize/1;
            if(datalength<size_min||datalength>size_max){
                file.close();
                return false;
            }
        }
        else if(channels==2)
        {
            int datalength=datasize/1/2;
            if(datalength<size_min||datalength>size_max){
                file.close();
                return false;
            }
        }
        else
        {
            //QMessageBox::warning(NULL,("出错！"),Filename+("不支持的轨道数！"));
            file.close();
            return false;
        }
    }
    else
    {
        //QMessageBox::warning(NULL,("出错！"),Filename+("比特数未知！"));
        file.close();
        return false;
    }
    file.close();
    return true;
}
