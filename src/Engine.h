#pragma once

#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>

class Engine
{
private:
	void drawThreading();
	sf::RenderWindow window;
	std::thread drawThread;
	std::atomic<bool> runnigDrawThread;

	const int FPS = 60;

protected:
	virtual void handleEvent() = 0;
	virtual void draw() = 0;
	virtual void update() = 0;

	void BreakDrawThread();

	sf::RenderWindow& getWindow() { return window; }

public:
	Engine();
	void run();
};

