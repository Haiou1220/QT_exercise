#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString styleSheet =  "QMainWindow { background: rgb(255,255,255); }"
                          " QLineEdit { background: yellow ;}"
                           "QCheckBox:hover { color: red ;}"
                         ""
                         ""
                         ""
                         ""
                         ""
                         "";
  ui->label->setStyleSheet("QLabel {"
                           ""
                           " background: blue ;"
                              "border-image: url(://sexy.jpg) 50 50 50 50 stretch stretch ;"
                              ""
                              ""
                              ""
                              ""
                              "}");
    this->setStyleSheet(styleSheet);

    ui->pushButton->setStyleSheet("QPushButton:pressed{"
                                  "border: 5px outset red;"
                                  ""
                                  ""
                                  ""
                                  ""
                                  ""
                                  ""
                                  "}");


    ui->spinBox->setStyleSheet("QSpinBox::up-button:hover{"
                               "border: 5px outset red;"
                               ""
                               ""
                               ""
                               ""
                               ""
                               ""
                               "}"
                               "QSpinBox::down-button:hover"
                               "{"
                                  "border: 5px outset red;"


                                "}"
                               );

}

MainWindow::~MainWindow()
{
    delete ui;
}
