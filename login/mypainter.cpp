#include "mypainter.h"
#include "ui_mypainter.h"
#include "mainwindow.h"
#include "QLinearGradient"

int  paint_status = 0;

mypainter::mypainter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mypainter)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("画笔"));
    /*
    //线形渐变
    QLinearGradient linearGradient(QPointF(100,100)),QPointF(150,100));
    //插入颜色
    linearGradient.setColorAt(0,Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::red);
    linearGradient.setColorAt(1, Qt::green);
    //指定渐变区域以外的区域的扩散方式
    linearGradient.setSpread(QGradient::RepeatSpread);
    //使用渐变作为画刷
    QPainter painter(this);
    painter.setBrush(linearGradient);
    painter.drawRect(100, 100, 90, 40);
    */

}

mypainter::~mypainter()
{
    delete ui;
}


void mypainter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen; //画笔
    pen.setStyle(Qt::DashLine);
    painter.drawLine(QPointF(0, 0), QPointF(100, 100));  //画一条线
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(255, 128,99));
  //  pen.setStyle();
    QBrush brush(QColor(0, 255, 0, 125)); //画刷
    painter.setPen(pen); //添加画笔
    painter.setBrush(brush); //添加画刷

    painter.drawRect(100, 100, 200, 100); //绘制矩形



    QRectF rectangle(300.0,200.0, 80.0, 60.0); //矩形
    int startAngle = 30 * 16;     //起始角度
    int spanAngle = 120 * 16;   //跨越度数

    painter.drawArc(rectangle, startAngle, spanAngle);


}

void mypainter::on_pushButton_back_clicked()
{
    MainWindow *m= new MainWindow;
    m->show();
    this->close();

}

void mypainter::on_button_drawRect_clicked(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(Qt::DotLine);
    QBrush brush(Qt::blue);
    brush.setStyle(Qt::HorPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(150,150,300,300);

}

void mypainter::on_button_drawArc_clicked()
{
    paint_status = 1;
    /*
    qDebug()<<"矩形"<<endl;
    QRectF rectangle(10.0, 20.0, 80.0, 60.0); //矩形
    int startAngle = 30 * 16;     //起始角度
    int spanAngle = 120 * 16;   //跨越度数
    QPainter painter(this);
    painter.drawArc(rectangle, startAngle, spanAngle);
    */
}

void mypainter::on_button_drawRect_clicked()
{
    qDebug()<<"三角形"<<endl;
    QRectF rectangle(10.0, 20.0, 80.0, 60.0); //矩形
    int startAngle = 30 * 16;     //起始角度
    int spanAngle = 120 * 16;   //跨越度数
    QPainter painter(this);
    painter.drawArc(rectangle, startAngle, spanAngle);

}
