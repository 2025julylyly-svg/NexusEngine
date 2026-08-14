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
        std::optional<input_event> key = input.GetKeyInputEvent();
        if (key.has_value()) {
            if (key.value().type == EV_KEY) {
                if (key.value().value == 1) {
                    if (key.value().code == 1) {
                        break;
                    }
                    std::cout << "Key Pressed: " << key.value().code << std::endl;
                }
            }
        }
    }
    return 0;
}