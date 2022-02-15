#include "gamemanager.h"
#include "donjon.h"
#include "player.h"
#include "QKeyEvent"
#include "glwidgetdisplay.h"


GameManager::GameManager()
{
    new Donjon();
    joueur = new Player();
    input = new Input(joueur);
    instanceDJ = new Donjon(15,15);
    //Initialisation des salles et du joueur
    instanceDJ->GenerationDonjon();


    cube = new Cube();
}
void GameManager::Init()
{
    instanceDJ = new Donjon(15,15);
    //Initialisation des salles et du joueur
    instanceDJ->GenerationDonjon();
}
void GameManager::Render(){

}
void GameManager::Run(){
    Init();
}
void GameManager::Update()
{
    QVector2D vec;
    QVector2D vecTopGauche;
    QVector2D vecCube;
    joueur->DrawPlayer();
    instanceDJ->getStartingRoom()->drawRoom(instanceDJ->rooms);
    vec = joueur->GetPosition();
    vecTopGauche = joueur->GetPositionHautGauche();
    cube->DrawCube();
    vecCube = cube->GetPosition();
    // room.drawTop(true);
    // room.drawBot(true);
    // room.drawRight(true);
    // room.drawLeft(true);
    CheckCollision(joueur,cube);
}

void GameManager::LoadContent()
{

}

template<class T> static
bool  approximate(T a , T b)
{
    T diff = a -b ;
    if (diff <  numeric_limits<T>::epsilon() && -diff <  numeric_limits<T>::epsilon())
        return true;
    else return false;
}

bool GameManager::CheckCollision(Player *one, Cube *two) // AABB - AABB collision
{

    // collision x-axis?
    float someValuex = one->GetPosition().x();
    if (approximate(one->GetPosition().x(), two->GetPosition().x()))
        someValuex = 0.0;

    float someValuey = one->GetPosition().y();
    if (approximate(one->GetPosition().y(), two->GetPosition().y()))
        someValuey = 0.0;




    bool collisionX = someValuex >= two->GetPosition().x() &&
            two->GetPosition().x() >= someValuex;
    // collision y-axis?
    bool collisionY = someValuey >= two->GetPosition().y() &&
            two->GetPosition().y() >= someValuey;
    // collision only if on both axes
    if(collisionX && collisionY)
    {
        glColor3f(255,0,0);
    }
    else{
        glColor3f(255,255,255);
    }
    return collisionX && collisionY;
}

