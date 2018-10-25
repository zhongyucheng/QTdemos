#include "mytimer.h"
#include "ui_mytimer.h"
#include "mainwindow.h"

myTimer::myTimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTimer)
{
    ui->setupUi(this);
    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(100000);

    QTimer *timer = new QTimer(this);
    //关联定时器溢出信号和相应的槽函数
    connect(timer,&QTimer::timeout, this, &myTimer::timerUpdate);
    timer->start(1000);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    this->setWindowTitle(tr("定时器"));


}

myTimer::~myTimer()
{
    delete ui;
}


void myTimer::timerEvent(QTimerEvent *event)
{
   if (event->timerId() == id1) { // 判断是哪个定时器
       ui->label->setText(tr("%1").arg(qrand()%10));
       qDebug()<<"this is"<<id1<<"timer"<<endl;

   }
   else if (event->timerId() == id2) {
       ui->label_2->setText(tr("hello world!"));
       qDebug()<<"this is"<<id2<<"timer"<<endl;

   }
   else {
       qApp->quit();

   }
}

void myTimer::on_pushButton_back_clicked()
{
    MainWindow *m= new MainWindow;
    m->show();
    this->close();
}

void myTimer::timerUpdate()
{
    //获取系统现在的时间
    QDateTime time = QDateTime::currentDateTime();
    //设置系统时间显示格式
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    //在标签上显示时间
    ui->lineEdit->setText(str);
    ui->textEdit->setText(str);

    // 产生300以内的正整数
    int rand = qrand() % 300;
    ui->lineEdit->move(rand, rand);

}
