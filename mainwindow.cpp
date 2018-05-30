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
#include <QTableWidget>
#include <QTimeLine>
#include <QProgressBar>

#include "workplace.h"
#include "rectangle.h"
#include "line.h"
#include "svssave.h"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    styleSheets();

    setColor(QColor(Qt::yellow));
    setBorderWidth(2);

    setLineColor(QColor(Qt::red));
    setLineWidth(1);


    setBorderColor(Qt::black);

	workplaceScene = new WorkPlace(this);

    workplaceScene->setSceneRect(0,0,1200,620);

    this->resize(1200,620);
    this->setFixedSize(1200,620);
    setStyleSheet("QMenu::item:selected {border: 1px solid black;}");

     m_ui->graphicsView->setScene(workplaceScene);
     m_ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
     m_ui->graphicsView->setCursor(QCursor());

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    m_ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);


    connect(m_ui->lineColor, &ColorLabel::clicked,
			[=](){
		QColorDialog dialog;
		connect(&dialog, &QColorDialog::colorSelected, this, &MainWindow::setColor);
		dialog.exec();
			});

    connect(m_ui->borderColor, &ColorLabel::clicked,
			[=](){
		QColorDialog dialog;
		connect(&dialog, &QColorDialog::colorSelected, this, &MainWindow::setBorderColor);
		dialog.exec();
	});

    connect(m_ui->borderColor_3, &ColorLabel::clicked,
            [=](){
        QColorDialog dialog;
        connect(&dialog, &QColorDialog::colorSelected, this, &MainWindow::setLineColor);
        dialog.exec();
    });


    connect(m_ui->borderWidth, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
			this, &MainWindow::setBorderWidth);

    connect(m_ui->borderWidth_2, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::setLineWidth);


    connect(m_ui->m_square, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::RectangleType);});
    connect(m_ui->m_move, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::DefaultType);});
    connect(m_ui->m_line, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(WorkPlace::LineType);});

    connect(workplaceScene, &WorkPlace::signalSelectItem, this, &MainWindow::selectItem);

	connect(workplaceScene, &WorkPlace::signalNewSelectItem, this, &MainWindow::selectNewItem);

    connect(workplaceScene, &WorkPlace::selectionChanged, this, &MainWindow::checkSelections);

    m_ui->widget_line->hide();
    m_ui->widget_rect->hide();

}


MainWindow::~MainWindow()
{
    delete m_ui;
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

void MainWindow::styleSheets()
{
    setWindowIcon(QIcon(":/icon/Resources/cube.svg"));

    QPixmap bkgnd(":/icon/Resources/grid-background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPixmap pixmapReset(":/icon/Resources/square.svg");
    QIcon ButtonIconReset(pixmapReset);
    m_ui->m_square->setIcon(ButtonIconReset);
    m_ui->m_square->setIconSize(QSize(30,30));
    m_ui->m_square->setStyleSheet("background-color:white;");

    QPixmap pixmapSearch(":/icon/Resources/pen.svg");
    QIcon ButtonIconSearch(pixmapSearch);
    m_ui->m_line->setIcon(ButtonIconSearch);
    m_ui->m_line->setIconSize(QSize(30,30));
    m_ui->m_line->setStyleSheet("background-color:white;");

    QPixmap pixmapClose(":/icon/Resources/vector.svg");
    QIcon ButtonIconClose(pixmapClose);
    m_ui->m_move->setIcon(ButtonIconClose);
    m_ui->m_move->setIconSize(QSize(30,30));
    m_ui->m_move->setStyleSheet("background-color:white;");

    QFont newFont("StyleItalic", 8, QFont::Medium);
    QApplication::setFont(newFont);

}


void MainWindow::setLineColor(const QColor &color)
{
    m_lineColor = color;
    m_ui->borderColor_3->setColor(m_lineColor);
    if(currentLine != nullptr){
        QPen pen(color,currentLine->pen().width());
        currentLine->setPen(pen);
    }
    emit lineColorChanged(m_lineColor);
}

void MainWindow::setLineWidth(const int &width)
{
    m_lineWidth = width;
    m_ui->borderWidth_2->setValue(m_lineWidth);
    if(currentLine != nullptr){
        QPen pen(currentLine->pen().color(),width);
        currentLine->setPen(pen);
    }
    emit lineWidthChanged(m_lineWidth);
}

void MainWindow::setColor(const QColor &color)
{
    m_color = color;
    m_ui->lineColor->setColor(color);
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
    m_ui->borderColor->setColor(color);
	if(currentRectangle != nullptr){
		QPen pen(color,currentRectangle->pen().width());
		currentRectangle->setPen(pen);
	}
	emit borderColorChanged(m_borderColor);
}

void MainWindow::newRectangle(Rectangle* rect)
{
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
    m_ui->borderColor_3->setColor(m_lineColor);
    m_ui->borderWidth_2->setValue(m_lineWidth);
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

void MainWindow::checkSelections()
{
   if(workplaceScene->selectedItems().length() > 1)
   {
       m_ui->widget_line->setEnabled( false );
       m_ui->widget_rect->setEnabled( false );
   }
   else
   {
       m_ui->widget_line->setEnabled( true );
       m_ui->widget_rect->setEnabled( true );
   }
}


void MainWindow::on_m_line_clicked()
{
    m_ui->widget_rect->hide();
    m_ui->widget_line->show();
}

void MainWindow::on_m_square_clicked()
{
     m_ui->widget_line->hide();
     m_ui->widget_rect->show();
}

void MainWindow::on_actionOpen_triggered()
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
            Line *line = qgraphicsitem_cast<Line*>(item);
            workplaceScene->addItem(line);
            break;
        }
        case QGraphicsRectItem::Type: {
            Rectangle *rect = qgraphicsitem_cast<Rectangle*>(item);
            workplaceScene->addItem(rect);
            break;
        }
        default:
            break;
        }
    }
}

void MainWindow::on_actionSave_triggered()
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
}

