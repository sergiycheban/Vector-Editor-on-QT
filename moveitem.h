#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>


class MoveItem: public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	explicit MoveItem(QObject* parent = 0);
	~MoveItem();

private:
	QRectF boundingRect() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);


private slots:
	void ColorChanged(QColor color);

private:
	QColor				m_color;
};

#endif // MOVEITEM_H
