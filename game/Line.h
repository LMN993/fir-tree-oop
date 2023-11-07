#pragma once
#include "Point3d.h"
#include "SpiralCamera.h"
class Line
{
private:
	Point3d start;
	Point3d end;
	float alpha;
public:
	Line(Point3d start, Point3d end, float alpha): start(start), end(end), alpha(alpha){}
	Point2d project_start(SpiralCamera& camera);
	Point2d project_end(SpiralCamera& camera);
	float get_alpha();
};

