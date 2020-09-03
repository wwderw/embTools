#include "unitconversion.h"
#include "ui_unitconversion.h"

unitConversion::unitConversion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unitConversion)
{
    ui->setupUi(this);


    //Set the Window Titles
    setWindowTitle("embTools - Unit Conversions");
}

unitConversion::~unitConversion()
{
    delete ui;
}

void unitConversion::on_in_valueChanged(double arg1)
{
    double in = ui -> in -> value();

    double answer = in * 25.4;

    ui -> mm -> setValue(answer);

}

void unitConversion::on_mm_valueChanged(double arg1)
{
    double mm = ui -> mm -> value();
    double answer = mm / 25.4;

    ui -> in -> setValue(answer);
}

void unitConversion::on_in1_valueChanged(double arg1)
{
    double in = ui -> in1 -> value();
    double answer = in / 0.39370;

    ui -> cm -> setValue(answer);

}

void unitConversion::on_cm_valueChanged(double arg1)
{
    double cm =  ui -> cm -> value();
    double answer = cm * 0.39370;

    ui -> in1 -> setValue(answer);
}

void unitConversion::on_px_valueChanged(double arg1)
{
    double px = ui -> px -> value();
    double answer = px * 0.2645833333;

    ui -> mm1 -> setValue(answer);
}

void unitConversion::on_mm1_valueChanged(double arg1)
{
    double mm = ui -> mm1 -> value();
    double answer = mm / 0.2645833333;

    ui -> px -> setValue(answer);
}

void unitConversion::on_in2_valueChanged(double arg1)
{
    double in = ui -> in2 -> value();
    double answer = in * 72;

    ui -> pts -> setValue(answer);
}

void unitConversion::on_pts_valueChanged(double arg1)
{
    double pts = ui -> pts -> value();
    double answer = pts / 72;

    ui -> in2 -> setValue(answer);
}
