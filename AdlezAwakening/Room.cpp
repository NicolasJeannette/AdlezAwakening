#include "Room.h"


//constructeur par defaut
Room::Room()
{

}


// création d'une salle avec un type prédéfenie
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

Room::~Room()
{
}

void Room::GenerationSalle()
{
//Génération d'une salle contenant un cercle et un carré
}

void Room::DrawRoom()
{
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.2, -0.2);
	glVertex2f(5,0);
	glVertex2f(1, 1);
	glEnd();

}

void Room::SetPosition(int x, int y)
{
	this->posx = x;
	this->posy = y;
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