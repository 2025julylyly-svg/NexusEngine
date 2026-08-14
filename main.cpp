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
        else if (input.IsKeyHeld( 30 )) {
            std::cout << "A : Key Held" << std::endl;
        }
        input.Reset();
        std::this_thread::sleep_for( std::chrono::milliseconds(100) );
    }
    return 0;
}