#ifndef ROOM_H
#define ROOM_H
#include <string>
#include "glwidgetdisplay.h"
using namespace std;

class Room
{
public:
	enum RoomType
	{
		Start,
		Bonus,
		Standard,
		End,
		Null
	};
	Room();
	Room(RoomType rt);
	~Room();

	struct RoomDoor
	{
		bool East_Door;
		bool West_Door;
		bool North_Door;
		bool South_Door;
	};

	RoomType type;
	int numDoor;
	string designation;

	int posx;
	int posy;

	void GenerationSalle();
	void DrawRoom();
	void SetPosition(int x, int y);
	void SetRoomType(RoomType rt);



};

#endif // ROOM_H
