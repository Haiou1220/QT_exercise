#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//鼠标进出事件
void Widget::enterEvent(QEvent *event){


}
//鼠标进出事件
 void Widget::leaveEvent(QEvent *event) {


 }

//键盘事件
 void Widget::keyPressEvent(QKeyEvent *event) {

     static QString event_str;
     static QString str;

     //  if(event->key()==Qt::Key_A) qDebug()<<"Qt::Key_A";
     //qDebug()<<hex<<a;

    event_str =  event->text();
    //回车发送整一句
      if(event_str == "\r"){

        qDebug()<< str;
        str.clear();

      }else {
        str+=event_str;
        //回显
         qDebug()<< event_str;
      }







 }
