#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "paintscene.h"
#include "colortile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_undoButton_clicked();
    void on_redoButton_clicked();
    void on_cleanupButton_clicked();
    void on_ShapeTypeComboBox_currentIndexChanged(const QString &arg1);
    void on_PenSizeSlider_valueChanged(int value);
    void on_PenSizeSpinBox_valueChanged(int arg1);
    void slotPenColorChanged(const QString& colorName);

signals:
    void signalPenSizeChanged(int penSize);
    void signalShapeTypeChanged(const QString &shapeType);
    void signalPenColorChanged(const QColor color);

private:
    void colorPaletteInstall();
    QVector<ColorTile*> _colorTiles;
    Ui::MainWindow *ui;
    PaintScene *p_Scene;

    int m_iPenSize;
    QString m_sShapeType;
};

#endif // MAINWINDOW_H
