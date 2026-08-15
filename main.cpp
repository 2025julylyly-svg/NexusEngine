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
        if (input.GetKeyPressed() == 30) {
            std::cout << "KeyPressed" << std::endl;
        }
        std::cout << "---------------------" << std::endl;
        std::this_thread::sleep_for( std::chrono::milliseconds(1000) );
        input.Reset();
    }
    return 0;
}