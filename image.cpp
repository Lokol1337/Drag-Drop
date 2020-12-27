#include "image.h"

image::image(QWidget *parent) : QLabel(parent)
{
    QPixmap pix(":/car.jpg");
    setPixmap(pix);
    show();
}
