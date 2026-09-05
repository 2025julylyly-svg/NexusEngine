/*********************
 * Nexus Game Engine *
 *********************/
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <set>
#include <thread>
#include <vector>
#include "Engine/Actors/Shapes/CircleShape/Circle.h"
#include "Engine/Systems/Collision/SpatialHashingGrid/BoardPhase/GridWindow.h"
#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#include "Library/HashSet/Hash_Set.h"
#include "Library/MapWithoutHashData/MAIN/Map.h"
#include "Set.h"
#include "VecPos.h"
#include "Engine/MainEngine/Engine.h"
#include "Engine/Systems/Input/InputSystemFiles/InputManager/inputManager.h"
#define NE() std::cout << R"(
 /$$   /$$|
| $$$ | $$|
| $$$$| $$|   /$$$$$$   /$$   /$$|  /$$   /$$   /$$$$$$$
| $$ $$ $$|  /$$__  $$ |  $$ /$$/  | $$  | $$  /$$_____/
| $$  $$$$| | $$$$$$$$  \  $$$$/   | $$  | $$ |  $$$$$$
| $$\  $$$| | $$_____/   >$$  $$\  | $$  | $$  \____  $$
| $$ \  $$| |  $$$$$$$  /$$/\  $$| |  $$$$$$/  /$$$$$$$/
|__/  \__/   \_______/ |__/  \__/   \______/  |_______/
)" << std::endl;


namespace {
    class Logic final : public GameLogic
    {
    public:
        void CollisionCheckingManaging() const override {}

        void InputManaging() const override {}

        void Main() const override {
            this->InputManaging();
        }
    };
}


int main() {
    NE();
    Logic logic;
    Engine engine;
    engine.CreateWindow( { 900, 900 }, 60 );
    engine.Run( &logic );
    return 0;
}
