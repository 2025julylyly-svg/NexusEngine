cmake_minimum_required(VERSION 4.3)
project(NexusEngine)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
        NexusEngine main.cpp
        Library/VectorDataStruct/VECTOR/EmptySnakeBodyDataStructError.cpp
        Library/VectorDataStruct/VECTOR/NotFoundElementError.cpp
        Library/VectorDataStruct/VECTOR/InvalidInputError.cpp
        Library/STRING/Library/String/Error/IndexOutofReangeError/IndexOutofrange.cpp
        Library/STRING/Library/String/MAIN/String.cpp
        Library/QUEUE/Library/QueueFiles/Errors/IsEmptyQueueError.cpp
        Library/MapingData/MAP/NotFoundKeyError.cpp
        Library/MapingData/MAP/NotFoundKeyError.h
        Library/MapingData/MAP/map.h
        Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h
        Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.cpp
        Engine/Controls/Error/InputError/CantReadKeyError.h
        Engine/Controls/Error/InputError/CantReadKeyError.cpp
        Engine/Actors/Shapes/CircleShape/Circle.h
        Engine/Actors/Shapes/CircleShape/Circle.cpp
        Engine/Systems/Window/WindowSystem.cpp
        Engine/Systems/Window/WindowSystem.h
        Engine/Actors/Shapes/RectangleShape/Rectangle.cpp
        Engine/Actors/Shapes/RectangleShape/Rectangle.h
        Engine/Systems/Collision/SpatioalHashingGrid/BoardPhase/GridWindow.cpp
        Engine/Systems/Collision/SpatioalHashingGrid/BoardPhase/GridWindow.h
)

target_include_directories(NexusEngine PRIVATE
        Library/MapingData/MAP
        Library/VectorDataStruct/VECTOR
        Library/STRING/Library/String/MAIN
        Library/QUEUE/Library/QueueFiles/MAIN)

target_link_libraries(NexusEngine PRIVATE sfml-graphics sfml-window sfml-system)