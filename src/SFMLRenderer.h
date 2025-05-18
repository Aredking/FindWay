#pragma once

#include "Map.h"

#include <SFML/Graphics.hpp>
#include <vector>

class SFMLRenderer
{
public:
	static void drawMap(sf::RenderWindow&, sf::RenderTexture&, sf::View&, Map&, int tileSize);
};

