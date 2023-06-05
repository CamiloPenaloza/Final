#include <QGraphicsPixmapItem>
#ifndef CLIMATE_ENEMIES_H
#define CLIMATE_ENEMIES_H
#define width_gota 213
#define height_gota 181
#define width_fuego 145
#define height_fuego 46
#define meteoritoPosicion 0
class climate_enemies : public QGraphicsPixmapItem
{
public:
    climate_enemies(int type);
    ~climate_enemies();
    void changecurrentpixmap(int x, int y);
    void set_ampliar(int ampliar);
    void fire_move();
private:
    int ampliar, type;
    void cargarnuevosprite();
    QPixmap *currentsprite, *pixmap;
};


#endif // CLIMATE_ENEMIES_H
