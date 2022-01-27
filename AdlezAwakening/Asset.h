#ifndef ASSET_H
#define ASSET_H
#include "Stat.h"
#include "Vector2.h"
#include "Vector3.h"
#include "string"
using namespace std;

class  Asset
{

public:
    //Asset(Texture &text);

    ~Asset();

    void  setPosition(Vector2 position);
    void move(float speed_X, float speed_Y, float ElapsedTime);
    Vector2 getPosition();
    bool killWhenOutOfScreen();
    Vector2 getPixelSprite();

    // event sur la collision d'un objet
    virtual bool   onTriggerEnter(Asset* obj);


    enum type_asset
    {
        e_Projectile = 0,
        e_PlayerShip,
        e_EnemieShip,
        e_Bonus,
        e_Meteor,
        e_Background,
        e_boom_Animation
    };

    type_asset _type_asset;

    //#Unity
   // virtual void Update(RenderWindow&) = 0;

    //string gameObjectName;
   // Sprite sprite;
   // Texture &texture;
   // Stat stats;
};
#endif // ASSET_H
