#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>


class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

signals:

public slots:

public:

    void  mousePressEvent(QMouseEvent* e ) override;

};

#endif // MYPUSHBUTTON_H
