#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class previewwindow : public QWidget
{
    Q_OBJECT

public:
    previewwindow(QWidget *parent = 0);
    ~previewwindow();

    void setWindowFlags(Qt::WindowFlags flags);

private:
    QTextEdit *textEdit;
    QPushButton *closeButton;
};

#endif // PREVIEWWINDOW_H
