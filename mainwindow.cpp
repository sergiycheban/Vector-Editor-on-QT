#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QBrush>
#include <QPen>
#include <QToolButton>
#include <QDebug>

#include "workplace.h"
#include "rectangle.h"
#include "settings.h"


static int randomBetween(int low, int high)
{
	return (qrand() % ((high + 1) - low) + low);
}


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    setColor(QColor(Qt::red));
    setBorderWidth(2);

	setBorderColor(Qt::black);

	workplaceScene = new WorkPlace(this);
    workplaceScene->setSceneRect(0,0,960,570);


//	this->resize(640,640);
//	this->setFixedSize(640,640);

	 ui->graphicsView->setScene(workplaceScene);
	 ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	 ui->graphicsView->setCursor(QCursor());

	scene = new QGraphicsScene(this);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->resize(960,570);
	ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);

//    ui->setupUi(this);
//    QPixmap bkgnd("D:/2144.jpg");
//    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
//    QPalette palette;
//    palette.setBrush(QPalette::Background, bkgnd);
//    this->setPalette(palette);

	connect(ui->lineColor, &ColorLabel::clicked,
			[=](){
		QColorDialog dialog;
		connect(&dialog, &QColorDialog::colorSelected, this, &MainWindow::setColor);
		dialog.exec();
			});

	connect(ui->borderColor, &ColorLabel::clicked,
			[=](){
		QColorDialog dialog;
		connect(&dialog, &QColorDialog::colorSelected, this, &MainWindow::setBorderColor);
		dialog.exec();
	});


	connect(ui->borderWidth, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
			this, &MainWindow::setBorderWidth);

	connect(ui->m_square, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::RectangleType);});
    connect(ui->m_move, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::DefaultType);});

    connect(workplaceScene, &WorkPlace::signalSelectItem, this, &MainWindow::selectItem);

	connect(workplaceScene, &WorkPlace::signalNewSelectItem, this, &MainWindow::selectNewItem);
}


MainWindow::~MainWindow()
{
	delete ui;
	delete currentRectangle;
}


QColor MainWindow::color() const
{
	return m_color;
}

int MainWindow::borderWidth() const
{
	return m_borderWidth;
}

void MainWindow::setColor(const QColor &color)
{   
    qDebug() << "setColor";
	m_color = color;
    ui->lineColor->setColor(color);
	if(currentRectangle != nullptr)
			currentRectangle->setBrush(QBrush(m_color));
	qDebug() << "color =" << " " << color;
	emit colorChanged(m_color);
}


void MainWindow::setBorderWidth(const int &width)
{
	m_borderWidth = width;
	if(currentRectangle != nullptr){
		if(width == 0){
			currentRectangle->setPen(Qt::NoPen);
		} else {
			QPen pen(currentRectangle->pen().color(), width);
			currentRectangle->setPen(pen);
		}
	}
	emit borderWidthChanged(m_borderWidth);
}

void MainWindow::setBorderColor(const QColor &color)
{
	m_borderColor = color;
    qDebug() << color;
	ui->borderColor->setColor(color);
	if(currentRectangle != nullptr){
		QPen pen(color,currentRectangle->pen().width());
		currentRectangle->setPen(pen);
	}
	emit borderColorChanged(m_borderColor);
}

void MainWindow::newRectangle(Rectangle* rect)
{

        qDebug() << "newRectangle";
		rect->setBrush(QBrush(m_color));

    if(m_borderWidth == 0)
		rect->setPen(Qt::NoPen);
     else
        rect->setPen(QPen(m_borderColor, m_borderWidth));

}

void MainWindow::loadRectangle(Rectangle* rect)
{
	currentRectangle = rect;

	m_color = currentRectangle->brush().color();
	if(currentRectangle->pen().style() == Qt::NoPen){
		m_borderWidth = 0;
	} else {
		m_borderWidth = currentRectangle->pen().width();
	}
}

void MainWindow::deselect()
{
	currentPolyline = nullptr;
}

void MainWindow::setVisible(bool visible)
{
	if(!visible && currentRectangle != nullptr){
		QWidget::setVisible(true);
	} else {
		QWidget::setVisible(visible);
	}
}


void MainWindow::selectNewItem(QGraphicsItem *item)
{
	switch (item->type()) {
	case QGraphicsRectItem::Type: {
        Rectangle* rect = qgraphicsitem_cast<Rectangle *>(item);
		newRectangle(rect);
		break;
}
	default:
		break;
        }
}

void MainWindow::selectItem(QGraphicsItem *item)
{
    switch (item->type()) {
    case QGraphicsRectItem::Type: {
        Rectangle* rect = qgraphicsitem_cast<Rectangle *>(item);
        loadRectangle(rect);
        break;
    }
    default:
        break;
    }
}


















