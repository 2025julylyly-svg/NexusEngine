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
    input_event key {};
    if (read( FileEventKey, &key, sizeof(key) ) != sizeof(key)) {
        return std::nullopt;
    }
    KeyState[key.code] = static_cast<bool>(key.value != 0);
    return key;
}

// This function gives you the keycode of the Pressed key.
short int ReadInput::IsKeyPressed() {
    std::optional<input_event> key = this->GetKeyInputEvent();
    if (key.has_value()) {
        if (key.value().value == 1) {
            return static_cast<short int>(key.value().code);
        }
        return -1;
    }
    return -1;
}

// This function gives you the keycode of the Held key
short int ReadInput::IsKeyHeld() {
    std::optional<input_event> key = this->GetKeyInputEvent();
    if (key.has_value()) {
        if (key.value().value == 2) {
            return static_cast<short int>(key.value().code);
        }
        return -1;
    }
    return -1;
}

// This function gives you the keycode of the Released key
short int ReadInput::IsKeyReleased() {
    std::optional<input_event> key = this->GetKeyInputEvent();
    if (key.has_value()) {
        if (key.value().value == 0) {
            return static_cast<short int>(key.value().code);
        }
        return -1;
    }
    return -1;
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

bool ReadInput::IsKeyHeld(unsigned short int KeyCode) {
    std::optional<input_event> key = this->GetKeyInputEvent();
    if (key.has_value()) {
        if (key.value().value == 2) {
            return KeyState[KeyCode] == false;
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