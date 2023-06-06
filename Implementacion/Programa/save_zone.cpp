#include "save_zone.h"

save_zone::save_zone()
{
    pixmap = new QPixmap(":/sprites/Polycount-Forum.png");
    currentsprite = new QPixmap;
}

save_zone::~save_zone()
{
    delete pixmap;
    delete currentsprite;
}

void save_zone::changecurrentpixmap(int x, int y)
{
    *currentsprite = pixmap->copy(x*zone_x_size, y*zone_y_size,
                                    zone_x_size,   zone_y_size);
    cargarnuevosprite();
}

void save_zone::set_ampliar(int ampliar)
{
    this->ampliar = ampliar;
    cargarnuevosprite();
}

void save_zone::cargarnuevosprite()
{
    setPixmap(currentsprite->scaled(currentsprite->width()*ampliar,
                                    currentsprite->height()*ampliar));
}

