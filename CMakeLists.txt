cmake_minimum_required(VERSION 4.3)
project(NexusEngine)

set(CMAKE_CXX_STANDARD 26)

add_executable(NexusEngine main.cpp
Library/VECTOR/EmptySnakeBodyDataStructError.cpp
Library/VECTOR/InvalidInputError.cpp
Library/VECTOR/NotFoundElementError.cpp
Library/String/Error/IndexOutofReangeError/IndexOutofrange.cpp
Library/String/MAIN/String.cpp
Library/QUEUE/Errors/IsEmptyQueueError.cpp
Library/MAP/NotFoundKeyError.cpp
Library/MAP/map.h
Library/MAP/NotFoundKeyError.h
Library/QUEUE/MAIN/Queue.h
Library/String/Error/IndexOutofReangeError/IndexOutofrange.h
Library/String/MAIN/String.h
Library/VECTOR/EmptySnakeBodyDataStructError.h
Library/VECTOR/InvalidInputError.h
Library/VECTOR/NotFoundElementError.h
Library/VECTOR/Vector.h)
target_include_directories(NexusEngine PRIVATE
Library/MAP
Library/VECTOR
Library/String
Library/QUEUE)
