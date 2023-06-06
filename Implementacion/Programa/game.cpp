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

void game::moveFire1()
{
    if (!gameStarted) {
        return; // Si el juego no ha comenzado, no permitir el movimiento del personaje
    }
    fuego->fire_move(5, 5);

}
void game::moveFire2()
{
    if (!gameStarted) {
        return; // Si el juego no ha comenzado, no permitir el movimiento del personaje
    }
    fg->fire_move(10, 10);

}

void game::crearMeteoritos()
{
    fuego = new climate_enemies(2);
    addItem(fuego);
    // Incrementa la posición del fuego
    fuegoPosicion += 30;

    // Establece la posición del fuego
    int x = 1000 + fuegoPosicion; // Ajusta la posición horizontal según tus necesidades
    int y = 0; // Ajusta la posición vertical según tus necesidades
    fuego->setPos(x, y);

    fuego->changecurrentpixmap(3, 0);
    fuego->set_ampliar(2);
    fuego->setRotation(300);

    fireTimer = new QTimer(this);
    connect(fireTimer, SIGNAL(timeout()), this, SLOT(moveFire()));
    fireTimer->start(40);
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
        // Fuego 1
        fuego = new climate_enemies(2);
        addItem(fuego);
        fuego->setPos(900,0);
        fuego->changecurrentpixmap(3,0);
        fuego->set_ampliar(2);
        fuego->setRotation(320);
        fireTimer = new QTimer(this);
        fireTimer->setInterval(100);
        connect(fireTimer, SIGNAL(timeout()), this, SLOT(moveFire1()));
        fireTimer->start(40);
        // Fuego 2
       fg = new climate_enemies(2);
       addItem(fg);
       fg->setPos(1500,-20);
       fg->changecurrentpixmap(3,0);
       fg->set_ampliar(2);
       fg->setRotation(300);
       fireTimer->setInterval(1000);
       connect(fireTimer, SIGNAL(timeout()), this, SLOT(moveFire2()));
       fireTimer->start(40);

    } else if (level == 3) {
        removeItem(fuego);
        delete fuego;
        fuego = nullptr;
        removeItem(fg);
        delete fg;
        fg = nullptr;
        fireTimer->stop();
        delete fireTimer;

    }  else if (level == 4) {

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
    else if ((fuego && character->collidesWithItem(fuego))||(fg && character->collidesWithItem(fg))) {
        QMessageBox::information(nullptr, "Perdiste", "Game Over");
        removeItem(fuego);
        delete fuego;
        fuego = nullptr;
        removeItem(fg);
        delete fg;
        fg = nullptr;
        fireTimer->stop();
        delete fireTimer;
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

