#pragma once
#include "raylib.h"
#include "Point2d.h"

class Context
{
public:
	Context();
	~Context();

	void Clear(Color color);
	void Line(Point2d start, Point2d end, Color color);
};

