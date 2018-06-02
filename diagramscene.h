#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QObject>
#include <QGraphicsScene>

class DiagramItem;
class QGraphicsSceneDragDropEvent;
class QGraphicsViewItem;

class DiagramScene : public QGraphicsScene
{
    Q_OBJECT

public:
    DiagramScene(QObject *parent = 0);

signals:
    void itemMoved(DiagramItem *movedItem, const QPointF &movedFromPosition);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QGraphicsItem *movingItem;
    QPointF oldPos;
};

#endif
