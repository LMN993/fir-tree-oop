#pragma once
#include "Game.h"
#include <vector>
#include "Spiral.h"
#include "SpiralCamera.h"
#include "imgui.h"

class FirTree: public Game
{
private:
	std::vector<Spiral> spirals;
	SpiralCamera camera;
	void DrawSpiral(Context& ctx, Spiral &spiral);
protected:
	void Update(float deltaTime) override;
	void Draw(Context& ctx) override;
	void DrawUI() override;
public:
	FirTree();
};

