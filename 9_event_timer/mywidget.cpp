#include "mywidget.h"
#include "ui_mywidget.h"
#include "mypushbutton.h"
#include  <QDebug>
#include  <QMessageBox>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)

{
    ui->setupUi(this);

    //定时器初始化
   timerID1 = this->startTimer(1);
   timerID2 =  this->startTimer(std::chrono::seconds(2));


   // static bool flag_timeStop_switch_on = true;类声明
    connect(ui->pushButton_2,&MyPushButton::pressed,//定时器的显示（按键文字，时间数字） 暂停与继续
            [=]()
            {

        if(flag_timeStop_switch_on ){

        this->killTimer(timerID1);
            ui->pushButton_2->setText("StartTime");
             flag_timeStop_switch_on = false;

        }else{

            timerID1 = this->startTimer(1);
                ui->pushButton_2->setText("StopTime");
            flag_timeStop_switch_on = true;
        }


           // qDebug()<<QString("按键被按下:%1").arg(i++);


            }

            );
   //清除初始化text
      ui->label->clear();
       ui->label_2->clear();

       //安装事件过滤器
       ui->pushButton_2->installEventFilter(this);
       this->installEventFilter(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget:: timerEvent(QTimerEvent *event)
{
    static int timer_count1  = 0;
    static int timer_count2  = 0;


    if(event->timerId() == timerID1)
    {
        ui->label->setText(QString("<center><h1>Time Count:%1</h1></center>").arg(timer_count1++));


    }else if (event->timerId() == timerID2) {
        ui->label_2->setText(QString("<center><h1>Time Count:%1</h1></center>").arg(timer_count2++));

    }

}

//test-ignor

void  MyWidget:: mousePressEvent(QMouseEvent* ) {

qDebug()<<"夫类mousePressEvent（）发生了，";


   }

void MyWidget::closeEvent(QCloseEvent *event) {

    int ret =  QMessageBox::question(this,"close_or_no","close?");
    if(ret == QMessageBox::Yes)
    {
      event->accept();//close关闭窗口
        //event->ignore();//不关闭窗口

    }else {

     event->ignore();//不关闭窗口,传给夫组件
    // event->accept();//close关闭窗口
    }


}

bool MyWidget::event(QEvent* e) {

    if(e->type() ==QEvent::MouseButtonPress )
    {

        qDebug()<<"event()--QEvent::MouseButtonPress,call";

       return true;
    }else

    if(e->type()== QEvent::Timer  ){


        //注释下面，既可干掉定时器
//        QTimerEvent* TE_e = static_cast<QTimerEvent*>(e);
//        timerEvent(TE_e);
         //注释上面，既可干掉定时器

        {//如果是事件QEvent::Timer//在event分发之前，处理定时器事件
            QTimerEvent* event = static_cast<QTimerEvent*>(e);
            static int timer_count1  = 0;
            static int timer_count2  = 0;


            if(event->timerId() == timerID1)
            {
                ui->label->setText(QString("<center><h1>Time Count:%1</h1></center>").arg(timer_count1++));


            }else if (event->timerId() == timerID2) {
                ui->label_2->setText(QString("<center><h1>Time Count:%1</h1></center>").arg(timer_count2++));

            }

        }//在event分发之前，处理定时器事件

        return true;//停止传播
    }

    else
    {

        return  QWidget::event( e);
    }



}


  bool MyWidget::  eventFilter(QObject* obj,QEvent* eve)
  {


      if (obj == ui->pushButton_2) {//obj == ui->pushButton_2
          if(eve->type() == QEvent::MouseButtonDblClick){
             //begen
            qDebug()<<"ui->pushButton_2---QEvent::MouseButtonDblClick";
            return true;
           //end
          }else {
             return  QWidget::eventFilter(obj,eve) ;
          }

      }

      //obj == mywidget,打印按键,按键启动与停止计时器，'s'停止'c'继续
      if (obj == this) {
          if(eve->type() == QEvent::KeyRelease){
             //begen
              QKeyEvent* KE_e = static_cast<QKeyEvent*>(eve);
            qDebug()<<QString("obj::this--key:%1").arg(KE_e->text())  ;
            if(KE_e->text()=="s"){
                if(flag_timeStop_switch_on== true ){
                    this->killTimer(timerID1);
                    ui->pushButton_2->setText("StartTime");
                    flag_timeStop_switch_on = false;
                }

            }
            if(KE_e->text()=="c"){

                   if(flag_timeStop_switch_on ==false ) {
                    timerID1 = this->startTimer(1);
                    ui->pushButton_2->setText("StopTime");
                    flag_timeStop_switch_on = true;
                     }

            }
            return true;
           //end
          }else {
             return  QWidget::eventFilter(obj,eve) ;
          }

      }










      //default:
      else {
          return  QWidget::eventFilter(obj,eve) ;
      }

  }







