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
        try {
            input_event key = input.GetKeyPressed();
            if (key.type == EV_KEY) {
                if (key.code == BTN_LEFT) {
                    std::cout << "Left Key Pressed" << std::endl;
                }
            }
        }
        catch (const CantReadKeyError& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "Press any key to continue..." << std::endl;
    }
    return 0;
}