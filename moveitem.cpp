#include "moveitem.h"
#include "mainwindow.h"

#include "QDebug"



MoveItem::MoveItem(QObject* parent) :
	QObject(parent), QGraphicsItem()
{

	MainWindow* m_main = new MainWindow;
	connect( m_main, SIGNAL( lineColorChanged( QColor ) ), this , SLOT ( ColorChanged( QColor ) ) );
}


MoveItem::~MoveItem()
{
}

QRectF MoveItem::boundingRect() const
{
	return QRectF (-30,-30,60,60);
}

void MoveItem::paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget )
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	painter->setPen(Qt::black);
	painter->setBrush( Qt::yellow );
	painter->drawRect( -30,-30,60,60 );
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	this->setPos(mapToScene(event->pos()));
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	Q_UNUSED(event);
	this->setCursor(QCursor(Qt::ClosedHandCursor));
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	Q_UNUSED(event);
	this->setCursor(QCursor(Qt::ClosedHandCursor));
}

void MoveItem::ColorChanged(QColor color)
{
	m_color = color;
	qDebug( ) << m_color;
}
