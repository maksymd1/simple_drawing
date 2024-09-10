#ifndef SCENEITEM_H
#define SCENEITEM_H

#include <QGraphicsItem>
#include <QPainter>

class Sceneitem : public QGraphicsItem
{
public:
    Sceneitem() {}
    virtual void updatePosition(QPointF &pos) = 0;

private:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
};

// LINE ----------------------------

class Line : public Sceneitem
{
public:
    Line(QPointF topLeftPos, int penSize, QColor color);
    QRectF boundingRect() const;
    void updatePosition(QPointF &pos);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int m_iPenSize;
    QColor m_qcColor;

    QLineF line;
};

// Rect ---------------------------

class Rect : public Sceneitem
{
public:
    Rect(QPointF topLeftPos, int penSize, QColor color);
    QRectF boundingRect() const;
    void updatePosition(QPointF &pos);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int m_iPenSize;
    QColor m_qcColor;

    QRectF rectangle;
};

// Ellipse -----------------------------

class Ellipse : public Sceneitem
{
public:
    Ellipse(QPointF topLeftPos, int penSize, QColor color);
    QRectF boundingRect() const;
    void updatePosition(QPointF &pos);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int m_iPenSize;
    QColor m_qcColor;

    QRectF ellipse;
};

// Curve -----------------------------

class Curve : public Sceneitem
{
public:
    Curve(QPointF topLeftPos, int penSize, QColor color);
    QRectF boundingRect() const;
    void updatePosition(QPointF &pos);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int m_iPenSize;
    QColor m_qcColor;

    QPolygonF curvedLine;
};



#endif // SCENEITEM_H
