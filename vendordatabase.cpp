#include "vendordatabase.h"
#include "ui_vendordatabase.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlQueryModel>
#include <QDebug>
#include <iostream>

vendorDatabase::vendorDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vendorDatabase)
{
    ui->setupUi(this);
    //Setup Window Titles
    setWindowTitle("embTools - Vendor Database");
}

vendorDatabase::~vendorDatabase()
{
    delete ui;
}

void vendorDatabase::on_client_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    connOpen();

    QSqlQuery query;
    query.prepare("SELECT * FROM Vendor");

    query.exec();
    model->setQuery(query);

    //Override the 256 default row limit

    while (model->canFetchMore())
        model->fetchMore();


    ui-> display ->setModel(model);

    qDebug()<< (model->rowCount());
    connClose();
}

void vendorDatabase::on_addClient_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    connOpen();
    QSqlQuery query;

    QString name, email, phone, mobile, address, billing, busName, website;
    name=ui->name->text();
    email=ui->email->text();
    phone=ui->phone->text();
    mobile=ui->mobile->text();
    address=ui->address->text();
    billing=ui->billing->text();
    busName=ui->busName->text();
    website=ui->website->text();

    query.prepare("INSERT INTO Vendor (Name, Email, Phone, Mobile, Address, BillingAddress, BusinessName, Website) VALUES ('"+name+"', '"+email+"', '"+phone+"', '"+mobile+"', '"+address+"', '"+billing+"', '"+busName+"', '"+website+"')");
    query.exec();
    connClose();


   //Clear Entry Fields
   ui->name->clear();
   ui->email->clear();
   ui->phone->clear();
   ui->mobile->clear();
   ui->address->clear();
   ui->billing->clear();
   ui->busName->clear();
   ui->website->clear();

   on_client_clicked();
}

void vendorDatabase::on_delete_2_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    connOpen();
    QSqlQuery query;

    QString name;
    name=ui->name->text();


    query.prepare("DELETE FROM Vendor where Name == '"+name+"'");
    query.exec();
    connClose();


   //Clear Entry Fields
   ui->name->clear();
   ui->email->clear();
   ui->phone->clear();
   ui->mobile->clear();
   ui->address->clear();
   ui->billing->clear();
   ui->busName->clear();
   ui->website->clear();

   on_client_clicked();
}

void vendorDatabase::on_update_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    connOpen();
    QSqlQuery query;

    QString name, email, phone, mobile, address, billing, busName, website;
    name=ui->name->text();
    email=ui->email->text();
    phone=ui->phone->text();
    mobile=ui->mobile->text();
    address=ui->address->text();
    billing=ui->billing->text();
    busName=ui->busName->text();
    website=ui->website->text();

    query.prepare("UPDATE Vendor set Name='"+name+"', Email='"+email+"', Phone='"+phone+"', Mobile='"+mobile+"', Address='"+address+"', BillingAddress='"+billing+"', BusinessName='"+busName+"', Website='"+website+"' where Name='"+name+"'");
    query.exec();
    connClose();


   //Clear Entry Fields
   ui->name->clear();
   ui->email->clear();
   ui->phone->clear();
   ui->mobile->clear();
   ui->address->clear();
   ui->billing->clear();
   ui->busName->clear();
   ui->website->clear();

   on_client_clicked();
}

void vendorDatabase::on_sortName_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    connOpen();
    QSqlQuery query;

    query.prepare("SELECT * FROM Vendor ORDER BY 1 ASC");
    query.exec();

    model->setQuery(query);

    //Override the 256 default row limit

    while (model->canFetchMore())
        model->fetchMore();


    ui-> display ->setModel(model);
    connClose();
}

void vendorDatabase::on_sortBus_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    connOpen();
    QSqlQuery query;

    query.prepare("SELECT * FROM Vendor ORDER BY 7 ASC");
    query.exec();

    model->setQuery(query);

    //Override the 256 default row limit

    while (model->canFetchMore())
        model->fetchMore();


    ui-> display ->setModel(model);
    connClose();
}
