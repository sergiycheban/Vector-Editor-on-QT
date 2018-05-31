#include "workplace.h"
#include <QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include "rectangle.h"
#include "mainwindow.h"
#include "line.h"

WorkPlace::WorkPlace( QObject* parent ) :
	QGraphicsScene( parent ),
	currentItem( nullptr ),
	m_currentAction( DefaultType ),
	m_previousAction( 0 ),
	m_leftMouseButtonPressed( false )
{

}

WorkPlace::~WorkPlace()
{
	delete currentItem;
}

int WorkPlace::currentAction() const
{
	return m_currentAction;
}

QColor WorkPlace::color_1() const
{
	return m_colorW;
}

QPointF WorkPlace::previousPosition() const
{
	return m_previousPosition;
}

void WorkPlace::setCurrentAction( const int type )
{
	m_currentAction = type;
	emit currentActionChanged( m_currentAction );
}

void WorkPlace::setPreviousPosition( const QPointF previousPosition )
{
	if ( m_previousPosition == previousPosition )
	{
		return;
	}

	m_previousPosition = previousPosition;
	emit previousPositionChanged();
}

void WorkPlace::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
	if ( event->button() & Qt::LeftButton )
	{
		m_leftMouseButtonPressed = true;
		setPreviousPosition( event->scenePos() );

		if ( QApplication::keyboardModifiers() & Qt::ShiftModifier )
		{
			m_previousAction = m_currentAction;
			setCurrentAction( SelectionType );
		}
	}

	switch ( m_currentAction )
	{

		case LineType:
			{
				if ( m_leftMouseButtonPressed && !( event->button() & Qt::RightButton )
					 && !( event->button() & Qt::MiddleButton ) )
				{
					deselectItems();
					Line* line = new Line();
					currentItem = line;
					addItem( currentItem );
					connect( line, &Line::clicked, this, &WorkPlace::signalSelectItem );
					connect( line, &Line::signalMove, this, &WorkPlace::slotMove );
					QPainterPath path;
					path.moveTo( m_previousPosition );
					line->setPath( path );
					emit signalNewSelectItem( line );
				}

				break;
			}

		case RectangleType:
			{
				if ( m_leftMouseButtonPressed && !( event->button() & Qt::RightButton )
					 && !( event->button() & Qt::MiddleButton ) )
				{
					deselectItems();
					Rectangle* rectangle = new Rectangle();
					currentItem = rectangle;
					addItem( currentItem );
					connect( rectangle, &Rectangle::clicked, this, &WorkPlace::signalSelectItem );
					connect( rectangle, &Rectangle::signalMove, this, &WorkPlace::slotMove );
					emit signalNewSelectItem( rectangle );
				}

				break;
			}

		default:
			{
				QGraphicsScene::mousePressEvent( event );
				break;
			}
	}
}

void WorkPlace::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
	switch ( m_currentAction )
	{

		case LineType:
			{
				if ( m_leftMouseButtonPressed )
				{
					Line* line = qgraphicsitem_cast<Line*>( currentItem );
					QPainterPath path;
					path.moveTo( m_previousPosition );
					path.lineTo( event->scenePos() );
					line->setPath( path );
				}

				break;
			}

		case RectangleType:
			{
				if ( m_leftMouseButtonPressed )
				{
					auto dx = event->scenePos().x() - m_previousPosition.x();
					auto dy = event->scenePos().y() - m_previousPosition.y();
					Rectangle* rectangle = qgraphicsitem_cast<Rectangle*>( currentItem );
					rectangle->setRect( ( dx > 0 ) ? m_previousPosition.x() : event->scenePos().x(),
										( dy > 0 ) ? m_previousPosition.y() : event->scenePos().y(),
										qAbs( dx ), qAbs( dy ) );
				}

				break;
			}

		default:
			{
				QGraphicsScene::mouseMoveEvent( event );
				break;
			}
	}
}


void WorkPlace::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
	if ( event->button() & Qt::LeftButton )
	{
		m_leftMouseButtonPressed = false;
	}

	switch ( m_currentAction )
	{
		case LineType:
		case RectangleType:
			{
				if ( !m_leftMouseButtonPressed &&
					 !( event->button() & Qt::RightButton ) &&
					 !( event->button() & Qt::MiddleButton ) )
				{
					currentItem = nullptr;
				}

				break;
			}

		default:
			{
				QGraphicsScene::mouseReleaseEvent( event );
				break;
			}
	}
}

void WorkPlace::keyPressEvent( QKeyEvent* event )
{
	switch ( event->key() )
	{
		case Qt::Key_Delete:
			{
				foreach ( QGraphicsItem* item, selectedItems() )
				{
					removeItem( item );
					delete item;
				}

				deselectItems();
				break;
			}

		case Qt::Key_A:
            {
                if ( event->modifiers() & Qt::CTRL )
                {

                    qDebug() << "ddasd";
					foreach ( QGraphicsItem* item, items() )
                    {
						item->setSelected( true );
					}

					if ( selectedItems().length() == 1 )
					{
						signalSelectItem( selectedItems().at( 0 ) );
                    }
                }

				break;
			}

		case Qt::Key_Z:
			{
				if ( event->modifiers() & Qt::CTRL )
				{
					qDebug() << "QWERTY";
					break;
				}
			}

		default:
			break;
	}

	QGraphicsScene::keyPressEvent( event );
}

void WorkPlace::deselectItems()
{
	foreach ( QGraphicsItem* item, selectedItems() )
	{
		item->setSelected( false );
	}

	selectedItems().clear();
}

void WorkPlace::slotMove( QGraphicsItem* signalOwner, qreal dx, qreal dy )
{
	foreach ( QGraphicsItem* item, selectedItems() )
	{
		if ( item != signalOwner )
		{
			item->moveBy( dx, dy );
		}
	}
}
