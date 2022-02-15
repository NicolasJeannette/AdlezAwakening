#include "Room.h"
#include "glwidgetdisplay.h"


Room::Room()
{

}

Room::Room(RoomType rt)
{

}

void Room::GenerationSalle()
{
//Génération d'une salle contenant un cercle et un carré
}

void Room::drawBot(bool haveDoor)
{
    if (haveDoor)
    {
        glBegin(GL_LINE_STRIP);
        glVertex2f(-5.5, -3.5);
        glVertex2f(-2.2, -3.5);
        glVertex2f(-2.2, -5);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glVertex2f(5.5, -3.5);
        glVertex2f(2.2, -3.5);
        glVertex2f(2.2, -5);
        glEnd();
    }else
    {
        glBegin(GL_LINE_STRIP);
        glVertex2f(-5.5, -3.5);
        glVertex2f(5.5, -3.5);
        glEnd();
    }
}

void Room::drawTop(bool haveDoor)
{
    if (haveDoor)
    {
        glBegin(GL_LINE_STRIP);
        glVertex2f(-5.5, 3.5);
        glVertex2f(-2.2, 3.5);
        glVertex2f(-2.2, 5);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glVertex2f(5.5, 3.5);
        glVertex2f(2.2, 3.5);
        glVertex2f(2.2, 5);
        glEnd();
    }else
    {
        glBegin(GL_LINE_STRIP);
        glVertex2f(-5.5, 3.5);
        glVertex2f(5.5, 3.5);
        glEnd();
    }
}

void Room::drawRight(bool haveDoor)
{
    if (haveDoor)
    {
        glBegin(GL_LINE_STRIP);
        glVertex2f(5.5, 3.5);
        glVertex2f(5.5, 1.5);
        glVertex2f(7, 1.5);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glVertex2f(5.5, -3.5);
        glVertex2f(5.5, -1.5);
        glVertex2f(7, -1.5);
        glEnd();
    }else
    {
        glBegin(GL_LINE_STRIP);
        glVertex2f(5.5, 3.5);
        glVertex2f(5.5,-3.5);
        glEnd();
    }
}

void Room::drawLeft(bool haveDoor)
{
    if (haveDoor)
    {
        glBegin(GL_LINE_STRIP);
        glVertex2f(-5.5, 3.5);
        glVertex2f(-5.5, 1.5);
        glVertex2f(-7, 1.5);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glVertex2f(-5.5, -3.5);
        glVertex2f(-5.5, -1.5);
        glVertex2f(-7, -1.5);
        glEnd();
    }else
    {
        glBegin(GL_LINE_STRIP);
        glVertex2f(5.5, 3.5);
        glVertex2f(5.5,-3.5);
        glEnd();
    }
}
