#include "contribute.h"
#include "ui_contribute.h"

contribute::contribute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contribute)
{
    ui->setupUi(this);

    //Setup Window Titles
    setWindowTitle("embTools - Contribute");
    ui->link->setOpenExternalLinks(true);
}

contribute::~contribute()
{
    delete ui;
}
