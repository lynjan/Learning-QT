#include "previewwindow.h"
#include "controllerwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controllerwindow w;
    w.show();

    return a.exec();
}
