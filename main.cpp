#include "mainwindow.h"

#include <QApplication>
#include <QTimer>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("assets/embToolsLogo.png"));
    splash->show();

    MainWindow w;

    QTimer::singleShot(2500, splash, SLOT(close()));
    QTimer::singleShot(2500,&w, SLOT(show()));

    w.show();
    return a.exec();
}
