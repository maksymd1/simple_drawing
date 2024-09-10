#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_iPenSize(4),
    m_sShapeType("")
{
    ui->setupUi(this);
    p_Scene = new PaintScene;
    ui->graphicsView->setScene(p_Scene);
    ui->graphicsView->setSceneRect(ui->graphicsView->rect());
    colorPaletteInstall();

    connect(this, SIGNAL(signalShapeTypeChanged(QString) ), p_Scene, SLOT(slotSetFigureType(QString)) );
    connect(this, SIGNAL(signalPenSizeChanged(int)), p_Scene, SLOT(slotSetPenSize(int)) );
    connect(this, SIGNAL(signalPenColorChanged(QColor)), p_Scene, SLOT(slotSetPenColor(QColor)) );

    slotPenColorChanged("black");
    emit signalShapeTypeChanged(ui->ShapeTypeComboBox->itemText(0));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete p_Scene;
    _colorTiles.clear();
}

void MainWindow::on_undoButton_clicked()
{
    if(p_Scene) {
        p_Scene->undoLastAction();
    }
}

void MainWindow::on_redoButton_clicked()
{
    if(p_Scene) {
        p_Scene->redoLastAction();
    }
}

void MainWindow::on_cleanupButton_clicked()
{
    p_Scene->clearScene();
}

void MainWindow::on_ShapeTypeComboBox_currentIndexChanged(const QString &arg1)
{
    if(m_sShapeType != arg1) {
        m_sShapeType = arg1;
        emit signalShapeTypeChanged(m_sShapeType);
    }
}

void MainWindow::on_PenSizeSlider_valueChanged(int value)
{
    if(m_iPenSize != value) {
        m_iPenSize = value;
        ui->PenSizeSpinBox->setValue(m_iPenSize);
        emit signalPenSizeChanged(m_iPenSize);
    }
}

void MainWindow::on_PenSizeSpinBox_valueChanged(int arg1)
{
    if(m_iPenSize != arg1) {
        m_iPenSize = arg1;
        ui->PenSizeSlider->setValue(m_iPenSize);
        emit signalPenSizeChanged(m_iPenSize);
    }
}

void MainWindow::slotPenColorChanged(const QString& colorName)
{
    QString style = "background-color: " + colorName;
    ui->CurrentPenColor->setStyleSheet(style);
    emit signalPenColorChanged(QColor(colorName));
}

void MainWindow::colorPaletteInstall()
{
    QGridLayout *hlayout = new QGridLayout;
    hlayout->setSpacing(2);

    _colorTiles << new ColorTile("black");
    hlayout->addWidget(_colorTiles.last(), 0, 0);
    _colorTiles << new ColorTile("#bfbfbf");
    hlayout->addWidget(_colorTiles.last(), 0, 1);
    _colorTiles << new ColorTile("#000382");
    hlayout->addWidget(_colorTiles.last(), 0, 2);
    _colorTiles << new ColorTile("#007f80");
    hlayout->addWidget(_colorTiles.last(), 0, 3);
    _colorTiles << new ColorTile("#007e00");
    hlayout->addWidget(_colorTiles.last(), 0, 4);
    _colorTiles << new ColorTile("#807f00");
    hlayout->addWidget(_colorTiles.last(), 0, 5);
    _colorTiles << new ColorTile("#830300");
    hlayout->addWidget(_colorTiles.last(), 0, 6);
    _colorTiles << new ColorTile("#7f0a7d");
    hlayout->addWidget(_colorTiles.last(), 0, 7);

    _colorTiles << new ColorTile("#7f7f7f");
    hlayout->addWidget(_colorTiles.last(), 1, 0);
    _colorTiles << new ColorTile("white");
    hlayout->addWidget(_colorTiles.last(), 1, 1);
    _colorTiles << new ColorTile("#00037e");
    hlayout->addWidget(_colorTiles.last(), 1, 2);
    _colorTiles << new ColorTile("#00dff5");
    hlayout->addWidget(_colorTiles.last(), 1, 3);
    _colorTiles << new ColorTile("#00cf00");
    hlayout->addWidget(_colorTiles.last(), 1, 4);
    _colorTiles << new ColorTile("#fbec01");
    hlayout->addWidget(_colorTiles.last(), 1, 5);
    _colorTiles << new ColorTile("#f00b00");
    hlayout->addWidget(_colorTiles.last(), 1, 6);
    _colorTiles << new ColorTile("#f319f6");
    hlayout->addWidget(_colorTiles.last(), 1, 7);

    ui->colorWidget->setLayout(hlayout);

    foreach (auto &tile, _colorTiles) {
        connect(tile, SIGNAL(signalTileClicked(QString)), this, SLOT(slotPenColorChanged(QString)));
    }

}
