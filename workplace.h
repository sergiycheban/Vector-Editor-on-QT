#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <QObject>
#include <QGraphicsScene>

#include "rectangle.h"

class QGraphicsSceneMouseEvent;
class QKeyEvent;

class WorkPlace : public QGraphicsScene
{
	Q_OBJECT

	Q_PROPERTY(int currentAction READ currentAction WRITE setCurrentAction NOTIFY currentActionChanged)
	Q_PROPERTY(QPointF previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY previousPositionChanged)

public:
	explicit WorkPlace(QObject *parent = 0);
	~WorkPlace();

	enum ActionTypes {
		DefaultType,
		LineType,
		RectangleType,
		SelectionType
	};

	int currentAction() const;
	QColor color_1() const;
	QPointF previousPosition() const;

	void setCurrentAction(const int type);
	void setPreviousPosition(const QPointF previousPosition);

signals:
	void previousPositionChanged();
	void currentActionChanged(int);
	void signalSelectItem(QGraphicsItem* item);
	void signalNewSelectItem(QGraphicsItem* item);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
//	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;

private slots:
	void deselectItems();
//	void color( QColor m_color );
//	void newRectangle(Rectangle* rect);

public slots:
	void slotMove(QGraphicsItem* signalOwner, qreal dx, qreal dy);

private:

	QGraphicsScene*		scene;
	QGraphicsItem*		currentItem;
	int					m_currentAction;
	int					m_previousAction;
	QPointF				m_previousPosition;
	bool				m_leftMouseButtonPressed;


	QColor m_colorW;
};

#endif // WORKPLACE_H
