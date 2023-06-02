#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QVector>
#include "main_character.h"

#define weight_map 1201
#define hight_map 500

class game : public QGraphicsScene
{
    Q_OBJECT
public:
    game();
    ~game();
    void keyPressEvent(QKeyEvent *event);
    void genblockmatrix();
private:
    main_character *character, *ch;
    QBrush k;
    QImage pp;
    void change_background(const QString& imagePath);
    int imageCounter;
private slots:
    void reset_visual();
};

#endif // GAME_H
