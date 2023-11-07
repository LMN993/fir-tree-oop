#include "Context.h"

Context::Context()
{
	BeginDrawing();
	
}

Context::~Context()
{
	EndDrawing();
}

void Context::Clear(Color color)
{
	ClearBackground(color);
}

void Context::Line(Point2d start, Point2d end, Color color)
{
	DrawLineEx(
		Vector2{ start.get_x(), start.get_y() },
		Vector2{ end.get_x(), end.get_y() },
		2.0,
		color
	);
}
