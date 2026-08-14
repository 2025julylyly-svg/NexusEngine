/*********************
 * Nexus Game Engine *
 *********************/
#include <iostream>
#include "Engine/Input/InputSystemFiles/InputManager.h"
#define NE() std::cerr << "*********************\n" << "* Nexus Game Engine *\n" << "*********************" << std::endl;

int main() {
    NE();
    InputManager input;
    int x = 120;
    int y = 75;
    bool pause = false;
    while (true) {
        if (input.GetKeyPressed() == 1) {
            pause = !pause;
        }
        if (pause) {
            continue;
        }
        std::cout << "~" << std::endl;
    }
    return 0;
}