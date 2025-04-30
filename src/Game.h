#pragma once

#include "Engine.h"
#include "Map.h"
#include "SFMLRenderer.h"

#include <iostream>

class Game : public Engine
{
private:
	enum class States
	{
		CreateMap,
	};

	const int HEIGHT_FIELD = 20;
	const int WIDTH_FIELD = 20;

	const int HEIGHT_GAME_AREA = 900;
	const int WIDTH_GAME_AREA = 900;
	SFMLRenderer renderer;
	Map map;
	States stateGame;

	
	void handleEvent() override;
	void draw() override;
	void update() override;
	void setCell(Map::Cell&&);

public:

	Game();
};

