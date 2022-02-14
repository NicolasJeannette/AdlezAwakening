#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "player.h"
#include "input.h"


class GameManager
{
public:
    GameManager();
    void Init();
    void Run();
    void Update();
    void Render();
    void LoadContent();
    Player *joueur;
    Input *input;
protected:

};

#endif // GAMEMANAGER_H
