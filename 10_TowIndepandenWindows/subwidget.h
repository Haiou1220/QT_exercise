#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent = nullptr);

signals:
      void subwidget_sign(void);

public slots:

private:
      QPushButton b1;

public:
     void sub_button_signal(void);

};

#endif // SUBWIDGET_H
