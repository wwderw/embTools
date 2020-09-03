#ifndef QUOTESHEET_H
#define QUOTESHEET_H

#include <QDialog>

namespace Ui {
class quoteSheet;
}

class quoteSheet : public QDialog
{
    Q_OBJECT

public:
    explicit quoteSheet(QWidget *parent = nullptr);
    ~quoteSheet();

private slots:
    void on_getQuote_clicked();

    void on_print_clicked();

private:
    Ui::quoteSheet *ui;
};

#endif // QUOTESHEET_H
