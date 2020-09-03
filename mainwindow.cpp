#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stitchplayer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Code to open up notes.txt open program opening
    QFile file("assets/notes.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in (&file);
    QString text = in.readAll();
    ui->notes->setText(text);
    file.close();

    //Set Window Title
    setWindowTitle("embTools");
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_actionStitch_Run_Time_Calculator_triggered()
{


    StitchPlayer = new stitchPlayer(this);

    StitchPlayer ->show();

}

void MainWindow::on_actionUnit_Conversions_triggered()
{
    UnitConversion = new unitConversion(this);
    UnitConversion -> show();
}

void MainWindow::on_save_clicked()
{

    QFile file("assets/notes.txt");
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    QString text = ui-> notes -> toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}





void MainWindow::on_actionDatabase_triggered()
{
    Database = new database(this);
    Database->show();
}

void MainWindow::on_actionVender_Database_triggered()
{
    VendorDatabase = new vendorDatabase(this);
    VendorDatabase->show();
}

void MainWindow::on_actionQuote_Sheet_triggered()
{
    QuoteSheet=new quoteSheet(this);
    QuoteSheet->show();
}

void MainWindow::on_actionContribute_triggered()
{
    Contribute=new contribute(this);
    Contribute->show();
}

void MainWindow::on_actionAbout_triggered()
{
    About = new about(this);
    About->show();
}
