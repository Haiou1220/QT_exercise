#include "mywidget.h"
#include "ui_mywidget.h"
#include "QPainter"
#include "QPixmap"
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //创建绘图设备为PIX
    QPixmap Pix(this->width(),this->height());
    QPainter p(&Pix);

    p.drawPixmap(0,0,50,50,QPixmap(":/new/smile.png"));

    Pix.save("./auto.png");

    QPainter Painter(this);


}

MyWidget::~MyWidget()
{
    delete ui;
}
