#include "player.h"
#include "glwidgetdisplay.h"
Player::~Player(){

}
Player::Player()
{
    m_startPos = QVector2D(0, 0); //World Position
    m_startDir = QVector2D(0, 0);
    m_playerDir = m_startDir;
}
void Player::DrawPlayer(){
  // glTranslatef(m_playerDir.x(), m_playerDir.y(),0);

    // Rotation
    //glRotatef(0.f, 90.0f, 0.0, 0.0f);
   glBegin(GL_POLYGON);
     glVertex2f(m_playerDir.x() + 0.5, m_playerDir.y() + -0.5); //Bas droite
     glVertex2f(m_playerDir.x() + 0.5,m_playerDir.y() + 0.5);//Haut droite
     glVertex2f(m_playerDir.x() +- 0.5,m_playerDir.y() + 0.5); // Haut Gauche
     glVertex2f(m_playerDir.x() +- 0.5,m_playerDir.y() + -0.5); // Bas Gauche
   glEnd();
}
QVector2D Player::GetPositionHautGauche()
{
    return QVector2D(m_playerDir.x() +- 0.5,m_playerDir.y() + 0.5);
}
QVector2D Player::GetPositionHautDroite()
{
    return QVector2D(m_playerDir.x() + 0.5,m_playerDir.y() + 0.5);
}
QVector2D Player::GetPositionBasDroite()
{
    return QVector2D(m_playerDir.x() + 0.5, m_playerDir.y() + -0.5);
}
QVector2D Player::GetPositionBasGauche()
{
    return QVector2D(m_playerDir.x() +- 0.5,m_playerDir.y() + -0.5);
}
QVector2D Player::GetPosition()
{
    return QVector2D(m_playerDir.x(),m_playerDir.y());
}



