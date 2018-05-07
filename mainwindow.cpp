#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QBrush>
#include <QPen>
#include <QToolButton>

#include "workplace.h"
#include "rectangle.h"


static int randomBetween(int low, int high)
{
	return (qrand() % ((high + 1) - low) + low);
}


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	setLineColor(QColor(Qt::black));

     workplaceScene = new WorkPlace(this);
     workplaceScene->setSceneRect(0,0,2000,2000);

	 connect(ui->lineColor, &ColorLabel::clicked,
			[=](){
		QColorDialog dialog;
		connect(&dialog, &QColorDialog::colorSelected, this, &MainWindow::setLineColor);
		dialog.exec();
			});

    this->resize(640,640);
    this->setFixedSize(640,640);

     ui->graphicsView->setScene(workplaceScene);
     ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
     ui->graphicsView->setCursor(QCursor());

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->resize(600,600);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);


    connect(ui->m_square, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::RectangleType);});


    connect(ui->m_move, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::DefaultType);});

    scene->setSceneRect(0,0,500,500);
    ui->m_square->setIcon(QIcon("D:/QWERTY/Resources/selection.svg"));

}


MainWindow::~MainWindow()
{
	delete ui;
	delete currentPolyline;
}



QColor MainWindow::lineColor() const
{
    return m_color;
}

void MainWindow::setLineColor(const QColor &color)
{
    m_color = color;
    qDebug( ) << m_color;
    ui->lineColor->setColor(m_color);
    if(currentPolyline != nullptr){
            qDebug( ) << "1";
        QPen pen(color,currentPolyline->pen().width());
        currentPolyline->setPen(pen);
    }
    emit lineColorChanged(m_color);
    qDebug( ) << m_color;
}




