#pragma once
#include "../Systems/Collision/SpatialHashingGrid/NarrowPhase/CheckCollisionShaes/CheckColl.h"
#include "../Systems/Input/InputSystemFiles/ReadInput/ReadInputKey.h"

class WS;
/**
 * @class GameLogic
 * @brief Abstract base class for game logic implementation.
 *
 * This class defines the interface for game logic, including setting dependencies and
 * the main game loop.
 *
 * @note Concrete implementations of this class should provide a definition for the `Main` method.
 */
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
