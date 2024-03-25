#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgsrubberband.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileInfo>
#include <QComboBox>

#include <qgsapplication.h>
#include <qgsvectorlayer.h>
#include <qgsproject.h>
#include <qgsmapcanvas.h>
#include <qgsrasterlayer.h>
#include <qgsmarkersymbol.h>
#include <qgsmarkersymbollayer.h>
#include <qgssinglesymbolrenderer.h>
#include <qgssvgannotation.h>
#include <qgsannotationmanager.h>
#include <qgsmaptool.h>
#include <qgsmaptoolemitpoint.h>
#include <qgsrectangle.h>
#include <qgsrubberband.h>
#include <qgsmapmouseevent.h>
#include <qgsmaptoolidentify.h>
#include <qgsmaptoolidentifyfeature.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QgsMapCanvas *mapCanvas;
    QList<QgsMapLayer*> layers;
    QgsVectorLayer *markerLayer;
};

#endif // MAINWINDOW_H
