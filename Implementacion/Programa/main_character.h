#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include <QGraphicsPixmapItem>
#define character_x_size 30
#define character_y_size 35
#define weight_map 1201
#define hight_map 500
class main_character: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    main_character();
    ~main_character();
    void changecurrentpixmap(int x, int y);
    void set_ampliar(int ampliar);
    void moveDown();
    void moveUp();
    void moveLeft();
    void muerte();
private:
    int ampliar;
    QPixmap *pixmap, *currentsprite;
    void cargarnuevosprite();
signals:
    void changemap();
public slots:
    void moveRight();
};

#endif // MAIN_CHARACTER_H
