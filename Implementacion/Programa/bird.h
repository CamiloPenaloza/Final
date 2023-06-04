#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsPixmapItem>
#define bird_x_size 16
#define bird_y_size 16

class bird: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bird();
    ~bird();
//    void spawn();
//    void move();
//    int get_position();
    void changecurrentpixmap(int x, int y);
    void set_ampliar(int ampliar);
    void moveLeft();
    void moveDown();
    void moveUp();
    void setTarget(int targetX, int targetY);
private:
    int ampliar;
    QPixmap *pixmap, *currentsprite;
    void cargarnuevosprite();
};

#endif // BIRD_H
