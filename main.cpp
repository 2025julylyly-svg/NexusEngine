/*********************
 * Nexus Game Engine *
 *********************/
#include <iostream>
#include "Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#define NE() std::cerr << "*********************\n" << "* Nexus Game Engine *\n" << "*********************" << std::endl;

int main() {
    NE();
    ReadInput input;
    while (true) {
        if (input.IsKeyReleased( 30 )) {
            std::cout << "Key Released" << std::endl;
        }
    }
    return 0;
}