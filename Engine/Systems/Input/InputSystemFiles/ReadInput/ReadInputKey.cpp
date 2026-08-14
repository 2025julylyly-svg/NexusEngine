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
        KeyHeld[i] = false;
        KeyReleased[i] = false;
    }
}

void ReadInput::GetKeyInputEvent() {
    input_event key {};
    if (read( FileEventKey, &key, sizeof(key) ) != sizeof(key)) {
        return;
    }
    if (key.value == 0) {
        KeyPressed[key.code] = false;
        KeyHeld[key.code] = false;
        KeyReleased[key.code] = true;
    } else if (key.value == 1) {
        KeyPressed[key.code] = true;
    } else if (key.value == 2) {
        KeyHeld[key.code] = true;
    }
}

bool ReadInput::IsKeyPressed(const unsigned short int KeyCode) {
    return KeyPressed[KeyCode];
}

bool ReadInput::IsKeyHeld(const unsigned short int KeyCode) {
    return KeyHeld[KeyCode];
}

bool ReadInput::IsKeyReleased(const unsigned short int KeyCode) {
    return KeyReleased[KeyCode];
}

unsigned short int ReadInput::GetKeyPressed() {
    for (unsigned short int i = 1; i <= 125; ++i) {
        if (KeyPressed[i]) {
            return i;
        }
    }
    return 0;
}

unsigned short int ReadInput::GetKeyHeld() {
    for (unsigned short int i = 1; i <= 125; ++i) {
        if (KeyHeld[i]) {
            return i;
        }
    }
    return 0;
}

unsigned short int ReadInput::GetKeyReleased() {
    for (unsigned short int i = 1; i <= 125; ++i) {
        if (KeyReleased[i]) {
            return i;
        }
    }
    return 0;
}

void ReadInput::Reset() {
    for (unsigned int i = 1; i <= 125; ++i) {
        KeyPressed[i] = false;
        KeyHeld[i] = false;
        KeyReleased[i] = false;
    }
}

ReadInput::~ReadInput() {
    if (FileEventKey != -1) {
        close( FileEventKey );
    }
}
