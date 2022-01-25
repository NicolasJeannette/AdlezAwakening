#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{

public:
   Vector3(float _x, float _y, float _z);
   void Inverse(float v[3]);
   void Copy(const float v[3], float out[3]);
   void Translate(const float v0[3], const float v1[3], float out[3]);
   void Scale(const float v0[3], const float v1[3], float out[3]);
   float Distance(const float p1[3], const float p2[3]);
protected:
    float x,y,z;
};

#endif // VECTOR3_H
