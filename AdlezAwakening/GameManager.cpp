#include <QWindow>
#include "GameManager.h"
#include "QGraphicsScene"

GameManager::GameManager(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene)
{

    // timer.start(1000/33);

    // this->Game();
    // scene.installEventFilter(this);

     // this->resume();
}
GameManager::~GameManager()
{
}
