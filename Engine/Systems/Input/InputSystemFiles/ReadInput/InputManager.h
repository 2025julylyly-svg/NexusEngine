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
#include "../../InputError/CantReadKeyError.h"
class ReadInputManager
{
private:
    int FileEventKey;
public:
    ReadInputManager();
    [[nodiscard]] std::optional<input_event> GetKeyInputEvent();
    ~ReadInputManager();
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
 * 43 = z
 * 44 = x
 * 45 = c
 * 46 = v
 * 47 = b
 * 48 = n
 * 49 = m
 * 50 = ,
 * 51 = .
 * 52 = /
 * 53 = right shift
 */