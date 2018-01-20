#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QRegExp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
