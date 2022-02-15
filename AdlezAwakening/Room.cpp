#include "Room.h"
#include "glwidgetdisplay.h"


Room::Room()
{
    int random = rand() % 5;

        switch (random)
        {
        case Room::Start:
            designation = "[S]";
            break;
        case Room::Bonus:
            designation = "[B]";
            break;
        case Room::End:
            designation = "[E]";
            break;
        case Room::Standard:
            designation = "[X]";
            break;
        case Room::Null:
            designation = "[ ]";
            break;
        default:
            break;
        }
}
Room::~Room()
{
}

Room::Room(string desi)
{
    this->designation = desi;
}

Room::Room(RoomType rt)
{
    this->type = rt;

        switch (rt)
        {
        case Room::Start:
            designation = "[S]";
            break;
        case Room::Bonus:
            designation = "[B]";
            break;
        case Room::End:
            designation = "[E]";
            break;
        case Room::Null:
            designation = "[ ]";
            break;
        case Room::Standard:
            designation = "[X]";
            break;
        default:
            break;
        }
}
void Room::SetRoomType(RoomType rt)
{
    this->type = rt;

    switch (rt)
    {
    case Room::Start:
        designation = "[S]";
        break;
    case Room::Bonus:
        designation = "[B]";
        break;
    case Room::End:
        designation = "[E]";
        break;
    case Room::Null:
        designation = "[ ]";
        break;
    case Room::Standard:
        designation = "[X]";
        break;
    default:
        break;
    }
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

void Room::SetPosition(int x, int y)
{
    this->posx = x;
    this->posy = y;
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
        glVertex2f(-5.5, 3.5);
        glVertex2f(-5.5,-3.5);
        glEnd();
    }
}


void Room::drawRoom(vector<vector<Room*>> &adjacente )
{

   drawTop(adjacente[this->posx-1 ][this->posy]->type != Room::Null);
   drawBot(adjacente[this->posx+1 ][this->posy]->type != Room::Null);
   drawRight(adjacente[this->posx ][this->posy+1]->type != Room::Null);
   drawLeft(adjacente[this->posx ][this->posy-1]->type != Room::Null);


}
