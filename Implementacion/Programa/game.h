#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QString>
#include "main_character.h"
#include "bird.h"
#include "climate_enemies.h"
#include "save_zone.h"
#define weight_map 1201
#define hight_map 500

class game : public QGraphicsScene
{
    Q_OBJECT
public:
    game();
    ~game();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool gameStarted;
private:
     int fuegoPosicion = 0;
    main_character *character, *ch;
    bird *pajaro, *br;
    save_zone *zoneSecure;
    climate_enemies *fuego, *fg;

    QBrush k;
    QImage pp;
    void change_background(const QString& imagePath);
    int imageCounter;


    // Movimientos del personaje
    QTimer *timer;
    QTimer *timerMuerte;
    bool movingUp;
    bool movingDown;
    bool movingLeft;
    void rutinaMuerte();


    //Pajaro
    QTimer *birdTimer;
    void removeBird();

    // meteorito
    QTimer *fireTimer;
    void createMeteoito();
    void removeMeteoito();

    //Niveles
    int level;
    void loadLevel(int level);
    void resetGame();

    // Colisiones
    void checkBottomCollision();
    void checkCeilingCollision();


    // Lluvia
    void createRaindrops();
    void checkCollisionsG();
    void hideRainDrops();


   // Zona segura
    void createSegureZone();
    void removeSegureZone();


    // Puntaje

    int puntaje;
    void updatePuntaje();

private slots:
    void reset_visual();
    void moveCharacter();
    void muerteCharacter();
    void moveBird();

    // Fuegos nivel 2
    void moveFire1();
    void moveFire2();

    //
    void checkCollisions();

signals:
    void updatePuntajeSignal(const QString& puntaje);
};

#endif // GAME_H
