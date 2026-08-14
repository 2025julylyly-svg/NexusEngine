#include "ReadInputKey.h"

ReadInput::ReadInput() {
    FileEventKey = open( "/dev/input/event7", O_RDONLY | O_NONBLOCK );
    if (FileEventKey == -1) {
        std::cout << "Error: can not open '/dev/input/event7'" << std::endl;
        perror( "open" );
        exit( 0 );
    }
    for (unsigned int i = 1; i <= 125; ++i) {
        KeyState[i] = false;
    }
}

std::optional<input_event> ReadInput::GetKeyInputEvent() {
    input_event key{};
    if (read (FileEventKey, &key, sizeof(key)) != sizeof(key)) {
        return std::nullopt;
    }
    KeyState[key.code] = key.value != 0;
    return key;
}

bool ReadInput::IsKeyPressed(unsigned short int KeyCode) {
    std::optional<input_event> key = this->GetKeyInputEvent();
    if (key.has_value()) {
        if (key.value().value == 1) {
            return KeyState[KeyCode];
        }
        return false;
    }
    return false;
}

ReadInput::~ReadInput() {
    if (FileEventKey != -1) {
        close( FileEventKey );
    }
}