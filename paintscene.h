#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QPaintEvent>
#include <QUndoStack>
#include <memory>

#include "sceneitem.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    PaintScene(QObject *parent = 0);
    ~PaintScene();

    void undoLastAction();
    void redoLastAction();
    void clearScene();

public slots:
    void slotSetPenSize(int penSize);
    void slotSetFigureType(const QString& figure);
    void slotSetPenColor(const QColor& color);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

private:
    QPointF qpMousePos;
    bool isDrawing;
    int m_iPenSize;
    QColor m_qcColor;
    QString m_sFigureType;

    Sceneitem *p_SIfigure;
    //std::unique_ptr<Sceneitem> p_SIfigure;
    QUndoStack *p_undoStack;
};

#endif // PAINTSCENE_H
