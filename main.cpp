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
    ReadInput input;
    while (true) {
        input.GetKeyInputEvent();
        if (input.IsKeyPressed( 30 )) {
            std::cout << "A is Pressed" << std::endl;
        }
        else if (input.IsKeyPressed( 1 )) {
            break;
        }
        input.Reset();
    }
    return 0;
}
