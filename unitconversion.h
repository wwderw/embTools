#ifndef UNITCONVERSION_H
#define UNITCONVERSION_H

#include <QDialog>

namespace Ui {
class unitConversion;
}

class unitConversion : public QDialog
{
    Q_OBJECT

public:
    explicit unitConversion(QWidget *parent = nullptr);
    ~unitConversion();

private slots:
    void on_in_valueChanged(double arg1);

    void on_mm_valueChanged(double arg1);

    void on_in1_valueChanged(double arg1);

    void on_cm_valueChanged(double arg1);

    void on_px_valueChanged(double arg1);

    void on_mm1_valueChanged(double arg1);

    void on_in2_valueChanged(double arg1);

    void on_pts_valueChanged(double arg1);

private:
    Ui::unitConversion *ui;
};

#endif // UNITCONVERSION_H
