#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QObject>
#include <QGraphicsEllipseItem>

#include "dotsignal.h"
//class QGraphicsSceneMouseEvent;

class Ellipse : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
    Q_PROPERTY( QPointF previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY
                previousPositionChanged )

public:
    explicit Ellipse( QObject* parent = 0 );
    ~Ellipse();


    enum ActionStates
    {
        ResizeState = 0x01,
        RotationState = 0x02
    };

    enum CornerFlags
    {
        Top = 0x01,
        Bottom = 0x02,
        Left = 0x04,
        Right = 0x08,
        TopLeft = Top | Left,
        TopRight = Top | Right,
        BottomLeft = Bottom | Left,
        BottomRight = Bottom | Right
    };

    enum CornerGrabbers
    {
        GrabberTop = 0,
        GrabberBottom,
        GrabberLeft,
        GrabberRight,
        GrabberTopLeft,
        GrabberTopRight,
        GrabberBottomLeft,
        GrabberBottomRight
    };

    QPointF previousPosition() const;
    void setPreviousPosition( const QPointF previousPosition );

    void setRect( qreal x, qreal y, qreal w, qreal h );
    void setRect( const QRectF& rect );

signals:
    void rectChanged( Ellipse* rect );
    void previousPositionChanged();
    void clicked( Ellipse* rect );
    void signalMove( QGraphicsItem* item, qreal dx, qreal dy );


protected:
    void mouseMoveEvent( QGraphicsSceneMouseEvent* event ) override;
    void mousePressEvent( QGraphicsSceneMouseEvent* event ) override;
    void mouseReleaseEvent( QGraphicsSceneMouseEvent* event ) override;
    void hoverEnterEvent( QGraphicsSceneHoverEvent* event ) override;
    void hoverLeaveEvent( QGraphicsSceneHoverEvent* event ) override;
    void hoverMoveEvent( QGraphicsSceneHoverEvent* event ) override;
    QVariant itemChange( GraphicsItemChange change, const QVariant& value ) override;

private:
    unsigned int m_cornerFlags;
    unsigned int m_actionFlags;
    QPointF m_previousPosition;
    bool m_leftMouseButtonPressed;
    Dotsignal* cornerGrabber[8];

    void resizeLeft( const QPointF& pt );
    void resizeRight( const QPointF& pt );
    void resizeBottom( const QPointF& pt );
    void resizeTop( const QPointF& pt );

    void rotateItem( const QPointF& pt );
    void setPositionGrabbers();
    void hideGrabbers();
};

#endif // ELLIPSE_H


