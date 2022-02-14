#include "gamemanager.h"
#include "donjon.h"



GameManager::GameManager()
{
 new Donjon();
 joueur = new Player();
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

}
void GameManager::LoadContent()
{

}
