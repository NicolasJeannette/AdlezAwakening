#ifndef PLAYER_H
#define PLAYER_H
#include <QVector3D>
#include <QVector2D>


class Player
{
public:
    ~Player();
    Player();
    void DrawPlayer();
    QVector2D m_startPos;
    QVector2D m_startDir;
    QVector2D m_playerDir;

    QVector2D GetPositionHautDroite();
    QVector2D GetPositionBasGauche();
    QVector2D GetPositionBasDroite();
    QVector2D GetPositionHautGauche();
    QVector2D GetPosition();
private:
    bool isMoving;
    float _X, _Y ,_Z; // Translation

protected:

};

#endif // PLAYER_H
