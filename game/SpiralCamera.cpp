#include "SpiralCamera.h"

SpiralCamera::SpiralCamera(float new_width, float new_height, float new_scale, float y_pos, float z_pos)
{
	y_screen_offset = new_height / 2.0;
	x_screen_offset = new_width / 2.0;
	screen_scale = max(new_width, new_height) / new_scale;
	scale = new_scale;
	y_camera = y_pos;
	z_camera = z_pos;
	width = new_width;
	height = new_height;
}

void SpiralCamera::resize(float width, float height)
{
	if (abs(this->width - width) + abs(this->height - height) < 1.0) {
		return;
	}
	this->width = width;
	this->height = height;
	y_screen_offset = height / 2.0;
	x_screen_offset = width / 2.0;
	screen_scale = max(width,height) / this->scale;
}

Point2d SpiralCamera::project(Point3d& point)
{
	Point2d a;
	float new_x = x_screen_offset + screen_scale * (point.get_x() / (point.get_z() - z_camera));
	float new_y = y_screen_offset + screen_scale * ((point.get_y() - y_camera) / (point.get_z() - z_camera));
	a.set_x(new_x);
	a.set_y(new_y);
	return a;
}

