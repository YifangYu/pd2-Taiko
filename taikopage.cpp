#include "taikopage.h"
#include "key.h"
#include <QDebug>



taikopage::taikopage(QWidget *parent) : mainpointer(parent)
{
    keytime=0;
    QImage bg;
    bg.load(":/new/img/Title.jpg");
    bg = bg.scaled(768,576);
    this->setBackgroundBrush(bg);
    hit = new QSound(":/new/img/hit.wav");
}

void taikopage::setHitpoint()
{
    hitpoint = new Key(4);
    addItem(hitpoint);
    hitpoint->setPos(200,145);
}

void taikopage::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_W:
            if(check_if_hit()==1)
            {
                score++;
                hit->play();
            }
        break;

        case Qt::Key_A:
            if(check_if_hit()==2)
            {
                score++;
                hit->play();
            }
        break;

        case Qt::Key_D:
            if(check_if_hit()==3)
            {
                score++;
                hit->play();
            }
        break;

        case Qt::Key_S:
            if(check_if_hit()==0)
            {
                score++;
                hit->play();
            }
        break;

        case Qt::Key_B:
            qDebug() << "Hit";
    }
}

int taikopage::check_if_hit()
{
QList<QGraphicsItem *> hit_list = this->collidingItems(hitpoint);
    foreach (QGraphicsItem *i, hit_list) {
        Key *ifhit = dynamic_cast<Key *>(i);
        if(ifhit->X_pos < 240 && ifhit->X_pos > 190)
            if(ifhit->type==1)
            {
                return 1;
            }
            else if(ifhit->type==2)
            {
                return 2;
            }
            else if(ifhit->type==3)
            {
                return 3;
            }
            else if(ifhit->type==0)
            {
                return 0;
            }
        }
}

void taikopage::Start()
{
    QImage playground;
    playground.load(":/new/img/BK.jpg");
    playground = playground.scaled(768,576);
    this->setBackgroundBrush(playground);

}

 void taikopage::SetKeyMove(){
    setHitpoint();
    score = 0;
    keytime = 0;
    timer = new QTimer(mainpointer);
    for (int i=0;i<50;i++){
            int randomcase = rand ()%4;
            keypattern[i]=randomcase;
            item[i] = new Key(randomcase);
            addItem(item[i]);
            int position = 10 + rand () % 40;
            if (i==0)
                showtime[i]=position;
            else
                showtime[i]=showtime[i-1]+position;
            //qDebug() << showtime[i];
    }
    connect(timer,SIGNAL(timeout()),this,SLOT(movekey()));
    connect(timer,SIGNAL(timeout()),this,SLOT(key_timeout()));
    timer->start(25);
 }

void taikopage::movekey(){
    //qDebug()<<keytime;
    for (int i=0;i<50;i++){
        if(item[i]!=NULL)
        {
            if(keytime>=showtime[i])
            {
                item[i]->X_pos-=5;
                item[i]->setPos(item[i]->X_pos,145);
                if(item[i]->X_pos<500)
                {
                    item[i]->X_pos-=10;
                    item[i]->setPos(item[i]->X_pos,145);
                }
                if(item[i]->X_pos <190)
                {
                    this->removeItem(item[i]);
                    delete item[i];
                    item[i]=NULL;
                }
            }
            else if(keytime>850)
            {
                this->removeItem(item[i]);
                delete item[i];
                item[i]=NULL;

            }
        }
    }
    update();

}

 void taikopage::key_timeout()
 {
     keytime+=1;
 }

