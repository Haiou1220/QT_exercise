#include "mainwindow.h"
#include "QMenuBar"
#include "QMenu"
#include "QAction"
#include "QToolBar"
#include "QWidget"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{

 //菜单栏
    QMenuBar* MenuBar1 = this->menuBar();

    QMenu* Menu1 = MenuBar1->addMenu("文件");



//文件-->>新建
  QAction*  pNewFile =  Menu1->addAction("新建");


 //文件-->>打开
  Menu1->addSeparator();
   QAction*  pOpenFile =  Menu1->addAction("打开");

//文件-->>退出
  Menu1->addSeparator();
  QAction*  pExit =  Menu1->addAction("退出");

  //工具栏
  QToolBar* ToolBar1 = this->addToolBar("工具栏");

  ToolBar1->addAction(pOpenFile);//工具栏: 文件-->>打开


}






MainWindow::~MainWindow()
{

}
