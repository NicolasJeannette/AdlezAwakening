#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <cstdlib>
#include <vector>
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
    // Constructors
    Room(RoomType rt);
    Room(string desi);
    Room();

    // Setters
    void SetPosition(int x, int y);
    void SetRoomType(RoomType rt);

    ~Room();

    RoomType type;
    int numDoor; // The number of doors in this room (but not the sides)
    string designation; // A string representation of the room (not depend to the enum)

    void drawTop(bool haveDoor); // Draw the top wall of the room
    void drawBot(bool haveDoor); // Draw the bot wall of the room
    void drawRight(bool haveDoor); // Draw the right wall of the room
    void drawLeft(bool haveDoor); // Draw the left wall of the room


    int posx;
    int posy;

    void drawRoom(vector<vector<Room*>> &adjacente  ); // Draw the walls in the room and latter obsatcles
};

#endif // ROOM_H
