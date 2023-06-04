#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QVector>
#include <QTimer>
#include "main_character.h"
#include "bird.h"

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
    main_character *character, *ch;
    bird *pajaro, *br;
    QBrush k;
    QImage pp;
    void change_background(const QString& imagePath);
    int imageCounter;


    // Movimientos del personaje
    QTimer *timer;
    bool movingUp;
    bool movingDown;

    // Movimientos del birdo XD
    QTimer *birdTimer;


    //Niveles
    int level;
    void loadLevel(int level);


private slots:
    void reset_visual();
    void moveCharacter();
    void moveBird();

};

#endif // GAME_H
