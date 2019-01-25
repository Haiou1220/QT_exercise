#include "subwidget.h"

subwidget::subwidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("sub_windows");
    b1.setParent(this);
    b1.setText("swith_mainwindows");
    b1.move(200,200);
    b1.show();

    connect(&b1,&QPushButton::released, this, &subwidget::sub_button_signal);
}

void subwidget::sub_button_signal(void)
{

   emit subwidget_sign();
}
