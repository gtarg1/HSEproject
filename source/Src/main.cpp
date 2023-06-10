#include "Source/Controller/controller.h"
#include "Source/Entity/trackInfo.h"
#include "Source/View/mainwindow.h"
#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <iostream>
int main(int argc, char* argv[])
{


    QApplication a(argc, argv);

    Controller* controller = new Controller(new MainWindow(), new CSVModel());
    controller->initialize();

    return a.exec();
}