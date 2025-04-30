#include "SFMLRenderer.h"


void SFMLRenderer::drawMap(sf::RenderWindow& window, Map& map, sf::Vector2f& gameAreaSize)
{
    float h = static_cast<float>(gameAreaSize.y) / map.getHeight();
    float w = static_cast<float>(gameAreaSize.x) / map.getWidth();

    float gap = .5f; // Размер зазора в пикселях

    sf::VertexArray vertices(sf::PrimitiveType::Triangles, map.getWidth() * map.getHeight() * 6);

    for (int j = 0; j < map.getHeight(); ++j)
    {
        for (int i = 0; i < map.getWidth(); ++i)
        {
            int index = (i + j * map.getWidth()) * 6;

            float x = w * i + gap;
            float y = h * j + gap;
            float tileWidth = w - gap * 2;
            float tileHeight = h - gap * 2;

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
    backGround.setFillColor(sf::Color::Black);

    window.draw(backGround);
    window.draw(vertices);
}
