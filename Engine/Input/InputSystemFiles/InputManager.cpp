#include "InputManager.h"

InputManager::InputManager() {
    FileEventKey = open( "/dev/input/event7", O_RDONLY );
    if (FileEventKey == -1) {
        std::cout << "Error: can not open '/dev/input/event7'" << std::endl;
        perror( "open" );
        exit(0);
    }
}
std::optional<input_event> InputManager::GetKeyPressed() const {
    input_event key{};
    if (const ssize_t result = read( FileEventKey, &key, sizeof(key) ); result == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            return std::nullopt;
        }
        else {
            throw CantReadKeyError("can not read key");
        }
    }
    else if (result == sizeof(key)) {
        return key;
    }
    return std::nullopt;
}

InputManager::~InputManager() {
    if (FileEventKey != -1) {
        close(FileEventKey);
    }
}