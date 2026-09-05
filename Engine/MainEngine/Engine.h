#pragma once
#include "../Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.h"
#include "../Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#include "../Systems/Window/WindowSystem.h"

class Engine
{
private:
    WS window;
    Vector<sf::Shape*> Shapes;
    void UpdateGameState();

public:
    ReadInput input;
    CheckColl collision;
    explicit Engine();
    void CreateShape(sf::Shape*);
    void CreateWindow(const VecPos&);
    void Run();
    ~Engine();
};
