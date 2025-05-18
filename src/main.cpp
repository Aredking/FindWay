#include "Game.h"
#include "Engine.h"

int main()
{
    Engine* engine = new Game();
    engine->run();
    delete engine;
}