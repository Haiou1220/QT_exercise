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
#include "QDialog"
#include "QMessageBox"
#include "QFileDialog"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)

{

//    //菜单栏1
//    QMenuBar *pmenubar =  this->menuBar();//new QMenuBar(this);
//   // QMenu* pMenu1_1 = new QMenu("文件");

//      QMenu* menu1_1 =pmenubar->addMenu("文件");//("新建");//要复习要复习

//      QMenu* menu1_2 =  pmenubar->addMenu("编辑");



   //菜单栏2：menu1

        QMenuBar* pMenBar1 = new QMenuBar(this);//或者 this->menuBar();
         this->setMenuBar(pMenBar1);


   QMenu* pMenu1_0 =  pMenBar1->addMenu("文件");//或者new QMenu("menu1");

    pMenBar1->addMenu(pMenu1_0);


   QAction *action_new =   pMenu1_0->addAction("新建") ;
   connect(action_new,&QAction::triggered,

           []()
           {

                qDebug() <<"aaa";
           }


           );





   //  menu01->addSeparator() ;
  //  QAction *action_open =   menu01->addAction("打开") ;
  //   menu01->addSeparator() ;


    QStatusBar *status = this->statusBar();
    QWidget *widget = new QWidget(this);
    status->addWidget(widget);

//工具栏
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

//对话框模态与非模态

      QMenuBar* pMenBar = new QMenuBar(this);
      this->setMenuBar(pMenBar);

     QMenu* pMenu1 = new QMenu("menu1");
      pMenBar->addMenu(pMenu1);

  QAction* pAct1 =  pMenu1->addAction("modal or unmodal dialog");
    QAction* pAct2 =  pMenu1->addAction("about");

    QAction* pAct3 =  pMenu1->addAction("openFile");

    connect(pAct1,&QAction::triggered,
            [=]()
            {
              QDialog* a = new QDialog(this);//(this);//不指定父对象 变得好大；
              a->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
              //a->show();//非模态
             a->exec();//模态

                qDebug()<<"modal dialog";

          //  int ret =    QMessageBox::question(this,"dui hua kuang","are yoy ok??", QMessageBox::Help);

            }
            );

    connect(pAct2,&QAction::triggered,  //标准窗口，集成的窗口,不用自己创建，很方便
            [=]()
            {
            //  QDialog* a = new QDialog(this);
            //  a->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
            //  a->show();
             // a.exec();
           int ret =    QMessageBox::question(this,"dui hua kuang","are yoy ok??", QMessageBox::No|QMessageBox::Yes|QMessageBox::Help);

                       switch(ret)
                              {
                       case QMessageBox::No:  qDebug()<<" NO"; break;

                       case QMessageBox::Yes:  qDebug()<<" yes"; break;

                       default: qDebug()<<" ????"; break;


                             }



            }
            );

    connect(pAct3,&QAction::triggered,  //文件打开
            [=]()
            {
            //  QDialog* a = new QDialog(this);
            //  a->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
            //  a->show();
             // a.exec();
            QString str =   QFileDialog::getOpenFileName(this,
                                            "Select file to open ",
                                            "",
                                            "souce:(*h *cpp);;"
                                            "All: (*.*)");

             qDebug()<<str;

                       //(this,"dui hua kuang","are yoy ok??", QMessageBox::No|QMessageBox::Yes|QMessageBox::Help);

                       //switch(ret)
                             // {
                      // case QMessageBox::No:  qDebug()<<" NO"; break;

                      // case QMessageBox::Yes:  qDebug()<<" yes"; break;

                     //  default: qDebug()<<" ????"; break//;


                            // }


            }
            );


}

MyMainWindow::~MyMainWindow()
{

}
