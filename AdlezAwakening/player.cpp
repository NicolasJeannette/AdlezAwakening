#include "player.h"
#include "glwidgetdisplay.h"
Player::~Player(){

}
Player::Player()
{
    m_startPos = QVector2D(0, 0);
    m_startDir = QVector2D(0, 0);
    m_playerDir = m_startDir;
}
void Player::DrawPlayer(){
  // glTranslatef(m_playerDir.x(), m_playerDir.y(),0);

    // Rotation
    //glRotatef(0.f, 90.0f, 0.0, 0.0f);

   glBegin(GL_POLYGON);
     glVertex2f(0.5, -0.5);
     glVertex2f(0.5, 0.5);
     glVertex2f(-0.5, 0.5);
     glVertex2f(-0.5, -0.5);
   glEnd();
}

