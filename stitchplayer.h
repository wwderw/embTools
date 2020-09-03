#ifndef STITCHPLAYER_H
#define STITCHPLAYER_H

#include <QDialog>

namespace Ui {
class stitchPlayer;
}

class stitchPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit stitchPlayer(QWidget *parent = nullptr);
    ~stitchPlayer();

private slots:
    void on_submit_clicked();

private:
    Ui::stitchPlayer *ui;
};

#endif // STITCHPLAYER_H
