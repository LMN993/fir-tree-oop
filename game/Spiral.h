#pragma once
#include <algorithm>
#include "Line.h"
#include <vector>
#include <string>
#include "raylib.h"
using namespace std;

constexpr float THETA_MIN = 0.0;
constexpr float THETA_MAX = 8.0 * PI;
constexpr float PERIOD= THETA_MAX;
constexpr float LINE_SPACING = 1.5 / 12.0;
constexpr float LINE_LENGTH= LINE_SPACING / 2.0;
constexpr float G_RATE = 1.0 / (2.0 * PI);
constexpr float G_FACTOR  = G_RATE / 3.0;
constexpr float SPEED  = PERIOD * 1.5;

class Spiral
{
private:
    Color foreground;
    float angle_offset;
    float factor;
    float offset;
    vector<Line> segment;
    std::string name;
public:
    Spiral(std::string name, Color foreground, float angle_offset, float factor);
    float d_theta(float theta, float l_line_length, float rate, float factor);
    Point3d get_point(float theta, float factor, float angle_offset, float rate);
    float get_alpha(Point3d& point, float factor, float rate);
    void compute_segment(float dt);
    vector<Line> get_lines();
    Color get_color();
    std::string get_name();
    void set_color(Color color);
};

