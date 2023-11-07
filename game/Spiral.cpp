#include "Spiral.h"

Spiral::Spiral(std::string name, Color foreground, float angle_offset, float factor) : name(name)
{
    float new_angle_offset = angle_offset * PI;
    float  new_factor = factor * G_FACTOR;
    
    this->foreground = foreground;
    this->angle_offset = new_angle_offset;
    this->factor = new_factor;
    offset = 0.0;
}

float Spiral::d_theta(float theta, float l_line_length, float rate, float factor)
{
    float inv_theta = sqrt(rate * rate + factor * factor * theta * theta);
    return l_line_length / inv_theta;
}

Point3d Spiral::get_point(float theta, float factor, float angle_offset, float rate)
{
    Point3d point;
    float x = theta * factor * cos(theta + angle_offset);
    float y = rate * theta;
    float z = -theta * factor * sin(theta + angle_offset);
    point.set_x(x);
    point.set_y(y);
    point.set_z(z);
    return point;
}

float Spiral::get_alpha(Point3d& point, float factor, float rate)
{
    return (min(1.0, (atan(point.get_y() * factor / rate * 0.1 + 0.02 - point.get_z() * 40.0) * 0.35 + 0.65)));
}

void Spiral::compute_segment(float dt)
{
    offset += dt * SPEED;
    if (offset > PERIOD){
        offset -= PERIOD;
    }

        float theta = THETA_MIN
        - d_theta(
            THETA_MIN,
            LINE_SPACING * offset /PERIOD,
            G_RATE,
            factor
            );

    segment.clear();

    while( theta < THETA_MAX){
        float theta_old = max(theta, THETA_MIN);
        theta += d_theta(theta, LINE_LENGTH, G_RATE, factor);
        float theta_end = min(
            float((theta_old + max(theta, THETA_MIN)) / 2.0),
            THETA_MAX
        );
        if (theta_end < THETA_MIN) {
            continue;
        }

        Point3d start = get_point(theta_old, factor, angle_offset, G_RATE);
        Point3d end = get_point(theta_end, factor, angle_offset, G_RATE);
        float alpha = get_alpha(start, factor, G_RATE);
        segment.push_back(Line ( start, end, alpha ));
        
    }

}

vector<Line> Spiral::get_lines()
{

    return segment;
}

Color Spiral::get_color()
{
    return foreground;
}

std::string Spiral::get_name()
{
    return name;
}

void Spiral::set_color(Color color)
{
    foreground = color;
}


