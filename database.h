#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include <QTableView>
#include <QSqlDatabase>
#include <QDebug>

namespace Ui {
class database;
}

class database : public QDialog
{
    Q_OBJECT

//Functions for Database

    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    };
    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("assets/client.db");

        if (!mydb.open())
        {
            qDebug()<<("Connection Failed!!");
            return false;
        }else
        {
            qDebug()<<("Connected");
            return true;
        }
    };


//End functions for database

public:
    explicit database(QWidget *parent = nullptr);
    ~database();




private slots:




    void on_addClient_clicked();

    void on_delete_2_clicked();

    void on_update_clicked();

    void on_sortName_clicked();

    void on_sortBus_clicked();



    void on_clientVendor_activated(const QString &arg1);

    void on_export_2_clicked();

private:
    Ui::database *ui;



};

#endif // DATABASE_H
