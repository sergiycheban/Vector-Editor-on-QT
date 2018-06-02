#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

    QPixmap pixmapClose(":/icon/Resources/cave-painting.svg");
    QPixmap newPixmap = pixmapClose.scaled(QSize(200,200),  Qt::KeepAspectRatio);

    QSplashScreen* splash = new QSplashScreen;
    splash->setPixmap(QPixmap(newPixmap));
    splash->show();

	MainWindow w;
	w.show();

	return a.exec();
}
