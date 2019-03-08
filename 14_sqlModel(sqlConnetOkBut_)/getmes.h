#ifndef GETMES_H
#define GETMES_H

#include <QWidget>

namespace Ui {
class GetMes;
}

class GetMes : public QWidget
{
    Q_OBJECT

public:
    explicit GetMes(QWidget *parent = nullptr);
    ~GetMes();
bool openNext();

private slots:
    void on_pushButton_clicked();

    void on_Process_clicked();

    void on_RunSql_clicked();

private:
    Ui::GetMes *ui;
    QString process_start_str ;
    QString HostName_str ;
    QString Database_str ;
    QString UserName_str ;
    QString Password_str ;
    QString connect_ok ;
};

#endif // GETMES_H
