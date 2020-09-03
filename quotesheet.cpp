#include "quotesheet.h"
#include "ui_quotesheet.h"
#include <QPrinter>
#include <QtPrintSupport>
#include <QPrintDialog>
#include <QPixmap>
#include <QDialog>
#include <QScreen>
#include <QDebug>
#include <QScrollBar>
quoteSheet::quoteSheet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quoteSheet)
{
    ui->setupUi(this);
    //Setup Window Titles
    setWindowTitle("embTools - Quote Sheet");
}

quoteSheet::~quoteSheet()
{
    delete ui;
}

void quoteSheet::on_getQuote_clicked()
{
    QString text;
    int qty01, qty02, qty03, qty04, qty05, qty06, qty07, qty08, qty09, qty10;
    double base01, base02, base03, base04, base05, base06, base07, base08, base09,base10;
    double product;

    double mark;
    double dis;
    double markup;
    double discount;
    int stitches;
    double setup;
    double stitchPrice;
    double digitizing;
    double quote;

    qty01=ui->qty01->value();
    qty02=ui->qty02->value();
    qty03=ui->qty03->value();
    qty04=ui->qty04->value();
    qty05=ui->qty05->value();
    qty06=ui->qty06->value();
    qty07=ui->qty07->value();
    qty08=ui->qty08->value();
    qty09=ui->qty09->value();
    qty10=ui->qty10->value();

    base01=ui->base01->value();
    base01=ui->base01->value();
    base01=ui->base01->value();
    base01=ui->base01->value();
    base01=ui->base01->value();
    base01=ui->base01->value();
    base01=ui->base01->value();
    base01=ui->base01->value();
    base01=ui->base01->value();
    base01=ui->base01->value();

    product=(qty01*base01) + (qty02*base02) + (qty03*base03) + (qty04*base04) + (qty05*base05) + (qty06*base06) + (qty07*base07) + (qty08*base08) + (qty09*base09) + (qty10*base10);

    mark=ui->markup->value();
    dis=ui->discount->value();


    markup = ((mark / 100) * product) + product;
    discount = (dis / 100) * product;

    stitches = ui->stitch->value();
    setup=ui->setup->value();
    stitchPrice=ui->priceK->value();

    digitizing = (stitchPrice / 1000) * stitches;

    quote = setup + markup + (digitizing - discount);



    ui->quoteDisplay->display(quote);





}

void quoteSheet::on_print_clicked()
{


    QPrinter printer;
    printer.setDocName("Invoice.pdf");
    printer.setPrinterName("Printer Name");
    printer.setFullPage(true);
    printer.setResolution(300);
    printer.setOrientation(QPrinter::Portrait);
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec()==QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }


    QPainter painter;
    painter.begin(&printer);
    double xscale=printer.pageRect().width()/ double(ui->scroll->width());
    double yscale=printer.pageRect().height()/ double(ui->scroll->height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x(), printer.paperRect().y());
    painter.scale(scale, scale);
    painter.translate(0, 0);
    ui->scroll->render(&painter);

}
