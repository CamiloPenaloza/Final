#include <QGraphicsPixmapItem>
#ifndef CLIMATE_ENEMIES_H
#define CLIMATE_ENEMIES_H
#define width_gota 46
#define height_gota 79
#define width_fuego 145
#define height_fuego 46

class climate_enemies : public QGraphicsPixmapItem
{
public:
    climate_enemies(int type);
    ~climate_enemies();
    void changecurrentpixmap(int x, int y);
    void set_ampliar(int ampliar);
    void fire_move(int x_move, int y_move);
private:
    int ampliar, type;
    void cargarnuevosprite();
    QPixmap *currentsprite, *pixmap;
};


#endif // CLIMATE_ENEMIES_H
