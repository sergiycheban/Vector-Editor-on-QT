#include "svssave.h"
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <QDomDocument>
#include <QStringList>
#include <QTransform>
#include <QDebug>
#include "rectangle.h"
#include "line.h"

SvgSave::SvgSave(QObject *parent) : QObject(parent)
{

}

SvgSave::~SvgSave()
{

}

QList<Rectangle *> SvgSave::getRectangles()
{
    QList<Rectangle *> rectList;
      return rectList;
}

QList<Line *> SvgSave::getLines()
{
    QList<Line *> lineList;
        return lineList;
}

QList<QGraphicsItem *> SvgSave::getElements(const QString filename)
{
    QList<QGraphicsItem *> graphicsList;

    QDomDocument doc;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return graphicsList;

    QDomNodeList gList = doc.elementsByTagName("g");

    for (int i = 0; i < gList.size(); i++) {
        QDomNode gNode = gList.item(i);

        QDomElement pathElement = gNode.firstChildElement("path");
        if (!pathElement.isNull()){
            Line *line = new Line();
            auto pElement = gNode.toElement();

            line->setBrush(QBrush(Qt::transparent));

            QColor strokeColor(pElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(pElement.attribute("stroke-opacity").toFloat());
            line->setPen(QPen(strokeColor, pElement.attribute("stroke-width", "0").toInt()));

            QPainterPath path;
            QStringList listDotes = pathElement.attribute("d").split(" ");
            QString first = listDotes.at(0);
            QStringList firstElement = first.replace(QString("M"),QString("")).split(",");
            path.moveTo(firstElement.at(0).toInt(),firstElement.at(1).toInt());
            for(int i = 1; i < listDotes.length(); i++){
                QString other = listDotes.at(i);
                QStringList dot = other.replace(QString("L"),QString("")).split(",");
                path.lineTo(dot.at(0).toInt(),dot.at(1).toInt());
            }
            line->setPath(path);
            graphicsList.append(line);
            continue;
        }

        QDomElement rectangle = gNode.firstChildElement("rect");
        if (!rectangle.isNull()){
            Rectangle *rect = new Rectangle();
            auto gElement = gNode.toElement();
            rect->setRect(rectangle.attribute("x").toInt(),
                          rectangle.attribute("y").toInt(),
                          rectangle.attribute("width").toInt(),
                          rectangle.attribute("height").toInt());

                QColor fillColor(gElement.attribute("fill", "#ffffff"));
                fillColor.setAlphaF(gElement.attribute("fill-opacity","0").toFloat());
                rect->setBrush(QBrush(fillColor));

            QColor strokeColor(gElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

            QString transString = gElement.attribute("transform");
            transString.replace(QString("matrix("),QString(""));
            transString.replace(QString(")"),QString(""));

            rect->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toInt()));

            graphicsList.append(rect);
            continue;
        }
    }
    file.close();

    return graphicsList;
}

QRectF SvgSave::getSizes(const QString filename)
{
    QDomDocument doc;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return QRectF(0,0,200,200);

    QDomNodeList list = doc.elementsByTagName("svg");
    if(list.length() > 0) {
        auto svgElement = list.item(0).toElement();
        auto parameters = svgElement.attribute("viewBox").split(" ");
        return QRectF(parameters.at(0).toInt(),
                      parameters.at(1).toInt(),
                      parameters.at(2).toInt(),
                      parameters.at(3).toInt());
    }
    return QRectF(0,0,200,200);
}
