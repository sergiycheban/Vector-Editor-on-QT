#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QMessageBox>
#include <QBrush>
#include <QPen>
#include <QToolButton>
#include <QDebug>
#include "QFileDialog"
#include <QSvgGenerator>

#include "workplace.h"
#include "rectangle.h"
#include "settings.h"
#include "line.h"
#include "svssave.h"


static int randomBetween(int low, int high)
{
	return (qrand() % ((high + 1) - low) + low);
}


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    setColor(QColor(Qt::yellow));
    setBorderWidth(2);

    setLineColor(QColor(Qt::red));
    setLineWidth(1);


    setBorderColor(Qt::black);

	workplaceScene = new WorkPlace(this);

    workplaceScene->setSceneRect(0,0,960,620);


 //   myDiagramItem = new DiagramItem( this );

    this->resize(960,620);
    this->setFixedSize(960,620);

	 ui->graphicsView->setScene(workplaceScene);
	 ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	 ui->graphicsView->setCursor(QCursor());

    scene = new QGraphicsScene(this);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);

 //   ui->graphicsView->resize(960,980);
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

    connect(ui->borderColor_3, &ColorLabel::clicked,
            [=](){
        QColorDialog dialog;
        connect(&dialog, &QColorDialog::colorSelected, this, &MainWindow::setLineColor);
        dialog.exec();
    });


	connect(ui->borderWidth, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
			this, &MainWindow::setBorderWidth);

    connect(ui->borderWidth_2, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::setLineWidth);

	connect(ui->m_square, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::RectangleType);});
    connect(ui->m_move, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::DefaultType);});   
    connect(ui->m_line, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::LineType);});

    connect(workplaceScene, &WorkPlace::signalSelectItem, this, &MainWindow::selectItem);

	connect(workplaceScene, &WorkPlace::signalNewSelectItem, this, &MainWindow::selectNewItem);
    ui->widget_line->hide();
    ui->widget_rect->hide();

}


MainWindow::~MainWindow()
{
	delete ui;
	delete currentRectangle;
    delete currentLine;
}


QColor MainWindow::color() const
{
	return m_color;
}

int MainWindow::borderWidth() const
{
    return m_borderWidth;
}

QColor MainWindow::lineColor() const
{
    return m_lineColor;
}

int MainWindow::lineWidth() const
{
    return m_lineWidth;
}


void MainWindow::setLineColor(const QColor &color)
{
    m_lineColor = color;
    ui->borderColor_3->setColor(m_lineColor);
    if(currentLine != nullptr){
        QPen pen(color,currentLine->pen().width());
        currentLine->setPen(pen);
    }
    emit lineColorChanged(m_lineColor);
}

void MainWindow::setLineWidth(const int &width)
{
    m_lineWidth = width;
    ui->borderWidth_2->setValue(m_lineWidth);
    if(currentLine != nullptr){
        QPen pen(currentLine->pen().color(),width);
        currentLine->setPen(pen);
    }
    emit lineWidthChanged(m_lineWidth);
}

void MainWindow::setColor(const QColor &color)
{
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

void MainWindow::newLine(Line *line)
{
    line->setBrush(QBrush(Qt::transparent));
    line->setPen(QPen(m_lineColor, m_lineWidth));
}

void MainWindow::loadLine(Line *line)
{
    currentLine = line;
    m_lineColor = currentLine->pen().color();
    m_lineWidth = currentLine->pen().width();
    ui->borderColor_3->setColor(m_lineColor);
    ui->borderWidth_2->setValue(m_lineWidth);
}


void MainWindow::deselect()
{
    currentLine = nullptr;
    currentRectangle = nullptr;
}

void MainWindow::setVisible(bool visible)
{
	if(!visible && currentRectangle != nullptr){
		QWidget::setVisible(true);
	} else {
		QWidget::setVisible(visible);
	}

    if(!visible && currentLine != nullptr){
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
    case QGraphicsPathItem::Type: {
        Line* line = qgraphicsitem_cast<Line *>(item);
        newLine(line);
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
    case QGraphicsPathItem::Type: {
        Line* line = qgraphicsitem_cast<Line *>(item);
        loadLine(line);
        break;
    }

    default:
        break;
    }
}


void MainWindow::on_m_open_clicked()
{
    QString newPath = QFileDialog::getOpenFileName(this, trUtf8("Open SVG"),
                                                   path, tr("SVG files (*.svg)"));
    if (newPath.isEmpty())
        return;

    path = newPath;
    workplaceScene->clear();

    workplaceScene->setSceneRect(SvgSave::getSizes(path));

    foreach (QGraphicsItem *item, SvgSave::getElements(path)) {
        switch (item->type()) {
        case QGraphicsPathItem::Type: {
            Line *polyline = qgraphicsitem_cast<Line*>(item);
            workplaceScene->addItem(polyline);
            connect(polyline, &Line::clicked, workplaceScene, &WorkPlace::signalSelectItem);
            connect(polyline, &Line::signalMove, workplaceScene, &WorkPlace::slotMove);
            break;
        }
        case QGraphicsRectItem::Type: {
            Rectangle *rect = qgraphicsitem_cast<Rectangle*>(item);
            workplaceScene->addItem(rect);
            connect(rect, &Rectangle::clicked, workplaceScene, &WorkPlace::signalSelectItem);
            connect(rect, &Rectangle::signalMove, workplaceScene, &WorkPlace::slotMove);
            break;
        }
        default:
            break;
        }
    }
}

void MainWindow::on_m_save_clicked()
{
    QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save SVG"),
        path, tr("SVG files (*.svg)"));

    if (newPath.isEmpty())
        return;

    path = newPath;

    QSvgGenerator generator;
    generator.setFileName(path);
    generator.setSize(QSize(workplaceScene->width(), workplaceScene->height()));
    generator.setViewBox(QRect(0, 0, workplaceScene->width(), workplaceScene->height()));
    generator.setTitle(trUtf8("Vector Editor"));
    generator.setDescription(trUtf8("File created by Vector Editor."));

    QPainter painter;
    painter.begin(&generator);
    workplaceScene->render(&painter);
    painter.end();
    QMessageBox::warning( this,"=)", "Yeap" );
}

void MainWindow::on_m_line_clicked()
{
    ui->widget_rect->hide();
    ui->widget_line->show();
}

void MainWindow::on_m_square_clicked()
{
     ui->widget_line->hide();
     ui->widget_rect->show();
}
