/*********************
 * Nexus Game Engine *
 *********************/
#include <iostream>
#include <thread>
#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#define NE() std::cerr << "*********************\n" << "* Nexus Game Engine *\n" << "*********************" << std::endl;

int main() {
    NE();
    ReadInput input;
    while (true) {
        if (const short int key = input.IsKeyPressed(); key != -1) {
            if (key == 1) {
                break;
            }
            std::cout << "Key pressed: " << key << std::endl;
        }
        std::cout << "Hello" << std::endl;
        std::this_thread::sleep_for( std::chrono::milliseconds(100) );
    }
    return 0;
}