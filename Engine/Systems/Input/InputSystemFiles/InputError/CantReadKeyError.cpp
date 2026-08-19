#include "CantReadKeyError.h"
CantReadKeyError::CantReadKeyError(const char* message) : std::logic_error( message ) {}