#include "InputManager.h"

InputManager::InputManager() {
    FileEventKey = open( "/dev/input/event7", O_RDONLY );
    if (FileEventKey == -1) {
        std::cout << "Error: can not open '/dev/input/event7'" << std::endl;
        perror( "open" );
        exit(0);
    }
}
input_event InputManager::GetKeyPressed() const {
    input_event key{};
    if (read( FileEventKey, &key, sizeof(key) ) != sizeof(key)) {
        throw CantReadKeyError("can not read key");
    }
    return key;
}

InputManager::~InputManager() {
    if (FileEventKey != -1) {
        close(FileEventKey);
    }
}