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
 vec = joueur->GetPosition();
 vecTopGauche = joueur->GetPositionHautGauche();
 cube->DrawCube();
 vecCube = cube->GetPosition();
 room.drawTop(true);
 room.drawBot(true);
 room.drawRight(true);
 room.drawLeft(true);
 CheckCollision(joueur,cube);
}

void GameManager::LoadContent()
{

}
bool GameManager::CheckCollision(Player *one, Cube *two) // AABB - AABB collision
{
    // collision x-axis?
    float someValuex = one->GetPosition().x();
    if (someValuex <  std::numeric_limits<float>::epsilon() &&
        someValuex > -std::numeric_limits<float>::epsilon()) {
      someValuex = 0.0;
    }
    float someValuey = one->GetPosition().y();
    if (someValuey <  std::numeric_limits<float>::epsilon() &&
        someValuey > -std::numeric_limits<float>::epsilon()) {
      someValuey = 0.0;
    }



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

