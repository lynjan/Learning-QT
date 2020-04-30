#include "widget.h"
#include "ui_widget.h"
#include <QFont>
#include <QPixmap>
#include <QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QFont font("宋体", 10, -1, true);
    //font.setFamily("华文行楷");
    //font.setBold(true);
    //font.setPointSize(20);
    //font.setItalic(true);
    //ui->label->setFont(font);

    //ui->label->setFont(QFont("宋体", 10, -1, true));

    //QFont *font = new QFont("宋体", 10, -1, true);
    //ui->label->setFont(*font);
    //delete font;
//-----------------------------------------------------------
    //ui->label->setPixmap(QPixmap("./logo.png"));

    //QPixmap pixmap("./logo.png");
    //ui->label->setPixmap(pixmap);

    //QPixmap *pixmap = new QPixmap("./logo.png");
    //ui->label->setPixmap(*pixmap);
    //delete pixmap;
 //-----------------------------------------------------------
    //QMovie *movie = new QMovie("./donghua.gif");
    //ui->label->setMovie(movie);
    //movie->start();




}

Widget::~Widget()
{
    delete ui;
}
