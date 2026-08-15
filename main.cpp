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
    ReadInput input;
    while (true) {
        input.GetKeyInputEvent();
        if (input.IsKeyPressed( 30 )) {
            std::cout << "KeyPressed" << std::endl;
        }
        std::cout << "---------------------" << std::endl;
        input.Reset();
        std::this_thread::sleep_for( std::chrono::milliseconds(100) );
    }
    return 0;
}