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

#include "Engine/Systems/Window/WindowSystem.h"
#define NexusEngine() \
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
    NexusEngine()
    WindowSystem window;
    window.create( sf::VideoMode( { 900, 900 } ), "Nexus Engine" );
    Rectangle rt1;
    rt1.setSize( { 40, 40 } );
    rt1.setPosition( { 100, 100 } );
    rt1.setFillColor( sf::Color::Blue );
    rt1.SetSpeed( 5 );
    Rectangle rt2;
    rt2.setSize( { 80, 80 } );
    rt2.setPosition( { 400, 100 } );
    rt2.setFillColor( sf::Color::Red );
    CheckColl coll(900,900);
    coll.set( &rt1 );
    coll.set( &rt2 );
    unsigned long long int n = 0;
    while (window.isOpen()) {
        while (const auto& event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (event->is<sf::Event::KeyPressed>()) {
                if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A )) {
                    rt1.MoveLeft();
                } else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D )) {
                    rt1.MoveRight();
                } else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W )) {
                    rt1.MoveUp();
                } else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S )) {
                    rt1.MoveDown();
                }
            }
        }
        if (coll.RectanglePolygon( &rt1 ).found( &rt2 )) {
            std::cout << ++n << std::endl;
        }
        window.clear();
        window.draw( rt1 );
        window.draw( rt2 );
        window.display();
    }
    return 0;
}
