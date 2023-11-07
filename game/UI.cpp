#include "UI.h"
#include "imgui.h"

void UI::Draw(int fps, vector<Spiral> &spirals)
{
    bool active = true;
    ImGui::Begin("Options", &active, ImGuiWindowFlags_None);

    auto fps_s = std::to_string(fps);
    ImGui::LabelText("FPS", fps_s.c_str());

    for (auto& spiral : spirals) {
        float color3[3];
        color3[0] = spiral.get_color().r / 255.0;
        color3[1] = spiral.get_color().g / 255.0;
        color3[2] = spiral.get_color().b / 255.0;
        ImGui::ColorEdit3(spiral.get_name().c_str(), color3);
        spiral.set_color(Color{
            static_cast<unsigned char>(color3[0] * 255.0),
            static_cast<unsigned char>(color3[1] * 255.0),
            static_cast<unsigned char>(color3[2] * 255.0),
            255
            });
    }

    ImGui::End();
}
