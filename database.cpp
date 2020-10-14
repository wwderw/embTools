#include "database.h"
#include "ui_database.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlQueryModel>
#include <QDebug>
#include <iostream>
#include <QScrollBar>
#include <QFile>

database::database(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);
    //Setup Window Titles
    setWindowTitle("embTools - Client/Vendor Database");




}

database::~database()
{

    delete ui;
}


void database::on_addClient_clicked()
{
  if (ui->clientVendor->currentIndex() == 0){
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

    query.prepare("INSERT INTO Client (Name, Email, Phone, Mobile, Address, BillingAddress, BusinessName, Website) VALUES ('"+name+"', '"+email+"', '"+phone+"', '"+mobile+"', '"+address+"', '"+billing+"', '"+busName+"', '"+website+"')");
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


  }else{
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
  }



}

void database::on_delete_2_clicked()
{

 if(ui->clientVendor->currentIndex() == 0){
    QSqlQueryModel * model = new QSqlQueryModel();
    connOpen();
    QSqlQuery query;

    QString name;
    name=ui->name->text();


    query.prepare("DELETE FROM Client where Name == '"+name+"'");
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
 }else{
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
 }


}

void database::on_update_clicked()
{
  if(ui->clientVendor->currentIndex() == 0){
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

    query.prepare("UPDATE Client set Name='"+name+"', Email='"+email+"', Phone='"+phone+"', Mobile='"+mobile+"', Address='"+address+"', BillingAddress='"+billing+"', BusinessName='"+busName+"', Website='"+website+"' where Name='"+name+"'");
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

  }else{
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
  }


}

void database::on_sortName_clicked()
{
 if(ui->clientVendor->currentIndex() == 0){
    QSqlQueryModel * model = new QSqlQueryModel();
    connOpen();
    QSqlQuery query;

    query.prepare("SELECT * FROM Client ORDER BY 1 ASC");
    query.exec();

    model->setQuery(query);

    //Override the 256 default row limit

    while (model->canFetchMore())
        model->fetchMore();


    ui-> display ->setModel(model);
    connClose();

 }else{
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

}

void database::on_sortBus_clicked()
{
  if (ui->clientVendor->currentIndex() == 0){
    QSqlQueryModel * model = new QSqlQueryModel();
    connOpen();
    QSqlQuery query;

    query.prepare("SELECT * FROM Client ORDER BY 7 ASC");
    query.exec();

    model->setQuery(query);

    //Override the 256 default row limit

    while (model->canFetchMore())
        model->fetchMore();


    ui-> display ->setModel(model);
    connClose();

  }else{
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
}



void database::on_clientVendor_activated(const QString &arg1)
{
    if (ui->clientVendor->currentIndex() == 0){
        QSqlQueryModel * model = new QSqlQueryModel();
        connOpen();

        QSqlQuery query;
        query.prepare("SELECT * FROM Client");

        query.exec();
        model->setQuery(query);

        //Override the 256 default row limit

        while (model->canFetchMore())
            model->fetchMore();


        ui-> display ->setModel(model);

        qDebug()<< (model->rowCount());
        connClose();
    }else{
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
}

void database::on_export_2_clicked()
{
    if(ui->clientVendor->currentIndex() == 0){
           connOpen();
           QSqlQueryModel * model = new QSqlQueryModel();
           QSqlQuery query;
           QString series;


           query.prepare("SELECT * FROM Client ORDER BY 2 ASC");

           query.exec();
           model->setQuery(query);

           //Override the 256 default row limit

           while (model->canFetchMore())
               model->fetchMore();

           ui-> display ->setModel(model);
           connClose();

           //Collect Data for Exporting
           QString seriesData;
           int rows = model -> rowCount();
           int cols = model-> columnCount();

           for (int i = 0; i<rows; i++){
               for (int j = 0; j<cols; j++){
               seriesData += model->data(model->index(i,j)).toString();
               seriesData += ", ";

               }
               seriesData += "\n" ;
           }

           QFile csv("Clients.csv");
           if(csv.open(QIODevice::WriteOnly)){
               QTextStream output(&csv);
               output<<seriesData;
               csv.close();
           }
           connClose();
    }else{
        connOpen();
        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery query;
        QString series;


        query.prepare("SELECT * FROM Vendor ORDER BY 2 ASC");

        query.exec();
        model->setQuery(query);

        //Override the 256 default row limit

        while (model->canFetchMore())
            model->fetchMore();

        ui-> display ->setModel(model);
        connClose();

        //Collect Data for Exporting
        QString seriesData;
        int rows = model -> rowCount();
        int cols = model-> columnCount();

        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
            seriesData += model->data(model->index(i,j)).toString();
            seriesData += ", ";

            }
            seriesData += "\n" ;
        }

        QFile csv("Vendors.csv");
        if(csv.open(QIODevice::WriteOnly)){
            QTextStream output(&csv);
            output<<seriesData;
            csv.close();
        }
        connClose();
    }
}
