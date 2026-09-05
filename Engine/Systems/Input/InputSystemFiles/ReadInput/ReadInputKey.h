#pragma once
#include <HashMap.h>
#include <vector>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "VecPos.h"
#include "../../../Engine/Systems/Input/InputSystemFiles/InputError/CantReadKeyError.h"

class ReadInputKeyboard
{
private:
    int FileEventKeyboard;
    Mapping::HashMap<unsigned short int, bool> KeyPressed;
    Mapping::HashMap<unsigned short int, bool> KeyHeld;
    Mapping::HashMap<unsigned short int, bool> KeyReleased;
    std::vector<unsigned short int> NeedToChangeValueToFalse;

public:
    ReadInputKeyboard();
    void GetKeyInputEvent();
    bool IsKeyPressed(unsigned short int);
    bool IsKeyHeld(unsigned short int);
    bool IsKeyReleased(unsigned short int);
    unsigned short int GetKeyPressed();
    unsigned short int GetKeyHeld();
    unsigned short int GetKeyReleased();
    /*
     * Reset keyboard input events
     *
     * This function resets all keyboard input events such as KeyPressed, KeyHeld, and KeyReleased.
     * It also clears the list of keys that need to change their values.
     */
    void Reset();
    ~ReadInputKeyboard();
};

class ReadInputMouse
{
private:
    enum STATE : unsigned short int
    {
        Before,
        Current
    };
private:
    int FileEventMouse;
    Mapping::HashMap<unsigned short int, bool> MouseState;
public:
    explicit ReadInputMouse();
    static VecPos GetMousePosition();
    ~ReadInputMouse();
};
