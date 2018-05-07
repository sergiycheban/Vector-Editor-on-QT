#include "selectionrect.h"
#include <QPen>
#include <QBrush>

SelectionRect::SelectionRect(QObject *parent) :
    QObject(parent)
{
    setBrush(QBrush(QColor(158,182,255,96)));
    setPen(QPen(QColor(158,182,255,200),1));
}

SelectionRect::~SelectionRect()
{

}

int SelectionRect::type() const
{
    return Type;
}
