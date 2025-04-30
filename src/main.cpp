#include "Game.h"
#include "Engine.h"
#include <iostream>

int main()
{
    Engine* engine = new Game();
    engine->run();

    delete engine;

}