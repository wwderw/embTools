#ifndef VENDORDATABASE_H
#define VENDORDATABASE_H

#include <QDialog>
#include <QTableView>
#include <QSqlDatabase>
#include <QDebug>

namespace Ui {
class vendorDatabase;
}

class vendorDatabase : public QDialog
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
            mydb.setDatabaseName("assets/vendor.db");

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
    explicit vendorDatabase(QWidget *parent = nullptr);
    ~vendorDatabase();

private slots:
    void on_client_clicked();

    void on_addClient_clicked();

    void on_delete_2_clicked();

    void on_update_clicked();

    void on_sortName_clicked();

    void on_sortBus_clicked();

private:
    Ui::vendorDatabase *ui;
};

#endif // VENDORDATABASE_H
