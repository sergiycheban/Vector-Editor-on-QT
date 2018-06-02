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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "colorlabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionAdd_tad;
    QAction *actionInfo;
    QAction *actionSelect_all;
    QAction *actionDelete_Item;
    QAction *actionSeparate_menu;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QPushButton *m_question;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_rect;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    ColorLabel *lineColor;
    QLabel *label_2;
    ColorLabel *borderColor;
    QLabel *label_4;
    QSpinBox *borderWidth;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_6;
    QSpinBox *borderWidth_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget_line;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    ColorLabel *borderColor_3;
    QLabel *label_5;
    QSpinBox *borderWidth_2;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_2;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGraphicsView *graphicsView;
    QWidget *tab_2;
    QGraphicsView *graphicsView_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_5;
    QPushButton *m_square;
    QPushButton *m_line;
    QPushButton *m_move;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_save;
    QPushButton *m_open;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(1300, 620);
        MainWindow->setMaximumSize(QSize(1300, 620));
        QFont font;
        font.setKerning(true);
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setAnimated(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionAdd_tad = new QAction(MainWindow);
        actionAdd_tad->setObjectName(QStringLiteral("actionAdd_tad"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionSelect_all = new QAction(MainWindow);
        actionSelect_all->setObjectName(QStringLiteral("actionSelect_all"));
        actionDelete_Item = new QAction(MainWindow);
        actionDelete_Item->setObjectName(QStringLiteral("actionDelete_Item"));
        actionDelete_Item->setCheckable(false);
        actionSeparate_menu = new QAction(MainWindow);
        actionSeparate_menu->setObjectName(QStringLiteral("actionSeparate_menu"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        m_question = new QPushButton(centralWidget);
        m_question->setObjectName(QStringLiteral("m_question"));
        m_question->setMinimumSize(QSize(30, 30));
        m_question->setMaximumSize(QSize(25, 25));

        gridLayout_2->addWidget(m_question, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_rect = new QWidget(centralWidget);
        widget_rect->setObjectName(QStringLiteral("widget_rect"));
        widget_rect->setMinimumSize(QSize(120, 0));
        widget_rect->setMaximumSize(QSize(90, 16777215));
        layoutWidget = new QWidget(widget_rect);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 121, 215));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(90, 30));

        verticalLayout_4->addWidget(label);

        lineColor = new ColorLabel(layoutWidget);
        lineColor->setObjectName(QStringLiteral("lineColor"));
        lineColor->setMaximumSize(QSize(90, 20));

        verticalLayout_4->addWidget(lineColor);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(90, 30));

        verticalLayout_4->addWidget(label_2);

        borderColor = new ColorLabel(layoutWidget);
        borderColor->setObjectName(QStringLiteral("borderColor"));
        borderColor->setMaximumSize(QSize(90, 20));

        verticalLayout_4->addWidget(borderColor);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(90, 30));
        label_4->setScaledContents(false);

        verticalLayout_4->addWidget(label_4);

        borderWidth = new QSpinBox(layoutWidget);
        borderWidth->setObjectName(QStringLiteral("borderWidth"));
        borderWidth->setMaximumSize(QSize(90, 30));
        borderWidth->setMinimum(0);
        borderWidth->setMaximum(200);
        borderWidth->setValue(1);

        verticalLayout_4->addWidget(borderWidth);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);

        doubleSpinBox = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximumSize(QSize(90, 16777215));
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox->setValue(1);

        verticalLayout_4->addWidget(doubleSpinBox);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        borderWidth_3 = new QSpinBox(layoutWidget);
        borderWidth_3->setObjectName(QStringLiteral("borderWidth_3"));
        borderWidth_3->setMaximumSize(QSize(90, 30));
        borderWidth_3->setMinimum(10);
        borderWidth_3->setMaximum(100);
        borderWidth_3->setValue(10);

        verticalLayout_4->addWidget(borderWidth_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_3->addWidget(widget_rect);

        widget_line = new QWidget(centralWidget);
        widget_line->setObjectName(QStringLiteral("widget_line"));
        widget_line->setMinimumSize(QSize(120, 0));
        widget_line->setMaximumSize(QSize(120, 16777215));
        layoutWidget1 = new QWidget(widget_line);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 121, 136));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(90, 0));
        label_3->setMaximumSize(QSize(90, 30));

        verticalLayout->addWidget(label_3);

        borderColor_3 = new ColorLabel(layoutWidget1);
        borderColor_3->setObjectName(QStringLiteral("borderColor_3"));
        borderColor_3->setMinimumSize(QSize(90, 0));
        borderColor_3->setMaximumSize(QSize(90, 20));

        verticalLayout->addWidget(borderColor_3);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(90, 0));
        label_5->setMaximumSize(QSize(90, 30));
        label_5->setScaledContents(false);

        verticalLayout->addWidget(label_5);

        borderWidth_2 = new QSpinBox(layoutWidget1);
        borderWidth_2->setObjectName(QStringLiteral("borderWidth_2"));
        borderWidth_2->setMaximumSize(QSize(90, 30));
        borderWidth_2->setMinimum(0);
        borderWidth_2->setMaximum(200);
        borderWidth_2->setValue(1);

        verticalLayout->addWidget(borderWidth_2);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout->addWidget(label_8);

        doubleSpinBox_2 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximumSize(QSize(90, 16777215));
        doubleSpinBox_2->setMaximum(1);
        doubleSpinBox_2->setSingleStep(0.01);
        doubleSpinBox_2->setValue(1);

        verticalLayout->addWidget(doubleSpinBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_3->addWidget(widget_line);


        gridLayout_2->addLayout(verticalLayout_3, 0, 3, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(1020, 0));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(32, 32));
        tabWidget->setElideMode(Qt::ElideMiddle);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1020, 551));
        graphicsView->setMinimumSize(QSize(1020, 551));
        graphicsView->setMaximumSize(QSize(1020, 551));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        graphicsView_3 = new QGraphicsView(tab_2);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(0, 0, 1020, 551));
        graphicsView_3->setMinimumSize(QSize(1020, 551));
        graphicsView_3->setMaximumSize(QSize(1020, 551));
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 2, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(120, 0));
        widget->setMaximumSize(QSize(120, 16777215));
        widget1 = new QWidget(widget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(0, 2, 121, 141));
        verticalLayout_5 = new QVBoxLayout(widget1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        m_square = new QPushButton(widget1);
        m_square->setObjectName(QStringLiteral("m_square"));
        m_square->setEnabled(true);
        m_square->setMaximumSize(QSize(90, 29));
        m_square->setCheckable(false);

        verticalLayout_5->addWidget(m_square);

        m_line = new QPushButton(widget1);
        m_line->setObjectName(QStringLiteral("m_line"));
        m_line->setMaximumSize(QSize(90, 29));

        verticalLayout_5->addWidget(m_line);

        m_move = new QPushButton(widget1);
        m_move->setObjectName(QStringLiteral("m_move"));
        m_move->setMaximumSize(QSize(90, 29));

        verticalLayout_5->addWidget(m_move);


        verticalLayout_2->addWidget(widget);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_save = new QPushButton(centralWidget);
        m_save->setObjectName(QStringLiteral("m_save"));
        m_save->setMinimumSize(QSize(40, 40));
        m_save->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(m_save);

        m_open = new QPushButton(centralWidget);
        m_open->setObjectName(QStringLiteral("m_open"));
        m_open->setMinimumSize(QSize(40, 40));
        m_open->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(m_open);


        gridLayout_2->addLayout(horizontalLayout, 1, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Graphic Editor", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionAdd_tad->setText(QApplication::translate("MainWindow", "Add tad", nullptr));
        actionInfo->setText(QApplication::translate("MainWindow", "Information", nullptr));
        actionSelect_all->setText(QApplication::translate("MainWindow", "Select all", nullptr));
        actionDelete_Item->setText(QApplication::translate("MainWindow", "Delete Item", nullptr));
        actionSeparate_menu->setText(QApplication::translate("MainWindow", "Separate menu", nullptr));
        m_question->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Rect", nullptr));
        lineColor->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Border", nullptr));
        borderColor->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Width", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Opacity", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Shadow", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Line", nullptr));
        borderColor_3->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Width", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Opacity", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Main", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Subsidiary", nullptr));
        m_square->setText(QApplication::translate("MainWindow", "Rectangle", nullptr));
        m_line->setText(QApplication::translate("MainWindow", "Line        ", nullptr));
        m_move->setText(QApplication::translate("MainWindow", "Edit        ", nullptr));
        m_save->setText(QString());
        m_open->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
