#include "qwavehandle.h"



QWaveHandle::QWaveHandle()
{

}

QWaveHandle::QWaveHandle(QString name)
{
    this->ReadFile(name);
}

QWaveHandle::~QWaveHandle()
{

}

bool QWaveHandle::ReadFile(QString Filename)
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
            qint16 temp;
            datalength=datasize/2;
            for(ulong i=0;i<=datalength;i++){
                stream.readRawData((char *)&temp,sizeof (qint16));
                wavedataL->append((qreal)temp/INT16_MAX);
            }
        }
        else if(channels==2){
            qint16 temp;
            datalength=datasize/2/2;
            for(ulong i=0;i<=datalength;i++){
                stream.readRawData((char *)&temp,sizeof (qint16));
                wavedataL->append((qreal)temp/INT16_MAX);
                stream.readRawData((char *)&temp,sizeof (qint16));
                wavedataR->append((qreal)temp/INT16_MAX);
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
            qint8 temp;
            datalength=datasize/1;
            for(ulong i=0;i<=datalength;i++){
                stream.readRawData((char *)&temp,sizeof (qint8));
                wavedataL->append((qreal)temp/INT8_MAX);
            }
        }
        else if(channels==2)
        {
            qint8 temp;
            datalength=datasize/1/2;
            for(ulong i=0;i<=datalength;i++){
                stream.readRawData((char *)&temp,sizeof (qint8));
                wavedataL->append((qreal)temp/INT8_MAX);
                stream.readRawData((char *)&temp,sizeof (qint8));
                wavedataR->append((qreal)temp/INT8_MAX);
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

void QWaveHandle::clear()
{
    wavedataL->clear();
    wavedataR->clear();
}

bool QWaveHandle::WriteFile(QString Filename)
{
    if(Filename.isEmpty())
    {
        //QMessageBox::warning(NULL,("出错！"),("文件名为空！"));
        return false;
    }

    if(QFile::exists(Filename))
    {
        QFile::remove(Filename);
    }
    QFile file(Filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        //QMessageBox::warning(NULL,("出错！"),("打开文件：")+Filename+("失败！"));
        file.close();
        return false;
    }
    QDataStream stream(&file);

#if Q_BYTE_ORDER==Q_LITTLE_ENDIAN
    stream.setByteOrder(QDataStream::LittleEndian);
#else
    stream.setByteOrder(QDataStream::BigEndian);
#endif

    szRIFFID[0]='R';
    szRIFFID[1]='I';
    szRIFFID[2]='F';
    szRIFFID[3]='F';
    szRIFFformat[0]='W';
    szRIFFformat[1]='A';
    szRIFFformat[2]='V';
    szRIFFformat[3]='E';
    formatID[0]='f';
    formatID[1]='m';
    formatID[2]='t';
    formatID[3]=' ';
    formatsize=4*sizeof (uint16_t)+2*sizeof (uint32_t);
    formattag=1;
    if(!wavedataR->isEmpty())
    {
        channels=2;
    }
    else
    {
        channels=1;
    }
    avgbytespersec=(samplespersec*bitspersample*channels)/8;
    blockalign=(bitspersample*channels)/8;
    dataID[0]='d';
    dataID[1]='a';
    dataID[2]='t';
    dataID[3]='a';
    if(bitspersample==16){
        if(channels==1){
            datasize=(wavedataL->size())*sizeof (qint16);
        }else{
            datasize=(wavedataL->size()+wavedataR->size())*sizeof (qint16);
        }

    }else{
        if(channels==1){
            datasize=(wavedataL->size())*sizeof (qint8);
        }else{
            datasize=(wavedataL->size()+wavedataR->size())*sizeof (qint8);
        }
    }

    uiRIFFsize=datasize+12*sizeof (char)+4*sizeof (uint16_t)+4*sizeof (uint32_t);
    stream.writeRawData((char *)&szRIFFID[0],sizeof (char));
    stream.writeRawData((char *)&szRIFFID[1],sizeof (char));
    stream.writeRawData((char *)&szRIFFID[2],sizeof (char));
    stream.writeRawData((char *)&szRIFFID[3],sizeof (char));
    stream.writeRawData((char *)&uiRIFFsize,sizeof (uint32_t));
    stream.writeRawData((char *)&szRIFFformat[0],sizeof (char));
    stream.writeRawData((char *)&szRIFFformat[1],sizeof (char));
    stream.writeRawData((char *)&szRIFFformat[2],sizeof (char));
    stream.writeRawData((char *)&szRIFFformat[3],sizeof (char));
    stream.writeRawData((char *)&formatID[0],sizeof (char));
    stream.writeRawData((char *)&formatID[1],sizeof (char));
    stream.writeRawData((char *)&formatID[2],sizeof (char));
    stream.writeRawData((char *)&formatID[3],sizeof (char));
    stream.writeRawData((char *)&formatsize,sizeof (uint32_t));
    stream.writeRawData((char *)&formattag,sizeof (uint16_t));
    stream.writeRawData((char *)&channels,sizeof (uint16_t));
    stream.writeRawData((char *)&samplespersec,sizeof (uint32_t));
    stream.writeRawData((char *)&avgbytespersec,sizeof (uint32_t));
    stream.writeRawData((char *)&blockalign,sizeof (uint16_t));
    stream.writeRawData((char *)&bitspersample,sizeof (uint16_t));
    stream.writeRawData((char *)&dataID[0],sizeof (char));
    stream.writeRawData((char *)&dataID[1],sizeof (char));
    stream.writeRawData((char *)&dataID[2],sizeof (char));
    stream.writeRawData((char *)&dataID[3],sizeof (char));
    stream.writeRawData((char *)&datasize,sizeof (uint32_t));
    if(bitspersample==16)
    {
        if(channels==1){
            qint16 temp;
            datalength=wavedataL->size();
            for(ulong i=0;i<datalength;i++){
                temp=wavedataL->at(i)*INT16_MAX;
                stream.writeRawData((char *)&temp,sizeof (qint16));
            }
        }
        else if(channels==2){
            qint16 temp;
            datalength=wavedataL->size();
            for(ulong i=0;i<datalength;i++){
                temp=wavedataL->at(i)*INT16_MAX;
                stream.writeRawData((char *)&temp,sizeof (qint16));
                temp=wavedataR->at(i)*INT16_MAX;
                stream.writeRawData((char *)&temp,sizeof (qint16));
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
            qint8 temp;
            datalength=wavedataL->size();
            for(ulong i=0;i<datalength;i++){
                temp=wavedataL->at(i)*INT8_MAX;
                stream.writeRawData((char *)&temp,sizeof (qint8));
            }
        }
        else if(channels==2)
        {
            qint8 temp;
            datalength=wavedataL->size();
            for(ulong i=0;i<datalength;i++){
                temp=wavedataL->at(i)*INT8_MAX;
                stream.writeRawData((char *)&temp,sizeof (qint8));
                temp=wavedataR->at(i)*INT8_MAX;
                stream.writeRawData((char *)&temp,sizeof (qint8));
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

QWaveHandle & QWaveHandle::operator=(QWaveHandle &data)
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
    *this->wavedataL=*data.wavedataL;
    *this->wavedataR=*data.wavedataR;
    return data;
}

bool QWaveHandle::checkwav(QString Filename,uint16_t channelst,uint32_t samplespersect,uint16_t bitspersamplet,int sizet)
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
            if(datalength<sizet){
                file.close();
                return false;
            }
        }
        else if(channels==2){
            int datalength=datasize/2/2;
            if(datalength<sizet){
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
            if(datalength<sizet){
                file.close();
                return false;
            }
        }
        else if(channels==2)
        {
            int datalength=datasize/1/2;
            if(datalength<sizet){
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
