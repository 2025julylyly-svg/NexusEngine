#pragma once
#include <cstdlib>
#include <fcntl.h>
#include <optional>
#include <map.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <linux/input.h>
#include "../InputError/CantReadKeyError.h"
class InputManager
{
private:
    int FileEventKey;
    Mapping::Map<unsigned int, bool> KeyState; // true : pressed, false : released
public:
    InputManager();
    [[nodiscard]] bool GetKeyState(const unsigned int&);
    [[nodiscard]] bool GetKeyState(const unsigned int&&);
    [[nodiscard]] bool GetKeyState(input_event);
    ~InputManager();
};
/*
 * 1 = esc
 * 2 = number 1
 * 3 = number 2
 * ...
 * 10 = number 9
 * 11 = number 0
 * 12 = -
 * 13 = ( = )
 * 14 = backspace
 * 15 = tab
 * 16 = q
 * 17 = w
 * 18 = e
 * 19 = r
 * 20 = t
 * 21 = y
 * 22 = u
 * 23 = i
 * 24 = o
 * 25 = p
 * 26 = [
 * 27 = ]
 * 28 = enter
 * 29 = left ctrl
 * 30 = a
 * 31 = s
 * 32 = d
 * 33 = f
 * 34 = g
 * 35 = h
 * 36 = j
 * 37 = k
 * 38 = l
 * 39 = ;
 * 40 = '
 */