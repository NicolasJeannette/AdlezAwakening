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


    vector<tuple <Room*, int>> visitedRoom;
    vector<tuple <Room*, int>> RoomToVisit; // each line contain cordonate and weight
    int _maxXnbRoom = 15;
    int _maxYnbRoom = 15;
     int numberRoom =10;


     Room* dijkstra(Room* origin);
    vector<Room*> GetAdjacentRoom(int originX,int originY);
    bool HasVisitedRoom(Room* );
    void SetStartndEndRoom(Room* OriginRoom);
    vector <vector<Room*>> rooms;
    void GenerationDonjon();
    void DisplayDungeon();
    Room* getStartingRoom();


};

#endif // DONJON_H
