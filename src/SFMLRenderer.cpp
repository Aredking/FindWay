#include "SFMLRenderer.h"

void SFMLRenderer::drawMap(sf::RenderWindow& window, sf::RenderTexture& gameSurface, sf::View& view, Map& map, int tileSize)
{
    sf::Vector2f gameAreaSize{ static_cast<float>(gameSurface.getSize().x), static_cast<float>(gameSurface.getSize().y) };

    float gap = 1.f; // Размер зазора в пикселях

    sf::VertexArray vertices(sf::PrimitiveType::Triangles, map.getWidth() * map.getHeight() * 6);

    for (int j = 0; j < map.getHeight(); ++j)
    {
        for (int i = 0; i < map.getWidth(); ++i)
        {
            int index = (i + j * map.getWidth()) * 6;

            float x = tileSize * i + gap;
            float y = tileSize * j + gap;
            float tileWidth = tileSize - gap * 2;
            float tileHeight = tileSize - gap * 2;

            sf::Color color = Map::getColorCell(map.getCell(j, i));

            vertices[index + 0].position = sf::Vector2f(std::round(x), std::round(y));
            vertices[index + 0].color = color;

            vertices[index + 1].position = sf::Vector2f(std::round(x + tileWidth), std::round(y));
            vertices[index + 1].color = color;

            vertices[index + 2].position = sf::Vector2f(std::round(x + tileWidth), std::round(y + tileHeight));
            vertices[index + 2].color = color;

            vertices[index + 3].position = sf::Vector2f(std::round(x), std::round(y));
            vertices[index + 3].color = color;

            vertices[index + 4].position = sf::Vector2f(std::round(x + tileWidth), std::round(y + tileHeight));
            vertices[index + 4].color = color;

            vertices[index + 5].position = sf::Vector2f(std::round(x), std::round(y + tileHeight));
            vertices[index + 5].color = color;
        }
    }

    sf::RectangleShape backGround({ gameAreaSize.x, gameAreaSize.y });
    backGround.setFillColor(sf::Color::Transparent);
    //gameSurface.setView(view);

    //gameSurface.clear();

    //gameSurface.display();

    //sf::RectangleShape debugRect(sf::Vector2f(100, 100));
    //debugRect.setPosition({ 300, 300 });
    //debugRect.setFillColor(sf::Color::Red);

    //sf::View view(sf::FloatRect({ 0.f, 0.f }, { static_cast<float>(gameSurface.getSize().x) ,  static_cast<float>(gameSurface.getSize().y) }));


    gameSurface.setView(view);


    gameSurface.clear();
    gameSurface.draw(backGround);
    gameSurface.draw(vertices);
    gameSurface.display();


    sf::Sprite gameSurfaceSprite(gameSurface.getTexture());
    window.draw(gameSurfaceSprite);
}
