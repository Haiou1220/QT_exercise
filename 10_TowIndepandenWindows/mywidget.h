#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void text_chang(void);
    void deal_button(void);
    void sub_button_slot(void);

private:
    QPushButton b;
    QPushButton* p_button ;
   subwidget w1;
};

#endif // MYWIDGET_H
