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
  //  CheckCollision(joueur,cube);
    QPointF A,B,C,D;
    A = QPointF(joueur->GetPositionHautGauche().toPointF());
    B = QPointF(joueur->GetPositionBasGauche().toPointF());
    C = QPointF(cube->GetPositionHautDroite().toPointF());
    D = QPointF(cube->GetPositionBasDroite().toPointF());
    LinesIntersect(A,B,C,D);
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
template<class T> static
T  GetDifference(T a , T b)
{
    T diff = a -b ;

     return diff;
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
 bool GameManager::LinesIntersect(QPointF A, QPointF B, QPointF C, QPointF D)
    {
        QPointF CmP = QPointF(C.x() - A.x(), C.y() - A.y());
        QPointF r = QPointF(B.x() - A.x(), B.y() - A.y());
        QPointF s = QPointF(D.x() - C.x(), D.y() - C.y());

        float CmPxr = CmP.x() * r.y() - CmP.y() * r.x();
        float CmPxs = CmP.x() * s.y() - CmP.y() * s.x();
        float rxs = r.x() * s.y() - r.y() * s.x();

        bool test = approximate(CmPxr,0.0f);
        if (test)
        {
            // Lines are collinear, and so intersect if they have any overlap
            glColor3f(255,0,0);
            return ((C.x() - A.x() < 0.0) != (C.x() - B.x() < 0.0))
                || ((C.y() - A.y() < 0.0) != (C.y() - B.y() < 0.0));
        }

        if (rxs == 0.0)
        {
            glColor3f(255,255,255);

            return false; // Lines are parallel.
        }


        float rxsr = 1.0 / rxs;
        float t = CmPxs * rxsr;
        float u = CmPxr * rxsr;

        return (t >= 0.0) && (t <= 1.0) && (u >= 0.0) && (u <= 1.0);
    }

