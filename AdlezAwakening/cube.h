#ifndef CUBE_H
#define CUBE_H
#include "QVector2D"

class Cube
{
public:
    Cube();
    ~Cube();
    QVector2D GetPosition();
    void DrawCube();
};

#endif // CUBE_H
