#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QLinearGradient>
#include <QDebug>

namespace Ui {
class mypainter;
}

class mypainter : public QWidget
{
    Q_OBJECT

public:
    explicit mypainter(QWidget *parent = 0);
    ~mypainter();

protected:
void paintEvent(QPaintEvent *);

private slots:
void on_pushButton_back_clicked();

void on_button_drawRect_clicked(QPaintEvent *);

void on_button_drawArc_clicked();

void on_button_drawRect_clicked();

private:
    Ui::mypainter *ui;
};

#endif // MYPAINTER_H
