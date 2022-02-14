#ifndef PLAYER_H
#define PLAYER_H
#include <QVector2D>


class Player
{
public:
    ~Player();
    Player();
    void Update();
    QVector2D m_startPos;
    QVector2D m_startDir;
    QVector2D m_playerDir;
private:
    bool isMoving;

protected:

};

#endif // PLAYER_H
