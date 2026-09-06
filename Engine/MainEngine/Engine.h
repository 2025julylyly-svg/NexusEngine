#pragma once
#include "../Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.h"
#include "../Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"
#include "../Systems/Input/InputSystemFiles/InputManager/inputManager.h"
#include "../Systems/Window/WindowSystem.h"
#include "../UserGameLogic/GameLogic.h"

class Engine
{
private:
    unsigned int fps = 60.0f;
    Vector<sf::Shape*> Shapes;
    WS window;
    ReadInputKeyboard input;
    CheckColl collision;
private: // private functions
    void UpdateGameState();
    void Free();

public:
    explicit Engine();
    void CreateShape(sf::Shape*);
    void CreateWindow(const VecPos&, const unsigned int&);
    void Run(GameLogic*);
    ~Engine();
};
