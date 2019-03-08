#include "mymainwindow.h"
#include "getmes.h"
#include <QApplication>
#include <QDebug>
//
#include "connection.h"
#include <QProcess>
#include <QStyleFactory>                           //修改风格1步
//
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //
    a.setStyle(QStyleFactory::create("fusion"));   //修改风格2步

    //获取用户数据库安装地址，数据库用户名等
      GetMes* b = new GetMes ();
      b->show();

        qDebug()<<"000000000000000000000";
    //获取用户数据库安装地址，数据库用户名等


        qDebug()<<"888888888888888888888888888";
        MyMainWindow w;
        w.show();







    return a.exec();
}
