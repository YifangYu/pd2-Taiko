#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include <QSound>
#include <QMainWindow>
#include <taikopage.h>
#include <QPushButton>
#include <QApplication>
#include <QFont>
#include <QGraphicsTextItem>
#include <QKeyEvent>


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


public slots:
    void check_if_hit();

private:
    Ui::MainWindow *ui;
    taikopage *taiko;
    QPushButton *btn_start;
    QPushButton *btn_exit;
    QGraphicsTextItem *clocktext;
    QFont *clockfont;
    int clocknumber;
    QKeyEvent *W;
    QKeyEvent *keyevent;
    //QSound *bgm;

private slots:
    void timer_timeout();
    void clock();

};

#endif // MAINWINDOW_H
