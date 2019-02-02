#include "mywidet.h"
#include "QSpinBox"
#include "QSlider"
#include "QHBoxLayout"


MyWidet::MyWidet(QWidget *parent) : QWidget(parent)
{
    QSpinBox* mywidet_spin = new QSpinBox;
    QSlider*  mywidet_slinder = new QSlider(Qt::Orientation::Horizontal,this);
    mywidet_slinder->setMaximum(50);
    QHBoxLayout*  mywidet_hboxlayout = new QHBoxLayout(this);

    mywidet_hboxlayout->addWidget(mywidet_spin);
    mywidet_hboxlayout->addWidget(mywidet_slinder);

    this->layout();

connect(mywidet_spin,
        static_cast<void (QSpinBox::*)(int) >(&QSpinBox::valueChanged),

      mywidet_slinder,
      &QSlider::setValue

        );

connect(mywidet_slinder,
        &QSlider::valueChanged,

      mywidet_spin,
      &QSpinBox::setValue
        );


}


