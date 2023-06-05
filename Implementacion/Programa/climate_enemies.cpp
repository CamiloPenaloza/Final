#include "climate_enemies.h"

climate_enemies::climate_enemies(int type)
{
    this->type = type;
    if (type == 1) {
            pixmap = new QPixmap(":/sprites/gota.png");
            currentsprite = new QPixmap();
    }else if (type == 2) {
        pixmap = new QPixmap(":/sprites/fire.png");
        currentsprite = new QPixmap();
    }
}


climate_enemies::~climate_enemies()
{
    delete pixmap;
    delete currentsprite;
}

void climate_enemies::cargarnuevosprite()
{
    setPixmap(currentsprite->scaled(currentsprite->width() * ampliar,
                                    currentsprite->height() * ampliar));
}

void climate_enemies::set_ampliar(int ampliar)
{
    this->ampliar = ampliar;
    cargarnuevosprite();
}

void climate_enemies::changecurrentpixmap(int x, int y)
{
    if (type == 1) {
        *currentsprite = pixmap->copy(x * width_gota, y * height_gota,
                                      width_gota, height_gota);
    } else if (type == 2) {
        *currentsprite = pixmap->copy(x * width_fuego, y * height_fuego,
                                      width_fuego, height_fuego);
    }

    cargarnuevosprite();
}
