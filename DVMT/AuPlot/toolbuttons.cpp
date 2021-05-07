#include "toolbuttons.h"
#include "ui_toolbuttons.h"

ToolButtons::ToolButtons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolButtons)
{
    ui->setupUi(this);
    ui->b1->setMinimumHeight(height()*0.8);
    ui->b2->setMinimumHeight(height()*0.8);
    ui->b4->setMinimumHeight(height()*0.8);
    ui->b5->setMinimumHeight(height()*0.8);
    ui->b6->setMinimumHeight(height()*0.8);
    ui->b7->setMinimumHeight(height()*0.8);
    ui->b8->setMinimumHeight(height()*0.8);
    ui->b9->setMinimumHeight(height()*0.8);
    ui->b10->setMinimumHeight(height()*0.8);
    ui->b11->setMinimumHeight(height()*0.8);
    ui->b12->setMinimumHeight(height()*0.8);
    ui->b1->resize(ui->b1->width(),height()*0.8);
    ui->b2->resize(ui->b2->width(),height()*0.8);
    ui->b4->resize(ui->b4->width(),height()*0.8);
    ui->b5->resize(ui->b5->width(),height()*0.8);
    ui->b6->resize(ui->b6->width(),height()*0.8);
    ui->b7->resize(ui->b7->width(),height()*0.8);
    ui->b8->resize(ui->b8->width(),height()*0.8);
    ui->b9->resize(ui->b9->width(),height()*0.8);
    ui->b10->resize(ui->b10->width(),height()*0.8);
    ui->b11->resize(ui->b11->width(),height()*0.8);
    ui->b12->resize(ui->b12->width(),height()*0.8);
    ui->b1->move(ui->b1->geometry().x(),height()*0.1);
    ui->b2->move(ui->b2->geometry().x(),height()*0.1);
    ui->b4->move(ui->b4->geometry().x(),height()*0.1);
    ui->b5->move(ui->b5->geometry().x(),height()*0.1);
    ui->b6->move(ui->b6->geometry().x(),height()*0.1);
    ui->b7->move(ui->b7->geometry().x(),height()*0.1);
    ui->b8->move(ui->b8->geometry().x(),height()*0.1);
    ui->b9->move(ui->b9->geometry().x(),height()*0.1);
    ui->b10->move(ui->b10->geometry().x(),height()*0.1);
    ui->b11->move(ui->b11->geometry().x(),height()*0.1);
    ui->b12->move(ui->b12->geometry().x(),height()*0.1);
}

ToolButtons::~ToolButtons()
{
    delete ui;
}

void ToolButtons::on_b1_clicked(bool checked)
{
    emit control(1+checked);
}

void ToolButtons::on_b2_clicked(bool checked)
{
    emit control(3+checked);
}

void ToolButtons::on_b4_clicked()
{
    emit control(0);
}

void ToolButtons::on_b5_clicked()
{
    emit control(-1);
}

void ToolButtons::on_b6_clicked(bool checked)
{

    if(checked){
        ui->b6->setText("停止");
    }else{
        ui->b6->setText("播放");
    }
    emit plotplay(checked);
}

void ToolButtons::setplay(bool play)
{
    if(play!=ui->b6->isChecked()){
        if(play){
            ui->b6->setChecked(true);
            ui->b6->setText("停止");
        }else{
            ui->b6->setChecked(false);
            ui->b6->setText("播放");
        }
    }

}

void ToolButtons::setcanplay(bool can)
{
    ui->b6->setEnabled(can);
}

void ToolButtons::resizeEvent(QResizeEvent *event)
{
    ui->b1->setMinimumHeight(height()*0.8);
    ui->b2->setMinimumHeight(height()*0.8);
    ui->b4->setMinimumHeight(height()*0.8);
    ui->b5->setMinimumHeight(height()*0.8);
    ui->b6->setMinimumHeight(height()*0.8);
    ui->b7->setMinimumHeight(height()*0.8);
    ui->b8->setMinimumHeight(height()*0.8);
    ui->b9->setMinimumHeight(height()*0.8);
    ui->b10->setMinimumHeight(height()*0.8);
    ui->b11->setMinimumHeight(height()*0.8);
    ui->b12->setMinimumHeight(height()*0.8);
    ui->b1->resize(ui->b1->width(),height()*0.8);
    ui->b2->resize(ui->b2->width(),height()*0.8);
    ui->b4->resize(ui->b4->width(),height()*0.8);
    ui->b5->resize(ui->b5->width(),height()*0.8);
    ui->b6->resize(ui->b6->width(),height()*0.8);
    ui->b7->resize(ui->b7->width(),height()*0.8);
    ui->b8->resize(ui->b8->width(),height()*0.8);
    ui->b9->resize(ui->b9->width(),height()*0.8);
    ui->b10->resize(ui->b10->width(),height()*0.8);
    ui->b11->resize(ui->b11->width(),height()*0.8);
    ui->b12->resize(ui->b12->width(),height()*0.8);
    ui->b1->move(ui->b1->geometry().x(),height()*0.1);
    ui->b2->move(ui->b2->geometry().x(),height()*0.1);
    ui->b4->move(ui->b4->geometry().x(),height()*0.1);
    ui->b5->move(ui->b5->geometry().x(),height()*0.1);
    ui->b6->move(ui->b6->geometry().x(),height()*0.1);
    ui->b7->move(ui->b7->geometry().x(),height()*0.1);
    ui->b8->move(ui->b8->geometry().x(),height()*0.1);
    ui->b9->move(ui->b9->geometry().x(),height()*0.1);
    ui->b10->move(ui->b10->geometry().x(),height()*0.1);
    ui->b11->move(ui->b11->geometry().x(),height()*0.1);
    ui->b12->move(ui->b12->geometry().x(),height()*0.1);
    QWidget::resizeEvent(event);
}

void ToolButtons::on_b7_clicked(bool checked)
{
    this->Auto=checked;
}

void ToolButtons::setfourlines(bool fourlines)
{
    this->fourlines=fourlines;
    ui->b8->setChecked(true);
    ui->b9->setChecked(false);
    ui->b10->setChecked(false);
    ui->b11->setChecked(false);
    emit linechanged(1);
    if(fourlines){
        ui->b8->setEnabled(true);
        ui->b9->setEnabled(true);
        ui->b10->setEnabled(true);
        ui->b11->setEnabled(true);
    }else{
        ui->b8->setEnabled(true);
        ui->b9->setEnabled(true);
        ui->b10->setEnabled(false);
        ui->b11->setEnabled(false);
    }
}

void ToolButtons::setcansave(bool can)
{
    ui->b12->setEnabled(can);
}

void ToolButtons::on_b8_clicked()
{
    ui->b8->setChecked(true);
    ui->b9->setChecked(false);
    ui->b10->setChecked(false);
    ui->b11->setChecked(false);
    emit linechanged(1);
}

void ToolButtons::on_b9_clicked()
{
    ui->b8->setChecked(false);
    ui->b9->setChecked(true);
    ui->b10->setChecked(false);
    ui->b11->setChecked(false);
    emit linechanged(2);
}

void ToolButtons::on_b10_clicked()
{
    ui->b8->setChecked(false);
    ui->b9->setChecked(false);
    ui->b10->setChecked(true);
    ui->b11->setChecked(false);
    emit linechanged(3);
}

void ToolButtons::on_b11_clicked()
{
    ui->b8->setChecked(false);
    ui->b9->setChecked(false);
    ui->b10->setChecked(false);
    ui->b11->setChecked(true);
    emit linechanged(4);
}

void ToolButtons::on_b12_clicked()
{
    emit saved();
}

void ToolButtons::wannachangeline()
{
    if(Auto){
        if(ui->b8->isChecked()){
            ui->b8->setChecked(false);
            ui->b9->setChecked(true);
            ui->b10->setChecked(false);
            ui->b11->setChecked(false);
            emit linechanged(2);
        }else if(ui->b9->isChecked()){
            if(fourlines){
                ui->b8->setChecked(false);
                ui->b9->setChecked(false);
                ui->b10->setChecked(true);
                ui->b11->setChecked(false);
                emit linechanged(3);
            }else{
                ui->b8->setChecked(true);
                ui->b9->setChecked(false);
                ui->b10->setChecked(false);
                ui->b11->setChecked(false);
                emit linechanged(1);
                if(ui->b12->isEnabled()){
                    emit saved();
                }
            }
        }else if(ui->b10->isChecked()){
            ui->b8->setChecked(false);
            ui->b9->setChecked(false);
            ui->b10->setChecked(false);
            ui->b11->setChecked(true);
            emit linechanged(4);
        }else if(ui->b11->isChecked()){
            ui->b8->setChecked(true);
            ui->b9->setChecked(false);
            ui->b10->setChecked(false);
            ui->b11->setChecked(false);
            emit linechanged(1);
            if(ui->b12->isEnabled()){
                emit saved();
            }
        }else{

        }
    }
}

void ToolButtons::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(61,59,79));
    QWidget::paintEvent(event);
}

void ToolButtons::setlocked(bool locked)
{
    ui->b4->setEnabled(!locked);
    ui->b5->setEnabled(!locked);
    ui->b12->setEnabled(!locked);
}

void ToolButtons::on_b7_toggled(bool checked)
{
    emit autoed(checked);
}
