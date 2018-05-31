#ifndef VEPOLYLINE_H
#define VEPOLYLINE_H

#include <QObject>
#include <QGraphicsPathItem>
#include "dotsignal.h"
class QGraphicsSceneMouseEvent;

class Line : public QObject, public QGraphicsPathItem
{
	Q_OBJECT
	Q_PROPERTY( QPointF previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY
				previousPositionChanged )

public:
	explicit Line( QObject* parent = 0 );
	~Line();

	QPointF previousPosition() const;
	void setPreviousPosition( const QPointF previousPosition );
	void setPath( const QPainterPath& path );

signals:
	void previousPositionChanged();
	void clicked( Line* rect );
	void signalMove( QGraphicsItem* item, qreal dx, qreal dy );

protected:
	void mouseMoveEvent( QGraphicsSceneMouseEvent* event ) override;
	void mousePressEvent( QGraphicsSceneMouseEvent* event ) override;
	void mouseReleaseEvent( QGraphicsSceneMouseEvent* event ) override;
	void hoverLeaveEvent( QGraphicsSceneHoverEvent* event ) override;
	void hoverMoveEvent( QGraphicsSceneHoverEvent* event ) override;
	void hoverEnterEvent( QGraphicsSceneHoverEvent* event ) override;

public slots:

private slots:
	void slotMove( QGraphicsItem* signalOwner, qreal dx, qreal dy );

private:
	QPointF m_previousPosition;
	bool m_leftMouseButtonPressed;
	QList<Dotsignal* > listDotes;

//    void updateDots();
};

#endif // VEPOLYLINE_H
