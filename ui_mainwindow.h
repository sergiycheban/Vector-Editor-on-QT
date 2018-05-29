/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "colorlabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    ColorLabel *borderColor_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_rect;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    ColorLabel *lineColor;
    QLabel *label_2;
    ColorLabel *borderColor;
    QLabel *label_4;
    QSpinBox *borderWidth;
    QSpacerItem *verticalSpacer;
    QWidget *widget_line;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    ColorLabel *borderColor_3;
    QLabel *label_5;
    QSpinBox *borderWidth_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *m_square;
    QPushButton *m_line;
    QPushButton *m_move;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1200, 620);
        MainWindow->setMaximumSize(QSize(1200, 620));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(95, 10, 1091, 571));
        borderColor_2 = new ColorLabel(centralWidget);
        borderColor_2->setObjectName(QStringLiteral("borderColor_2"));
        borderColor_2->setGeometry(QRect(11, 350, 16, 16));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 150, 91, 351));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_rect = new QWidget(layoutWidget);
        widget_rect->setObjectName(QStringLiteral("widget_rect"));
        layoutWidget1 = new QWidget(widget_rect);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 92, 171));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(90, 30));

        verticalLayout_4->addWidget(label);

        lineColor = new ColorLabel(layoutWidget1);
        lineColor->setObjectName(QStringLiteral("lineColor"));
        lineColor->setMaximumSize(QSize(90, 20));

        verticalLayout_4->addWidget(lineColor);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(90, 30));

        verticalLayout_4->addWidget(label_2);

        borderColor = new ColorLabel(layoutWidget1);
        borderColor->setObjectName(QStringLiteral("borderColor"));
        borderColor->setMaximumSize(QSize(90, 20));

        verticalLayout_4->addWidget(borderColor);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(90, 30));
        label_4->setScaledContents(false);

        verticalLayout_4->addWidget(label_4);

        borderWidth = new QSpinBox(layoutWidget1);
        borderWidth->setObjectName(QStringLiteral("borderWidth"));
        borderWidth->setMaximumSize(QSize(90, 30));
        borderWidth->setMinimum(0);
        borderWidth->setMaximum(200);
        borderWidth->setValue(1);

        verticalLayout_4->addWidget(borderWidth);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_3->addWidget(widget_rect);

        widget_line = new QWidget(layoutWidget);
        widget_line->setObjectName(QStringLiteral("widget_line"));
        layoutWidget2 = new QWidget(widget_line);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 91, 111));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(90, 30));

        verticalLayout->addWidget(label_3);

        borderColor_3 = new ColorLabel(layoutWidget2);
        borderColor_3->setObjectName(QStringLiteral("borderColor_3"));
        borderColor_3->setMaximumSize(QSize(90, 20));

        verticalLayout->addWidget(borderColor_3);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(90, 30));
        label_5->setScaledContents(false);

        verticalLayout->addWidget(label_5);

        borderWidth_2 = new QSpinBox(layoutWidget2);
        borderWidth_2->setObjectName(QStringLiteral("borderWidth_2"));
        borderWidth_2->setMaximumSize(QSize(90, 30));
        borderWidth_2->setMinimum(0);
        borderWidth_2->setMaximum(200);
        borderWidth_2->setValue(1);

        verticalLayout->addWidget(borderWidth_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_3->addWidget(widget_line);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 10, 91, 131));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_square = new QPushButton(layoutWidget3);
        m_square->setObjectName(QStringLiteral("m_square"));
        m_square->setEnabled(true);
        m_square->setMaximumSize(QSize(90, 40));
        m_square->setCheckable(false);

        verticalLayout_2->addWidget(m_square);

        m_line = new QPushButton(layoutWidget3);
        m_line->setObjectName(QStringLiteral("m_line"));
        m_line->setMaximumSize(QSize(90, 40));

        verticalLayout_2->addWidget(m_line);

        m_move = new QPushButton(layoutWidget3);
        m_move->setObjectName(QStringLiteral("m_move"));
        m_move->setMaximumSize(QSize(90, 40));

        verticalLayout_2->addWidget(m_move);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Graphic Editor", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        borderColor_2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Rect color", nullptr));
        lineColor->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Border color", nullptr));
        borderColor->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Border width", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Line color", nullptr));
        borderColor_3->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Line width", nullptr));
        m_square->setText(QApplication::translate("MainWindow", "Rect", nullptr));
        m_line->setText(QApplication::translate("MainWindow", "Line", nullptr));
        m_move->setText(QApplication::translate("MainWindow", "Edit", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
