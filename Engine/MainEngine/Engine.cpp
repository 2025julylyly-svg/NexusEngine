#include "Engine.h"
Engine::Engine() = default;

void Engine::CreateWindow(const VecPos& WindowSize) {
    window.create( sf::VideoMode( {
                       static_cast<unsigned int>(WindowSize.get_x()),
                       static_cast<unsigned int>(WindowSize.get_y()) } ), "Nexus Engine" );
}

void Engine::CreateShape(sf::Shape* shape) {
    Shapes.Append( shape );
}

void Engine::UpdateGameState() {
    window.clear( window.GetScreenFillColor() );
    for (std::size_t shape = 0; shape < Shapes.Size(); ++shape) {
        window.draw( *Shapes[shape] );
    }
    window.display();
}

void Engine::Run() {
    while (window.isOpen()) {
    }
}

Engine::~Engine() {
    for (std::size_t shape = 0; shape < Shapes.Size(); ++shape) {
        delete Shapes[shape];
    }
}
