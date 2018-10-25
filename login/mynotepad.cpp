#include "mynotepad.h"
#include "ui_mynotepad.h"

#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QDialog>

mynotepad::mynotepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mynotepad)
{
    ui->setupUi(this);

 /*   QPushButton *btn = new QPushButton(this);
    QLineEdit *le = new QLineEdit(this);

    // 新建栅格布局管理器
    QGridLayout *layout = new QGridLayout;
    // 添加部件，从第0行0列开始，占据1行1列
    layout->addWidget(btn, 0, 0, 1, 1);
    // 添加部件，从第0行1列开始，占据1行2列
    layout->addWidget(le, 0, 1, 1, 2);
    // 添加部件，从第1行0列开始，占据1行3列
    layout->addWidget(ui->textEdit, 1, 0, 1, 3);
    ui->centralwidget->setLayout(layout);


     this->setWindowTitle(tr("记事本"));

*/

    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("查找"));
    findLineEdit = new QLineEdit(findDlg);
    QPushButton *btn= new QPushButton(tr("查找下一个"), findDlg);
    QVBoxLayout *layout= new QVBoxLayout(findDlg);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    connect(btn, &QPushButton::clicked, this, &mynotepad::showFindText);

    // 初始化文件为未保存状态
    isUntitled = true;
    // 初始化文件名为"未命名.txt"
    curFile = tr("未命名.txt");
    // 初始化窗口标题为文件名
    setWindowTitle(curFile);

   ui->statusbar->showMessage(tr("练习程序-记事本"),10000);



}

mynotepad::~mynotepad()
{
    delete ui;
}


void mynotepad::newFile()
{
    if(maybeSave())
    {
        isUntitled=true;
        curFile=tr("未命名.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool mynotepad::maybeSave()
{
    if(ui->textEdit->document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr ("尚未保存，是否保存"));
   //     QPushButton *yesBtn = box.addButton(tr("是(&Y)")),
    //           QMessageBox::YesRole);

        QPushButton *yesBtn = box.addButton(tr("是(&Y)"),
                                            QMessageBox::YesRole);


        box.addButton(tr("否(&N)"), QMessageBox::NoRole);
        QPushButton *cancelBut = box.addButton(tr("取消"),
                                               QMessageBox::RejectRole);


    //    box.addButton(tr("否")),QMessageBox::NoRole;
    //    QPushButton *cancelBut = box.addButton(tr("取消")),QMessageBox::RejectRole);

        box.exec();

        if(box.clickedButton() == yesBtn)
            return save();
        else if (box.clickedButton() ==cancelBut )
            return false;

    }
//未更改返回true
    return true;
}



bool mynotepad::save()
{
    if(isUntitled)
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFile);
    }
}


bool mynotepad::saveAs()
{
    QString filename =QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
    if(filename.isEmpty()) return false;
    return saveFile(filename);
}



bool mynotepad::saveFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
      //  QMessageBox::warning(this,tr("多文档编辑器")),
        //tr("无法读取文件 %1\n%2.").arg(fileName).arg(file.errorString());

        // %1和%2分别对应后面arg两个参数，/n起换行的作用
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法写入文件 %1：/n %2")
                             .arg(fileName).arg(file.errorString()));


        return false;
    }
    QTextStream out(&file);
    // 鼠标指针变为等待状态
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();
    // 鼠标指针恢复原来的状态
    QApplication::restoreOverrideCursor();
    isUntitled = false;
    // 获得文件的标准路径
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}


//打开动作

void mynotepad::on_action_Open_triggered()

{
    if(maybeSave())
    {
        QString filename =QFileDialog::getOpenFileName(this);

        if(!filename.isEmpty())
        {
            loadFile(filename);
            ui->textEdit->setVisible(true);
        }
    }
}

//关闭动作
void mynotepad::on_action_Close_triggered()
{
    if (maybeSave()) {
        ui->textEdit->setVisible(false);
    }
}



void mynotepad::on_action_Exit_triggered()

{
    // 先执行关闭操作，再退出程序
    // qApp是指向应用程序的全局指针
    on_action_Close_triggered();
    qApp->quit();

}

// 撤销动作
void mynotepad::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

// 剪切动作
void mynotepad::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}

// 复制动作
void mynotepad::on_action_Copy_triggered()
{
    ui->textEdit->copy();
}

// 粘贴动作
void mynotepad::on_action_Paste_triggered()
{
    ui->textEdit->paste();
}

void mynotepad::showFindText()
{
    QString str = findLineEdit->text();

    if (!ui->textEdit->find(str, QTextDocument::FindBackward))
    {
       QMessageBox::warning(this, tr("查找"),
                tr("找不到%1").arg(str));
    }
}

void mynotepad::on_action_Find_triggered()
{
    findDlg->show();

}

void mynotepad::on_action_Back_triggered()
{
    MainWindow *m =new MainWindow;


    m->show();

    this->close();

}


void mynotepad::closeEvent(QCloseEvent *event)
{
    // 如果maybeSave()函数返回true，则关闭程序
    if (maybeSave()) {
        event->accept();
    } else {   // 否则忽略该事件
        event->ignore();
    }
}



bool mynotepad::loadFile(const QString &fileName)
{
    QFile file(fileName); // 新建QFile对象
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法读取文件 %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return false; // 只读方式打开文件，出错则提示，并返回false
    }
    QTextStream in(&file); // 新建文本流对象
    QApplication::setOverrideCursor(Qt::WaitCursor);
    // 读取文件的全部文本内容，并添加到编辑器中
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    // 设置当前文件
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}


void mynotepad::on_action_New_triggered()
{
    newFile();
}

void mynotepad::on_action_Save_triggered()
{
    save();
}

void mynotepad::on_action_SaveAs_triggered()
{
    saveAs();
}








