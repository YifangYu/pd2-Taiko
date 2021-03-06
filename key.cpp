#include "key.h"
#include "taikopage.h"
#include <cstdlib>
#include <time.h>

Key::Key(int randomcase)
{
    X_pos=780;
    QPixmap key;
    switch(randomcase){
        case 1:
            key.load(":/new/img/w-01.jpg");
            type = 1;
            break;
        case 2:
            key.load(":/new/img/A-01.jpg");
            type = 2;
            break;
        case 3:
            key.load(":/new/img/D-01.jpg");
            type = 3;
            break;
        case 0:
            key.load(":/new/img/S-01.jpg");
            type = 0;
            break;
        case 4:
            key.load(":/new/img/hitpoint.jpg");
            break;
        default:
        break;
    }
    key = key.scaled(key.width() , key.height(),Qt::KeepAspectRatio);
    this->setPixmap(key);
    this->setPos(X_pos,145);
}

