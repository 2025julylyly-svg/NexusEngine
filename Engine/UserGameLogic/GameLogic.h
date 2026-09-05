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

    explicit GameLogic(ReadInput* InputPTR, WS* WindowPTR, CheckColl* CollisionCheckerPTR) :
        Input( InputPTR ), Window( WindowPTR ), CollisionChecker( CollisionCheckerPTR ) {}

    void Set(CheckColl* CollisionCheckerPTR, WS* WindowPTR, ReadInput* InputPTR);
    virtual void Main() const = 0;
    virtual void InputManaging() const = 0;
    virtual void CollisionCheckingManaging() const = 0;
};
