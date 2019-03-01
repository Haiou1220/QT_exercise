#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget() override;
   void guessNumButton();//自定义槽函数，无接受参数

private slots:
    void on_pushButton_entrance_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_tips_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::MyWidget *ui;
    int gameTimeEventID;//游戏总时间
    int statusEventID;//进度条刷新
   int  countTimeEventID;//倒计时
   int  WinTimeEventID;//胜利win倒计时
   int  FailTimeEventID;//fail倒计时

   int myGameTime;//游戏剩余时间
   QString myGuessNum;//我猜的数字
   QString rand_str = "1234";//随机数字符串 ，方便比较
protected:
     void timerEvent(QTimerEvent *event) override ;  // override
    void showMyGuess(void);




};

#endif // MYWIDGET_H
