#include "NotFoundKeyError.h"

NotFoundKeyError::NotFoundKeyError( const std::string& Message) : std::runtime_error(Message) {}
