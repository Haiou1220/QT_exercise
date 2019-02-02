#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_switch_windows_clicked();

    void on_switch_1_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_label_2_linkActivated(const QString &link);

    void on_lcdNumber_overflow();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
     QMovie* pMyMove ;
};

#endif // MAINWINDOW_H
