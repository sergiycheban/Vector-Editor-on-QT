#ifndef SELECTIONRECT_H
#define SELECTIONRECT_H

#include <QObject>
#include <QGraphicsRectItem>

class SelectionRect : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit SelectionRect(QObject *parent = 0);
    ~SelectionRect();

    enum {
        Type = UserType + 1
    };
    int type() const override;

signals:

public slots:
};

#endif // SELECTIONRECT_H
