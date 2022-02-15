#include "gamemanager.h"
#include "donjon.h"
#include "player.h"
#include "QKeyEvent"


GameManager::GameManager()
{
 new Donjon();
 joueur = new Player();
 input = new Input(joueur);
 instanceDJ = new Donjon(15,15);
 //Initialisation des salles et du joueur
 instanceDJ->GenerationDonjon();


}
void GameManager::Init()
{

}
void GameManager::Render(){

}
void GameManager::Run(){
    Init();
}
void GameManager::Update()
{
 joueur->DrawPlayer();
 instanceDJ->getStartingRoom()->drawRoom(instanceDJ->rooms);
}
void GameManager::LoadContent()
{

}
