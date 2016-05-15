#ifndef KEY_H
#define KEY_H
#include <QGraphicsPixmapItem>

class Key : public QGraphicsPixmapItem
{
public:
    Key(int randomcase);
    int X_pos;
    int randomcase;
    int type;

};

#endif // KEY_H
