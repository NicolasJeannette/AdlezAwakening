#include "donjon.h"
#include <QtDebug>
#include <string>
#include <iostream>
#include <tuple>
#include <time.h>


Donjon::Donjon(int maxXnbRoom, int maxYnbRoom) :
    _maxXnbRoom(maxXnbRoom), _maxYnbRoom(maxYnbRoom)
{

}
void Donjon::GenerationDonjon()
{
    srand((unsigned)time(0));

    //probabilité de spawn une salle
    int prob_spawnRoom = 25;
    const int pourcentage = 100;

    // on remplis notre vector Vecrtical
    for (int x = 0; x < _maxXnbRoom; x++)
    {
        vector <Room*> row;

        // on remplis notre vector Horizontale
        for (int y = 0; y < _maxYnbRoom; y++)
        {
            Room* room = new Room(Room::RoomType::Null);
            room->SetPosition(x, y);
            row.push_back(room);
        }
        rooms.push_back(row);
    }

    int randX = rand() % _maxXnbRoom;
    int randY = rand() % _maxYnbRoom;


    rooms[randX][randY]->SetRoomType(Room::RoomType::Standard);


    int currentTrackerX = randX, currentTrackerY = randY;
    while (numberRoom > 0)
    {
        vector<Room*> adjRoom = GetAdjacentRoom(currentTrackerX, currentTrackerY);
        //DisplayDungeon();
        int numberRoomAjd = adjRoom.size();
        for (int i = 0; i < numberRoomAjd; i++)
        {
            int spawnRoom = rand() % pourcentage;
            if (spawnRoom <= prob_spawnRoom)
            {
                adjRoom[i]->SetRoomType(Room::RoomType::Standard);
                currentTrackerX = adjRoom[i]->posx;
                currentTrackerY = adjRoom[i]->posy;
                numberRoom--;
                if (numberRoom == 0)
                {
                    //	adjRoom[i]->designation = "[1]";
                    SetStartndEndRoom(adjRoom[i]);

                }
            }
        }
    }

    DisplayDungeon();
}

void Donjon::DisplayDungeon()
{
 string tmp ;
    for (int x = 0; x < rooms.size(); x++)
    {
        for (int y = 0; y < rooms[x].size(); y++)
        {
            tmp +=   rooms[x][y]->designation;
        }
        tmp += "\n";
    }
    qDebug() << tmp.c_str();
}

vector<Room*> Donjon::GetAdjacentRoom(int originX,int originY)
{
    vector<Room*> l_roomsAdjacente;

    if (originY - 1 >= 0 && originY - 1 < _maxYnbRoom)
    {
        if (rooms[originX][originY-1]->type == Room::RoomType::Null)
        {
            l_roomsAdjacente.push_back(rooms[originX][originY - 1]);
        }
    }

    if (originY + 1 >= 0 && originY + 1 < _maxYnbRoom)
    {
        if (rooms[originX][originY + 1]->type == Room::RoomType::Null)
        {
            l_roomsAdjacente.push_back(rooms[originX][originY + 1]);
        }
    }

    if (originX - 1 >= 0 && originX - 1 < _maxXnbRoom)
    {
        if (rooms[originX - 1][originY]->type == Room::RoomType::Null)
        {
            l_roomsAdjacente.push_back(rooms[originX - 1][originY]);
        }
    }

    if (originX + 1 >= 0 && originX + 1 < _maxXnbRoom)
    {
        if (rooms[originX + 1][originY]->type == Room::RoomType::Null)
        {
            l_roomsAdjacente.push_back(rooms[originX + 1][originY]);
        }
    }
    return l_roomsAdjacente;
}


void Donjon::SetStartndEndRoom(Room* OriginRoom)
{
    int OriginX = OriginRoom->posx;
    int OriginY = OriginRoom->posy;

    int DistanceManathan = 0;
    int tmpDistanceManathan = 0;

    Room* FarestRoomS = nullptr;
    Room* FarestRoomE = nullptr;
    int DistanceManathanE = 0;
    int tmpDistanceManathanE = 0;

    for (int x = 0; x < rooms.size(); x++)
    {
        for (int y = 0; y < rooms[x].size(); y++)
        {
            if (rooms[y][x]->type == Room::RoomType::Standard)
                tmpDistanceManathan =
                        abs(OriginX - rooms[y][x]->posx) + abs(OriginY - rooms[y][x]->posy);

            if (tmpDistanceManathan > DistanceManathan)
            {
                FarestRoomS = rooms[y][x];
                DistanceManathan = tmpDistanceManathan;
            }

        }
    }
    FarestRoomS->designation = "[S]";
FarestRoomS->type = Room::RoomType::Start;
    // for (int x = 0; x < rooms.size(); x++)
    // {
    //     for (int y = 0; y < rooms[x].size(); y++)
    //     {
    //         if (rooms[y][x]->type == Room::RoomType::Standard)
    //             tmpDistanceManathanE =
    //             abs(FarestRoomS->posx - rooms[y][x]->posx) + abs(FarestRoomS->posy - rooms[y][x]->posy);
    //         if (tmpDistanceManathanE > DistanceManathanE)
    //         {
    //             FarestRoomE = rooms[y][x];
    //             DistanceManathanE = tmpDistanceManathanE;
    //         }
    //     }
    // }
    // FarestRoomE->designation = "[E]";
    dijkstra(FarestRoomS);
}


bool  Donjon::HasVisitedRoom(Room* room)
{
    for (int i = 0 ; i < visitedRoom.size(); i++ )
    {
        if(room == get<0>(visitedRoom[i]))
            return true;
    }
    return false;
}

Room* Donjon::dijkstra(Room* origin)
{


    RoomToVisit.push_back(make_tuple(origin, 0));


    while(RoomToVisit.size() !=  0)
    {
        tuple<Room*, int> RoomInfo =  RoomToVisit[0];

        int x = get<0>(RoomInfo)->posx;
        int y = get<0>(RoomInfo)->posy;
        int pathWeight =get<1>(RoomInfo);

        visitedRoom.push_back(RoomInfo);
        RoomToVisit.erase(RoomToVisit.begin());


        if (y -1 >= 0 && rooms[x][y-1]->type == Room::RoomType::Standard && !HasVisitedRoom(rooms[x][y-1]))
            RoomToVisit.push_back(make_tuple(rooms[x][y-1], pathWeight++));

        if (y +1 < _maxXnbRoom && rooms[x][y+1]->type == Room::RoomType::Standard && !HasVisitedRoom(rooms[x][y+1]))
            RoomToVisit.push_back(make_tuple(rooms[x][y+1], pathWeight++));

        if (x -1 >= 0 && rooms[x-1][y]->type == Room::RoomType::Standard && !HasVisitedRoom(rooms[x-1][y]))
            RoomToVisit.push_back(make_tuple(rooms[x-1][y], pathWeight++));

        if (x +1 <_maxYnbRoom && rooms[x+1][y]->type == Room::RoomType::Standard && !HasVisitedRoom(rooms[x+1][y]))
            RoomToVisit.push_back(make_tuple(rooms[x+1][y], pathWeight++));



    }
    Room* EndRoom = nullptr;
    int maxWeight = -1;
    for (int i = 0 ; i < visitedRoom.size(); i++ )
    {
        if (get<1>(visitedRoom[i]) >= maxWeight)
        {
            maxWeight = get<1>(visitedRoom[i]);
            EndRoom = get<0>(visitedRoom[i]);
        }
    }
    EndRoom->designation = "[E]";
    return EndRoom;
}
