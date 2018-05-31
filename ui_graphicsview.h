/********************************************************************************
** Form generated from reading UI file 'graphicsview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSVIEW_H
#define UI_GRAPHICSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicsView
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *GraphicsView)
    {
        if (GraphicsView->objectName().isEmpty())
            GraphicsView->setObjectName(QStringLiteral("GraphicsView"));
        GraphicsView->resize(1189, 576);
        graphicsView = new QGraphicsView(GraphicsView);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1101, 541));
        graphicsView->setMinimumSize(QSize(1101, 541));
        graphicsView->setMaximumSize(QSize(1101, 541));

        retranslateUi(GraphicsView);

        QMetaObject::connectSlotsByName(GraphicsView);
    } // setupUi

    void retranslateUi(QWidget *GraphicsView)
    {
        GraphicsView->setWindowTitle(QApplication::translate("GraphicsView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphicsView: public Ui_GraphicsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSVIEW_H
