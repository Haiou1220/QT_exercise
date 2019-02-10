#include "mylabel.h"


MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
  this->setMouseTracking(true);
  label1 =  new QLabel(this);

  this->label1->resize(600,50);

}


//鼠标事件
void MyLabel:: mouseMoveEvent(QMouseEvent *ev) {
static QString str ;
str = QString("<center><h1>Move:%1,%2</h1></center>"
                             )
                      .arg(ev->x()).arg(ev->y());



 this->setText(str);




}
//鼠标事件
 void MyLabel::mouseReleaseEvent(QMouseEvent *ev)  {
   static QString str ;
   str = QString("<center><h1>Release:%1,%2</h1></center>"
                          )
                   .arg(ev->x()).arg(ev->y());

     switch (ev->button()) {

     case Qt::LeftButton:{
         str+="<center><h1>LeftButton</h1></center>";
         break;}
         case Qt::RightButton:{
          str+="<center><h1>RightButton</h1></center>";
         break;}
         case Qt::MidButton:{
          str+="<center><h1>MidButton</h1></center>";
         break;}
        default:break;


     }
    this->setText(str);

 }
//鼠标事件
 void MyLabel::mousePressEvent(QMouseEvent *ev)  {
 static QString str ;
     str = QString("<center><h1>Press:%1,%2</h1></center>"
                             )
                      .arg(ev->x()).arg(ev->y());



        switch (ev->buttons()) {

        case Qt::LeftButton:{
            str+="<center><h1>LeftButton</h1></center>";
            break;}
            case Qt::RightButton:{
             str+="<center><h1>RightButton</h1></center>";
            break;}
            case Qt::MidButton:{
             str+="<center><h1>MidButton</h1></center>";
            break;}
           default:break;

        }
       this->setText(str);

 }

 //鼠标进事件
 void MyLabel::enterEvent(QEvent *event){
     static int a;
     static QString str;

    str = QString("<center><h1>Enter:%1</h1></center>" ).arg(a++);


     this->label1->setText(str);

 }
 //鼠标出事件
  void MyLabel::leaveEvent(QEvent *event) {

      static int a;
      static QString str;

       this->label1->clear();

      str = QString("<center><h1>Leave :%1</h1></center>") .arg(a++);

         this->setText(str);


  }

