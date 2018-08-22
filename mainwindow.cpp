#include "mainwindow.h"
//#include "numbers123.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    test1 = new Numbers123;
    setCentralWidget(test1);
}

MainWindow::~MainWindow(){
    delete test1;
}
