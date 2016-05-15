#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSound>
#include <QMainWindow>
#include <taikopage.h>
#include <QPushButton>
#include <QApplication>
#include <QFont>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QImage>


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
    QImage *scorepage;
    QPushButton *btn_start;
    QPushButton *btn_exit;
    QPushButton *btn_restart;
    QPushButton *btn_exit2;
    QGraphicsTextItem *clocktext;
    QGraphicsTextItem *playscore;
    QFont *clockfont;
    QFont *playscorefont;
    QString *playscoretext;
    int clocknumber;
    QKeyEvent *W;
    QKeyEvent *keyevent;
    QSound *bgm;

private slots:
    void timer_timeout();
    void clock();

};

#endif // MAINWINDOW_H
