#ifndef WINDOW_H
#define WINDOW_H
#include <QFrame>

class QDragEnterEvent;
class QDropEvent;

class windowAgr: public QFrame
{
public:
    windowAgr(QWidget *parent = nullptr);
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // WINDOW_H
