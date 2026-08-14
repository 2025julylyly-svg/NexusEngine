#include "InputManager.h"

InputManager::InputManager() {
    FileEventKey = open( "/dev/input/event7", O_RDONLY );
    if (FileEventKey == -1) {
        std::cout << "Error: can not open '/dev/input/event7'" << std::endl;
        perror( "open" );
        exit(0);
    }
}
unsigned int InputManager::GetKeyPressed() const {
    input_event key{};
    if (read( FileEventKey, &key, sizeof(key) ) != sizeof(key)) {
        return -1;
    }
    return key.code;
}

InputManager::~InputManager() {
    if (FileEventKey != -1) {
        close(FileEventKey);
    }
}