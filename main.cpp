/*********************
 * Nexus Game Engine *
 *********************/
#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <String.h>
#include <map.h>

#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#define NE() std::clog << "*********************\n" << "* Nexus Game Engine *\n" << "*********************" << std::endl;

int main() {
    NE();
    ReadInput input;
    while (true) {
        input.GetKeyInputEvent();
        if (input.IsKeyPressed( 30 )) {
            std::cout << "a" << std::endl;
        }
        if (input.IsKeyPressed( 1 )) {
            break;
        }
        input.Reset();
        std::this_thread::sleep_for( std::chrono::milliseconds(100) );
    }
    return 0;
}