#include "input.h"
#include "player.h"
#include "QKeyEvent"
Input::Input(Player* player) : p(player)
{
}

Input::~Input()
{
}

void Input::listenEvent(QKeyEvent *e)
{

    if (e->key() == Qt::Key_Z || e->key() == Qt::Key_Up)
                    p->m_playerDir += QVector2D(0, 0.1);
            if (e->key() == Qt::Key_S || e->key() == Qt::Key_Down)
                    p->m_playerDir += QVector2D(0, -0.1);
            if (e->key() == Qt::Key_Q || e->key() == Qt::Key_Left)
                    p->m_playerDir += QVector2D(-0.1, 0);
            if (e->key() == Qt::Key_D || e->key() == Qt::Key_Right)
                    p->m_playerDir += QVector2D(0.1, 0);

}
