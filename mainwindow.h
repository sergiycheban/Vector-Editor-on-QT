#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QWidget>


#include <moveitem.h>
#include <workplace.h>
#include <diagramitem.h>
#include "line.h"


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
    QColor lineColor() const;
    int lineWidth() const;


signals:
	void colorChanged( QColor &color);
	void borderWidthChanged(const int &width);
	void borderColorChanged(const QColor &color);
    void lineColorChanged(const QColor &color);
    void lineWidthChanged(const int &width);


public slots:
    void setLineColor(const QColor &color);
    void setLineWidth(const int &width);
	void setColor(const QColor &color);
	void setBorderWidth(const int &width);
	void setBorderColor(const QColor &color);
	void newRectangle(Rectangle* rect);
	void loadRectangle(Rectangle* rect);
    void newLine(Line *line);
    void loadLine(Line *line);
	void setVisible(bool visible) override;
	void deselect();
    void selectNewItem(QGraphicsItem* item);
    void selectItem(QGraphicsItem* item);


private slots:

    void on_m_open_clicked();

    void on_m_save_clicked();

    void on_m_line_clicked();

    void on_m_square_clicked();

private:
	Ui::MainWindow*		ui;
    DiagramItem*        myDiagramItem;
	QGraphicsScene*		scene;
	QColor				m_color;
	int					m_borderWidth;
    int                 m_lineWidth;
	QColor				m_borderColor;
    QColor              m_lineColor;


    QPointF myOldPos;
    QPointF newPos;

//	QGraphicsPathItem*	currentPolyline = nullptr;
    QGraphicsRectItem*  rect;

	WorkPlace*			workplaceScene;
	QString				path;
	Rectangle*			currentRectangle = nullptr;
    Line*               currentLine      = nullptr;


};

#endif // MAINWINDOW_H
