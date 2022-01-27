#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H
#include "QGraphicsScene"
class QGraphicsScene;


class CharacterController : public QObject
{
    Q_OBJECT
public:
    ~CharacterController();
    CharacterController(QGraphicsScene &scene, QObject *parent = 0);

private:
    QGraphicsScene &scene;
};

#endif // CHARACTERCONTROLLER_H
