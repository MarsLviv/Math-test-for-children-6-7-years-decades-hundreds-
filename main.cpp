// project made in Qt 5.10.1 21.08.2018

#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QObject::tr("Math test for numbers"));
    MainWindow w;
    int width = 530;
    int height = 280;
    w.resize(width, height);

    w.move((QApplication::desktop()->width() - width) / 2 ,
               (QApplication::desktop()->height() - height) / 2);

    w.show();

    return a.exec();
}
