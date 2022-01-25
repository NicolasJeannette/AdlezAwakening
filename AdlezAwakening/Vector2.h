#ifndef VECTOR2_H
#define VECTOR2_H
class Vector2
{

public:
   Vector2(float _x, float _y);
   void Inverse(float v[2]);
   void Copy(const float v[2], float out[2]);
   void Translate(const float v0[2], const float v1[2], float out[2]);
   void Scale(const float v0[2], const float v1[2], float out[2]);
   float Distance(const float p1[2], const float p2[2]);
protected:
    float x,y;
};
#endif // VECTOR2_H
