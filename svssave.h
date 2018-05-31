#ifndef SVSSAVE_H
#define SVSSAVE_H


#include <QObject>
#include "line.h"
#include "rectangle.h"

class QGraphicsItem;


class SvgSave : public QObject
{
	Q_OBJECT
public:
	explicit SvgSave( QObject* parent = 0 );
	~SvgSave();
	static QList<Rectangle*> getRectangles();
	static QList<Line*> getLines();
	static QList<QGraphicsItem*> getElements( const QString filename );
	static QRectF getSizes( const QString filename );

signals:

public slots:
};

#endif // SVSSAVE_H
