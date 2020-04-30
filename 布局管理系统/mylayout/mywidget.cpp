#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLayout>

mywidget::mywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mywidget)
{
    ui->setupUi(this);

    //QHBoxLayout *layout = new QHBoxLayout;//新建水平布局管理器
    //layout->addWidget(ui->fontComboBox);//向布局管理器钟添加部件
    //layout->addWidget(ui->textEdit);//向布局管理器钟添加部件
    //layout->setSpacing(50);//设置部件间的间隔
    //layout->setContentsMargins(0, 0, 50, 100);//设置布局管理局到边界的距离，左，上，右，下
    //setLayout(layout);

    //QGridLayout *layout = new QGridLayout;
    ////添加部件，从第0行0列开始，占据1行2列
    //layout->addWidget(ui->fontComboBox, 0, 0, 1, 2);
    ////添加部件，从第0行2列开始，占据1行1列
    //layout->addWidget(ui->pushButton, 0, 2, 1, 1);
    ////添加部件，从第1行0列开始，占据1行3列
    //layout->addWidget(ui->textEdit, 1, 0, 1, 3);
    //setLayout(layout);

    ui->textEdit->hide();

}

mywidget::~mywidget()
{
    delete ui;
}

void mywidget::on_pushButton_toggled(bool checked)
{
    ui->textEdit->setVisible(checked);
    if(checked) ui->pushButton->setText(tr("Hide"));
    else ui->pushButton->setText(tr("Visible"));
}
