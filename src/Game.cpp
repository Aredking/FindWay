#include "Game.h"

Game::Game() : renderer(), stateGame(States::CreateMap), map(10, 10), gameSurf({ static_cast<unsigned>(WIDTH_GAME_AREA), static_cast<unsigned>(HEIGHT_GAME_AREA) }), viewGameSurf(sf::FloatRect({ 0, 0 }, { static_cast<float>(WIDTH_GAME_AREA), static_cast<float>(HEIGHT_GAME_AREA) }))
{
    gameSurf.setView(viewGameSurf);
    std::cout << "GAME Constructor" << std::endl;
    map.setRandCells();
}

void Game::handleEvent()
{
    while (const std::optional event = getWindow().pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            BreakDrawThread();
            getWindow().close();
        }
        if (event->is<sf::Event::KeyPressed>())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && zoom < 1.f)
            {
                zoom *= 1.25f;
                viewGameSurf = gameSurf.getDefaultView();
                viewGameSurf.zoom(zoom);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && zoom > 0.5f)
            {
                zoom *= 0.8f;
                viewGameSurf = gameSurf.getDefaultView();
                viewGameSurf.zoom(zoom);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                viewGameSurf.move({ 0, static_cast<float>(-TILESIZE) });
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                viewGameSurf.move({ 0, static_cast<float>(TILESIZE) });
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                viewGameSurf.move({ static_cast<float>(TILESIZE), 0 });
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                viewGameSurf.move({ static_cast<float>(-TILESIZE), 0 });
            }

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

    if (map.isBuilding());
}

void Game::setCell(Map::Cell&& cell)
{
    sf::Vector2f worldPos = gameSurf.mapPixelToCoords(sf::Mouse::getPosition(getWindow()), viewGameSurf);

    int row = worldPos.y / TILESIZE;
    int col = worldPos.x / TILESIZE;

    if (row >= 0 && row < map.getHeight() && col >= 0 && col < map.getWidth())
    {
        map.setCell(row, col, cell);
    }
}

void Game::draw()
{
    renderer.drawMap(getWindow(), gameSurf, viewGameSurf, map, TILESIZE);
}
