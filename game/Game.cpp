#include "Game.h"
#include "rlImGui.h"

void Game::Update(float deltaTime)
{
}

void Game::Draw(Context &ctx)
{
    ctx.Clear(BLACK);
}

void Game::DrawUI()
{
    bool open = true;
    ImGui::ShowDemoWindow(&open);
}

Game::Game(std::string name, int width, int height) : game_name(name), screenWidth(width), screenHeight(height), fps(0)
{
}

void Game::Run()
{
    SetConfigFlags(
        FLAG_WINDOW_RESIZABLE |
        FLAG_VSYNC_HINT |
        FLAG_MSAA_4X_HINT
    );
    InitWindow(screenWidth, screenHeight, game_name.c_str());
    rlImGuiSetup(true);

    while (!WindowShouldClose())
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
        fps = GetFPS();
        Update(GetFrameTime());
        Context ctx;
        Draw(ctx);

        rlImGuiBegin();
        DrawUI();
        rlImGuiEnd();
    }

    rlImGuiShutdown();
    CloseWindow();
}
