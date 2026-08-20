#pragma once
#include <exception>
#include <stdexcept>
#include <string>
class NotFoundKeyError final : public std::runtime_error
{
public:
    explicit NotFoundKeyError(const std::string&);
};