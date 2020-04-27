#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    errolog = new QErrorMessage(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    //使用静态函数
    //QColor color = QColorDialog::getColor(Qt::red, this, QString::fromLocal8Bit("颜色对话框"), QColorDialog::ShowAlphaChannel);
    //qDebug() << "color: " << color;

    //创建对象方法
    QColorDialog dialog(Qt::red, this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();
    qDebug() << "color: " << color;

}

void MyWidget::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("文件对话框"), "D:", QString::fromLocal8Bit("图片文件(*png *jpg);;文本文件(*txt)"));
    qDebug() << "filename: " << filename;
}

void MyWidget::on_pushButton_3_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok) ui->pushButton_3->setFont(font);
    else qDebug() << QString::fromLocal8Bit("没有选择字体");

}

void MyWidget::on_pushButton_4_clicked()
{
    bool ok;
    //获取字符串
    QString string = QInputDialog::getText(this, QString::fromLocal8Bit("输入字符串对话框"), QString::fromLocal8Bit("请输入用户名:"), QLineEdit::Normal, QString::fromLocal8Bit("admin"), &ok);
    if (ok) qDebug() << "string: " << string;

    //获取整数
    int value1 = QInputDialog::getInt(this, QString::fromLocal8Bit("输入整数对话框"), QString::fromLocal8Bit("请输入-1000到1000之间的整数"), 100, -1000, 1000, 10 &ok);\
    if (ok) qDebug() << "value1: " << value1;

    //获取浮点数
    double value2 = QInputDialog::getDouble(this, QString::fromLocal8Bit("输入浮点数对话框"), QString::fromLocal8Bit("请输入-1000到1000之间的浮点数"), 0.00, -1000, 1000, 2 &ok);
    if (ok) qDebug() << "value2: " << value2;

    //获取条目
    QStringList items;
    items << QString::fromLocal8Bit("条目1") << QString::fromLocal8Bit("条目2");
    QString item = QInputDialog::getItem(this, QString::fromLocal8Bit("输入条目对话框"), QString::fromLocal8Bit("请选择或输入一个条目"), items, 0, true, &ok);
    if (ok) qDebug() << "item: " << item;



}

void MyWidget::on_pushButton_5_clicked()
{
    //问题对话框
    int ret1 = QMessageBox::question(this, QString::fromLocal8Bit("问题对话框"), QString::fromLocal8Bit("你连接QT吗"), QMessageBox::Yes, QMessageBox::No);
    if(ret1 == QMessageBox::Yes) qDebug() << QString::fromLocal8Bit("问题");
    //提示对话框
    int ret2 = QMessageBox::information(this, QString::fromLocal8Bit("提示对话框"), QString::fromLocal8Bit("这是QT书籍!"), QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok) qDebug() << QString::fromLocal8Bit("提示");
    //警告对话框
    int ret3 = QMessageBox::warning(this, QString::fromLocal8Bit("警告对话框"), QString::fromLocal8Bit("不能提前结束!"), QMessageBox::Abort);
    if(ret3 == QMessageBox::Ok) qDebug() << QString::fromLocal8Bit("警告");
    //错误对话框
    int ret4 = QMessageBox::critical(this, QString::fromLocal8Bit("严重错误对话框"), QString::fromLocal8Bit("不能提前结束"));
    if(ret4 == QMessageBox::Ok) qDebug() << QString::fromLocal8Bit("错误");
    //关于对话框
    QMessageBox::about(this, QString::fromLocal8Bit("关于对话框"),QString::fromLocal8Bit("yafeilinux致力于Qt及Qt Creator的普及工作"));

}

void MyWidget::on_pushButton_6_clicked()
{
    QProgressDialog dialog(QString::fromLocal8Bit("文件复制进度"), QString::fromLocal8Bit("取消"), 0, 50000, this);
    dialog.setWindowTitle(QString::fromLocal8Bit("进度对话框"));
    dialog.setWindowModality(Qt::WindowModal);//将对话框设置为模态
    dialog.show();
    for (int i=0; i<50000; i++){
        dialog.setValue(i);
        QCoreApplication::processEvents();//避免界面冻结
        if(dialog.wasCanceled()) break;
    }
    dialog.setValue(50000);
    qDebug() << QString::fromLocal8Bit("复制结束");
}

void MyWidget::on_pushButton_7_clicked()
{
    errolog->setWindowTitle(QString::fromLocal8Bit("错误信息对话框"));
    errolog->showMessage(QString::fromLocal8Bit("这里是出错信息"));
}

void MyWidget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(QString::fromLocal8Bit("向导对话框"));
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}

QWizardPage *MyWidget::createPage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("介绍"));
    return page;
}

QWizardPage *MyWidget::createPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("用户选择信息"));
    return page;
}

QWizardPage *MyWidget::createPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("结束"));
    return page;
}

