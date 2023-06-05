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

void climate_enemies::fire_move()
{
    static int anim_count = 0;
    int current_x = x();
    changecurrentpixmap(0,1);
    setX(current_x - 10);
    int current_y = y();
    setY(current_y + 10);
    // Cambiar la imagen del sprite si se ha movido lo suficiente
    if (x() != current_x) {
        anim_count++;
        int sprite_x = (anim_count / 2) % 4;
        changecurrentpixmap(sprite_x, 0);
    }
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
