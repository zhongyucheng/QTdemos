#ifndef MYFORM_H
#define MYFORM_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class myform;
}

class myform : public QWidget
{
    Q_OBJECT

public:
    explicit myform(QWidget *parent = 0);
    ~myform();

private:
    Ui::myform *ui;
};

#endif // MYFORM_H
