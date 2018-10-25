#ifndef MYEVENT_H
#define MYEVENT_H

#include <QWidget>
#include "mainwindow.h"
#include <QMouseEvent>
#include <QKeyEvent>

namespace Ui {
class myEvent;
}

class myEvent : public QWidget
{
    Q_OBJECT

public:
    explicit myEvent(QWidget *parent = 0);
    ~myEvent();

private slots:
    void on_pushButton_back_clicked();

protected:
    void mousePressEvent(QMouseEvent *e);

    void keyPressEvent(QKeyEvent *);

private:
    Ui::myEvent *ui;
};

#endif // MYEVENT_H
