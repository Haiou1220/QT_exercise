#include "getmes.h"
#include "ui_getmes.h"
#include "connection.h"
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
//
#include "mymainwindow.h"
#include "getmes.h"
#include <QApplication>
#include <QDebug>
//
#include "connection.h"
#include <QProcess>
#include <QStyleFactory>
//

GetMes::GetMes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetMes)
{
    ui->setupUi(this);







}

GetMes::~GetMes()
{
    delete ui;
}



void GetMes::on_Process_clicked()//打开文件按键
{

    this->process_start_str = ui->Process_str->text() ;//process路径文本
    if(process_start_str.size()==0)//process路径文本为空
    {
        //调用IO打开sqld文件
        QString str =   QFileDialog::getOpenFileName(this,
                                        "Select mysqld.exe to open ",
                                        "",
                                        "mysqld:(*exe);;"
                                        "All: (*.*)");
       this->process_start_str = str;

       ui->Process_str->setText(this->process_start_str);//显示打开文件路径


    }



}

void GetMes::on_RunSql_clicked()//运行按键
{   //重新初始化
    this->connect_ok = "ok";
    //获取process路径
    this->process_start_str=this->process_start_str = ui->Process_str->text() ;//process路径文本

    //获取数据库信息
     this->HostName_str = ui->HostName->text();
    this->Database_str = ui->DataBaseName->text();
    this->UserName_str = ui->UserName->text();
    this->Password_str = ui->PassWord->text();

    //运行数据库进程
      qDebug()<<this->process_start_str;
      QProcess process;
      process.start( this->process_start_str);

     //数据库链接进行
    QSqlDatabase* db  = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL")) ;



    db->setHostName(this->HostName_str);
                                qDebug()<<this->HostName_str;
    db->setDatabaseName(this->Database_str);       //这里输入你的数据库名
    db->setUserName(this->UserName_str);

    db->setPassword(this->Password_str);   //这里输入你的密码

    if(true)//用户名空
     {
        if(this->process_start_str.size() ==0)
        {
            QMessageBox::warning(this,"非法操作","process空");
            this->connect_ok = "no";
        }

        if(this->UserName_str.size() ==0)
        {
            QMessageBox::warning(this,"非法操作","UserName空");
            this->connect_ok = "no";
        }
        if(this->HostName_str.size() == 0){
             QMessageBox::warning(this,"非法操作","HostName空");
             this->connect_ok = "no";
        }
        if (this->Database_str.size() ==0) {
            QMessageBox::warning(this,"非法操作","Database空");
            this->connect_ok = "no";
        }

     }

    if (!db->open(this->UserName_str,this->Password_str)) {//打开不成功
    QMessageBox::critical(this, QObject::tr("无法打开数据库"),
    "无法创建数据库连接！ ", QMessageBox::Cancel);

    }else{//打开成功
        if( this->connect_ok == "no")//无效打开
        {
            QMessageBox::critical(this,"无效","无效操作");

        }else{//有效操作

          QMessageBox::information(this,"成功","连接成功");

            //连接成功
          this->close();


        }


        //下面来创建表
        // 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
        QSqlQuery query(*db);
        // 使数据库支持中文
        query.exec("SET NAMES 'Latin1'");
        // 创建 course 表
        query.exec("create table course (id INT PRIMARY KEY, "
        "name VARCHAR(20), teacher VARCHAR(20))");
        //varchar(n)  变长字符串类型，
        //int primary key 数据类型的属性PRIMARY KEY--主键
        query.exec("insert into course values(0, '数学', '刘老师')");
        query.exec("insert into course values(1, '英语', '张老师')");
        query.exec("insert into course values(2, '计算机', '李老师')");



    }


}


bool GetMes::openNext(){

    bool ok = this->connect_ok == "ok";
    return (ok );
}

void GetMes::on_pushButton_clicked(){ }
