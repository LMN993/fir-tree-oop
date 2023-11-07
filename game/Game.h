#pragma once

#include "Context.h"
#include <string>
#include "raylib.h"
#include "imgui.h"

class Game
{
private:
	std::string game_name;
protected:
	virtual void Update(float deltaTime);
	virtual void Draw(Context &ctx);
	virtual void DrawUI();
	int screenWidth;
	int screenHeight;
	int fps;
public:
	Game(std::string name, int width, int height);
	void Run();
};

