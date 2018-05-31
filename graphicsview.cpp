#include "graphicsview.h"
#include "ui_graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent) :
	QWidget(parent),
	m_ui(new Ui::GraphicsView)
{
	m_ui->setupUi(this);

	workplaceScene = new WorkPlace( this );

	workplaceScene->setSceneRect( 0, 0, 1200, 620 );

	this->resize( 1200, 620 );
	this->setFixedSize( 1200, 620 );
	setStyleSheet("QMenu::item:selected {border: 1px solid black;}");

	m_ui->graphicsView->setScene( workplaceScene );
	m_ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	m_ui->graphicsView->setCursor(QCursor());

	scene = new QGraphicsScene( this );
	scene->setItemIndexMethod( QGraphicsScene::NoIndex );
	m_ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);


	workplaceScene->setCurrentAction( WorkPlace::RectangleType );

}

GraphicsView::~GraphicsView()
{
	delete m_ui;
}
