#include "mywidget.h"
#include <QPushButton>
#include "subwidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{

    move(-10,100);

    this->setWindowTitle("主要_windows");
    b.setParent(this);
    b.setText("swith_subwindows");
    b.move(200,200);
    b.show();

    connect(&b,&QPushButton::released, this, &MyWidget::deal_button);

    connect(&w1,&subwidget::subwidget_sign, this, &MyWidget::sub_button_slot);

    w1.show();
    int a=1,b=2;
    //
    QPushButton* p_button = new QPushButton("退出,all",this);
    p_button->show();

    connect(p_button,&QPushButton::clicked, [=](bool is_checked)
                    {
                        static unsigned int ok_conut=5;
                        qDebug()<<is_checked;

                        qDebug()<<"再按"<<(--ok_conut)<<"次退出";

                        if(0==ok_conut){
                            w1.close();
                            this->close();
                          }
                         //qDebug()<<"a="<<a<<"b="<<b;

                    }



            );

    //

}


void MyWidget::deal_button(void)
{

   this->hide();
    w1.show();
}

void MyWidget::sub_button_slot(void)
{

    this->show();
    w1.hide();
}

MyWidget::~MyWidget()
{

}


