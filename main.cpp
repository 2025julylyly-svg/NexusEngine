/*********************
 * Nexus Game Engine *
 *********************/
#include "Engine/Actors/Shapes/CircleShape/Circle.h"
#include "Engine/Actors/Shapes/RectangleShape/Rectangle.h"
#include "Engine/Systems/Collision/SpatialHashingGrid/BoardPhase/GridWindow.h"
#include "Engine/Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.h"
#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#include "Library/HashSet/Hash_Set.h"
#include "Library/MapWithoutHashData/MAIN/Map.h"
#include "Set.h"
#include "VecPos.h"
#include <iostream>
#include <set>
#include <thread>
#include <vector>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/VideoMode.hpp>
#define NE() \
    std::cout << R"(
 /$$   /$$|
| $$$ | $$|
| $$$$| $$|   /$$$$$$   /$$   /$$|  /$$   /$$   /$$$$$$$
| $$ $$ $$|  /$$__  $$ |  $$ /$$/  | $$  | $$  /$$_____/
| $$  $$$$| | $$$$$$$$  \  $$$$/   | $$  | $$ |  $$$$$$
| $$\  $$$| | $$_____/   >$$  $$\  | $$  | $$  \____  $$
| $$ \  $$| |  $$$$$$$  /$$/\  $$| |  $$$$$$/  /$$$$$$$/
|__/  \__/   \_______/ |__/  \__/   \______/  |_______/
)" << std::endl;

int main() {
    NE();
    sf::RenderWindow window( sf::VideoMode( { 900, 900 } ), "Test" );
    Polygon pn;
    pn.setPointCount( 5 );
    pn.setPoint( 0, { 350.0f, 50.0f } );
    pn.setPoint( 1, { 650.0f, 250.0f } );
    pn.setPoint( 2, { 550.0f, 600.0f } );
    pn.setPoint( 3, { 150.0f, 600.0f } );
    pn.setPoint( 4, { 50.0f, 250.0f } );
    pn.setFillColor( sf::Color::Blue );
    Rectangle rectangle;
    rectangle.setSize( {40,40} );
    rectangle.setPosition( {40,100} );
    rectangle.setFillColor( sf::Color::Green );
    rectangle.SetSpeed( 10 );
    CheckColl coll( 900, 900 );
    coll.set( &rectangle );
    coll.set( &pn );
    unsigned long long int n = 0;
    while (window.isOpen()) {
        while (const auto& event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (event->is<sf::Event::KeyPressed>()) {
                if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A )) {
                    rectangle.MoveLeft();
                } else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D )) {
                    rectangle.MoveRight();
                } else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W )) {
                    rectangle.MoveUp();
                } else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S )) {
                    rectangle.MoveDown();
                }
            }
        }
        window.clear();
        window.draw( pn );
        window.draw( rectangle );
        window.display();
    }
    return 0;
}
