#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QLabel label("Hello world");
    //label.show();

    //QLabel *label = new QLabel("Hello world");
    //label->show();
    //label->setAttribute(Qt::WA_DeleteOnClose);

    //QPushButton button("Quit");
    //QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
    //button.show();

    QPushButton *button = new QPushButton("Quit");
    QObject::connect(button, &QPushButton::clicked, &QApplication::quit);
    button->show();
    button->setAttribute(Qt::WA_DeleteOnClose);


    return a.exec();
}
