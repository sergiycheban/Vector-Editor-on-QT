#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QWidget>


#include <moveitem.h>
#include <workplace.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(int borderWidth READ borderWidth WRITE setBorderWidth NOTIFY borderWidthChanged)


public:
	explicit MainWindow(QWidget* parent = 0);
	~MainWindow();

	QColor color() const;
	int borderWidth() const;

signals:
	void colorChanged( QColor &color);
	void borderWidthChanged(const int &width);
	void borderColorChanged(const QColor &color);


public slots:
	void setColor(const QColor &color);
	void setBorderWidth(const int &width);
	void setBorderColor(const QColor &color);
	void newRectangle(Rectangle* rect);
	void loadRectangle(Rectangle* rect);
	void setVisible(bool visible) override;
	void deselect();
    void selectNewItem(QGraphicsItem* item);
    void selectItem(QGraphicsItem* item);



private:
	Ui::MainWindow*		ui;
	QGraphicsScene*		scene;
	QColor				m_color;
	int					m_borderWidth;
	QColor				m_borderColor;

	QGraphicsPathItem*	currentPolyline = nullptr;

	WorkPlace*			workplaceScene;
	QString				path;
	Rectangle*			currentRectangle = nullptr;

};

#endif // MAINWINDOW_H
