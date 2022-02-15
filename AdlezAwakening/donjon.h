#ifndef DONJON_H
#define DONJON_H
#include <vector>
#include "Room.h"
using namespace std;

class Donjon
{
public:
    Donjon(int maxXnbRoom = 0, int maxYnbRoom = 0);
    ~Donjon();
   void GenerationDonjon();
    void DisplayDungeon();
    Room* dijkstra(Room* origin);
    vector<Room*> GetAdjacentRoom(int originX,int originY);
    bool HasVisitedRoom(Room* );
    void SetStartndEndRoom(Room* OriginRoom);
    vector <vector<Room*>> rooms;
    int _maxXnbRoom = 15;
    int _maxYnbRoom = 15;

     int numberRoom =10;

     // chimique
     vector<tuple <Room*, int>> visitedRoom;
     vector<tuple <Room*, int>> RoomToVisit; // each line contain cordonate and weight
};

#endif // DONJON_H
