#include "logindialog.h"
#include "ui_logindialog.h"
#include "QMessageBox"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->pwdLineEidt->setEchoMode(QLineEdit::Password);
    this->setWindowTitle("登录");

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->usrLineEdit->text() == tr("a")&& ui->pwdLineEidt->text() == tr("a"))


    {
         accept();

    }

        else {

        QMessageBox::warning(this, tr("警告！"),
                          tr("用户名或密码错误！"),
                          QMessageBox::tr("重试"));

        ui->usrLineEdit->clear();

        ui->pwdLineEidt->clear();

        ui->usrLineEdit->setFocus();



      //  QMessageBox::warning(this,tr("警告!")),
              //  tr("用户名错误"),
           //     QMessageBox::Yes);   */

    }


}
