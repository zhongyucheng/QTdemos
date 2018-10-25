#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog dlg;
    MainWindow w;
    // w.setWindowTitle("主界面");
  //   dlg.setWindowTitle("登录界面");

    if(dlg.exec()==QDialog::Accepted)
    {
        w.show();

    qDebug()<<"this is main.cpp"<<endl;
        return a.exec();
    }

    else {
        return 0;
    }

}
