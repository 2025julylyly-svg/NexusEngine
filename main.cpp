/*********************
 * Nexus Game Engine *
 *********************/
#include <iostream>
#include <thread>
#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#define NE() std::clog << "*********************\n" << "* Nexus Game Engine *\n" << "*********************" << std::endl;

int main() {
    NE();
    ReadInput input;
    while (true) {
        input.GetKeyInputEvent();
        if (input.IsKeyPressed( 30 )) {
            std::cout << "A : Key Pressed" << std::endl;
        }
        else if (input.IsKeyPressed( 1 )) {
            std::cout << "ESC : Key Pressed" << std::endl;
        }
        else if (input.IsKeyPressed( 57 )) {
            break;
        }
        std::cout << "Hello" << std::endl;
        std::this_thread::sleep_for( std::chrono::milliseconds(100) );
        input.Reset();
    }
    return 0;
}