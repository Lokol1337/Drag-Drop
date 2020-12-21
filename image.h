#ifndef IMAGE_H
#define IMAGE_H
#include <QWidget>
#include <QLabel>

class image
       : public QLabel
{
public:
    image(QWidget *parent = nullptr);
};

#endif // IMAGE_H
