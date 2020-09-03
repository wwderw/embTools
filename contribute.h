#ifndef CONTRIBUTE_H
#define CONTRIBUTE_H

#include <QDialog>

namespace Ui {
class contribute;
}

class contribute : public QDialog
{
    Q_OBJECT

public:
    explicit contribute(QWidget *parent = nullptr);
    ~contribute();

private:
    Ui::contribute *ui;
};

#endif // CONTRIBUTE_H
