#pragma once
#include <cstdlib>
#include <fcntl.h>
#include <optional>
#include <map.h>
#include <Vector.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <linux/input.h>
#include "../../../Engine/Controls/Error/InputError/CantReadKeyError.h"

class ReadInput
{
private:
    int FileEventKey;
    Mapping::Map<unsigned short int, bool> KeyPressed;
    Mapping::Map<unsigned short int, bool> KeyHeld;
    Mapping::Map<unsigned short int, bool> KeyReleased;

public:
    ReadInput();
    void GetKeyInputEvent();
    bool IsKeyPressed(const unsigned short int&);
    bool IsKeyHeld(const unsigned short int&);
    bool IsKeyReleased(const unsigned short int&);
    unsigned short int GetKeyPressed();
    unsigned short int GetKeyHeld();
    unsigned short int GetKeyReleased();
    void Reset();
    ~ReadInput();
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
 * 41 = `
 * 42 = left shift
 * 43 = \
 * 44 = z
 * 45 = x
 * 46 = c
 * 47 = v
 * 48 = b
 * 49 = n
 * 50 = m
 * 51 = ,
 * 52 = .
 * 53 = /
 * 54 = right shift
 * 55 = *
 * 56 = left alt
 * 57 = space
 */
