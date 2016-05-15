#ifndef TAIKOPAGE_H
#define TAIKOPAGE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <QDebug>
#include <QKeyEvent>
#include <QList>
#include "key.h"
#include <QSound>


class taikopage : public QGraphicsScene
{
    Q_OBJECT
public:
    taikopage(QWidget *parent);
    QTimer *forshowtime;  //foe ket to show
    QTimer *timer; //for key move
    void setHitpoint();
    void keyPressEvent(QKeyEvent *event);
    int score = 0;
    int check_if_hit();
    Key *hitpoint;



signals:
    void send();

public slots:
    void Start();
    void SetKeyMove();
    void movekey();
private:
    QPushButton *W;
    QWidget *mainpointer;
    Key *item[50];
    Key *ifhit;
    Key *test;


    int keytime; //when the key should show
    int showtime[50];
    int keypattern[50]; //record the WASD

private slots:
    void key_timeout();

};

#endif // TAIKOPAGE_H
