#pragma once
#include "../Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.h"
#include "../Systems/Window/WindowSystem.h"

class Engine
{
private:
    WS window;
    CheckColl collision;
    void UpdateGameState();
public:
    explicit Engine();
    void CreateWindow(const VecPos&);
    void Run();
    ~Engine();
};
