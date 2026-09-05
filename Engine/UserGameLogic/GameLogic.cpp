#include "GameLogic.h"

GameLogic::GameLogic() = default;

void GameLogic::Set(CheckColl* CollisionCheckerPTR, WS* WindowPTR, ReadInputKeyboard* InputPTR) {
    CollisionChecker = CollisionCheckerPTR;
    Window = WindowPTR;
    Input = InputPTR;
}
