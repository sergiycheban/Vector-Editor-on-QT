#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsScene>


#include "workplace.h"

namespace Ui {
class GraphicsView;
}

class GraphicsView : public QWidget
{
	Q_OBJECT

public:
	explicit GraphicsView(QWidget *parent = 0);
	~GraphicsView();


private:
	Ui::GraphicsView*   m_ui;

	WorkPlace*			workplaceScene;
	QGraphicsScene*		scene;
};

#endif // GRAPHICSVIEW_H
