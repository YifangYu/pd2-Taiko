#include "taikopage.h"
#include "key.h"
#include <iostream>
taikopage::taikopage(QWidget *parent) : mainpointer(parent)
{
    keytime=0;
    QImage bg;
    bg.load(":/new/img/Title.jpg");
    bg = bg.scaled(768,576);
    this->setBackgroundBrush(bg);
}

void taikopage::Start(bool phase)
{
    emit send();
    QImage playground;
    playground.load(":/new/img/BK.jpg");
    playground = playground.scaled(768,576);
    this->setBackgroundBrush(playground);

}

 void taikopage::SetKeyMove(bool key1){
    //set W key
    /*W = new QPushButton(mainpointer);
    W->setGeometry(X,145,62,62);
    W->setIcon(QIcon(":/new/img/w-01.jpg"));
    W->setIconSize(QSize(62,62));
    W->show();*/

    srand (time(NULL));
    for (int i=0;i<4;i++){
        int randomcase = rand ()%4;
        item[i] = new Key(randomcase);
        addItem(item[i]);
        timer = new QTimer(mainpointer);
    }
    connect(timer,SIGNAL(timeout()),this,SLOT(movekey()));
    connect(timer,SIGNAL(timeout()),this,SLOT(key_timeout()));
    timer->start(30);

    item2 = new Key(0);
    addItem(item2);
    timer = new QTimer(mainpointer);
    connect(timer,SIGNAL(timeout()),this,SLOT(movekey()));
    timer->start(100);
 }

void taikopage::movekey(){

    srand (time(NULL));
    for (int i=0;i<4;i++){
        int position = rand () % 100;
        if(keytime>position)
        {
            int varspeed =1 + rand () % 7;
            item[i]->X_pos-=5;
            item[i]->setPos(item[i]->X_pos,145);
            if(item[i]->X_pos <200)
            this->removeItem(item[i]);
        }
    }

    int varspeed = rand () % 7;
    item2->X_pos-=5;
    item2->setPos(item2->X_pos,145);
    if(item2->X_pos <200)
    this->removeItem(item2);
    update();
}

 void taikopage::waitforappear(){
     sleep(1);
 }

 void taikopage::key_timeout()
 {
     keytime+=1;
 }

