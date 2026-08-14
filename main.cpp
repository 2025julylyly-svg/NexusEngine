/*********************
 * Nexus Game Engine *
 *********************/
#include <iostream>
#include "Engine/Input/InputSystemFiles/InputManager.h"
#define NE() std::cerr << "*********************\n" << "* Nexus Game Engine *\n" << "*********************" << std::endl;

int main() {
    NE();
    InputManager input;
    while (true) {
        try {
            if (std::optional<input_event> key = input.GetKeyPressed(); key.has_value()) {
                if (key.value().type == EV_KEY) {
                    if (key.value().code == KEY_A) {
                        std::cout << "Key Pressed: " << key.value().code << "   " << "State: " << key.value().value << std::endl;
                    }
                }
            }
            else {
                std::cout << "Press any key to continue..." << std::endl;
            }
        }
        catch (const CantReadKeyError& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}