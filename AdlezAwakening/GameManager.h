#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "player.h"
#include "input.h"
#include "Room.h"
#include "cube.h"



class GameManager
{
public:
    GameManager();
    void Init();
    void Run();
    void Update();
    void Render();
    void LoadContent();
    bool CheckCollision(Player *joueur,Cube *cube);
    Player *joueur;
    Input *input;
    Cube *cube;
    Room room;
protected:

};

#endif // GAMEMANAGER_H
