#pragma once
#include <HashMap.h>
#include <vector>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "VecPos.h"
#include "../../../Engine/Systems/Input/InputSystemFiles/InputError/CantReadKeyError.h"
/**
 * @class ReadInputKeyboard
 * @brief Manages and provides information about keyboard input events and states.
 *
 * This class is designed to handle keyboard input events, track the states of individual keys,
 * and provide functions to check the current state of each key (pressed, held, released).
 * It also includes methods to retrieve the most recently pressed, held, and released keys.
 * Additionally, it provides a function to reset all keyboard input events.
 */
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

/**
 * @class ReadInputMouse
 * @brief Manages and provides information about mouse input events and states.
 *
 * This class is designed to handle mouse input events, track the states of mouse buttons,
 * and provide functions to check the current state of each mouse button (left, right, middle).
 * It also includes a function to retrieve the current mouse position.
 */
class ReadInputMouse
{
private:
    enum STATE : unsigned short int
    {
        Before, Current
    };

private:
    int FileEventMouse;
    Mapping::HashMap<unsigned short int, bool> LeftButtonState;
    Mapping::HashMap<unsigned short int, bool> RightButtonState;
    Mapping::HashMap<unsigned short int, bool> MiddleButtonState;

public:
    explicit ReadInputMouse();
    void GetMouseInputEvent();
    static VecPos GetMousePosition();
    ///////////////////////
    ///// Left Button /////
    ///////////////////////
    bool IsLeftButtonPressed();
    bool IsLeftButtonHeld();
    bool IsLeftButtonReleased();
    ////////////////////////
    ///// Right Button /////
    ////////////////////////
    bool IsRightButtonPressed();
    bool IsRightButtonHeld();
    bool IsRightButtonReleased();
    /////////////////////////
    ///// Middle Button /////
    /////////////////////////
    bool IsMiddleButtonPressed();
    bool IsMiddleButtonHeld();
    bool IsMiddleButtonReleased();
    void Update();
    ~ReadInputMouse();
};
