#include "Game.h"

Game::Game() : renderer(), map(WIDTH_FIELD, HEIGHT_FIELD), stateGame(States::CreateMap) {}

void Game::handleEvent()
{
    while (const std::optional event = getWindow().pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            getWindow().close();
        }
    }
}

void Game::update()
{
    if (stateGame == States::CreateMap)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) setCell(Map::Cell::Ground);

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) setCell(Map::Cell::Forest);

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) setCell(Map::Cell::Water);

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) setCell(Map::Cell::Mounts);
    }

    if (map.isBuilding()) std::cout << "Build";
}

void Game::setCell(Map::Cell&& cell)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(safeGetWindow());

    int row = float(mousePos.y) / (float(HEIGHT_GAME_AREA) / float(HEIGHT_FIELD));
    int col = float(mousePos.x) / (float(WIDTH_GAME_AREA) / float(WIDTH_FIELD));

    if (row >= 0 && row < HEIGHT_FIELD && col >= 0 && col < WIDTH_FIELD)
    {
        map.setCell(row, col, cell);
    }
}

void Game::draw()
{
    sf::Vector2f size({ float(WIDTH_GAME_AREA), float(HEIGHT_GAME_AREA) });
    renderer.drawMap(getWindow(), map, size);
}
