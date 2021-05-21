#include "Engine.h"

Engine::Engine()
{
    this->state = OFF;
}
void Engine::start()
{
    this->state = ON;
}
void Engine::stop()
{
    this->state = OFF;
}