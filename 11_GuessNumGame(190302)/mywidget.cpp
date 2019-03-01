#include "mywidget.h"
#include "ui_mywidget.h"
#include "QDebug"
#include <QMessageBox>
#include "QMovie"
#include "QTime"
//#include "QRandomGenerator"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //游戏运行进入设置页
    ui->stackedWidget->setCurrentIndex(0);

    //猜数字按键信号绑定
        connect(ui->pushButton_0,&QPushButton::clicked,this,&MyWidget::guessNumButton);
        connect(ui->pushButton_1,&QPushButton::clicked,this,&MyWidget::guessNumButton);
        connect(ui->pushButton_2,&QPushButton::clicked,this,&MyWidget::guessNumButton);
        connect(ui->pushButton_3,&QPushButton::clicked,this,&MyWidget::guessNumButton);
        connect(ui->pushButton_4,&QPushButton::clicked,this,&MyWidget::guessNumButton);
        connect(ui->pushButton_5,&QPushButton::clicked,this,&MyWidget::guessNumButton);
        connect(ui->pushButton_6,&QPushButton::clicked,this,&MyWidget::guessNumButton);
        connect(ui->pushButton_7,&QPushButton::clicked,this,&MyWidget::guessNumButton);
        connect(ui->pushButton_8,&QPushButton::clicked,this,&MyWidget::guessNumButton);
        connect(ui->pushButton_9,&QPushButton::clicked,this,&MyWidget::guessNumButton);//QPushButton::click不可以
                                                                                      //QPushButton::clicked才可以
        //this->connect(ui->pushButton_back,&QPushButton::click,this,&MyWidget::guessNumButton);
      //  this->connect(ui->pushButton_tips,&QPushButton::click,this,&MyWidget::guessNumButton);

    //qDebug()<<this->myGuessNum.size();//调试
     //ui->textBrowser->append("猜大了");//调试

    //初始化胜利页面动画
     QMovie* win_movie =  new QMovie();
    win_movie->setFileName(":/img/win.gif");
     win_movie->start();
     ui->label_win->setMovie(win_movie);
     ui->label_win->setScaledContents(true);//fill 填充

     //初始化失败fail页面动画
      QMovie* fail_movie =  new QMovie();
       fail_movie->setFileName(":/img/fail.gif");
      fail_movie->start();
      ui->label_fail->setMovie(fail_movie);
      ui->label_fail->setScaledContents(true);//fill 填充



}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_entrance_clicked()
{
    //获取猜数字设置时间
    QString str_set_time = ui->comboBox->currentText();
    myGameTime = str_set_time.toInt();//游戏时间
    //qDebug()<<str_set_time;

    //清空上一次结果
    myGuessNum.clear();

    //设置进度条最大与最小值
    ui->progressBar->setMaximum(myGameTime);
    ui->progressBar->setMinimum(0);

    //进入游戏界面
    ui->stackedWidget->setCurrentIndex(1);

    //设置游戏总时间定时器
    gameTimeEventID = this->startTimer(std::chrono::seconds(myGameTime));

    //设置进度条定时器(0.5sec)
    statusEventID = this->startTimer(std::chrono::milliseconds(50) );
    //设置时间倒计时(一秒钟)
     countTimeEventID = this->startTimer(std::chrono::seconds(1));

     //生成随机数
     int RandNUm ;
     uint seed = static_cast<uint > ( QTime(0,0,0).secsTo(QTime::currentTime()) );
     qsrand(seed);

     while( (RandNUm = qrand()%10000) < 1000 )
     {      //RandNUm小于等于9999 ； 当大于等于1000 -9999 退出
         //donothing
     }

     qDebug()<< rand_str ;//调试

     rand_str = QString::number(RandNUm);//生成随机数字符串

     qDebug()<< rand_str ;//调试
};

//重写定时器事件
void MyWidget::timerEvent(QTimerEvent *event)
{
    //游戏时间结束，失败页面调用
    if(event->timerId() == this->gameTimeEventID  )
    {
        //关闭定时器
        killTimer(gameTimeEventID);//游戏时间
        killTimer(countTimeEventID) ;//时间倒计时
         killTimer(statusEventID);//进度条定时器

        //弹窗游戏结束
        QMessageBox*  game_over_box = new QMessageBox(this);
        game_over_box->setWindowTitle("失败哦");
        game_over_box->setText("时间到了，OK键重新开始");

        //ok 按键，继续
        if(game_over_box->exec() == QMessageBox::Ok)
        {

            //清空上一次结果
            myGuessNum.clear();

            //显示失败页面
            ui->stackedWidget->setCurrentIndex(2);
            //启动失败页面倒计时
            FailTimeEventID = this->startTimer(std::chrono::seconds(5));
        }

    }//if_end

   //设置进度条定时器(0.5sec)
      if(event->timerId() == this->statusEventID  )
      {
         ui->progressBar->setValue(myGameTime);
         ui->MyTime->setNum(myGameTime);

      }//if_end

 //倒计时减时间
    if(event->timerId() == this->countTimeEventID  )
    {
        myGameTime-=1;

    } //if_end

//显示胜利动画倒计时事件
    if(event->timerId() == this->WinTimeEventID  )
    {
       this->killTimer(WinTimeEventID) ;//关闭定时器

       //显示游戏开始页面
       ui->stackedWidget->setCurrentIndex(0);

    }


    //显示失败动画  ，倒计时事件
        if(event->timerId() == this->FailTimeEventID  )
        {
           this->killTimer(FailTimeEventID) ;//关闭定时器

           //显示游戏开始页面
           ui->stackedWidget->setCurrentIndex(0);

        }


}

 void MyWidget::guessNumButton()
 {
  //获取信号发送者信息
  QObject* whichButton0 = this->sender();
 // QPushButton* whichButton = (QPushButton*) whichButton0;
  QPushButton* whichButton = dynamic_cast<QPushButton*>(whichButton0);//动态类型转换

  //获取当前按键字符串
  QString tempStr_Button = whichButton->text();

  if(whichButton != nullptr )//有效按键触发事件发生
  {
        //排除：：将要输入第一个猜数字是零
      if ((tempStr_Button == "0") && (0==this->myGuessNum.size()) ) {
        //donothing
      } else {//正常情况下

       myGuessNum += tempStr_Button;//存入

       //显示当前字符串
       ui->textBrowser->append(myGuessNum);

       if(myGuessNum.size()==4){//最大位数是4，结束猜数字，调用显示结果函数
          showMyGuess();
       }

      }


  }


 }

 void MyWidget::showMyGuess(void)
 {
     if (myGuessNum > rand_str) {//猜大了
         ui->textBrowser->append("猜大了");
         myGuessNum.clear();

     } else if (myGuessNum < rand_str) {
        ui->textBrowser->append("猜小了");
         myGuessNum.clear();
     } else if (myGuessNum == rand_str) {
         ui->textBrowser->append("猜对了");
          myGuessNum.clear();

          //停止多个定时器
          killTimer(gameTimeEventID);//游戏总时间定时器
          killTimer(statusEventID);//进度条定时器
          killTimer(countTimeEventID);//设置时间倒计时

          //显示胜利页面
          ui->stackedWidget->setCurrentIndex(3);
          ui->label_win->show();//播放动画
          //启动胜利动画倒计时
        this->WinTimeEventID = this->startTimer(std::chrono::seconds(5));

       }
 }

 //退格操作
void MyWidget::on_pushButton_back_clicked()
{
    if(myGuessNum.size()>=1)
    {
    this->myGuessNum.chop(1);//退格
    //显示当前字符串
    ui->textBrowser->append(myGuessNum);
    }
}

//提示操作（第一次提示显示最大位数 ，第二次显示 次大位数）
void MyWidget::on_pushButton_tips_clicked()
{
    static int count_tips = 0;// switch提示次数
    // 提示次数每entrance一次 加一
     count_tips+=1;

    static QString tips_show[4] = {//千百十个 数组
         "千位",
         "百位",
         "十位",
         "个位",
     } ;

     //千百十个 位提取出来 1234
    int qbgs = rand_str.toInt() ;
    int q_wei =  qbgs/1000;//千
    int b_wei =( qbgs%1000)/100;//百
    int s_wei  = (qbgs%100)/10;//十
    int g_wei  = qbgs%10; //个

    int tips_show_num[4] =//千百十个 数组
    {
        q_wei,b_wei,s_wei,g_wei,

    };


     switch (count_tips) {//显示提示:  *位*

     case 1 :
                  ui->textBrowser->append(  tips_show[count_tips-1] + QString::number(tips_show_num[count_tips-1]) )   ;
                  break;
     case 2 :
              ui->textBrowser->append(  tips_show[count_tips-1] + QString::number(tips_show_num[count_tips-1]) )   ;
          break;
     case 3 :
           ui->textBrowser->append(  tips_show[count_tips-1] + QString::number(tips_show_num[count_tips-1]) )   ;
          break;
     case 4 ://猜数字最大位数 为四位

          ui->textBrowser->append(  tips_show[count_tips-1] + QString::number(tips_show_num[count_tips-1]) )   ;
          break;

     case 5 ://猜数字最大位数 为四位//结束提示

          ui->textBrowser->append( "结束提示" ) ;
          break;

     default:
          ui->textBrowser->append( "结束提示" ) ;
         break;

     }


}

void MyWidget::on_pushButton_exit_clicked()
{
    this->close();
}
