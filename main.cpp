/*********************
 * Nexus Game Engine *
 *********************/
#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#define NE() std::clog << "*********************\n" << "* Nexus Game Engine *\n" << "*********************" << std::endl;

int main() {
    NE();
    sf::RenderWindow window(sf::VideoMode({900,900}), "SFML");
    sf::CircleShape shape(30);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition( {450,450} );
    while (window.isOpen()) {
        while (const auto& event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (event->is<sf::Event::KeyPressed>()) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                    shape.setPosition( {shape.getPosition().x - 0.1f, shape.getPosition().y} );
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                    shape.setPosition( {shape.getPosition().x + 0.1f, shape.getPosition().y} );
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                    shape.setPosition( {shape.getPosition().x, shape.getPosition().y + 0.1f} );
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                    shape.setPosition( {shape.getPosition().x, shape.getPosition().y - 0.1f} );
                }
            }
        }
        window.clear( sf::Color::Black );
        window.draw( shape );
        window.display();
        window.setFramerateLimit(30);
    }
    return 0;
}