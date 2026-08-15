#include "GridWindow.h"

GridWindow::GridWindow(float W, float H) : WidthScreen( W ), HeightScreen( H ) {
    for (int x = 0; static_cast<float>(x) < W; ++x) {
        state.Append( Vector<sf::Shape*>() );
    }
}
