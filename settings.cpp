#include "settings.h"

#include <QColorDialog>
#include <QBrush>
#include <QPen>
#include <QDebug>

Settings::Settings(QWidget *parent) :
	QWidget(parent)
{

	setColor(QColor(Qt::black));
	setBorderWidth(1);


}


QColor Settings::color() const
{
	return m_color;
}

int Settings::borderWidth() const
{
	return m_borderWidth;
}

void Settings::setColor(const QColor &color)
{
	m_color = color;
	ui->lineColor->setColor(color);
	if(currentRectangle != nullptr)
			currentRectangle->setBrush(QBrush(m_color));
	qDebug() << "color =" << " " << color;
	emit colorChanged(m_color);
}


void Settings::setBorderWidth(const int &width)
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

void Settings::newRectangle(Rectangle* rect)
{
		rect->setBrush(QBrush(m_color));

	if(m_borderWidth == 0){
		rect->setPen(Qt::NoPen);
	} else {
		rect->setPen(QPen(m_color, m_borderWidth));
	}
}

void Settings::loadRectangle(Rectangle* rect)
{
	currentRectangle = rect;

	m_color = currentRectangle->brush().color();
	if(currentRectangle->pen().style() == Qt::NoPen){
		m_borderWidth = 0;
	} else {
		m_borderWidth = currentRectangle->pen().width();
	}
}

void Settings::deselect()
{
	currentRectangle = nullptr;
}

void Settings::setVisible(bool visible)
{
	if(!visible && currentRectangle != nullptr){
		QWidget::setVisible(true);
	} else {
		QWidget::setVisible(visible);
	}
}
