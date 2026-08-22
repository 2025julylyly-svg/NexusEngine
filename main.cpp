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
#include "Engine/Systems/Collision/SpatialHashingGrid/BoardPhase/GridWindow.h"
#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#include "Library/MapWithoutHashData/MAIN/Map.h"
#include "Set.h"
#include "Library/HashSet/Hash_Set.h"
#include "VecPos.h"
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
int main() {
    NE();
    HashSet<int> s{1,2,3};
    for (const auto& it : s) {

    }
    return 0;
}
