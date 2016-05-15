#include "score.h"

score::score(QWidget *parent) : mainpointer(parent)
{
    QImage scorepage;
    scorepage.load(":/new/img/score.jpg");
    scorepage = scorepage.scaled(768,576);
    this->setBackgroundBrush(scorepage);
}
