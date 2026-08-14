#include "ReadInputKey.h"

ReadInput::ReadInput() {
    FileEventKey = open( "/dev/input/event7", O_RDONLY | O_NONBLOCK );
    if (FileEventKey == -1) {
        std::cout << "Error: can not open '/dev/input/event7'" << std::endl;
        perror( "open" );
        exit( 0 );
    }
    for (unsigned int i = 1; i <= 125; ++i) {
        KeyPressed[i] = false;
    }
}

void ReadInput::GetKeyInputEvent() {
    input_event key {};
    if (read( FileEventKey, &key, sizeof(key) ) != sizeof(key)) {
        return;
    }
    KeyPressed[key.code] = static_cast<bool>(key.value != 0);
}

bool ReadInput::IsKeyPressed(unsigned short int KeyCode) {
    return KeyPressed[KeyCode];
}

bool ReadInput::IsKeyHeld(unsigned short int KeyCode) {
    return KeyPressed[KeyCode];
}

void ReadInput::Reset() {
    for (unsigned int i = 1; i <= 125; ++i) {
        KeyPressed[i] = false;
    }
}

ReadInput::~ReadInput() {
    if (FileEventKey != -1) {
        close( FileEventKey );
    }
}