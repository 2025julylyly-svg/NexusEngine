/*********************
 * Nexus Game Engine *
 *********************/
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <thread>
#include <set>
#include "Engine/Systems/Collision/SpatialHashingGrid/BoardPhase/GridWindow.h"
#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#include "Library/MapWithoutHashData/MAIN/Map.h"
#include "VecPos.h"
#include "Set.h"
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
    Set<int> s;
    s.Add( 8 );
    s.Add( 2 );
    s.Add( 10 );
    s.Add( 21 );
    s.Add( 20 );
    s.Add( 21 );
    for (const auto& it : s) {
        std::cout << it << std::endl;
    }
    return 0;
}
