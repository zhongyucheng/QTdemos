#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QDebug"
#include "mynotepad.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_note_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_event_clicked();

    void on_pushButton_mytime_clicked();

    void on_pushButton_event_2_clicked();

    void on_pushButton_event_6_clicked();

    void on_pushButton_myfrom_clicked();

signals:
   // void showmynotepad();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
