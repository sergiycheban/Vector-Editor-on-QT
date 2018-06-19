#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

    QPixmap pixmapClose(":/icon/Resources/animated-cat-image-0072.gif");
    QPixmap newPixmap = pixmapClose.scaled(QSize(300,300),  Qt::KeepAspectRatio);

    QSplashScreen* splash = new QSplashScreen;
    splash->setPixmap(QPixmap(newPixmap));
    splash->show();

	MainWindow w;
	w.show();

	return a.exec();
}
