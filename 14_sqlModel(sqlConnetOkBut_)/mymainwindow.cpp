#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QProcess>
#include "connection.h"
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
MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{



    ui->setupUi(this);
    //
    //

    //
    model = new QSqlTableModel(this);
    model->setTable("course");
    model->select();

    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    //
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::on_pushButton_clicked()
{
    // 开始事务操作
    model->database().transaction();
    if (model->submitAll()) {
    model->database().commit(); //提交
    } else {
    model->database().rollback(); //回滚
    QMessageBox::warning(this, tr("tableModel"),
    tr("数据库错误: %1").arg(model->lastError().text()));
    }

}

void MyMainWindow::on_pushButton_4_clicked()
{
    model->revertAll();
}

void MyMainWindow::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit->text();
        if(name.length()){
        //根据姓名进行筛选， 一定要使用单引号
        model->setFilter(QString("teacher = '%1'").arg(name));
        model->select();
        }else
        { QMessageBox::warning(this, tr("Warning"),tr("姓名不能为空") );
        }

}

void MyMainWindow::on_pushButton_3_clicked()
{
    model->setTable("course");
    model->select();
}

void MyMainWindow::on_pushButton_7_clicked()//升降序排列
{
    //id 属性， 即第 0 列， 升序排列
    //选中的列Column
     int curCol= ui->tableView->currentIndex().column();
    //
    model->setSort(curCol, Qt::AscendingOrder);
    model->select();
}

void MyMainWindow::on_pushButton_8_clicked()//升降序排列
{
    //
    //选中的列Column
     int curCol= ui->tableView->currentIndex().column();
    //
    model->setSort(curCol, Qt::DescendingOrder);
    model->select();
}

void MyMainWindow::on_pushButton_6_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();
    // 删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
    tr("你确定删除当前行吗？ "),QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    { // 如果不删除， 则撤销
    model->revertAll();
    } else { // 否则提交， 在数据库中删除该行
    model->submitAll();
    }

}

void MyMainWindow::on_pushButton_5_clicked()
{
    // 获得表的行数
    int rowNum = model->rowCount();
    // 添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),rowNum+1);
}
