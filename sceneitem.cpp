#include "sceneitem.h"
#include <QDebug>

 /// ------------------------------- LINE ----------------------------------------
Line::Line(QPointF topLeftPos, int penSize, QColor color):
    m_iPenSize(penSize),
    m_qcColor(color),
    line(topLeftPos, topLeftPos)
{

}

void Line::updatePosition(QPointF &pos)
{
    line.setP2(pos);
}

QRectF Line::boundingRect() const
{
    return QRectF(line.p1(), line.p2());
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setWidth(m_iPenSize);
    pen.setColor(m_qcColor);
    painter->setPen(pen);
    painter->drawLine(line);
}
 /// ------------------------------- Rect ----------------------------------------
Rect::Rect(QPointF topLeftPos, int penSize, QColor color):
    m_iPenSize(penSize),
    m_qcColor(color),
    rectangle(topLeftPos, topLeftPos)
{

}

void Rect::updatePosition(QPointF &pos)
{
    rectangle.setBottomRight(pos);
}

QRectF Rect::boundingRect() const
{
    return rectangle;
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setWidth(m_iPenSize);
    pen.setColor(m_qcColor);
    painter->setPen(pen);
    painter->drawRect(rectangle);
}

/// ------------------------------- Ellipse ----------------------------------------
Ellipse::Ellipse(QPointF topLeftPos, int penSize, QColor color):
   m_iPenSize(penSize),
   m_qcColor(color),
   ellipse(topLeftPos, topLeftPos)
{

}

void Ellipse::updatePosition(QPointF &pos)
{
   ellipse.setBottomRight(pos);
}

QRectF Ellipse::boundingRect() const
{
   return ellipse;
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   Q_UNUSED(option);
   Q_UNUSED(widget);

   QPen pen;
   pen.setWidth(m_iPenSize);
   pen.setColor(m_qcColor);
   painter->setPen(pen);
   painter->drawEllipse(ellipse);
}

/// ------------------------------- Curve ----------------------------------------
Curve::Curve(QPointF topLeftPos, int penSize, QColor color):
   m_iPenSize(penSize),
   m_qcColor(color)
{
    curvedLine<<topLeftPos;
}

void Curve::updatePosition(QPointF &pos)
{
    curvedLine << pos;
}

QRectF Curve::boundingRect() const
{
   return curvedLine.boundingRect();
}

void Curve::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   Q_UNUSED(option);
   Q_UNUSED(widget);

   QPen pen;
   pen.setWidth(m_iPenSize);
   pen.setColor(m_qcColor);
   painter->setPen(pen);
   painter->drawPolyline(curvedLine);
}



