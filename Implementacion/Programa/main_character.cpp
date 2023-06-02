#include "main_character.h"

main_character::main_character()
{
    pixmap = new QPixmap(":/sprites/personaje.png");
    currentsprite = new QPixmap;
}

main_character::~main_character()
{
    delete pixmap;
    delete currentsprite;
}

void main_character::changecurrentpixmap(int x, int y)
{
    *currentsprite = pixmap->copy(x*character_x_size, y*character_y_size,
                                    character_x_size,   character_y_size);
    cargarnuevosprite();
}


void main_character::set_ampliar(int ampliar)
{
    this->ampliar = ampliar;
    cargarnuevosprite();
}

void main_character::cargarnuevosprite()
{
    setPixmap(currentsprite->scaled(currentsprite->width()*ampliar,
                                    currentsprite->height()*ampliar));
}

void main_character::moveRight()
{
    // Contador de cuadros de animación
    static int anim_count = 0;
    int current_x = x();
    changecurrentpixmap(1,0);
    setX(current_x + 10);
    // Cambiar la imagen del sprite si se ha movido lo suficiente
    if (x() != current_x) {
        anim_count++;
        int sprite_x = (anim_count / 2) % 8;
        changecurrentpixmap(sprite_x, 0);
    }
    if(x()>=weight_map){
        emit changemap();
    }
}

void main_character::moveDown()
{
    static int anim_count = 0;
    int current_y = y();
    setY(current_y + 3);
    changecurrentpixmap(0, 2);
    if (y() != current_y) {
        anim_count++;
        int sprite_y = (anim_count / 2) % 8;
        changecurrentpixmap(sprite_y, 1);
    }
}

void main_character::moveUp()
{
    static int anim_count = 0;
    int current_y = y();
    changecurrentpixmap(0,2);
    setY(current_y - 3);
    if (y() != current_y) {
        anim_count++;
        int sprite_y = (anim_count / 2) % 8;
        changecurrentpixmap(sprite_y, 0);
    }
}

void main_character::muerte()
{
    static int anim_count = 0;
    int current_y = y();
    setY(current_y + 3);
    changecurrentpixmap(0, 3);
    if (y() != current_y) {
        anim_count++;
        int sprite_y = (anim_count / 2) % 4;
        changecurrentpixmap(sprite_y, 2);
    }
}



