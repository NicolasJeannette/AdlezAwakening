#include "input.h"
#include "player.h"
#include "QKeyEvent"
Input::Input()
{
    p = new Player();
}

Input::~Input()
{
}

void Input::listenEvent(QKeyEvent *e)
{

    if (e->key() == Qt::Key_Z || e->key() == Qt::Key_Up)
                if (p->m_playerDir != QVector2D(0, -1))
                    p->m_playerDir = QVector2D(0, 1);
            if (e->key() == Qt::Key_S || e->key() == Qt::Key_Down)
                if (p->m_playerDir != QVector2D(0, 1))
                    p->m_playerDir = QVector2D(0, -1);
            if (e->key() == Qt::Key_Q || e->key() == Qt::Key_Left)
                if (p->m_playerDir != QVector2D(1, 0))
                    p->m_playerDir = QVector2D(-1, 0);
            if (e->key() == Qt::Key_D || e->key() == Qt::Key_Right)
                if (p->m_playerDir != QVector2D(-1, 0))
                    p->m_playerDir = QVector2D(1, 0);

}
