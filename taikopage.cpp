#include "taikopage.h"
#include "key.h"

taikopage::taikopage(QWidget *parent) : mainpointer(parent)
{
    keytime=0;
    QImage bg;
    bg.load(":/new/img/Title.jpg");
    bg = bg.scaled(768,576);
    this->setBackgroundBrush(bg);
}

void taikopage::Start()
{
    emit send();
    QImage playground;
    playground.load(":/new/img/BK.jpg");
    playground = playground.scaled(768,576);
    this->setBackgroundBrush(playground);

}

 void taikopage::SetKeyMove(){
    //set W key
    /*W = new QPushButton(mainpointer);
    W->setGeometry(X,145,62,62);
    W->setIcon(QIcon(":/new/img/w-01.jpg"));
    W->setIconSize(QSize(62,62));
    W->show();*/

    srand (time(NULL));
    for (int i=0;i<30;i++){
        int randomcase = rand ()%4;
        item[i] = new Key(randomcase);
        addItem(item[i]);
        timer = new QTimer(mainpointer);
        int position =10+ rand () % 100;
        if (i==0)
            showtime[i]=position;
        else
            showtime[i]=showtime[i-1]+position;
    }
    connect(timer,SIGNAL(timeout()),this,SLOT(movekey()));
    connect(timer,SIGNAL(timeout()),this,SLOT(key_timeout()));
    timer->start(30);

    /*item2 = new Key(0);
    addItem(item2);
    timer = new QTimer(mainpointer);
    connect(timer,SIGNAL(timeout()),this,SLOT(movekey()));
    timer->start(100);*/
 }

void taikopage::movekey(){
    for (int i=0;i<15;i++){
        if(item[i]!=NULL)
        {
            if(keytime>=showtime[i])
            {
                item[i]->X_pos-=5;
                item[i]->setPos(item[i]->X_pos,145);
                if(item[i]->X_pos <200)
                {
                    this->removeItem(item[i]);
                    item[i]=NULL;
                }
            }
        }
    }

    /*int varspeed = rand () % 7;
    item2->X_pos-=5;
    item2->setPos(item2->X_pos,145);
    if(item2->X_pos <200)
    this->removeItem(item2);
    */
    update();

}

 void taikopage::key_timeout()
 {
     keytime+=1;
 }

