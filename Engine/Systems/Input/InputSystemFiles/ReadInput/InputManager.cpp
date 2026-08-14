#include "InputManager.h"

ReadInputManager::ReadInputManager() {
    FileEventKey = open( "/dev/input/event7", O_RDONLY | O_NONBLOCK );
    if (FileEventKey == -1) {
        std::cout << "Error: can not open '/dev/input/event7'" << std::endl;
        perror( "open" );
        exit( 0 );
    }
}

std::optional<input_event> ReadInputManager::GetKeyInputEvent() {
    input_event key{};
    if (read (FileEventKey, &key, sizeof(key)) != sizeof(key)) {
        return std::nullopt;
    }
    return key;
}

ReadInputManager::~ReadInputManager() {
    if (FileEventKey != -1) {
        close( FileEventKey );
    }
}