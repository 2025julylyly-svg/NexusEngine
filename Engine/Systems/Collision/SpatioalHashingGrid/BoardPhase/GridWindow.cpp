#include "GridWindow.h"

GridWindow::GridWindow(float W, float H, Vector<sf::Shape> shapes) : WidthScreen( W ), HeightScreen( H ) {
    std::string key;
    for (int y = 0; y < H; y += 30) {
        for (int x = 0; x < W; x += 30) {
            key = std::to_string(x) + '-' + std::to_string(y);

        }
    }
}

void GridWindow::Reset() {

}
