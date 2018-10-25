#include "myform.h"
#include "ui_myform.h"

myform::myform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myform)
{
    ui->setupUi(this);
    this->setWindowTitle("手动创造控件");
    QPushButton button_new;
    button_new.setText("新窗口");
    button_new.setParent(this);
    button_new.show();
    QPushButton button_back;


}

myform::~myform()
{
    delete ui;
}
