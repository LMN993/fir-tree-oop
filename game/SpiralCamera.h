#pragma once
#include "Point2d.h"
#include "Point3d.h"
#include <algorithm> 
using namespace std;
class SpiralCamera
{
private:
    float y_screen_offset;
    float x_screen_offset;
    float screen_scale;
    float scale;
    float y_camera;
    float z_camera;
    float width;
    float height;
public:
    SpiralCamera(float width, float height, float scale, float y_pos, float z_pos);
    void resize(float  width, float height);
    Point2d project(Point3d &point);
};

