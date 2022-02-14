#include "gamemanager.h"
#include "donjon.h"
#include "player.h"
#include "QKeyEvent"


GameManager::GameManager()
{
 new Donjon();
 joueur = new Player();
 input = new Input(joueur);
}
void GameManager::Init()
{
    //Initialisation des salles et du joueur
}
void GameManager::Render(){

}
void GameManager::Run(){
    Init();
}
void GameManager::Update()
{
 joueur->DrawPlayer();
}
void GameManager::LoadContent()
{

}
