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
#include "key.h"


class taikopage : public QGraphicsScene
{
    Q_OBJECT
public:
    taikopage(QWidget *parent);
    QTimer *forshowtime;  //foe ket to show
    QTimer *timer; //for key move

signals:
    void send();
    void sendKey();
public slots:
    void Start(bool phase);
    void SetKeyMove(bool key);
    void movekey();
    void waitforappear();
private:
    QPushButton *W;
    QWidget *mainpointer;
    Key *item[4];
    Key *item2;
    int showtime;
    int keytime; //when the key should show

private slots:
    void key_timeout();

};

#endif // TAIKOPAGE_H
