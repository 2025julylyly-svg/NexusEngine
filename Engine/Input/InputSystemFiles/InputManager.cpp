#include "InputManager.h"

InputManager::InputManager() {
    FileEventKey = open( "/dev/input/event7", O_RDONLY | O_NONBLOCK );
    if (FileEventKey == -1) {
        std::cout << "Error: can not open '/dev/input/event7'" << std::endl;
        perror( "open" );
        exit(0);
    }
}

std::optional<input_event> InputManager::GetKeyReleased() const {
    input_event key{};
    if (read( FileEventKey, &key, sizeof(key) ) != sizeof(key)) {
        return std::nullopt;
    }
    if (key.value == 0) {
        return key;
    }
    return std::nullopt;
}

std::optional<input_event> InputManager::GetKeyPressed() const {
    input_event key{};
    if (read( FileEventKey, &key, sizeof(key) ) != sizeof(key)) {
        return std::nullopt;
    }
    if (key.value == 1) {
        return key;
    }
    return std::nullopt;
}

InputManager::~InputManager() {
    if (FileEventKey != -1) {
        close(FileEventKey);
    }
}