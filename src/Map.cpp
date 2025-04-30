#include "Map.h"

#include <iostream>

Map::Map(int width, int height)
{
	map = std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Map::Cell::Space));

	std::cout << this->getWidth() << " " << this->getHeight() << std::endl;
}

const std::vector<std::vector<Map::Cell>>& Map::getMap()
{
	return map;
}

int Map::getWidth()
{
	return map[0].size();
}

int Map::getHeight()
{
	return map.size();
}

void Map::setCell(int row, int col, const Map::Cell& cell)
{
	if (map[row][col] == Cell::Space) map[row][col] = cell;
}

Map::Cell& Map::getCell(int row, int col)
{
	return map[row][col];
}

sf::Color& Map::getColorCell(const Map::Cell& cell) {
	return colors.at(cell);
}

int Map::getComplexityCell(const Map::Cell& cell)
{
	return Map::complexityCell.at(cell);
}

bool Map::isBuilding()
{
	for (auto row : map)
		for (auto col : row)
			if (col == Map::Cell::Space) return false;
	
	return true;
}



