/*********************
 * Nexus Game Engine *
 *********************/
#include <iostream>
#include <thread>
#include <unordered_map>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "Engine/Systems/Collision/SpatialHashingGrid/BoardPhase/GridWindow.h"
#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#include "VecPos.h"
#define NE() std::cout << R"(
 /$$   /$$
| $$$ | $$
| $$$$| $$  /$$$$$$  /$$   /$$ /$$   /$$  /$$$$$$$
| $$ $$ $$ /$$__  $$|  $$ /$$/| $$  | $$ /$$_____/
| $$  $$$$| $$$$$$$$ \  $$$$/ | $$  | $$|  $$$$$$
| $$\  $$$| $$_____/  >$$  $$ | $$  | $$ \____  $$
| $$ \  $$|  $$$$$$$ /$$/\  $$|  $$$$$$/ /$$$$$$$/
|__/  \__/ \_______/|__/  \__/ \______/ |_______/
)" << std::endl;

int main() {
    NE();
    return 0;
}