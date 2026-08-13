cmake_minimum_required(VERSION 4.3)
project(NexusEngine)

set(CMAKE_CXX_STANDARD 26)

add_executable(NexusEngine main.cpp
Library/VectorDataStruct/VECTOR/EmptySnakeBodyDataStructError.cpp
Library/VectorDataStruct/VECTOR/NotFoundElementError.cpp
Library/VectorDataStruct/VECTOR/InvalidInputError.cpp
Library/STRING/Library/String/Error/IndexOutofReangeError/IndexOutofrange.cpp
Library/STRING/Library/String/MAIN/String.cpp
Library/QUEUE/Library/QueueFiles/Errors/IsEmptyQueueError.cpp
Library/MapingData/MAP/NotFoundKeyError.cpp)
target_include_directories(NexusEngine PRIVATE
Library/MapingData/MAP
Library/VectorDataStruct/VECTOR
Library/STRING/Library/String/MAIN
Library/QUEUE/Library/QueueFiles/MAIN)
