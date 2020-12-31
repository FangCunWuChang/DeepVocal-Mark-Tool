#include "aumathlib.h"

AuMathLib::AuMathLib()
{
#ifdef DEBUG_MODE
    int xxx=0;
    if(AuMathLib::if2_n(xxx)){
        qDebug("true");
    }else{
        qDebug("false");
    }
#endif
}

AuMathLib::AuMathLib(QVector<double> data)
{
    this->data=data;
}

void AuMathLib::setdata(QVector<double> data)
{
    this->data=data;
}

QVector<double> AuMathLib::getdata()
{
    return data;
}

QVector<double> AuMathLib::acf(double acfcut)
{
    int K=data.size()*acfcut;
    QVector<qreal> out;
    int N=data.size();
    double E0=0;
    for(int i=0;i<=N-K;i++)
    {
        E0=E0+data.at(i)*data.at(i);
    }
    for(int i=0;i<K;i++)
    {
        double sigma=0;
        for(int j=0;j<=N-1-K;j++)
        {
            sigma=sigma+(data.at(j)*data.at(j+i));
        }
        double E=0;
        for(int j=i;j<=i+N-K;j++)
        {
            E=E+data.at(j)*data.at(j);
        }
        out.append(sigma/sqrt(E0*E));
    }
    return out;
}

QVector<double> AuMathLib::acf(QVector<double> data,double acfcut)
{
    int K=data.size()*acfcut;
    QVector<qreal> out;
    int N=data.size();
    double E0=0;
    for(int i=0;i<=N-K;i++)
    {
        E0=E0+data.at(i)*data.at(i);
    }
    for(int i=0;i<K;i++)
    {
        double sigma=0;
        for(int j=0;j<=N-1-K;j++)
        {
            sigma=sigma+(data.at(j)*data.at(j+i));
        }
        double E=0;
        for(int j=i;j<=i+N-K;j++)
        {
            E=E+data.at(j)*data.at(j);
        }
        out.append(sigma/sqrt(E0*E));
    }
    return out;
}

double AuMathLib::fre(int FS,double cut)
{
    Q_UNUSED(cut);
    if(data.isEmpty()){
        return 0;
    }
    QVector<double> dacf=acf();
    /*
    int flag=0;
    for(int i=1;i<dacf.size()-1;i++){
        if(dacf.at(i-1)>=filter&&dacf.at(i)>=filter&&dacf.at(i+1)>=filter){
            if(dacf.at(i)>dacf.at(i-1)&&dacf.at(i)>=dacf.at(i+1)){
                flag=i;
            }
        }
    }
    return 1/(static_cast<double>(flag)*(1/FS));

    int len=dacf.size();
    QVector<qreal> dataca;
    for (int i=0;i<len;i++)
        {
            if(dacf.at(i)>cut)
            {
                dataca.append(dacf.at(i));
            }
            else

            {
                dataca.append(-1);
            }
        }
        int af=0;
        int rf=0;
        int flag=0;
        for (int i=0;i<len;i++)
        {
            if(dataca.at(i)!=-1&&flag==0)
            {
            }
            else if (dataca.at(i)==-1&&flag==0)
            {
                flag=1;
            }
            else if(dataca.at(i)!=-1&&flag==1)
            {
                af=i;
                flag=2;
            }
            else if(dataca.at(i)!=-1&&flag==2)
            {
            }
            else if(dataca.at(i)==-1&&flag==2)
            {
                rf=i;
                break;
            }
            else
            {

            }
        }
        double maxn=0;
        for (int i=af;i<rf;i++)
        {
            maxn=qMax(dataca.at(i),maxn);
        }
        int out=0;
        for (int i=af;i<rf;i++)
        {
            if(dataca.at(i)==maxn)
            {
                out=i;
            }
        }
        double outt=1/((double)out/(double)FS);
        return outt;*/
    double maxn=0;
    int cf=0;
    for(int i=1,flag=0;i<dacf.size()-1;i++){
        if(flag==0){
            if((dacf.at(i)<dacf.at(i-1))&&(dacf.at(i)<=dacf.at(i+1))){
                flag=1;
                cf=i;
            }
        }else{
            maxn=qMax(maxn,dacf.at(i));
        }
    }
    int mf=0;
    for(int i=cf;i<dacf.size();i++){
        if(dacf.at(i)==maxn){
            mf=i;
            break;
        }
    }
    double outt=1/((double)mf/(double)FS);
    return outt;
}

double AuMathLib::fre(QVector<double> data,int FS,double cut)
{
    Q_UNUSED(cut);
    if(data.isEmpty()){
        return 0;
    }
    QVector<double> dacf=AuMathLib::acf(data);
    /*
    int flag=0;
    for(int i=1;i<dacf.size()-1;i++){
        if(dacf.at(i-1)>=filter&&dacf.at(i)>=filter&&dacf.at(i+1)>=filter){
            if(dacf.at(i)>dacf.at(i-1)&&dacf.at(i)>=dacf.at(i+1)){
                flag=i;
            }
        }
    }
    qDebug("fre:%.2f",1/(static_cast<double>(flag)*(1/FS)));
    return 1/(static_cast<double>(flag)*(1/FS));

    int len=dacf.size();
    QVector<qreal> dataca;
    for (int i=0;i<len;i++)
        {
            if(dacf.at(i)>cut)
            {
                dataca.append(dacf.at(i));
            }
            else

            {
                dataca.append(-1);
            }
        }
        int af=0;
        int rf=0;
        int flag=0;
        for (int i=0;i<len;i++)
        {
            if(dataca.at(i)!=-1&&flag==0)
            {
            }
            else if (dataca.at(i)==-1&&flag==0)
            {
                flag=1;
            }
            else if(dataca.at(i)!=-1&&flag==1)
            {
                af=i;
                flag=2;
            }
            else if(dataca.at(i)!=-1&&flag==2)
            {
            }
            else if(dataca.at(i)==-1&&flag==2)
            {
                rf=i;
                break;
            }
            else
            {

            }
        }
        double maxn=0;
        for (int i=af;i<rf;i++)
        {
            maxn=qMax(dataca.at(i),maxn);
        }
        int out=0;
        for (int i=af;i<rf;i++)
        {
            if(dataca.at(i)==maxn)
            {
                out=i;
            }
        }
        double outt=1/((double)out/(double)FS);
        return outt;
        */
    double maxn=0;
    int cf=0;
    for(int i=1,flag=0;i<dacf.size()-1;i++){
        if(flag==0){
            if((dacf.at(i)<dacf.at(i-1))&&(dacf.at(i)<=dacf.at(i+1))){
                flag=1;
                cf=i;
            }
        }else{
            maxn=qMax(maxn,dacf.at(i));
        }
    }
    int mf=0;
    for(int i=cf;i<dacf.size();i++){
        if(dacf.at(i)==maxn){
            mf=i;
            break;
        }
    }
    double outt=1/((double)mf/(double)FS);
    return outt;
}

double AuMathLib::ene()
{
    if(data.isEmpty()){
        return 0;
    }
    double sigma=0;
    for(int i=0;i<data.size();i++){
        //sigma+=data.at(i)*data.at(i);
        sigma+=abs(data.at(i));
    }
    return static_cast<double>(sigma/data.size());
}

double AuMathLib::ene(QVector<double> data)
{
    if(data.isEmpty()){
        return 0;
    }
    double sigma=0;
    for(int i=0;i<data.size();i++){
        //sigma+=data.at(i)*data.at(i);
        sigma+=abs(data.at(i));
    }
    return static_cast<double>(sigma/data.size());
}

double AuMathLib::rptz()
{
    if(data.isEmpty()){
        return 0;
    }
    double sigma=0;
    for(int i=0;i<data.size()-1;i++){
        sigma+=qAbs(qAbs(signfunction(data.at(i)))-qAbs(signfunction(data.at(i+1))));
    }
    sigma/=data.size();
    return sigma;
}

double AuMathLib::rptz(QVector<double> data)
{
    if(data.isEmpty()){
        return 0;
    }
    double sigma=0;
    for(int i=0;i<data.size()-1;i++){
        sigma+=qAbs(qAbs(signfunction(data.at(i)))-qAbs(signfunction(data.at(i+1))));
    }
    sigma/=data.size();
    return sigma;
}

int AuMathLib::signfunction(double x)
{
    if(x>0){
        return 1;
    }else{
        return 0;
    }
}

void AuMathLib::swap(double *a,double *b)
{
    double t=*b;
    *b=*a;
    *a=t;
}

void AuMathLib::bitrp(QVector<double> *real,QVector<double> *imag)
{
    if(imag->size()!=real->size()){
        imag->resize(real->size());
    }
    int i=0,j=0,a=0,b=0,p=0;
    int n=real->size();
    if(!if2_n(n)){
        throw "Error_if2^n";
        return;
    }
    for(i=1,p=0;i<n;i*=2){
        p++;
    }
    for(i=0;i<n;i++){
        a=i;
        b=0;
        for(j=0;j<p;j++){
            b=(b<<1)+(a&1);
            a>>=1;
        }
        if(b>i){
            real->swapItemsAt(i,b);
            imag->swapItemsAt(i,b);
        }
    }
}

void AuMathLib::fft(QVector<double> *real,QVector<double> *imag)
{
    if(imag->size()!=real->size()){
        imag->resize(real->size());
    }
    int n=real->size();
    if(!if2_n(n)){
        throw "Error_if2^n";
        return;
    }
    QVector<double> *wreal=new QVector<double>,*wimag=new QVector<double>;
    wreal->resize(n/2);
    wimag->resize(n/2);
    double treal=0,timag=0,ureal=0,uimag=0,arg=0;
    int m=0,k=0,j=0,t=0,index1=0,index2=0;
    bitrp(real,imag);
    arg=-2*pi/n;
    treal=cos(arg);
    timag=sin(arg);
    wreal->replace(0,1);
    wimag->replace(0,0);
    for(j=1;j<n/2;j++){
        wreal->replace(j,wreal->at(j-1)*treal-wimag->at(j-1)*timag);
        wimag->replace(j,wreal->at(j-1)*timag+wimag->at(j-1)*treal);
    }
    for(m=2;m<=n;m*=2){
        for(k=0;k<n;k+=m){
            for(j=0;j<m/2;j++){
                index1=k+j;
                index2=index1+m/2;
                t=n*j/m;
                treal=wreal->at(t)*real->at(index2)-wimag->at(t)*imag->at(index2);
                timag=wreal->at(t)*imag->at(index2)+wimag->at(t)*real->at(index2);
                ureal=real->at(index1);
                uimag=imag->at(index1);
                real->replace(index1,ureal+treal);
                imag->replace(index1,uimag+timag);
                real->replace(index2,ureal-treal);
                imag->replace(index2,uimag-timag);
            }
        }
    }
}

void AuMathLib::ifft(QVector<double> *real,QVector<double> *imag)
{
    if(imag->size()!=real->size()){
        imag->resize(real->size());
    }
    int n=real->size();
    if(!if2_n(n)){
        throw "Error_if2^n";
        return;
    }
    QVector<double> *wreal=new QVector<double>,*wimag=new QVector<double>;
    wreal->resize(n/2);
    wimag->resize(n/2);
    double treal=0,timag=0,ureal=0,uimag=0,arg=0;
    int m=0,k=0,j=0,t=0,index1=0,index2=0;
    bitrp(real,imag);
    arg=2*pi/n;
    treal=cos(arg);
    timag=sin(arg);
    wreal->replace(0,1);
    wimag->replace(0,0);
    for(j=1;j<n/2;j++){
        wreal->replace(j,wreal->at(j-1)*treal-wimag->at(j-1)*timag);
        wimag->replace(j,wreal->at(j-1)*timag+wimag->at(j-1)*treal);
    }
    for(m=2;m<=n;m*=2){
        for(k=0;k<n;k+=m){
            for(j=0;j<m/2;j++){
                index1=k+j;
                index2=index1+m/2;
                t=n*j/m;
                treal=wreal->at(t)*real->at(index2)-wimag->at(t)*imag->at(index2);
                timag=wreal->at(t)*imag->at(index2)+wimag->at(t)*real->at(index2);
                ureal=real->at(index1);
                uimag=imag->at(index1);
                real->replace(index1,ureal+treal);
                imag->replace(index1,uimag+timag);
                real->replace(index2,ureal-treal);
                imag->replace(index2,uimag-timag);
            }
        }
    }
    for(j=0;j<n;j++){
        real->replace(j,real->at(j)/n);
        imag->replace(j,imag->at(j)/n);
    }
}

bool AuMathLib::if2_n(int n)
{
    if(n<=0){
        return false;
    }
    int ct=0;
    int xx=n;
    for(int i=0;i<32;i++){
        ct+=xx&1;
        xx>>=1;
        if(ct>=2)
        {
            return false;
        }
    }return true;
}

QVector<double> AuMathLib::ime()
{
    if(!if2_n(data.size())){
        throw "Error_if2^n";
    }
    QVector<double> *real=new QVector<double>,*imag=new QVector<double>;
    for(int i=0;i<data.size();i++){
        real->append(data.at(i));
        imag->append(0);
    }
    fft(real,imag);
    QVector<double> out;
    for(int i=0;i<data.size()/2;i++){
        if(i==0){
            out.append(qSqrt(real->at(i)*real->at(i)+imag->at(i)*imag->at(i))/data.size());
        }else{
            out.append(qSqrt(real->at(i)*real->at(i)+imag->at(i)*imag->at(i))*2/data.size());
        }
    }
    return out;
}

QVector<double> AuMathLib::ime(QVector<double> data)
{
    if(!if2_n(data.size())){
        throw "Error_if2^n";
    }
    QVector<double> *real=new QVector<double>,*imag=new QVector<double>;
    for(int i=0;i<data.size();i++){
        real->append(data.at(i));
        imag->append(0);
    }
    fft(real,imag);
    QVector<double> out;
    for(int i=0;i<data.size()/2;i++){
        if(i==0){
            out.append(qSqrt(real->at(i)*real->at(i)+imag->at(i)*imag->at(i))/data.size());
        }else{
            out.append(qSqrt(real->at(i)*real->at(i)+imag->at(i)*imag->at(i))*2/data.size());
        }
    }
    return out;
}

QVector<double> AuMathLib::amp()
{
    if(!if2_n(data.size())){
        throw "Error_if2^n";
    }
    QVector<double> *real=new QVector<double>,*imag=new QVector<double>;
    for(int i=0;i<data.size();i++){
        real->append(data.at(i));
        imag->append(0);
    }
    fft(real,imag);
    QVector<double> out;
    for(int i=0;i<data.size()/2;i++){
        out.append(tanh(imag->at(i)/real->at(i)));
    }
    return out;
}

QVector<double> AuMathLib::amp(QVector<double> data)
{
    if(!if2_n(data.size())){
        throw "Error_if2^n";
    }
    QVector<double> *real=new QVector<double>,*imag=new QVector<double>;
    for(int i=0;i<data.size();i++){
        real->append(data.at(i));
        imag->append(0);
    }
    fft(real,imag);
    QVector<double> out;
    for(int i=0;i<data.size()/2;i++){
        out.append(tanh(imag->at(i)/real->at(i)));
    }
    return out;
}

QVector<double> AuMathLib::imelog(QVector<double> data)
{
    QVector<double> out;
    QVector<double> temp=AuMathLib::ime(data);
    for(int i=0;i<data.size()/2;i++){
        out.append(20*log10(temp.at(i)));
    }
    return out;
}

QVector<double> AuMathLib::hanning(QVector<double> data)
{
    QVector<double> out;
    int N=data.size();
    for(int i=0;i<N;i++){
        out.append((double)((double)data.at(i)*(double)Hann(i+(double)((double)(N-1)/(double)2),N)));
    }
    return out;
}

double AuMathLib::Hann(int n,int N)
{
    //qDebug("Hann:%.3f",(double)(1+cos(2*pi*(double)((double)n/(double)(N-1))))/2);
    return (double)(1+cos(2*pi*(double)((double)n/(double)(N-1))))/2;
}

QVector<double> AuMathLib::imelogplus(QVector<double> data)
{
    QVector<double> out;
    QVector<double> temp=AuMathLib::ime(data);
    for(int i=0;i<data.size()/2;i++){
        out.append(20*log10(temp.at(i)-temp.at(0)));
    }
    return out;
}

QVector<double> AuMathLib::GetFs(QVector<double> data,int FS)
{
    QVector<double> out;
    out.resize(4);
    int flag=0;
    for(int i=1;i<data.size()-1;i++){
        if(data.at(i)>=data.at(i-1)&&data.at(i+1)<data.at(i)){
            if(flag<4){
                out.replace(flag,(double)((double)i*(double)((double)FS/(double)global::sets::step)));
                flag++;
            }else{
                break;
            }

        }
    }
    return out;
}
