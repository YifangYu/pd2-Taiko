#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    std::srand(std::time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Takio by YifangYu");
    w.setWindowIcon(QIcon(":/new/img/red.jpg"));
    w.show();

    return a.exec();
}
