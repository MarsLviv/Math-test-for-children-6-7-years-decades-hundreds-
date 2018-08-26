// project made in Qt 5.10.1 21.08.2018

#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QDebug>
#include <QLocale>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;

    QStringList langs;
    langs << "English" << "Ukrainian";

    QString chosenLang = QInputDialog::getItem(NULL, "Select language", "Language", langs);
    if (chosenLang == "Ukrainian"){
        t.load(":/main_uk.qm");
        a.installTranslator(&t);
    }

    a.setApplicationName(QObject::tr("Math test for numbers"));
    MainWindow w;
    int width = 530;
    int height = 280;
    w.resize(width, height);

    w.move((QApplication::desktop()->width() - width) / 2 ,
               (QApplication::desktop()->height() - height) / 2);

    w.show();

    QLocale locale;
    qDebug() << "QLocale::name()" << locale.name();
    QString strEng("en_US"), strUk("uk_UA");
    if (locale.name() == strEng)
        qDebug() << "OK";

    return a.exec();
}
// https://learning.ua/matematyka/tretii-klas/zapysuiemo-chyslo-za-rozriadamy
// https://www.youtube.com/watch?v=In5QH_ZrDJE
