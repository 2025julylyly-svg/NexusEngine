#include "ReadInputKey.h"

ReadInputKeyboard::ReadInputKeyboard() {
    FileEventKeyboard = open( "/dev/input/by-id/usb-SEMICO_USB_Keyboard-event-kbd", O_RDONLY | O_NONBLOCK );
    if (FileEventKeyboard == CANT_OPEN_FILE) {
        std::cout << "Error: can not open '/dev/input/by-id/usb-SEMICO_USB_Keyboard-event-kbd'" << std::endl;
        perror( "open" );
        exit( 0 );
    }
    for (unsigned int i = 0; i <= 125; ++i) {
        KeyPressed[i] = false;
        KeyHeld[i] = false;
        KeyReleased[i] = false;
    }
}

void ReadInputKeyboard::GetKeyInputEvent() {
    input_event key {};
    while (true) {
        if (const ssize_t result = read( FileEventKeyboard, &key, sizeof(key) );
            result != NOT_AVAILABLE_EVENT_FOR_READ) {
            NeedToChangeValueToFalse.push_back( key.code );
            if (key.type == EV_KEY) {
                ///// Keyboard input event //////
                if (key.value == 0) {
                    KeyPressed[key.code] = false;
                    KeyHeld[key.code] = false;
                    KeyReleased[key.code] = true;
                    return;
                } else if (key.value == 1) {
                    KeyPressed[key.code] = true;
                    return;
                } else if (key.value == 2) {
                    KeyHeld[key.code] = true;
                    return;
                }
                ///// Mouse input event
            }
        } else {
            break;
        }
    }
}


bool ReadInputKeyboard::IsKeyPressed(const unsigned short int KeyCode) {
    return KeyPressed[KeyCode];
}

bool ReadInputKeyboard::IsKeyHeld(const unsigned short int KeyCode) {
    return KeyHeld[KeyCode];
}

bool ReadInputKeyboard::IsKeyReleased(const unsigned short int KeyCode) {
    return KeyReleased[KeyCode];
}

unsigned short int ReadInputKeyboard::GetKeyPressed() {
    for (unsigned short int i = 0; i <= 125; ++i) {
        if (KeyPressed[i]) {
            return i;
        }
    }
    return 0;
}

unsigned short int ReadInputKeyboard::GetKeyHeld() {
    for (unsigned short int i = 0; i <= 125; ++i) {
        if (KeyHeld[i]) {
            return i;
        }
    }
    return 0;
}

unsigned short int ReadInputKeyboard::GetKeyReleased() {
    for (unsigned short int i = 0; i <= 125; ++i) {
        if (KeyReleased[i]) {
            return i;
        }
    }
    return 0;
}

void ReadInputKeyboard::Reset() {
    for (const auto& KeyNumber : NeedToChangeValueToFalse) {
        KeyPressed[KeyNumber] = false;
        KeyHeld[KeyNumber] = false;
        KeyReleased[KeyNumber] = false;
    }
    NeedToChangeValueToFalse.clear();
}

ReadInputKeyboard::~ReadInputKeyboard() {
    if (FileEventKeyboard != -1) {
        close( FileEventKeyboard );
    }
}

/**
 * Constructor for the ReadInputMouse class.
 * Initializes the MouseState map with two states, Before and Current, both set to false.
 */

ReadInputMouse::ReadInputMouse() {
    FileEventMouse = open( "/dev/input/by-id/usb-INSTANT_USB_GAMING_MOUSE-event-mouse",
                           O_RDONLY | O_NONBLOCK );
    if (FileEventMouse == CANT_OPEN_FILE) {
        std::cout << "Error: can not open '/dev/input/by-id/usb-INSTANT_USB_GAMING_MOUSE-event-mouse'" <<
            std::endl;
        perror( "open" );
        exit( 0 );
    }
    MouseState[ReadInputMouse::STATE::Before] = false;
    MouseState[ReadInputMouse::STATE::Current] = false;
}

VecPos ReadInputMouse::GetMousePosition() {
    return { static_cast<float>(sf::Mouse::getPosition().x), static_cast<float>(sf::Mouse::getPosition().y) };
}

ReadInputMouse::~ReadInputMouse() {
    if (FileEventMouse != -1) {
        close( FileEventMouse );
    }
}
