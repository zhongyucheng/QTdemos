#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mynotepad.h"
#include "logindialog.h"
#include "myevent.h"
#include "mytimer.h"
#include "mypainter.h"
#include "myform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("主界面"));

    qDebug()<<"this is mainwindow.cpp debug"<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ;

}

void MainWindow::on_pushButton_note_clicked()
{
    mynotepad *n=new mynotepad;



    n->show();

    this->close();
}

void MainWindow::on_pushButton_back_clicked()
{
    LoginDialog *l=new LoginDialog;
    l->show();
    this->close();

}

void MainWindow::on_pushButton_event_clicked()
{
    myEvent *e =new myEvent;
    e->show();
    this->close();

}



void MainWindow::on_pushButton_mytime_clicked()
{
    myTimer *t =new myTimer;
    t->show();
    this->close();

}

void MainWindow::on_pushButton_event_2_clicked()
{
    mypainter *p=new mypainter;
    p->show();
    this->close();

}

void MainWindow::on_pushButton_event_6_clicked()
{

}

void MainWindow::on_pushButton_myfrom_clicked()
{
    myform *p = new myform;
    p->show();
    this->close();

}
