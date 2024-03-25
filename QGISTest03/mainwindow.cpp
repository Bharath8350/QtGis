#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mapCanvas = new QgsMapCanvas();

    // Create a vector layer
    QString vectorFilePath = "QGISTest03_MapData/IND_adm1.shp";        //! India State Border Map
    QString baseName = QFileInfo(vectorFilePath).baseName();
    QgsVectorLayer *vectorLayer = new QgsVectorLayer(vectorFilePath, baseName, "ogr");

    // Check if the layer was loaded successfully
    if (!vectorLayer->isValid())
    {
        QMessageBox::critical(nullptr, "Error", "Failed to load vector layer!");
    }

    // Refresh the map
    mapCanvas->setDestinationCrs(QgsCoordinateReferenceSystem::fromEpsgId(4326));

    // Add the layer to the map
    QgsProject::instance()->addMapLayer(vectorLayer);
    mapCanvas->setExtent(vectorLayer->extent());
    layers.append(vectorLayer);
    mapCanvas->setLayers(QList<QgsMapLayer*>() << layers);

    mapCanvas->freeze(false);
    mapCanvas->refresh();
    ui->gridLayout->addWidget(mapCanvas, 1, 0, 1, 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
