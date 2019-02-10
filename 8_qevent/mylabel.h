#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include  <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

signals:

public slots:

protected:
  QLabel* label1;

     //鼠标事件
    virtual void mouseMoveEvent(QMouseEvent *ev) override;
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;
    virtual void mousePressEvent(QMouseEvent *ev) override ;


      //鼠标进出事件
      virtual void enterEvent(QEvent *event) override;
      virtual void leaveEvent(QEvent *event) override;

};

#endif // MYLABEL_H
