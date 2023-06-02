#include "game.h"

game::game()
{
    character = new main_character;
    addItem(character);
    character->setPos(100,245);
    character->changecurrentpixmap(0,0);
    character->set_ampliar(3);

    connect(character, SIGNAL(changemap()),this,SLOT(reset_visual()));
    pp.load(":/sprites/1.png");
    k.setTextureImage(pp);
    setBackgroundBrush(k);
    imageCounter = 2;
}

game::~game()
{
    delete character;
}

void game::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_D){
        character->moveRight();
    }
    if(event->key()==Qt::Key_S){
        character->moveDown();
    }
    if(event->key()==Qt::Key_W){
        character->moveUp();
    }
    if(event->key()==Qt::Key_M){
        character->muerte();
    }
}

void game::reset_visual()
{
    character->setPos(-10, 245);

    // Obtener la ruta de la imagen actual
    QString imagePath = ":/sprites/" + QString::number(imageCounter) + ".png";
    change_background(imagePath);

    // Incrementar el contador de imagen para la siguiente llamada
    imageCounter++;
    if (imageCounter > 3) {
        imageCounter = 1; // Reiniciar el contador si excede el número máximo de imágenes
    }
}


void game::change_background(const QString& imagePath)
{
    pp.load(imagePath);
    k.setTextureImage(pp);
    setBackgroundBrush(k);
}

