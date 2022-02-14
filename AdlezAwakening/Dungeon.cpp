//#include "Dungeon.h"
//
//void Dungeon::GenerateDungeon(int maxXnbRoom, int maxYnbRoom)
//{
//}
//
//Dungeon::Dungeon(int maxXnbRoom, int maxYnbRoom)
//	: maxXnbRoom(maxXnbRoom), maxYnbRoom(maxYnbRoom)
//{
//}
//
//
//
//// on recupère et renvois les 4 salle adjacente a la cible
//vector<Room*> Dungeon::GetAdjacentRoom(int originX, int originY)
//{
//	vector<Room*> l_roomsAdjacente;
//
//	if (originY - 1 >= 0 && originY - 1 < maxYnbRoom)
//	{
//		if (rooms[originX][originY - 1]->type == Room::RoomType::Null)
//		{
//			l_roomsAdjacente.push_back(rooms[originX][originY - 1]);
//		}
//	}
//
//	if (originY + 1 >= 0 && originY + 1 < maxYnbRoom)
//	{
//		if (rooms[originX][originY + 1]->type == Room::RoomType::Null)
//		{
//			l_roomsAdjacente.push_back(rooms[originX][originY + 1]);
//		}
//	}
//
//	if (originX - 1 >= 0 && originX - 1 < maxXnbRoom)
//	{
//		if (rooms[originX - 1][originY]->type == Room::RoomType::Null)
//		{
//			l_roomsAdjacente.push_back(rooms[originX - 1][originY]);
//		}
//	}
//
//	if (originX + 1 >= 0 && originX + 1 < maxXnbRoom)
//	{
//		if (rooms[originX + 1][originY]->type == Room::RoomType::Null)
//		{
//			l_roomsAdjacente.push_back(rooms[originX + 1][originY]);
//		}
//	}
//
//	return l_roomsAdjacente;
//}
//
//Dungeon::~Dungeon()
//{
//}
