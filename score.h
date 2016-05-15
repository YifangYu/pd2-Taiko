#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <taikopage.h>

class score : public QGraphicsScene
{
    Q_OBJECT
public:
    score(QWidget *parent);
    QWidget *mainpointer;

};

#endif // SCORE_H
