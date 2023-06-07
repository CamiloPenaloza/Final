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

    puntaje = 500;
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

void game::rutinaMuerte()
{
    timerMuerte = new QTimer(this);
    connect(timerMuerte, SIGNAL(timeout()), this, SLOT(muerteCharacter()));
    timerMuerte->start(40);
}



void game::moveCharacter()
{
    if (!gameStarted) {
        return; // Si el juego no ha comenzado, no permitir el movimiento del personaje
    }

    character->moveRight();

    if (movingUp) {
        character->moveUp();
        checkCeilingCollision();
    } else if (movingDown) {
        character->moveDown();
    } else if (movingLeft){
        character->moveLeft();
    }
    checkBottomCollision();

    if (level == 3 ){
        checkCollisionsG();
    }

}

void game::muerteCharacter()
{
    character->muerte();
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


void game::createRaindrops()
{
    // Crear múltiples gotas de lluvia
    const int numRaindrops = 4;      // Cantidad de gotas de lluvia
    const int startX = 100;          // Posición inicial en el eje X
    const int startY = -100;          // Posición inicial en el eje Y
    const int distance = 350;        // Distancia entre las gotas de lluvia
    const int delay = 500;           // Retraso en milisegundos entre cada generación de gota
    const qreal gravity = 500;       // Aceleración de la gravedad

    for (int i = 0; i < numRaindrops; i++) {
        QTimer::singleShot(i * delay, this, [=]() {
            climate_enemies*gotas = new climate_enemies(1);
            addItem(gotas);
            gotas->setPos(startX + i * distance, startY);
            gotas->changecurrentpixmap(0, 0);
            gotas->set_ampliar(1);

            QTimer* timer = new QTimer(this);
            connect(timer, &QTimer::timeout,this, [=]() {
                // Calcular el tiempo transcurrido desde el último intervalo del temporizador
                qreal dt = timer->interval() / 1000.0;  // Convertir de milisegundos a segundos

                // Calcular la velocidad y la nueva posición de la gota en función de la caída libre
                qreal vy = gravity * dt;
                qreal newY = gotas->y() + vy;

                // Actualizar la posición de la gota
                gotas->setPos(gotas->x(), newY);



                // Si la gota ha caído fuera de la pantalla, eliminarla
                if (gotas->y() > sceneRect().height()) {
                    removeItem(gotas);
                    delete gotas;
                    timer->stop();
                    timer->deleteLater();
                }
            });

            // Establecer la frecuencia de actualización del temporizador (en milisegundos)
            timer->setInterval(16);  // Aproximadamente 60 FPS
            timer->start();
        });
    }
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
        removeBird();
        // Enemigo De fuego
        createMeteoito();

    } else if (level == 3) {
        removeMeteoito();
        // funcion que crea los enemigos tipo gota
        createRaindrops();

    } else if (level == 4) {
        createSegureZone();
        pajaro = new bird;
        addItem(pajaro);
        pajaro->setPos(1200,400);
        pajaro->changecurrentpixmap(0,1);
        pajaro->set_ampliar(5);
        birdTimer = new QTimer(this);
        connect(birdTimer, SIGNAL(timeout()), this, SLOT(moveBird()));
        birdTimer->start(50); // Establece el intervalo de tiempo en milisegundos (ejemplo: 100 ms)
        connect(timer, SIGNAL(timeout()), this, SLOT(checkCollisions()));
    }
}

void game::checkCollisions()
{
    if(level == 1){
        if (pajaro && character->collidesWithItem(pajaro)) {
            puntaje -=50;
            updatePuntaje();
            rutinaMuerte();
            QMessageBox::information(nullptr, "Perdiste", "Game Over");
            removeBird();
            resetGame();
        }
    }
    else if (level == 2) {
        if ((fuego && character->collidesWithItem(fuego))||(fg && character->collidesWithItem(fg))) {
            puntaje -=30;
            updatePuntaje();
            rutinaMuerte();
            QMessageBox::information(nullptr, "Perdiste", "Game Over");
            removeMeteoito();
            resetGame();
        }
    }
    else if (level == 4) {
        if (zoneSecure && character->collidesWithItem(zoneSecure) ) {
            QString puntajeString = QString::number(puntaje);
            QString mensaje = "GANASTE\n\nPuntaje: " + puntajeString;
            QMessageBox::information(nullptr, "WIN", mensaje);
            puntaje +=50;
            updatePuntaje();
            rutinaMuerte();
            removeBird();
            removeSegureZone();
            resetGame();
        }else if((character->x()+character_x_size >= weight_map) || (pajaro && character->collidesWithItem(pajaro)) ){
            puntaje -=100;
            updatePuntaje();
            rutinaMuerte();
            QMessageBox::information(nullptr, "Perdiste", "Game Over");
            removeSegureZone();
            removeBird();
            resetGame();
        }
    }
}

void game::checkBottomCollision()
{
    qreal characterBottom = character->pos().y() + character->boundingRect().height();
    qreal sceneBottom = sceneRect().bottom();

    if (characterBottom >= sceneBottom) {
        puntaje -=30;
        updatePuntaje();
        // Colisión con el límite inferior
        rutinaMuerte();
        //timerMuerte->setInterval(1000);
        QMessageBox::information(nullptr, "Perdiste", "Game Over");

        if (level == 1) {
            removeBird();
        }
        if(level == 2){
            removeMeteoito();
        }
        if(level == 3){
            hideRainDrops();
        }
        if(level == 4){
            removeBird();
            removeSegureZone();
        }
        resetGame();
    }
}

void game::checkCeilingCollision()
{
    qreal characterTop = character->pos().y();
    qreal sceneCeiling = sceneRect().top();

    if (characterTop <= sceneCeiling) {
        puntaje -=30;
        updatePuntaje();
        // Colisión con el límite inferior
        rutinaMuerte();
        //timerMuerte->setInterval(1000);
        QMessageBox::information(nullptr, "Perdiste", "Game Over");

        if (level == 1) {
            removeBird();
        }
        if(level == 2){
            removeMeteoito();
        }
        if(level == 3){
            hideRainDrops();
        }
        if(level == 4){
            removeBird();
            removeSegureZone();
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
    timerMuerte->stop();
    delete timerMuerte;
   // connect(timer, SIGNAL(timeout()), this, SLOT(moveCharacter()));

    // Reiniciar el estado del movimiento del personaje
    movingUp = false;
    movingDown = false;
}

void game::removeBird()
{
    removeItem(pajaro);
    delete pajaro;
    pajaro = nullptr;
    birdTimer->stop();
    delete birdTimer;
}

void game::createMeteoito()
{
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
}

void game::removeMeteoito()
{
    removeItem(fuego);
    delete fuego;
    fuego = nullptr;
    removeItem(fg);
    delete fg;
    fg = nullptr;
    fireTimer->stop();
    delete fireTimer;
}

void game::checkCollisionsG()
{
    QList<QGraphicsItem*> collisions = character->collidingItems();
    foreach (QGraphicsItem* item, collisions) {
        if (item->type() == climate_enemies::Type) {
            puntaje -=10;
            updatePuntaje();
            rutinaMuerte();
            QMessageBox::information(nullptr, "Perdiste", "Game Over");

            // Ocultar las gotas de lluvia
            hideRainDrops();

            resetGame();
            return; // Salir de la función para evitar colisiones adicionales en el mismo nivel
        }
    }
}

void game::hideRainDrops()
{
    QList<QGraphicsItem*> sceneItems = items();
    foreach (QGraphicsItem* sceneItem, sceneItems) {
        climate_enemies* gotas = dynamic_cast<climate_enemies*>(sceneItem);
        if (gotas != nullptr) {
            gotas->hide();
        }
    }
}

void game::createSegureZone()
{
    zoneSecure = new save_zone();
    addItem(zoneSecure);
    zoneSecure->setPos(850,300);
    zoneSecure->changecurrentpixmap(0,0);
    zoneSecure->set_ampliar(1);
}


void game::removeSegureZone()
{
    removeItem(zoneSecure);
    delete zoneSecure;
    zoneSecure = nullptr;
}

void game::updatePuntaje()
{
    QString puntajeText = QString::number(puntaje);
    emit updatePuntajeSignal(puntajeText);
}



