#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSerialPort/QSerialPort"
#include "QtSerialPort/QSerialPortInfo"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化Port_comboBox
   // QAbstractButton* Port_comboBox
    //ui->Port_comboBox->*item
    //查找可用的串口
        foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
       {
            QSerialPort serial;
            serial.setPort(info);
           if(serial.open(QIODevice::ReadWrite))
           {
                ui->Port_comboBox->addItem(serial.portName());
               serial.close();
           }
       }
        //设置波特率下拉菜单默认显示第0项
       ui->Port_comboBox->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_OpenPort_pushButton_clicked()
{
    serial = new QSerialPort;

    if(ui->OpenPort_pushButton->text() == tr("打开串口"))
         {

             //设置串口名
              serial->setPortName(ui->Port_comboBox->currentText());
              //打开串口
              serial->open(QIODevice::ReadWrite);
              //设置波特率
              serial->setBaudRate(QSerialPort::Baud9600);//设置波特率为115200
              //设置数据位数
              switch (ui->SJ_comboBox_3->currentIndex())
              {
              case 8:
                  serial->setDataBits(QSerialPort::Data8);//设置数据位8
                  break;
              default:
                  break;
              }
              //设置校验位
              switch (ui->JY_comboBox_4->currentIndex())
              {
              case 0:
                  serial->setParity(QSerialPort::NoParity);
                  break;
              default:
                  break;
              }
              //设置停止位
              switch (ui->TZ_comboBox_5->currentIndex())
              {
              case 1:
                  serial->setStopBits(QSerialPort::OneStop);//停止位设置为1
                  break;
              case 2:
                  serial->setStopBits(QSerialPort::TwoStop);

              default:
                  break;
              }
              //设置流控制
              serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制


              //关闭设置菜单使能
                  ui->Port_comboBox->setEnabled(false);
                  ui->BT_comboBox_2->setEnabled(false);
                  ui->SJ_comboBox_3->setEnabled(false);
                  ui->JY_comboBox_4->setEnabled(false);
                  ui->TZ_comboBox_5->setEnabled(false);
                  ui->OpenPort_pushButton->setText(tr("关闭串口"));


         QObject::connect(serial,&QSerialPort::readyRead,this,&MainWindow::ReadData);

        }else
        {

          //关闭串口
          serial->clear();
          serial->close();
          serial->deleteLater();

          //恢复设置使能

          ui->Port_comboBox->setEnabled(true);
          ui->BT_comboBox_2->setEnabled(true);
          ui->SJ_comboBox_3->setEnabled(true);
          ui->JY_comboBox_4->setEnabled(true);
          ui->TZ_comboBox_5->setEnabled(true);
          ui->OpenPort_pushButton->setText(tr("打开串口"));

         }

}

void MainWindow::on_Send_PB_clicked()
{

         serial->write(ui->Send_textEdit->toPlainText().toLatin1());

}

void MainWindow::ReadData()
 {
     QByteArray buf;
     buf = serial->readAll();
     if(!buf.isEmpty())
     {
         QString str = ui->Show_textBrowser->toPlainText();
         str+=tr(buf);
         ui->Show_textBrowser->clear();
         ui->Show_textBrowser->append(str);

     }
     buf.clear();
 }
