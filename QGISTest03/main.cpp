#include "mainwindow.h"

#include <QApplication>

#include <qgsapplication.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QgsApplication::setPrefixPath("/path/to/qgis/installation", true);
    QgsApplication::initQgis();

    MainWindow w;
    w.show();

    return a.exec();
}
