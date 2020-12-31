#ifndef TOOLBUTTONS_H
#define TOOLBUTTONS_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class ToolButtons;
}

class ToolButtons : public QWidget
{
    Q_OBJECT

public:
    explicit ToolButtons(QWidget *parent = nullptr);
    ~ToolButtons();
    void setplay(bool play);
    void setcanplay(bool can);
    void setfourlines(bool fourlines);
    void setcansave(bool can);
    void setlocked(bool locked);

private:
    Ui::ToolButtons *ui;
    bool Auto=true;
    bool fourlines=true;
signals:
    void control(int controlcode);
    void plotplay(bool play);
    void linechanged(int id);
    void saved();
    void autoed(bool autoed);
private slots:
    void on_b1_clicked(bool checked);
    void on_b2_clicked(bool checked);
    void on_b3_clicked(bool checked);
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked(bool checked);
    void on_b7_clicked(bool checked);

    void on_b8_clicked();

    void on_b9_clicked();

    void on_b10_clicked();

    void on_b11_clicked();

    void on_b12_clicked();


    void on_b7_toggled(bool checked);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
public slots:
    void wannachangeline();
};

#endif // TOOLBUTTONS_H
