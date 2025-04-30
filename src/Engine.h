#pragma once

#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>

class Engine
{
private:
	void drawThreading();
	sf::RenderWindow window;

protected:
	virtual void handleEvent() = 0;
	virtual void draw() = 0;
	virtual void update() = 0;

	const sf::RenderWindow& safeGetWindow() const { return window; }
	sf::RenderWindow& getWindow() { return window; }

public:
	Engine();
	void run();
};

