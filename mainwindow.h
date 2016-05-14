#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <taikopage.h>
#include <QPushButton>
#include <QApplication>
#include <QFont>
#include <QGraphicsTextItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *countdowntimer;

private:
    Ui::MainWindow *ui;
    taikopage *taiko;
    QPushButton *btn_start;
    QPushButton *btn_exit;
    QGraphicsTextItem *clocktext;
    QFont *clockfont;
    int clocknumber;
private slots:
    void timer_timeout();
    void clock();

};

#endif // MAINWINDOW_H
