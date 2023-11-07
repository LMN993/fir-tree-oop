#include "FirTree.h"
#include "UI.h"

void FirTree::DrawSpiral(Context& ctx, Spiral& spiral)
{
    auto lines = spiral.get_lines();
    for (auto &line : lines) {
        auto start = line.project_start(camera);
        auto end = line.project_end(camera);
        Color color = spiral.get_color();
        color.a = static_cast<unsigned char>(line.get_alpha() * 255.0);

        ctx.Line(start, end, color);
    }
}

void FirTree::Update(float deltaTime)
{
    camera.resize(screenWidth, screenHeight);

    for (auto &spiral : spirals) {
        spiral.compute_segment(deltaTime);
    }
}

void FirTree::Draw(Context &ctx)
{
    ctx.Clear(BLACK);
    for (auto &spiral : spirals) {
        DrawSpiral(ctx, spiral);
    }
}

void FirTree::DrawUI()
{
    UI::Draw(fps, spirals);
}

FirTree::FirTree() : Game("Fir Tree", 600, 800), camera(10.0, 10.0, 1.0, 2.1, -5.0)
{   
    spirals.push_back(Spiral("Spiral Left 3", Color { 0x22, 0x00, 0x00, 0xff }, 0.92, 0.9));
    spirals.push_back(Spiral("Spiral Right 3", Color { 0x00, 0x22, 0x11, 0xff }, 0.08, 0.9));
    spirals.push_back(Spiral("Spiral Left 2", Color { 0x66, 0x00, 0x00, 0xff }, 0.95, 0.93));
    spirals.push_back(Spiral("Spiral Right 2", Color { 0x00, 0x33, 0x22, 0xff }, 0.05, 0.93));
    spirals.push_back(Spiral("Spiral Left 1", Color { 0xff, 0x00, 0x00, 0xff }, 1.0, 1.0));
    spirals.push_back(Spiral("Spiral Right 1", Color { 0x00, 0xff, 0xcc, 0xff }, 0.0, 1.0));
}
