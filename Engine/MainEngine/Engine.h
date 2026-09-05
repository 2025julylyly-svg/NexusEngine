#pragma once
#include "../Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.h"
#include "../Systems/Window/WindowSystem.h"

class Engine
{
private:
    WS window;
    CheckColl collision;
    Vector<sf::Shape*> shapes;
public:
    explicit Engine();
};
