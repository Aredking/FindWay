#pragma once

#include "Map.h"

#include <SFML/Graphics.hpp>
#include <vector>

class SFMLRenderer
{
public:
	static void drawMap(sf::RenderWindow&, Map&, sf::Vector2f&);
};

