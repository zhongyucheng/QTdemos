#include "myevent.h"
#include "ui_myevent.h"
#include <QMouseEvent>


myEvent::myEvent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myEvent)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("键鼠触发简例"));
}

myEvent::~myEvent()
{
    delete ui;
}

void myEvent::on_pushButton_back_clicked()
{
    MainWindow *m= new MainWindow;
    m->show();
    this->close();

}

void myEvent::mousePressEvent(QMouseEvent *e)
{
    ui->pushButton_mouse->setText(tr("(%1, %2)").arg(e->x()).arg(e->y()));
}


void myEvent::keyPressEvent(QKeyEvent *e)
{
   int x = ui->pushButton_mouse->x();
   int y = ui->pushButton_mouse->y();
   switch (e->key())
   {
   case Qt::Key_W : ui->pushButton_mouse->move(x, y-10); break;
   case Qt::Key_S : ui->pushButton_mouse->move(x, y+10); break;
   case Qt::Key_A : ui->pushButton_mouse->move(x-10, y); break;
   case Qt::Key_D : ui->pushButton_mouse->move(x+10, y); break;
   }
}
