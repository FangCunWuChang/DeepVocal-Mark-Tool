#include "egg.h"
#include "ui_egg.h"

Egg::Egg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Egg)
{
    ui->setupUi(this);
}

Egg::~Egg()
{
    delete ui;
}

void Egg::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(0,0,0,200));
    QPen pen;
    QBrush brush;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    QFont font;
    font.setPointSize(height()*0.02);
    painter.setFont(font);

    painter.drawText(0.05*width(),0.15*height(),"这是一个Bug!!!输入\"#close\"关掉这个Bug!!!");

    pen.setColor(Qt::green);
    painter.setPen(pen);
    font.setPointSize(height()*0.015);
    painter.setFont(font);


    int count_l=1;
    painter.drawText(0.05*width(),0.2*height(),"DeepVocal Mark Tool");
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"版本号："+QString(DVMT_VERSION));
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"编译时间："+QString(__DATE__)+" "+QString(__TIME__));
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"AuPlot版本："+QString(AU_VERSION));
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"Qt版本："+QString(qVersion()));
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"开源许可："+QString(DVMT_LICENSE));
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"github：https://github.com/FangCunWuChang/DeepVocal-Mark-Tool");
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"bilibili主页：https://space.bilibili.com/161161623");
    count_l++;

    pen.setColor(Qt::yellow);
    painter.setPen(pen);
    font.setPointSize(height()*0.015);
    painter.setFont(font);

    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"一些指令：");
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"#license - 显示许可协议");
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"#thanks - 显示致谢");
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"#qt - 关于Qt");
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"#infinity - 关于Infinity项目");
    count_l++;

    pen.setColor(QColor(255,0,255));
    painter.setPen(pen);
    font.setPointSize(height()*0.015);
    painter.setFont(font);

    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"一些测试功能：");
    count_l++;
    painter.drawText(0.05*width(),0.2*height()+count_l*height()*0.015+count_l*height()*0.005,"暂无测试功能");
    count_l++;

    QWidget::paintEvent(event);
}

void Egg::resizeEvent(QResizeEvent *event)
{
    ui->line->resize(0.6*width(),0.05*height());
    ui->line->move(0.2*width(),0.05*height());
    QWidget::resizeEvent(event);
}

void Egg::on_line_textChanged(const QString &arg1)
{
    /*
    if(arg1.count()>300){
        throw "Line too long";
    }*/
    if(((arg1.contains("HB",Qt::CaseInsensitive)||arg1.contains("Happy Birthday",Qt::CaseInsensitive)||arg1.contains("生贺",Qt::CaseInsensitive)||arg1.contains("生日快乐",Qt::CaseInsensitive))&&(arg1.contains("休休",Qt::CaseInsensitive)))||(arg1.contains("愁杀人来关月事",Qt::CaseInsensitive)&&arg1.contains("得休休处且休休",Qt::CaseInsensitive))){
        ui->line->clear();
        QMessageBox::information(this,"HB to 休休","休休：\n生日快乐啊。\n因为我之前从来没有给人祝贺过生日，所以我也不知道生日祝贺该说些什么。所以到了最后我就决定用最简单的一句“生日快乐”来祝贺你的生日。我把这句话留在这里，长久的留在这里，也会是永远的留在这里。\n生日快乐啊，休休。");
    }else if(arg1.contains("wuchang",Qt::CaseInsensitive)){
        ui->line->clear();
        QMessageBox::warning(this,"Enn...?","What are you doing?");
    }else if(arg1.contains("wu chang",Qt::CaseInsensitive)){
        ui->line->clear();
        QMessageBox::warning(this,"Arr...?","What are you doing?");
    }else if(arg1.contains("無常",Qt::CaseInsensitive)){
        ui->line->clear();
        QMessageBox::warning(this,"嗯？","你要做些什么？你不对劲！");
    }else if(arg1.contains("deepvocal",Qt::CaseInsensitive)){
        ui->line->clear();
        QMessageBox::warning(this,"啊这","今天又是等待DV2发布的一天呢。\nDV2已经发了！（后来补）");
    }else if(arg1.contains("Boxstar",Qt::CaseInsensitive)||arg1.contains("老盒",Qt::CaseInsensitive)){
        ui->line->clear();
        QMessageBox::warning(this,"哦","老盒yyds!!!");
    }else if(arg1=="#close"){
        ui->line->clear();
        this->close();
    }else if(arg1=="#qt"){
        ui->line->clear();
        QMessageBox::aboutQt(this,"关于Qt");
    }else if(arg1=="#license"){
        ui->line->clear();
        QFile file(":/text/license.GPLv3");
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QString text=file.readAll();
        file.close();
        GPL gpl(this);
        gpl.settext(text);
        gpl.exec();
    }else if(arg1=="#thanks"){
        ui->line->clear();
        QMessageBox::information(this,"鸣谢","感谢以下人员为DVMT的开发做出的贡献：\nAmamiya_Karin  魔凤啸天\n感谢中科院长春光机所在捐赠给东师附中测量体温的电脑上安装的Qt为DVMT提供了开发工具。\n感谢东北师范大学附属中学提供了一个零下十多度且只能站着的开发场地让我头脑清醒的设计算法。\n感谢学生处彭主任、马老师尽管多次说要对我不客气但并没有真的对我不客气。\n感谢所有参加了早期测试的用户们使DVMT不断变得更加优秀。");
    }else if(arg1=="#infinity"){
        ui->line->clear();
        QMessageBox::information(this,"关于Infinity项目","Infinity项目是由無常发起的一项以开放为主旨的歌声合成项目。\n更多信息详见项目官网：https://infinityproject.azurewebsites.net");
    }else{

    }


}
