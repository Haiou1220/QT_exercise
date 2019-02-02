#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QCompleter"
#include "QStringList"
#include "QSpinBox"
#include "QLabel"
#include "QPixmap"
#include "QMovie"
//#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList a1 ;  //= new QStringList();
    a1<<"hello"<<"Haiou"<<"hehe"<<"hi" ;

   QCompleter* a2 = new QCompleter(a1);  //(QStringList,this);

    a2->setCaseSensitivity(Qt::CaseInsensitive) ;//

     ui->lineEdit->setCompleter(a2);
    ui->spinBox->setPrefix("$");
    ui->spinBox->setRange(0,10);
   //
//表情图片和动画
   // ui->label->setScaledContents(true);

      ui->label->setPixmap(QPixmap(":/MyImage/imag/sexy.jpg"));
    //  ui->label->setScaledContents()
      ui->label->setScaledContents(true);

      //动画
      pMyMove = new QMovie(":/MyImage/imag/timg.gif");
     ui->label_2->setMovie(pMyMove );
     pMyMove->start();


     //标签之文本
    QString html_str = "<h2>"
                       "<a href=\"https://www.baidu.com\">"
                       "百度一下"
                       "</a>"
                       ""
            "<font size=\"3\" color=\"red\">This is some text!</font>"
                       "</h2>"  ;
     ui->label_3->setText(html_str);
     ui->label_3->setOpenExternalLinks(true);
    //数码管
     ui->lcdNumber->display(0);


     //进度条
     ui-> progressBar->setRange(0,100);

    ui-> progressBar->setValue(85);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: on_pushButton_4_clicked()

{

    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_switch_windows_clicked()
{
    //static unsigned int i = 0;
   // ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::on_switch_1_clicked()
{
    static unsigned int i = 0;
    ui->stackedWidget->setCurrentIndex(++i%3);
}

void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_5_clicked()
{
    QString str =  ui->lineEdit->text();
     ui->lineEdit_2->setText(str);
     ui->lineEdit->clear();
}

void MainWindow::on_label_2_linkActivated(const QString &link)
{


}

void MainWindow::on_lcdNumber_overflow()
{

}

void MainWindow::on_pushButton_6_clicked()
{
    static char count =0;
    static char ba =0;
     static char count_puls =1;

     count+=count_puls;
    ui->lcdNumber->display(count);
    ui-> progressBar->setValue(count);


    if( count%10 == 0 )
    {
           count_puls++;


    }

}
