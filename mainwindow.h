#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stitchplayer.h"
#include "unitconversion.h"
#include "database.h"
#include "vendordatabase.h"
#include "quotesheet.h"
#include "about.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QSql>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionStitch_Run_Time_Calculator_triggered();

    void on_actionUnit_Conversions_triggered();

    void on_save_clicked();

    void on_actionQuit_triggered();





    void on_actionDatabase_triggered();

    void on_actionVender_Database_triggered();

    void on_actionQuote_Sheet_triggered();

    void on_actionAbout_triggered();

    void on_actionReport_Bugs_Suggest_Features_General_Comments_triggered();

    void on_actionGet_Latest_Release_triggered();

    void on_actionGrab_Source_Code_triggered();

    void on_saveQuotes_clicked();

    void on_saveToDo_clicked();

    void on_actionVideos_triggered();

    void on_actionContact_triggered();

    void on_customDigitizing_triggered();

    void on_actionEmbroidery_Library_triggered();

    void on_actionDakota_Collectibles_triggered();

private:
    Ui::MainWindow *ui;
    stitchPlayer *StitchPlayer;
    unitConversion *UnitConversion;
    database *Database;
    vendorDatabase *VendorDatabase;
    quoteSheet *QuoteSheet;
    about *About;

};
#endif // MAINWINDOW_H
