#ifndef INPUT_H
#define INPUT_H
#include "QKeyEvent"
#include "player.h"


class Input
{
public:
    Input(Player* player);
        ~Input();

        bool forward = false;
        bool backward = false;
        bool right = false;
        bool left = false;

        void listenEvent(QKeyEvent *event);
        Player *p;
};

#endif // INPUT_H
