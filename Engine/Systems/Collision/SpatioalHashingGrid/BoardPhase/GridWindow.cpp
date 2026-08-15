#include "GridWindow.h"

GridWindow::GridWindow(float W, float H, const Vector<sf::Shape>& shapes) : WidthScreen( W ), HeightScreen( H ) {
    for (int y = 0; static_cast<float>(y) < H; y += 30) {
        for (int x = 0; static_cast<float>(x) < W; x += 30) {
            std::string key = std::to_string( x ) + '-' + std::to_string( y );

        }
    }
}
