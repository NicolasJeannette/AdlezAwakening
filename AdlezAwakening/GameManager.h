#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "player.h"


class GameManager
{
public:
    GameManager();
    void Init();
    void Run();
    void Update();
    void Render();
    void LoadContent();
protected:
    Player *joueur;
};

#endif // GAMEMANAGER_H
