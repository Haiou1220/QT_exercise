#include "mypushbutton.h"

#include <QDebug>



MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{



}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{

    if (e->button() ==Qt::LeftButton ) {

        qDebug()<<"子类mousePressEvent（）发生了，左按键，Qt::LeftButton";

       //e->ignore();//传给夫组件MyWidget中的event(),最后调用mousePressEvent（）
         e->accept();//不会传给夫组件


    } else {

        //QPushButton::mousePressEvent(e);//传给夫类
         e->ignore();//传给夫组件MyWidget中的event(),最后调用mousePressEvent（）
    }


}
