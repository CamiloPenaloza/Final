#include "bird.h"

bird::bird()
{
    pixmap = new QPixmap(":/sprites/bird.png");
    currentsprite = new QPixmap;
}

bird::~bird()
{
    delete pixmap;
    delete currentsprite;
}

void bird::changecurrentpixmap(int x, int y)
{
    *currentsprite = pixmap->copy(x*bird_x_size, y*bird_y_size,
                                    bird_x_size,   bird_y_size);
    cargarnuevosprite();
}

void bird::set_ampliar(int ampliar)
{
    this->ampliar = ampliar;
    cargarnuevosprite();
}

void bird::cargarnuevosprite()
{
    setPixmap(currentsprite->scaled(currentsprite->width()*ampliar,
                                    currentsprite->height()*ampliar));
}


void bird::moveLeft()
{
    static int anim_count = 0;
    int current_x = x();
    changecurrentpixmap(0,1);
    setX(current_x - 10);
    // Cambiar la imagen del sprite si se ha movido lo suficiente
    if (x() != current_x) {
        anim_count++;
        int sprite_x = (anim_count / 2) % 8;
        changecurrentpixmap(sprite_x, 1);
    }
}

void bird::moveDown()
{
    static int anim_count = 0;
    int current_y = y();
    setY(current_y + 10);
    changecurrentpixmap(0, 1);
    if (y() != current_y) {
        anim_count++;
        int sprite_y = (anim_count / 2) % 8;
        changecurrentpixmap(sprite_y, 1);
    }
}

void bird::moveUp()
{
    static int anim_count = 0;
    int current_y = y();
    setY(current_y - 10);
    changecurrentpixmap(0, 1);
    if (y() != current_y) {
        anim_count++;
        int sprite_y = (anim_count / 2) % 8;
        changecurrentpixmap(sprite_y, 1);
    }
}




