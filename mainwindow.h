#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QWidget>
#include <QUndoStack>


#include <workplace.h>
#include "line.h"
#include "graphicsview.h"


namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	Q_PROPERTY( QColor color READ color WRITE setColor NOTIFY colorChanged )
	Q_PROPERTY( int borderWidth READ borderWidth WRITE setBorderWidth NOTIFY borderWidthChanged )


public:
	explicit MainWindow( QWidget* parent = 0 );
	~MainWindow();

	QColor color() const;
	int borderWidth() const;
	QColor lineColor() const;
	int lineWidth() const;


signals:
	void colorChanged( QColor& color );
	void borderWidthChanged( const int& width );
	void borderColorChanged( const QColor& color );
	void lineColorChanged( const QColor& color );
	void lineWidthChanged( const int& width );


public slots:
    void connects();
    void drawBackground();
	void styleSheets();
	void setLineColor( const QColor& color );
	void setLineWidth( const int& width );
	void setColor( const QColor& color );
	void setBorderWidth( const int& width );
	void setBorderColor( const QColor& color );
    void newRectangle( Rectangle* rect );
    void loadRectangle( Rectangle* rect );
	void newLine( Line* line );
	void loadLine( Line* line );
	void setVisible( bool visible ) override;
	void deselect();
	void selectNewItem( QGraphicsItem* item );
	void selectItem( QGraphicsItem* item );
    void checkSelections();
    virtual void wheelEvent(QWheelEvent* event) override;
    void newTab();


private slots:
	void on_m_line_clicked();

    void on_m_square_clicked();

	void on_tabWidget_tabBarClicked( int index );

    void on_tabWidget_tabCloseRequested( int index );

    void on_doubleSpinBox_valueChanged(double value);

    void on_doubleSpinBox_2_valueChanged(double value);

    void on_borderWidth_3_valueChanged(int value);

    void on_m_open_clicked();

    void on_m_save_clicked();

    void on_m_question_clicked();

private:
    Ui::MainWindow*		m_ui;
    QGraphicsScene*		scene;
	QColor				m_color;
	int					m_borderWidth;
	int					m_lineWidth;
	QColor				m_borderColor;
    QColor				m_lineColor;

	QGraphicsRectItem*  rect;
    QUndoStack* undoStack;

	WorkPlace*			workplaceScene;
	WorkPlace*			workplaceScene_2;
    WorkPlace*			workplaceScene_3;
	QString				path;
    Rectangle*			currentRectangle = nullptr;
	Line*				currentLine      = nullptr;

    int					m_index          = 0;
	bool                m_check          = true;

    bool                checkShadow      = false;

    QGraphicsView*      m_view;
    int                 m_valueEffect;



};

#endif // MAINWINDOW_H
