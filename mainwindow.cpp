#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taikopage.h"
#include <QTimer>
#include <QKeyEvent>
#include <iostream>
#include <QDebug>
//#include <QSound>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    taiko = new taikopage(this);
    ui->graphicsView->setScene(taiko);
    taiko->setSceneRect(0,0,768,576);

    //set start button
    btn_start = new QPushButton(this);
    btn_start->setGeometry(120,375,200,80);
    btn_start->setIcon(QIcon(":/new/img/start-01.png"));
    btn_start->setIconSize(QSize(200,80));

    //set exit button
    btn_exit = new QPushButton(this);
    btn_exit->setGeometry(425,375,200,80);
    btn_exit->setIcon(QIcon(":/new/img/exit-01.png"));
    btn_exit->setIconSize(QSize(200,80));

    //set exit
    connect(btn_exit,SIGNAL(clicked()),QApplication::instance(),SLOT(quit()));

    //set start event, click and start to play
    connect(btn_start,SIGNAL(clicked(bool)),this,SLOT(clock()));
    connect(btn_start,SIGNAL(clicked(bool)),taiko,SLOT(Start()));
    connect(btn_start,SIGNAL(clicked(bool)),btn_start,SLOT(hide()));
    connect(btn_start,SIGNAL(clicked(bool)),btn_exit,SLOT(hide()));
    connect(btn_start,SIGNAL(clicked(bool)),taiko,SLOT(SetKeyMove()));

    /*keypressevent
    W = new QKeyEvent();
    if(W->key()== Qt::Key_W)
        std::cout<<"OK!!!"<<std::endl;*/
    keypressevent(keyevent);

    //set music
    //bgm = new QSound(":/new/img/Music.wav");
    //bgm->play();




}

void MainWindow::clock()
{
    //set time
    clocknumber = 30;
    clockfont = new QFont;
    clockfont->setFamily("Calibri");
    clockfont->setPixelSize(50);
    countdowntimer = new QTimer(this);
    countdowntimer->setInterval(1000);

        clocktext = new QGraphicsTextItem;
        clocktext->setPos(34,141);
        clocktext->adjustSize();
        clocktext->setFont(*clockfont);

    taiko->addItem(clocktext);
    connect(countdowntimer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
    countdowntimer->start();
}

void MainWindow::timer_timeout()
{
    QString clocknumbertext;
    clocknumbertext=QString::number(clocknumber);
    clocktext->setPlainText(clocknumbertext);
    clocknumber--;
    if(clocknumber==-2)
        this->close();
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keypressevent(QKeyEvent *keyevent)
{
    switch(keyevent->key())
    {
    case Qt::Key_W:
        std::cout<<"OK!!!"<<std::endl;
        qDebug() << "you had key W!!!!";
        break;
    case Qt::Key_A:

        break;
    case Qt::Key_D:

        break;
    case Qt::Key_S:

        break;

    }
}



