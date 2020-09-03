#include "stitchplayer.h"
#include "ui_stitchplayer.h"
#include <stdlib.h>
#include <string>


stitchPlayer::stitchPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stitchPlayer)
{
    ui->setupUi(this);

    //Setup Window Titles
    setWindowTitle("embTools - Stitch Run Time Calculator");
}

stitchPlayer::~stitchPlayer()
{
    delete ui;
}

void stitchPlayer::on_submit_clicked()
{

    int designStitch = ui -> stitch -> value();
    int machineSpeed = ui -> speed -> value();
    int designTrim = ui -> trim -> value();
    int designTrimSpeed = ui -> trimSpeed -> value();

    int calculate = ((designStitch / machineSpeed)+((designTrim * designTrimSpeed) / 60));

    ui-> answer -> display(calculate);
}
