#ifndef SAVE_ZONE_H
#define SAVE_ZONE_H
#include <QGraphicsPixmapItem>
#define zone_x_size 395
#define zone_y_size 316
class save_zone: public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT
public:
    save_zone();
    ~save_zone();
    void changecurrentpixmap(int x, int y);
    void set_ampliar(int ampliar);
private:
    int ampliar;
    QPixmap *pixmap, *currentsprite;
    void cargarnuevosprite();
};

#endif // SAVE_ZONE_H
