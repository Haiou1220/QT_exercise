#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QMouseEvent>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

protected:
    //虚函数，自动调用
   void paintEvent(QPaintEvent *event);
  void   mousePressEvent(QMouseEvent *event);
private:
    Ui::MyWidget *ui;
    QPoint myPos;
    QMouseEvent *my_mouse_event;
    bool L_Button = !true;
};

#endif // MYWIDGET_H
