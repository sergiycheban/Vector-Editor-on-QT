#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

#include "rectangle.h"

class VERectangle;

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
	Q_OBJECT


public:
	explicit Settings(QWidget *parent = 0);
	~Settings();

	QColor color() const;
	int borderWidth() const;

signals:
	void colorChanged( QColor &color);
	void borderWidthChanged(const int &width);


public slots:
	void setColor(const QColor &color);
	void setBorderWidth(const int &width);
	void newRectangle(Rectangle* rect);
	void loadRectangle(Rectangle* rect);
	void setVisible(bool visible) override;
	void deselect();



private:

	QColor				m_color;
	int					m_borderWidth;

	Rectangle*			currentRectangle;

};

#endif // SETTINGS_H
