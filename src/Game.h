#pragma once

#include "Engine.h"
#include "Map.h"
#include "SFMLRenderer.h"


class Game : public Engine
{
private:
	enum class States
	{
		CreateMap,
	};

	const int TILESIZE = 48;

	const int HEIGHT_GAME_AREA = 600;
	const int WIDTH_GAME_AREA = 600;
	float zoom = 1;

	SFMLRenderer renderer;
	Map map;
	States stateGame;

	sf::RenderTexture gameSurf;
	sf::View viewGameSurf;


	void handleEvent() override;
	void draw() override;
	void update() override;
	void setCell(Map::Cell&&);

public:

	Game();
};

