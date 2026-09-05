#pragma once
#include "../Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.h"
#include "../Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"

class WS;

class GameLogic
{
protected:
    CheckColl* CollisionChecker {};
    WS* Window {};
    ReadInputKeyboard* Input {};

public:
    explicit GameLogic();
    void Set(CheckColl* CollisionCheckerPTR, WS* WindowPTR, ReadInputKeyboard* InputPTR);
    virtual void Main() const = 0;
};
