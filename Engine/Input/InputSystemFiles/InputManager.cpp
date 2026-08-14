#include "InputManager.h"

InputManager::InputManager() {
    FileEventKey = open( "/dev/input/event7", O_RDONLY | O_NONBLOCK );
    if (FileEventKey == -1) {
        std::cout << "Error: can not open '/dev/input/event7'" << std::endl;
        perror( "open" );
        exit(0);
    }
}

bool InputManager::GetKeyState(const unsigned int& KeyCode) {
    return KeyState[KeyCode];
}

bool InputManager::GetKeyState(const unsigned int&& KeyCode) {
    return KeyState[KeyCode];
}

bool InputManager::GetKeyState(input_event key) {
    return KeyState[key.code];
}

InputManager::~InputManager() {
    if (FileEventKey != -1) {
        close(FileEventKey);
    }
}