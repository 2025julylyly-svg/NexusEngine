#pragma once
#include "../Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.h"
#include "../Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"

class WS;

class GameLogic
{
protected:
    CheckColl* CollisionChecker {};
    WS* Window {};
    ReadInput* Input {};

public:
    explicit GameLogic();
    void Set(CheckColl* CollisionCheckerPTR, WS* WindowPTR, ReadInput* InputPTR);
    virtual void Main() const = 0;
};
