#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Map
{
public:
	static enum class Cell
	{
		Ground,
		Forest,
		Water,
		Mounts,
		Space
	};

private:
	static inline std::unordered_map<Map::Cell, sf::Color> colors =
	{
		{Map::Cell::Ground, sf::Color(73, 35, 9)},
		{Map::Cell::Forest, sf::Color(60, 170, 60)},
		{Map::Cell::Water, sf::Color(22, 84, 252)},
		{Map::Cell::Mounts, sf::Color(61, 61, 61)},
		{Map::Cell::Space, sf::Color(255 ,255 ,255)}
	};

	static inline std::unordered_map<Map::Cell, int> complexityCell =
	{
		{Map::Cell::Ground, 2},
		{Map::Cell::Forest, 4},
		{Map::Cell::Water, 7},
		{Map::Cell::Mounts, 9},
	};

	std::vector<std::vector<Map::Cell>> map;

public:
	Map(int width, int height);
	const std::vector<std::vector<Map::Cell>>& getMap();
	void setCell(int, int, const Map::Cell&);

	void setRandCells();

	int getWidth();
	int getHeight();
	Map::Cell& getCell(int row, int col);

	static sf::Color& getColorCell(const Map::Cell&);
	static int getComplexityCell(const Map::Cell&);

	bool isBuilding();

};

