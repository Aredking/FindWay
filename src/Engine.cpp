#include "Engine.h"

Engine::Engine() : window(sf::RenderWindow(sf::VideoMode({ 1200, 900 }), "ASTAR", sf::Style::Close))
{
	window.setFramerateLimit(60);
}

void Engine::run()
{
	window.setActive(false);

	std::thread drawThread([&]() { drawThreading(); });

	while (window.isOpen())
	{
		handleEvent();
		update();
	}
	drawThread.join();
}

void Engine::drawThreading()
{
	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		draw();
		window.display();
	}
}
