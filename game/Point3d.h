#pragma once
#include "Point2d.h"
class Point3d :
    public Point2d
{
private:
    float z;
public:
    float get_z();
    void set_z(float z);
};

