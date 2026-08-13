#pragma once
#include <Vector.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
class InputManager
{
private:
    Vector<bool> KeyBinding;
public:
    InputManager();
    ~InputManager();
};