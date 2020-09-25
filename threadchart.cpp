#include "threadchart.h"
#include "ui_threadchart.h"

threadChart::threadChart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::threadChart)
{
    ui->setupUi(this);

    //Set Window Title
    setWindowTitle("embTools - Database of Thread Charts");
}

threadChart::~threadChart()
{
    delete ui;
}
