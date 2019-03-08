#include "mywidget.h"
#include "ui_mywidget.h"
#include "QPainter"
#include "QColor"
#include "QPen"
#include "QColor"
#include "QLine"
#include "QPoint"
#include "QBrush"


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::paintEvent(QPaintEvent *)
{

    QPainter p(this);//画家

    p.begin(this);

    //花背景图
   // p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/new/1.png"));
    p.drawPixmap(this->rect(),QPixmap(":/new/1.png"));
   //花背景图

    QPen pen;//画笔
    pen.setWidth(7);
    QColor c(Qt::GlobalColor::red);
    pen.setColor( c );

    p.setPen(pen);//设置画笔

    //画矩形
  // p.drawRect(20,20,this->width()-40,this->height()-40);

   //计算参数
    int w = this->width();
    int h = this->height();
    int const edge = 20;
    int const w_time = 7;
     int const y_time = 7;
    //纵4格，横4格
    int w_average = (w-2*edge)/w_time;
    int y_average = (h-2*edge)/y_time;
    int h_block = h -2*edge;
    int w_block = w -2*edge;


    QPoint PointLine_start_x(edge,edge),PointLine_start_y(edge,edge+h_block);
    QPoint PointLineAcross_start_x(edge,edge),PointLineAcross_start_y(edge+w_block,edge);

     //加法x坐标//加法y坐标
     QPoint p_plus_W_up(w_average,0);
     QPoint p_plus_H_up(0,y_average);


    //p.drawLine(PointLine_start_x,PointLine_start_y);


  //加法纵轴 int const w_time = ;
  p.drawLine(PointLine_start_x,PointLine_start_y);
  p.drawLine(PointLine_start_x+1*p_plus_W_up,PointLine_start_y+1*p_plus_W_up);
  p.drawLine(PointLine_start_x+2*p_plus_W_up,PointLine_start_y+2*p_plus_W_up);
  p.drawLine(PointLine_start_x+3*p_plus_W_up,PointLine_start_y+3*p_plus_W_up);
  p.drawLine(PointLine_start_x+4*p_plus_W_up,PointLine_start_y+4*p_plus_W_up);
  p.drawLine(PointLine_start_x+5*p_plus_W_up,PointLine_start_y+5*p_plus_W_up);
  p.drawLine(PointLine_start_x+6*p_plus_W_up,PointLine_start_y+6*p_plus_W_up);
  p.drawLine(PointLine_start_x+7*p_plus_W_up,PointLine_start_y+7*p_plus_W_up);
  p.drawLine(PointLine_start_x+8*p_plus_W_up,PointLine_start_y+8*p_plus_W_up);
  p.drawLine(PointLine_start_x+9*p_plus_W_up,PointLine_start_y+9*p_plus_W_up);

//加法横轴int const y_time = ;
  p.drawLine(PointLineAcross_start_x,PointLineAcross_start_y);
  p.drawLine(PointLineAcross_start_x+1*p_plus_H_up,PointLineAcross_start_y+1*p_plus_H_up);
  p.drawLine(PointLineAcross_start_x+2*p_plus_H_up,PointLineAcross_start_y+2*p_plus_H_up);
  p.drawLine(PointLineAcross_start_x+3*p_plus_H_up,PointLineAcross_start_y+3*p_plus_H_up);
  p.drawLine(PointLineAcross_start_x+4*p_plus_H_up,PointLineAcross_start_y+4*p_plus_H_up);
  p.drawLine(PointLineAcross_start_x+5*p_plus_H_up,PointLineAcross_start_y+5*p_plus_H_up);
  p.drawLine(PointLineAcross_start_x+6*p_plus_H_up,PointLineAcross_start_y+6*p_plus_H_up);
  p.drawLine(PointLineAcross_start_x+7*p_plus_H_up,PointLineAcross_start_y+7*p_plus_H_up);

//画圆圈
  pen.setColor(QColor(Qt::GlobalColor::blue));
  p.setPen(pen);

  p.setBrush(QBrush(Qt::GlobalColor::cyan,Qt::BrushStyle::Dense1Pattern));//画刷
  p.drawEllipse(QPointF(w/2,h/2),50,50);

//动态画图，手动刷新，鼠标位置
  int mypos_x = this->myPos.x();
  int mypos_y = this->myPos.y();

  if(L_Button == true)
  {
      L_Button = !true;
      p.drawPixmap(mypos_x,mypos_y,60,60,QPixmap(":/new/smile.png"));
  }




  p.end();

}


 void MyWidget:: mousePressEvent(QMouseEvent *event)
 {
     my_mouse_event = event;

     //左按键
    if(event->button() ==Qt::MouseButton::LeftButton)
      {
         L_Button = true ;
        this->myPos =  event->pos();
        this->update(QRect(this->myPos,this->myPos+QPoint(80,80)));
      }

    //右按键
     if(event->button() ==Qt::MouseButton::RightButton)
     {
          this->update();
     }

    QWidget::mousePressEvent(event);


 }
