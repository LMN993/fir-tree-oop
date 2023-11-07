#include "Line.h"

Point2d Line::project_start(SpiralCamera& camera)
{
    return camera.project(start);
}

Point2d Line::project_end(SpiralCamera& camera)
{
    return camera.project(end);
}

float Line::get_alpha()
{
    return alpha;
}
