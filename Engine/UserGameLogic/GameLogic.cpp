#include "GameLogic.h"

GameLogic::GameLogic() = default;

void GameLogic::Set(CheckColl* CollisionCheckerPTR, WS* WindowPTR, ReadInput* InputPTR) {
    CollisionChecker = CollisionCheckerPTR;
    Window = WindowPTR;
    Input = InputPTR;
}
