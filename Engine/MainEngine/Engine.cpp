#include "Engine.h"
Engine::Engine() = default;

void Engine::CreateWindow(const VecPos& WindowSize) {
    window.create( sf::VideoMode( {
                       static_cast<unsigned int>(WindowSize.get_x()),
                       static_cast<unsigned int>(WindowSize.get_y()) } ), "Nexus Engine" );
}

Engine::~Engine() = default;
