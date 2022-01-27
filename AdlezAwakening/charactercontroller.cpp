#include "charactercontroller.h"
#include "QGraphicsScene"

CharacterController::CharacterController(QGraphicsScene &scene, QObject *parent)  :
    QObject(parent),
    scene(scene)
{

}
CharacterController::~CharacterController()
{
}
