#ifndef THREADCHART_H
#define THREADCHART_H

#include <QDialog>

namespace Ui {
class threadChart;
}

class threadChart : public QDialog
{
    Q_OBJECT

public:
    explicit threadChart(QWidget *parent = nullptr);
    ~threadChart();

private:
    Ui::threadChart *ui;
};

#endif // THREADCHART_H
