#include <QtWidgets>

#include "diagramitem.h"

DiagramItem::DiagramItem(DiagramType diagramType, QGraphicsItem *item)
    : QGraphicsPolygonItem(item)
{
    if (diagramType == Box) {
        boxPolygon << QPointF(0, 0) << QPointF(0, 30) << QPointF(30, 30)
                   << QPointF(30, 0) << QPointF(0, 0);
        setPolygon(boxPolygon);
    } else {
        trianglePolygon << QPointF(15, 0) << QPointF(30, 30) << QPointF(0, 30)
                        << QPointF(15, 0);
        setPolygon(trianglePolygon);
    }

    QColor color(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256));
    QBrush brush(color);
    setBrush(brush);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
}
