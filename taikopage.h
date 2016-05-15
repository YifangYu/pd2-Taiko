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
    void Start();
    void SetKeyMove();
    void movekey();
private:
    QPushButton *W;
    QWidget *mainpointer;
    Key *item[15];
    Key *item2;
    int keytime; //when the key should show
    int showtime[15];

private slots:
    void key_timeout();

};

#endif // TAIKOPAGE_H
