#include "mymainwindow.h"
#include "QLabel"
#include "QMenuBar"
#include "QMenu"
#include "QPushButton"
#include "QStatusBar"
#include "QWidget"
#include "QAction"
#include "QDebug"
#include "QToolBar"
#include "QLabel"
#include "QDockWidget"
#include "QTextEdit"
MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    QMenuBar *menubar =  this->menuBar();//new QMenuBar(0);
    QMenu *menu1 =  menubar->addMenu("文件");
    QMenu *menu2 =  menubar->addMenu("编辑");

   QAction *action_new =   menu1->addAction("新建") ;
   connect(action_new,&QAction::triggered,

           []()
           {

                qDebug() <<"aaa";
           }


           );





     menu1->addSeparator() ;
    QAction *action_open =   menu1->addAction("打开") ;
     menu1->addSeparator() ;


   // QStatusBar *status = this->statusBar();
  //  QWidget *widget = new QWidget(this);
   // status->addWidget(widget);


     QToolBar *toolBar = addToolBar("toolBar");
     toolBar->addAction(action_new);

    QPushButton  *toolBar_open = new QPushButton("打开");
    connect(toolBar_open,&QPushButton::pressed,

            [=]()
            {
                 static unsigned int i = 1;
                  static QString str1 = "打开？",str2 = "打开";
                  if(++i%2==0){toolBar_open->setText(str1);
                      this->flag_SB_show = 1;
                  }else{
                      toolBar_open->setText(str2);
                      this->flag_SB_show = 0;
                       //statusBar_show->setText("11111111111111");
                  }
                 qDebug() <<"QPushButton打开";
            }

            );
    toolBar->addWidget(toolBar_open);

    //状态栏1
    QStatusBar *statusBar = this->statusBar();

    QLabel *statusBar_text = new QLabel("no normost file text");
    statusBar->addWidget(statusBar_text);

    //状态栏2
     statusBar->addWidget( new QLabel("ok",this));

     //状态栏3
      statusBar->addPermanentWidget(new QLabel("fault",this));

      //文本编辑框
      this->setCentralWidget(new QTextEdit(this));

     //浮动窗口dock

      QDockWidget *dock = new QDockWidget("dock");
    this-> addDockWidget(Qt::RightDockWidgetArea,dock);

      //浮动窗口中的文本编辑器

      dock->setWidget(new QTextEdit(this));


}

MyMainWindow::~MyMainWindow()
{

}
