#ifndef KEY_H
#define KEY_H
#include <QGraphicsPixmapItem>

class Key : public QGraphicsPixmapItem
{
public:
    Key(int randomcase);
    int X_pos;
    int randomcase;

private slots:

};

#endif // KEY_H
