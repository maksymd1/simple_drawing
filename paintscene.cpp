#include <QDebug>

#include "paintscene.h"
#include "scenecommands.h"

PaintScene::PaintScene(QObject *parent) :
    QGraphicsScene(parent),
    isDrawing(false),
    m_iPenSize(1),
    m_qcColor(Qt::black),
    m_sFigureType(""),
    p_SIfigure(nullptr)
{
    p_undoStack = new QUndoStack(this);
}

PaintScene::~PaintScene()
{
    p_SIfigure = nullptr;
    delete p_SIfigure;
    p_undoStack->clear();
}

void PaintScene::clearScene()
{
    this->clear();
    this->update();
    p_undoStack->clear();
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_sFigureType == "")
        return;

    isDrawing = true;
    qpMousePos = event->scenePos();

    if(m_sFigureType == "Line") {
        p_SIfigure = new Line(qpMousePos, m_iPenSize, m_qcColor);
    } else if(m_sFigureType == "Rect") {
        p_SIfigure = new Rect(qpMousePos, m_iPenSize, m_qcColor);
    } else if(m_sFigureType == "Ellipse") {
        p_SIfigure = new Ellipse(qpMousePos, m_iPenSize, m_qcColor);
    } else if(m_sFigureType == "Curve") {
        p_SIfigure = new Curve(qpMousePos, m_iPenSize, m_qcColor);
    }
    if(p_SIfigure != nullptr) {
        addItem(p_SIfigure);
    }
}

void PaintScene::slotSetPenSize(int penSize)
{
    m_iPenSize = penSize;
}

void PaintScene::slotSetFigureType(const QString& figure)
{
    m_sFigureType = figure;
}

void PaintScene::slotSetPenColor(const QColor& color)
{
    m_qcColor = color;
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    p_undoStack->push(new SceneCommands(this, p_SIfigure) );

    isDrawing = false;
    p_SIfigure = nullptr;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (isDrawing) {
        p_SIfigure->updatePosition(event->scenePos());
     }
    this->update();
}

void PaintScene::undoLastAction()
{
    p_undoStack->undo();
    this->update();
}

void PaintScene::redoLastAction()
{
    p_undoStack->redo();
    this->update();
}

