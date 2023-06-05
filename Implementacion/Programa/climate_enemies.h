#include <QGraphicsPixmapItem>
#include <string>
#ifndef CLIMATE_ENEMIES_H
#define CLIMATE_ENEMIES_H
#define width_gota 213
#define height_gota 181
//#define gotas ":/sprites/gota.png"
//#define fire ":/sprites/fire.png"
class climate_enemies: public QObject, public QGraphicsPixmapItem
{
public:
    climate_enemies();
    ~climate_enemies();
    void changecurrentpixmap(int x, int y);
//     const char enemy(int enemigo);
        void set_ampliar(int ampliar);

private:
    int ampliar;
    QPixmap *pixmap, *currentsprite;
    void cargarnuevosprite();
};


#endif // CLIMATE_ENEMIES_H
