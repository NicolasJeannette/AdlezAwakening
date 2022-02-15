#ifndef ROOM_H
#define ROOM_H


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
    Room();

    void GenerationSalle();

    void drawTop(bool haveDoor);
    void drawBot(bool haveDoor);
    void drawRight(bool haveDoor);
    void drawLeft(bool haveDoor);

    int posx;
    int posy;
};

#endif // ROOM_H
