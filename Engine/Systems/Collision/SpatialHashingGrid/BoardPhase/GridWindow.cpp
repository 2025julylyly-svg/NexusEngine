#include "GridWindow.h"

CreateGridWindow::CreateGridWindow(const int WS /* width screen */, const int HS /* height screen */) {
    WidthScreen = WS;
    HeightScreen = HS;
    this->init(cells);
}
void CreateGridWindow::init(Vector<Vector<cell>>& other) const {
    if (other.Size() != 0) {
        return;
    }
    for (int y = 0; y < HeightScreen; y += CELL_SIZE) {
        other.Append(Vector<cell>());
        for (int x = 0; x < WidthScreen; x += CELL_SIZE) {
            other[y == 0 ? 0 : y / CELL_SIZE].Append(cell());
        }
    }
}
Vector<Vector<CreateGridWindow::cell>> CreateGridWindow::CreateGrid(const Vector<Shape*>& shapes) const {
    Vector<Vector<cell>> GRID;
    init(GRID);
    for (Shape* shape : shapes) {
        for (int point = 0; point < shape->getPointCount(); ++point) {
            const float X = shape->getPoint(static_cast<std::size_t>(point)).x;
            const float Y = shape->getPoint(static_cast<std::size_t>(point)).y;
            GRID[static_cast<int>(Y) / CELL_SIZE][static_cast<int>(X) / CELL_SIZE].shapes.Append( { .x = X, .y = Y, .PTR_TO_SHAPE = shape } );
        }
    }
    return GRID;
}
void CreateGridWindow::AddShape(Shape* shape) {
    for (int point = 0; point < shape->getPointCount(); ++point) {
        const float X = (shape->getPoint(static_cast<std::size_t>(point)).x);
        const float Y = (shape->getPoint(static_cast<std::size_t>(point)).y);
        cells[static_cast<int>(Y) / CELL_SIZE][static_cast<int>(X) / CELL_SIZE].shapes.Append( { .x = X, .y = Y, .PTR_TO_SHAPE = shape } );
    }
}

void CreateGridWindow::Update(const Vector<Shape*>& shapes) {
    if (const Vector<Vector<cell>> NewGrid = this->CreateGrid(shapes); NewGrid == cells) {
        return;
    } else {
        cells = NewGrid;
    }
}
