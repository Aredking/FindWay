#include "Engine.h"

Engine::Engine() : window(sf::RenderWindow(sf::VideoMode({ 800, 600 }), "FIND WAY!", sf::Style::Close))
{
	window.setFramerateLimit(FPS);
	std::cout << "ENGINE Constructor" << std::endl;
}

void Engine::run()
{
	std::cout << "RUN" << std::endl;

	runnigDrawThread = true;
	window.setActive(false);
	drawThread = std::thread([&]() { drawThreading(); });

	while (window.isOpen())
	{
		handleEvent();
		update();
	}

}

void Engine::drawThreading()
{

	std::cout << "DRAW" << std::endl;
	window.setActive(true);

	while (runnigDrawThread)
	{
		window.clear(sf::Color::White);
		draw();
		window.display();
	}
	window.setActive(false);
}

void Engine::BreakDrawThread()
{
	runnigDrawThread = false;
	drawThread.join();
}
