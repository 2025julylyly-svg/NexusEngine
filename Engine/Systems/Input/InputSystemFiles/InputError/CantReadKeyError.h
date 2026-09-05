#pragma once
#include <exception>
#include <stdexcept>
#define CANT_OPEN_FILE (-1)
#define NOT_AVAILABLE_EVENT_FOR_READ (-1)
class CantReadKeyError final : public std::logic_error
{
public:
    explicit CantReadKeyError(const char* );
};