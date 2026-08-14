#pragma once
#include <exception>
#include <stdexcept>
class CantReadKeyError final : public std::logic_error
{
public:
    explicit CantReadKeyError(const char* );
};