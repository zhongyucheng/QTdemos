#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include "QDebug"

namespace Ui {
class myTimer;
}

class myTimer : public QWidget
{
    Q_OBJECT

public:
    explicit myTimer(QWidget *parent = 0);
    ~myTimer();

protected:
    void timerEvent(QTimerEvent *);

private slots:
    void on_pushButton_back_clicked();
    void timerUpdate();

private:
    Ui::myTimer *ui;

    int id1, id2, id3;

};

#endif // MYTIMER_H
