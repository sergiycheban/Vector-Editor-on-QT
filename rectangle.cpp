#include "rectangle.h"
#include <QPainter>
#include <QDebug>
#include <QCursor>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <math.h>

#include "dotsignal.h"
#include "mainwindow.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle( qreal angle )
{
    while ( angle < 0 )
    {
        angle += TwoPi;
    }

    while ( angle > TwoPi )
    {
        angle -= TwoPi;
    }

    return angle;
}

Rectangle::Rectangle( QObject* parent ) :
    QObject( parent ),
    m_cornerFlags( 0 ),
    m_actionFlags( ResizeState )
{
    setAcceptHoverEvents( true );
    setFlags( ItemIsSelectable | ItemSendsGeometryChanges );

    for ( int i = 0; i < 8; i++ )
    {
        cornerGrabber[i] = new Dotsignal( this );
    }

    setPositionGrabbers();

}

Rectangle::~Rectangle()
{
    for ( int i = 0; i < 8; i++ )
    {
        delete cornerGrabber[i];
    }
}

QPointF Rectangle::previousPosition() const
{
    return m_previousPosition;
}

void Rectangle::setPreviousPosition( const QPointF previousPosition )
{
    if ( m_previousPosition == previousPosition )
    {
        return;
    }

    m_previousPosition = previousPosition;
    emit previousPositionChanged();
}

void Rectangle::setRect( qreal x, qreal y, qreal w, qreal h )
{
    setRect( QRectF( x, y, w, h ) );
}

void Rectangle::setRect( const QRectF& rect )
{
    QGraphicsRectItem::setRect( rect );
}

void Rectangle::Rosina( QString = "cate" )
{

}

void Rectangle::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
    QPointF pt = event->pos();

    if ( m_actionFlags == ResizeState )
    {
        switch ( m_cornerFlags )
        {
            case Top:
                resizeTop( pt );
                break;

            case Bottom:
                resizeBottom( pt );
                break;

            case Left:
                resizeLeft( pt );
                break;

            case Right:
                resizeRight( pt );
                break;

            case TopLeft:
                resizeTop( pt );
                resizeLeft( pt );
                break;

            case TopRight:
                resizeTop( pt );
                resizeRight( pt );
                break;

            case BottomLeft:
                resizeBottom( pt );
                resizeLeft( pt );
                break;

            case BottomRight:
                resizeBottom( pt );
                resizeRight( pt );
                break;

            default:
                if ( m_leftMouseButtonPressed )
                {
                    setCursor( Qt::ClosedHandCursor );
                    auto dx = event->scenePos().x() - m_previousPosition.x();
                    auto dy = event->scenePos().y() - m_previousPosition.y();
                    moveBy( dx, dy );
                    setPreviousPosition( event->scenePos() );
                    emit signalMove( this, dx, dy );
                }

                break;
        }
    }

    else
    {
        switch ( m_cornerFlags )
        {
            case TopLeft:
            case TopRight:
            case BottomLeft:
            case BottomRight:
                {
                    rotateItem( pt );
                    break;
                }

            default:
                if ( m_leftMouseButtonPressed )
                {
                    setCursor( Qt::ClosedHandCursor );
                    auto dx = event->scenePos().x() - m_previousPosition.x();
                    auto dy = event->scenePos().y() - m_previousPosition.y();
                    moveBy( dx, dy );
                    setPreviousPosition( event->scenePos() );
                    emit signalMove( this, dx, dy );
                }

                break;
        }
    }

    QGraphicsItem::mouseMoveEvent( event );
}

void Rectangle::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    if ( event->button() & Qt::LeftButton )
    {
        m_leftMouseButtonPressed = true;
        setPreviousPosition( event->scenePos() );
        emit clicked( this );
    }

    QGraphicsItem::mousePressEvent( event );
}

void Rectangle::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    if ( event->button() & Qt::LeftButton )
    {
        m_leftMouseButtonPressed = false;
    }

    QGraphicsItem::mouseReleaseEvent( event );
}

void Rectangle::mouseDoubleClickEvent( QGraphicsSceneMouseEvent* event )
{
    m_actionFlags = ( m_actionFlags == ResizeState ) ? RotationState : ResizeState;
    setVisibilityGrabbers();
    QGraphicsItem::mouseDoubleClickEvent( event );
}

void Rectangle::hoverEnterEvent( QGraphicsSceneHoverEvent* event )
{
    setPositionGrabbers();
    setVisibilityGrabbers();
    QGraphicsItem::hoverEnterEvent( event );
}

void Rectangle::hoverLeaveEvent( QGraphicsSceneHoverEvent* event )
{
    m_cornerFlags = 0;
    hideGrabbers();
    setCursor( Qt::CrossCursor );
    QGraphicsItem::hoverLeaveEvent( event );
}

void Rectangle::hoverMoveEvent( QGraphicsSceneHoverEvent* event )
{
    QPointF pt = event->pos();
    qreal drx = pt.x() - rect().right();
    qreal dlx = pt.x() - rect().left();

    qreal dby = pt.y() - rect().top();
    qreal dty = pt.y() - rect().bottom();

    m_cornerFlags = 0;

    if ( dby < 7 && dby > -7 )
    {
        m_cornerFlags |= Top;
    }

    if ( dty < 7 && dty > -7 )
    {
        m_cornerFlags |= Bottom;
    }

    if ( drx < 7 && drx > -7 )
    {
        m_cornerFlags |= Right;
    }

    if ( dlx < 7 && dlx > -7 )
    {
        m_cornerFlags |= Left;
    }

    if ( m_actionFlags == ResizeState )
    {
        QPixmap p( ":/icon/Resources/cursor.svg" );
        QPixmap pResult;
        QTransform trans = transform();

        switch ( m_cornerFlags )
        {
            case Top:
            case Bottom:
                pResult = p.transformed( trans );
                setCursor( pResult.scaled( 24, 24, Qt::KeepAspectRatio ) );
                break;

            case Left:
            case Right:
                trans.rotate( 90 );
                pResult = p.transformed( trans );
                setCursor( pResult.scaled( 24, 24, Qt::KeepAspectRatio ) );
                break;

            case TopRight:
            case BottomLeft:
                trans.rotate( 45 );
                pResult = p.transformed( trans );
                setCursor( pResult.scaled( 24, 24, Qt::KeepAspectRatio ) );
                break;

            case TopLeft:
            case BottomRight:
                trans.rotate( 135 );
                pResult = p.transformed( trans );
                setCursor( pResult.scaled( 24, 24, Qt::KeepAspectRatio ) );
                break;

            default:
                setCursor( Qt::CrossCursor );
                break;
        }
    }

    else
    {
        switch ( m_cornerFlags )
        {
            case TopLeft:
            case TopRight:
            case BottomLeft:
            case BottomRight:
                {
                    QPixmap p( ":/icon/Resources/spiral.svg" );
                    setCursor( QCursor( p.scaled( 40, 40, Qt::KeepAspectRatio ) ) );
                    break;
                }

            default:
                setCursor( Qt::CrossCursor );
                break;
        }
    }

    QGraphicsItem::hoverMoveEvent( event );
}

QVariant Rectangle::itemChange( QGraphicsItem::GraphicsItemChange change, const QVariant& value )
{
    switch ( change )
    {
        case QGraphicsItem::ItemSelectedChange:
            m_actionFlags = ResizeState;
            break;

        default:
            break;
    }

    return QGraphicsItem::itemChange( change, value );
}

void Rectangle::resizeLeft( const QPointF& pt )
{
    QRectF tmpRect = rect();

    if ( pt.x() > tmpRect.right() )
    {
        return;
    }

    qreal widthOffset =  ( pt.x() - tmpRect.right() );

    if ( widthOffset > -10 )
    {
        return;
    }

    if ( widthOffset < 0 )
    {
        tmpRect.setWidth( -widthOffset );
    }

    else
    {
        tmpRect.setWidth( widthOffset );
    }

    tmpRect.translate( rect().width() - tmpRect.width(), 0 );
    prepareGeometryChange();

    setRect( tmpRect );

    update();
    setPositionGrabbers();
}

void Rectangle::resizeRight( const QPointF& pt )
{
    QRectF tmpRect = rect();

    if ( pt.x() < tmpRect.left() )
    {
        return;
    }

    qreal widthOffset =  ( pt.x() - tmpRect.left() );

    if ( widthOffset < 10 ) /// limit
    {
        return;
    }

    if ( widthOffset < 10 )
    {
        tmpRect.setWidth( -widthOffset );
    }

    else
    {
        tmpRect.setWidth( widthOffset );
    }

    prepareGeometryChange();
    setRect( tmpRect );
    update();
    setPositionGrabbers();
}

void Rectangle::resizeBottom( const QPointF& pt )
{
    QRectF tmpRect = rect();

    if ( pt.y() < tmpRect.top() )
    {
        return;
    }

    qreal heightOffset =  ( pt.y() - tmpRect.top() );

    if ( heightOffset < 11 ) /// limit
    {
        return;
    }

    if ( heightOffset < 0 )
    {
        tmpRect.setHeight( -heightOffset );
    }

    else
    {
        tmpRect.setHeight( heightOffset );
    }

    prepareGeometryChange();
    setRect( tmpRect );
    update();
    setPositionGrabbers();
}

void Rectangle::resizeTop( const QPointF& pt )
{
    QRectF tmpRect = rect();

    if ( pt.y() > tmpRect.bottom() )
    {
        return;
    }

    qreal heightOffset =  ( pt.y() - tmpRect.bottom() );

    if ( heightOffset > -11 ) /// limit
    {
        return;
    }

    if ( heightOffset < 0 )
    {
        tmpRect.setHeight( -heightOffset );
    }

    else
    {
        tmpRect.setHeight( heightOffset );
    }

    tmpRect.translate( 0, rect().height() - tmpRect.height() );
    prepareGeometryChange();
    setRect( tmpRect );
    update();
    setPositionGrabbers();
}

void Rectangle::rotateItem( const QPointF& pt )
{
    QRectF tmpRect = rect();
    QPointF center = boundingRect().center();
    QPointF corner;

    switch ( m_cornerFlags )
    {
        case TopLeft:
            corner = tmpRect.topLeft();
            break;

        case TopRight:
            corner = tmpRect.topRight();
            break;

        case BottomLeft:
            corner = tmpRect.bottomLeft();
            break;

        case BottomRight:
            corner = tmpRect.bottomRight();
            break;

        default:
            break;
    }

    QLineF lineToTarget( center, corner );
    QLineF lineToCursor( center, pt );

    qreal angleToTarget = ::acos( lineToTarget.dx() / lineToTarget.length() );
    qreal angleToCursor = ::acos( lineToCursor.dx() / lineToCursor.length() );

    if ( lineToTarget.dy() < 0 )
    {
        angleToTarget = TwoPi - angleToTarget;
    }

    angleToTarget = normalizeAngle( ( Pi - angleToTarget ) + Pi / 2 );

    if ( lineToCursor.dy() < 0 )
    {
        angleToCursor = TwoPi - angleToCursor;
    }

    angleToCursor = normalizeAngle( ( Pi - angleToCursor ) + Pi / 2 );


    auto resultAngle = angleToTarget - angleToCursor;

    QTransform trans = transform();
    trans.translate( center.x(), center.y() );
    trans.rotateRadians( rotation() + resultAngle, Qt::ZAxis );
    trans.translate( -center.x(),  -center.y() );
    setTransform( trans );
}

void Rectangle::setPositionGrabbers()
{
    QRectF tmpRect = rect();

    cornerGrabber[GrabberTop]->setPos( tmpRect.left() + tmpRect.width() / 2, tmpRect.top() );
    cornerGrabber[GrabberBottomRight]->setPos( tmpRect.bottomRight().x(), tmpRect.bottomRight().y() );
    cornerGrabber[GrabberBottom]->setPos( tmpRect.left() + tmpRect.width() / 2, tmpRect.bottom() );
    cornerGrabber[GrabberLeft]->setPos( tmpRect.left(), tmpRect.top() + tmpRect.height() / 2 );
    cornerGrabber[GrabberRight]->setPos( tmpRect.right(), tmpRect.top() + tmpRect.height() / 2 );
    cornerGrabber[GrabberTopLeft]->setPos( tmpRect.topLeft().x(), tmpRect.topLeft().y() );
    cornerGrabber[GrabberTopRight]->setPos( tmpRect.topRight().x(), tmpRect.topRight().y() );
    cornerGrabber[GrabberBottomLeft]->setPos( tmpRect.bottomLeft().x(), tmpRect.bottomLeft().y() );
}

void Rectangle::setVisibilityGrabbers()
{
    cornerGrabber[GrabberTopLeft]->setVisible( true );
    cornerGrabber[GrabberTopRight]->setVisible( true );
    cornerGrabber[GrabberBottomLeft]->setVisible( true );
    cornerGrabber[GrabberBottomRight]->setVisible( true );

    if ( m_actionFlags == ResizeState )
    {
        cornerGrabber[GrabberTop]->setVisible( true );
        cornerGrabber[GrabberBottom]->setVisible( true );
        cornerGrabber[GrabberLeft]->setVisible( true );
        cornerGrabber[GrabberRight]->setVisible( true );
    }

    else
    {
        cornerGrabber[GrabberTop]->setVisible( false );
        cornerGrabber[GrabberBottom]->setVisible( false );
        cornerGrabber[GrabberLeft]->setVisible( false );
        cornerGrabber[GrabberRight]->setVisible( false );
    }
}

void Rectangle::hideGrabbers()
{
    for ( int i = 0; i < 8; i++ )
    {
        cornerGrabber[i]->setVisible( false );
    }
}
