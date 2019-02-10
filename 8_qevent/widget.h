#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

protected:
      //鼠标进出事件
      virtual void enterEvent(QEvent *event) override;
      virtual void leaveEvent(QEvent *event) override;

//键盘事件
    virtual void keyPressEvent(QKeyEvent *event) override ;

};

#endif // WIDGET_H
