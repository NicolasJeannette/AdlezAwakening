#include "Vector3.h"
#include "QtMath"
#include "QVector3D"
void Vector3::Inverse(float v[3])
{
        v[0] = -v[0];
        v[1] = -v[1];
        v[2] = -v[2];
}

Vector3::Vector3(float _x, float _y, float _z)
    : x(_x), y(_y), z(_z)
   {

   }
void Vector3::Copy(const float v[3], float out[3])
{
       out[0] = v[0];
       out[1] = v[1];
       out[2] = v[2];
}
float Vector3::Distance(const float p1[3], const float p2[3])
{
        float x = p1[0]-p2[0];
        float y = p1[1]-p2[1];
        float z = p1[2]-p2[2];
        return qSqrt(x*x + y*y + z*z);
}
void Vector3::Scale(const float v0[3], const float v1[3], float out[3])
{
        out[0] = v0[0] * v1[0];
        out[1] = v0[1] * v1[1];
        out[2] = v0[2] * v1[2];
}
void Vector3::Translate(const float v0[3], const float v1[3], float out[3])
{
        out[0] = v0[0] + v1[0];
        out[1] = v0[1] + v1[1];
        out[2] = v0[2] + v1[2];
}
