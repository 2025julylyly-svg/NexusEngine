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
        std::optional<input_event> DownKey = input.GetKeyPressed();
        if (DownKey.has_value()) {
            if (DownKey.value().type == EV_KEY) {
                if (DownKey.value().code == KEY_W) {
                    std::cout << "Pressed W" << std::endl;
                }
                else if (DownKey.value().code == KEY_S) {
                    std::cout << "Pressed S" << std::endl;
                }
                else if (DownKey.value().code == KEY_A) {
                    std::cout << "Pressed A" << std::endl;
                }
                else if (DownKey.value().code == KEY_D) {
                    std::cout << "Pressed D" << std::endl;
                }
            }
        }
        std::optional<input_event> UpKey = input.GetKeyReleased();
        if (UpKey.has_value()) {
            if (UpKey.value().type == EV_KEY) {
                if (UpKey.value().code == KEY_W) {
                    std::cout << "Released W" << std::endl;
                }
                else if (UpKey.value().code == KEY_S) {
                    std::cout << "Released S" << std::endl;
                }
                else if (UpKey.value().code == KEY_A) {
                    std::cout << "Released A" << std::endl;
                }
                else if (UpKey.value().code == KEY_D) {
                    std::cout << "Released D" << std::endl;
                }
            }
        }
    }
    return 0;
}