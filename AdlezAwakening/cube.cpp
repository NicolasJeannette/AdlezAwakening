#include "cube.h"
#include "glwidgetdisplay.h"

Cube::Cube()
{

}
Cube::~Cube()
{

}
QVector2D Cube::GetPosition(){
    return QVector2D(0,0);
}
void Cube::DrawCube()
{
    glBegin(GL_POLYGON);
      glVertex2f(0.5, -0.5); //Bas droite
      glVertex2f(0.5, 0.5);//Haut droite
      glVertex2f(- 0.5, 0.5); // Haut Gauche
      glVertex2f(- 0.5,-0.5); // Bas Gauche
    glEnd();
}

