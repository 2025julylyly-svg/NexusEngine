#include "GridWindow.h"

CreateGridWindow::CreateGridWindow(const int WS /* width screen */, const int HS /* height screen */) {
    WidthScreen = WS;
    HeightScreen = HS;
    this->InitializeCells();
}

void CreateGridWindow::InitializeCells() {
    for (int y = 0; y < HeightScreen; y += 20) {
        cells.Append( Vector<cell>() );
    }
}

void CreateGridWindow::AddShape(sf::Shape* shape) const {
    for (int point = 0; point < shape->getPointCount(); ++point) {
        const float X = (shape->getPoint( static_cast<std::size_t>(point) ).x);
        const float Y = (shape->getPoint( static_cast<std::size_t>(point) ).y);
        cells[static_cast<int>(Y) / 20].Append( cell( X, Y, shape ) );
    }
}
