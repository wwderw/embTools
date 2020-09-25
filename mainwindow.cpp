#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stitchplayer.h"
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Code to open up notes.txt with program opening
    QFile file("assets/notes.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in (&file);
    QString text = in.readAll();
    ui->notes->setText(text);
    file.close();

    //Code to open up quotes.txt when opening program
    QFile quotes("assets/quotes.txt");
    quotes.open(QIODevice::ReadOnly);
    QTextStream qu(&quotes);
    QString quote = qu.readAll();
    ui->quotes->setText(quote);
    quotes.close();

    //Code to open up toDo.txt when opening program
    QFile toDo("assets/toDo.txt");
    toDo.open(QIODevice::ReadOnly);
    QTextStream to(&toDo);
    QString ToDo = to.readAll();
    ui->toDo->setText(ToDo);
    toDo.close();

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

void MainWindow::on_actionAbout_triggered()
{
    About = new about(this);
    About->show();
}

void MainWindow::on_actionReport_Bugs_Suggest_Features_General_Comments_triggered()
{
    QString bugs = "https://github.com/wwderw/embTools/issues";
    QDesktopServices::openUrl(bugs);
}

void MainWindow::on_actionGet_Latest_Release_triggered()
{
    QString release = "https://github.com/wwderw/embTools/releases";
    QDesktopServices::openUrl(release);
}

void MainWindow::on_actionGrab_Source_Code_triggered()
{
    QString code = "https://github.com/wwderw/embTools";
    QDesktopServices::openUrl(code);
}


void MainWindow::on_saveQuotes_clicked()
{
    QFile file("assets/quotes.txt");
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    QString text = ui-> quotes -> toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_saveToDo_clicked()
{
    QFile file("assets/toDo.txt");
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    QString text = ui-> toDo -> toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionVideos_triggered()
{
    QString madeira = "https://www.madeirausa.com/education/";
    QDesktopServices::openUrl(madeira);
}

void MainWindow::on_actionContact_triggered()
{
    QString wwd = "https://www.facebook.com/WildWDesigns/";
    QDesktopServices::openUrl(wwd);
}

void MainWindow::on_customDigitizing_triggered()
{
    QString wwd = "https://www.facebook.com/WildWDesigns/";
    QDesktopServices::openUrl(wwd);
}

void MainWindow::on_actionEmbroidery_Library_triggered()
{
    QString embLib = "https://www.emblibrary.com/EL/Default.aspx";
    QDesktopServices::openUrl(embLib);
}

void MainWindow::on_actionDakota_Collectibles_triggered()
{
    QString DC = "https://www.dakotacollectibles.com/comm/default.asp";
    QDesktopServices::openUrl(DC);
}
