#include "dotsignal.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

Dotsignal::Dotsignal(QGraphicsItem *parentItem, QObject *parent) :
    QObject(parent)
{
    setParentItem(parentItem);
    setAcceptHoverEvents(true);
    setBrush(QBrush(Qt::red));
    setRect(-4,-4,8,8);
    setDotFlags(0);
}

Dotsignal::Dotsignal(QPointF pos, QGraphicsItem *parentItem, QObject *parent) :
    QObject(parent)
{
    setParentItem(parentItem);
    setAcceptHoverEvents(true);
    setBrush(QBrush(Qt::black));
    setRect(-4,-4,8,8);
    setPos(pos);
    setPreviousPosition(pos);
    setDotFlags(0);
}

Dotsignal::~Dotsignal()
{

}

QPointF Dotsignal::previousPosition() const
{
    return m_previousPosition;
}

void Dotsignal::setPreviousPosition(const QPointF previousPosition)
{
    if (m_previousPosition == previousPosition)
        return;

    m_previousPosition = previousPosition;
    emit previousPositionChanged();
}

void Dotsignal::setDotFlags(unsigned int flags)
{
    m_flags = flags;
}

void Dotsignal::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_flags & Movable){
        auto dx = event->scenePos().x() - m_previousPosition.x();
        auto dy = event->scenePos().y() - m_previousPosition.y();
        moveBy(dx,dy);
        setPreviousPosition(event->scenePos());
        emit signalMove(this, dx, dy);
    } else {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void Dotsignal::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_flags & Movable){
        setPreviousPosition(event->scenePos());
    } else {
        QGraphicsItem::mousePressEvent(event);
    }
}

void Dotsignal::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMouseRelease();
    QGraphicsItem::mouseReleaseEvent(event);
}

void Dotsignal::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    setBrush(QBrush(Qt::red));
}

void Dotsignal::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    setBrush(QBrush(Qt::red));
}
