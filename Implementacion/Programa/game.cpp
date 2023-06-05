#include "game.h"
#include <QMessageBox>

game::game()
{
    gameStarted = false;
    character = new main_character;
    addItem(character);
    character->setPos(100,245);
    character->changecurrentpixmap(0,0);
    character->set_ampliar(3);


    connect(character, SIGNAL(changemap()),this,SLOT(reset_visual()));
    pp.load(":/sprites/1.png");
    k.setTextureImage(pp);
    setBackgroundBrush(k);
    imageCounter = 1;
    level = 0; // Establecer el nivel inicial
    loadLevel(level);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveCharacter()));

    timer->start(30);

//
    movingUp = false;
    movingDown = false;
    movingLeft = false;
//    collisionDetected = false;

}

game::~game()
{
    delete character;
    delete pajaro;
}


void game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_S) {
        movingDown = true;
    } else if (event->key() == Qt::Key_W) {
       movingUp = true;
    } else if (event->key() == Qt::Key_A){
        movingLeft = true;
    }
}

void game::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_S) {
        movingDown = false;
    } else if (event->key() == Qt::Key_W) {
        movingUp = false;
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
    level++;
    if (imageCounter > 3) {
        imageCounter = 1; // Reiniciar el contador si excede el número máximo de imágenes
    }

    // Cargar y configurar el nivel actual
    loadLevel(level);
}



void game::change_background(const QString& imagePath)
{
    pp.load(imagePath);
    k.setTextureImage(pp);
    setBackgroundBrush(k);
}

void game::moveCharacter()
{
    if (!gameStarted) {
        return; // Si el juego no ha comenzado, no permitir el movimiento del personaje
    }

    character->moveRight();

    if (movingUp) {
        character->moveUp();
    } else if (movingDown) {
        character->moveDown();
    } else if (movingLeft){
        character->moveLeft();
    }
    checkBottomCollision();

}


void game::moveBird()
{
    if (!gameStarted) {
        return; // Si el juego no ha comenzado, no permitir el movimiento del personaje
    }

    // Obtener la posición actual del personaje
    QPointF characterPos = character->pos();

    // Obtener la posición actual del pájaro
    QPointF birdPos = pajaro->pos();

    // Calcular la dirección hacia el personaje
    qreal direction = (characterPos.y() < birdPos.y()) ? -1 : 1;

    // Mover el pájaro hacia el personaje en el eje Y
    if (direction < 0) {
        pajaro->moveUp();
    } else {
        pajaro->moveDown();
    }

    // Mover el pájaro hacia la izquierda
    pajaro->moveLeft();
}

void game::moveFire()
{
    if (!gameStarted) {
        return; // Si el juego no ha comenzado, no permitir el movimiento del personaje
    }
    fuego->fire_move();
}


void game::loadLevel(int level)
{

    // Posicionar elementos según el nivel
    if (level == 1) {
        // Pajaro
        pajaro = new bird;
        addItem(pajaro);
        pajaro->setPos(1200,245);
        pajaro->changecurrentpixmap(0,1);
        pajaro->set_ampliar(5);
        birdTimer = new QTimer(this);
        connect(birdTimer, SIGNAL(timeout()), this, SLOT(moveBird()));
        birdTimer->start(50); // Establece el intervalo de tiempo en milisegundos (ejemplo: 100 ms)
        connect(timer, SIGNAL(timeout()), this, SLOT(checkCollisions()));
    } else if (level == 2) {
        removeItem(pajaro);
        delete pajaro;
        pajaro = nullptr;
        birdTimer->stop();
        delete birdTimer;


        // Enemigo De fuego
        fuego = new climate_enemies(2);
        addItem(fuego);
        fuego->setPos(1200,0);
        fuego->changecurrentpixmap(3,0);
        fuego->set_ampliar(3);
        fireTimer = new QTimer(this);
        connect(fireTimer, SIGNAL(timeout()), this, SLOT(moveFire()));
        fireTimer->start(50);
    }

}

void game::checkCollisions()
{
    if (pajaro && character->collidesWithItem(pajaro)) {
        QMessageBox::information(nullptr, "Perdiste", "Game Over");
        removeItem(pajaro);
        delete pajaro;
        pajaro = nullptr;
        birdTimer->stop();
        delete birdTimer;
        resetGame();
    }
}

void game::checkBottomCollision()
{
    qreal characterBottom = character->pos().y() + character->boundingRect().height();
    qreal sceneBottom = sceneRect().bottom();

    if (characterBottom >= sceneBottom) {
        // Colisión con el límite inferior
        QMessageBox::information(nullptr, "Perdiste", "Game Over");
        if (level == 1) {
               removeItem(pajaro);
               delete pajaro;
               pajaro = nullptr;
               birdTimer->stop();
               delete birdTimer;
        }
        resetGame();
    }
}



void game::resetGame()
{
    level = 0;
    imageCounter = 1;
    // Reiniciar el personaje
    character->setPos(100, 245);
    character->changecurrentpixmap(0, 0);
    character->set_ampliar(3);

    // Cargar y configurar el nivel 0
    loadLevel(level);

    // Reiniciar el fondo
    pp.load(":/sprites/1.png");
    k.setTextureImage(pp);
    setBackgroundBrush(k);

    // Reiniciar el timer del personaje
    timer->start(30);

    // Reiniciar el estado del movimiento del personaje
    movingUp = false;
    movingDown = false;
}

