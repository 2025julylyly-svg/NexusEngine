cmake_minimum_required(VERSION 4.3)
project(NexusEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
        NexusEngine main.cpp
        Library/VectorDataStruct/VECTOR/EmptySnakeBodyDataStructError.cpp
        Library/VectorDataStruct/VECTOR/NotFoundElementError.cpp
        Library/VectorDataStruct/VECTOR/InvalidInputError.cpp
        Library/STRING/Library/String/Error/IndexOutofRangeError/IndexOutofrange.cpp
        Library/STRING/Library/String/MAIN/String.cpp
        Library/QUEUE/Library/QueueFiles/Errors/IsEmptyQueueError.cpp
        Library/MappingData/MAP/NotFoundKeyError.cpp
        Library/MappingData/MAP/NotFoundKeyError.h
        Library/MappingData/MAP/HashMap.h
        Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h
        Engine/Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.cpp
        Engine/Systems/Input/InputSystemFiles/InputError/CantReadKeyError.h
        Engine/Systems/Input/InputSystemFiles/InputError/CantReadKeyError.cpp
        Engine/Actors/Shapes/CircleShape/Circle.h
        Engine/Actors/Shapes/CircleShape/Circle.cpp
        Engine/Systems/Window/WindowSystem.cpp
        Engine/Systems/Window/WindowSystem.h
        Engine/Actors/Shapes/RectangleShape/Rectangle.cpp
        Engine/Actors/Shapes/RectangleShape/Rectangle.h
        Engine/Systems/Collision/SpatialHashingGrid/BoardPhase/GridWindow.cpp
        Engine/Systems/Collision/SpatialHashingGrid/BoardPhase/GridWindow.h
        EngineLibrary/VectorPosition/VecPos.cpp
        EngineLibrary/VectorPosition/VecPos.h
        Library/MapWithoutHashData/MAIN/Map.h
        Library/Set/Set.h
        Engine/Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.cpp
        Engine/Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.h
        Library/HashSet/Hash_Set.h
        Engine/Actors/Shapes/PolygonShape/Polygon.cpp
        Engine/Actors/Shapes/PolygonShape/Polygon.h
        Engine/Systems/Collision/SpatialHashingGrid/NarrowPhase/shape_is/__shapes_is__.cpp
        Engine/Systems/Collision/SpatialHashingGrid/NarrowPhase/shape_is/__shapes_is__.h
)

target_include_directories(NexusEngine PRIVATE
        Library/MappingData/MAP
        Library/VectorDataStruct/VECTOR
        Library/STRING/Library/String/MAIN
        Library/QUEUE/Library/QueueFiles/MAIN
        EngineLibrary/VectorPosition
        Library/MapWithoutHashData/MAIN
        Library/Set)

target_link_libraries(NexusEngine PRIVATE sfml-graphics sfml-window sfml-system)