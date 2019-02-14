#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimerEvent>
#include <QCloseEvent>
#include <QEvent>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget() override;



private:
    Ui::MyWidget *ui;
    //定时器
   int  timerID1;
   int  timerID2 ;

   bool flag_timeStop_switch_on = true;

protected:
//定时器事件
   void timerEvent(QTimerEvent *event) override ;  // override

//test_ignor

   void mousePressEvent(QMouseEvent* e) override;


   //关闭窗口事件override
   void closeEvent(QCloseEvent *event) override;

protected:
   bool event(QEvent* e) override ;

  bool eventFilter(QObject* obj,QEvent* eve) override;


};

#endif // MYWIDGET_H
