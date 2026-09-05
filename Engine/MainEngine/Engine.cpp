#include "Engine.h"
Engine::Engine() = default;

void Engine::CreateWindow(const VecPos& WindowSize, const unsigned int& set_fps) {
    window.create( sf::VideoMode( {
                       static_cast<unsigned int>(WindowSize.get_x()),
                       static_cast<unsigned int>(WindowSize.get_y()) } ), "Nexus Engine" );
    fps = set_fps;
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

void Engine::Run(GameLogic* Game_Logic) {
    Game_Logic->Set( &collision, &window, &input );
    while (window.isOpen()) {
        while (const auto& event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                return;
            }
        }
        input.GetKeyInputEvent();
        Game_Logic->Main();
        Engine::UpdateGameState();
        input.Reset();
        window.setFramerateLimit( fps );
    }
}

void Engine::Free() {
    for (std::size_t shape = 0; shape < Shapes.Size(); ++shape) {
        delete Shapes[shape];
    }
}

Engine::~Engine() {
    this->Free();
}
