#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <cstdlib>
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
    Room(RoomType rt);
    Room(string desi);
    Room();

    void SetPosition(int x, int y);
        void SetRoomType(RoomType rt);

        ~Room();

        RoomType type;
        int numDoor;
        string designation;

    void drawTop(bool haveDoor);
    void drawBot(bool haveDoor);
    void drawRight(bool haveDoor);
    void drawLeft(bool haveDoor);


    int posx;
    int posy;
};

#endif // ROOM_H
