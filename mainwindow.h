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

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	QColor lineColor() const;

private slots:



signals:
	void lineColorChanged(const QColor &color);
    void currentActionChanged(int);

public slots:
    void setLineColor(const QColor &color);

private:
	Ui::MainWindow*		ui;
	QGraphicsScene*		scene;
    QColor              m_color;
	QGraphicsPathItem*	currentPolyline = nullptr;

    WorkPlace* workplaceScene;
    QString path;

    int m_currentAction;
};

#endif // MAINWINDOW_H
