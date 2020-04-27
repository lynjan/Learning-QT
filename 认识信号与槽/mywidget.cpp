#include "mywidget.h"
#include "mydialog.h"
#include "ui_mywidget.h"
#include <QDialog>
#include <QPushButton>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    //QDialog dialog(this);
    //dialog.show();

    //QDialog *dialog = new QDialog(this);
    //dialog->show();

    //QDialog dialog(this);
    //dialog.exec();

    //QDialog * dialog = new QDialog(this);
    //dialog->exec();

    //QDialog * dialog = new QDialog(this);
    //dialog->setModal(true);
    //dialog->show();

    //connect(ui->showClickButton, &QPushButton::clicked, this, &myWidget::showClickDialog);
}

myWidget::~myWidget()
{
    delete ui;
}

/*void myWidget::showClickDialog()
{
    QDialog *dialog =new QDialog(this);
    dialog->show();
}*/

void myWidget::on_showClickButton_clicked()
{
    QDialog *dialog =new QDialog(this);
    dialog->show();
}

void myWidget::on_pushButton_clicked()
{
    close();
    myDialog dlg;
    if (dlg.exec() == QDialog::Accepted) show();
}
