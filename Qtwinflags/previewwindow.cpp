#include "previewwindow.h"

previewwindow::previewwindow(QWidget *parent)
    : QWidget(parent)
{
    //textEdit设置
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    textEdit->setLineWrapMode(QTextEdit::NoWrap);

    //closeButton设置
    closeButton = new QPushButton(tr("&Close"), this);
    connect(closeButton, &QPushButton::clicked, this, &previewwindow::close);

    //布局
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(closeButton);
    setLayout(layout);

    setWindowTitle(tr("Preview"));
}

previewwindow::~previewwindow()
{

}

//重写setWindowFlags,将设置的内容显示在textEdit中
void previewwindow::setWindowFlags(Qt::WindowFlags flags)
{
    QWidget::setWindowFlags(flags);//执行setWindowsFlags,注意命名空间

    QString text;

    Qt::WindowFlags type = (flags & Qt::WindowType_Mask);//WindowType_Mask = 0x000000ff
    if(type == Qt::Window){
        text = "Qt::Window";
    }
    else if (type == Qt::Dialog) {
        text = "Qt::Dialog";
    }
    else if (type == Qt::Sheet) {
        text = "Qt::Sheet";
    }
    else if (type == Qt::Drawer) {
        text = "Qt::Drawer";
    }
    else if (type == Qt::Popup) {
        text = "Qt::Popup";
    }
    else if (type == Qt::Tool) {
        text = "Qt::Tool";
    }
    else if (type == Qt::ToolTip) {
        text = "Qt::ToolTip";
    }
    else if (type == Qt::SplashScreen) {
        text = "Qt::SplashScreen";
    }

    if (flags & Qt::MSWindowsFixedSizeDialogHint)
        text += "\n| Qt::MSWindowsFixedSizeDialogHint";
    if (flags & Qt::X11BypassWindowManagerHint)
        text += "\n| Qt::X11BypassWindowManagerHint";
    if (flags & Qt::FramelessWindowHint)
        text += "\n| Qt::FramelessWindowHint";
    if (flags & Qt::NoDropShadowWindowHint)
        text += "\n| Qt::NoDropShadowWindowHint";
    if (flags & Qt::WindowTitleHint)
        text += "\n| Qt::WindowTitleHint";
    if (flags & Qt::WindowSystemMenuHint)
        text += "\n| Qt::WindowSystemMenuHint";
    if (flags & Qt::WindowMinimizeButtonHint)
        text += "\n| Qt::WindowMinimizeButtonHint";
    if (flags & Qt::WindowMaximizeButtonHint)
        text += "\n| Qt::WindowMaximizeButtonHint";
    if (flags & Qt::WindowCloseButtonHint)
        text += "\n| Qt::WindowCloseButtonHint";
    if (flags & Qt::WindowContextHelpButtonHint)
        text += "\n| Qt::WindowContextHelpButtonHint";
    if (flags & Qt::WindowShadeButtonHint)
        text += "\n| Qt::WindowShadeButtonHint";
    if (flags & Qt::WindowStaysOnTopHint)
        text += "\n| Qt::WindowStaysOnTopHint";
    if (flags & Qt::CustomizeWindowHint)
        text += "\n| Qt::CustomizeWindowHint";

    textEdit->setPlainText(text);

}
