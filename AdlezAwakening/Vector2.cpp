#include "Vector2.h"
#include "QtMath"
#include "QVector3D"

void Vector2::Inverse(float v[2])
{
        v[0] = -v[0];
        v[1] = -v[1];
}

Vector2::Vector2(float _x, float _y)
    : x(_x), y(_y)
   {

   }
void Vector2::Copy(const float v[2], float out[2])
{
       out[0] = v[0];
       out[1] = v[1];
}
float Vector2::Distance(const float p1[2], const float p2[2])
{
        float x = p1[0]-p2[0];
        float y = p1[1]-p2[1];
        return qSqrt(x*x + y*y);
}
void Vector2::Scale(const float v0[2], const float v1[2], float out[2])
{
        out[0] = v0[0] * v1[0];
        out[1] = v0[1] * v1[1];
}
void Vector2::Translate(const float v0[2], const float v1[2], float out[2])
{
        out[0] = v0[0] + v1[0];
        out[1] = v0[1] + v1[1];
}
