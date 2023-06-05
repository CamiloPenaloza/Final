#include "climate_enemies.h"

climate_enemies::climate_enemies()
{

}

climate_enemies::~climate_enemies()
{
    delete pixmap;
    delete currentsprite;
}
void climate_enemies::cargarnuevosprite()
{
    setPixmap(currentsprite->scaled(currentsprite->width()*ampliar,
                                    currentsprite->height()*ampliar));
}
void climate_enemies::set_ampliar(int ampliar)
{
    this->ampliar = ampliar;
    cargarnuevosprite();
}
void climate_enemies::changecurrentpixmap(int x, int y)
{
    *currentsprite = pixmap->copy(x*width_gota, y*height_gota,
                                    width_gota,   height_gota);
    cargarnuevosprite();
}

const char climate_enemies::enemy(int enemigo)
{
    if (enemigo == 0) {
        const char x = ":/sprites/gota.png";
        return x;
    }else if (enemigo == 1) {
        const
        return fire;
    }
}


