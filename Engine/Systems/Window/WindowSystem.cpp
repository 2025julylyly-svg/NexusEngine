#include "WindowSystem.h"

WS::WS() {
    this->SetScreenFillColor( { 0, 0, 0 } );
}

void WS::SetScreenFillColor(const VecCol& TargetColor) {
    ScreenFillColor = { TargetColor.B, TargetColor.G, TargetColor.R };
}

sf::Color WS::GetScreenFillColor() const {
    return ScreenFillColor;
}
