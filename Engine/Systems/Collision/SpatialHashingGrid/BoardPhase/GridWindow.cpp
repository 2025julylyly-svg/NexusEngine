#include "GridWindow.h"

CreateGridWindow::CreateGridWindow(const int WS /* width screen */, const int HS /* height screen */) {
    WidthScreen = WS;
    HeightScreen = HS;
    this->init(cells);
}
void CreateGridWindow::init(Vector<Vector<cell>>& other) {
    if (other.Size() != 0) {
        return;
    }
    unsigned int row = 0;
    for (int y = 0; y < HeightScreen; y += CELL_SIZE) {
        other.Append(Vector<cell>());
        for (int x = 0; x < WidthScreen; x += CELL_SIZE) {
            other[row].Append(cell());
        }
        ++row;
    }
}
bool CreateGridWindow::IsPointOutOfBounds(const VecPos& point) const {
    if (*point.x < 0) {
        return true;
    } else if (*point.x > static_cast<float>(WidthScreen)) {
        return true;
    } else if (*point.y < 0) {
        return true;
    } else if (*point.y > static_cast<float>(HeightScreen)) {
        return true;
    }
    return false;
}
Vector<Vector<CreateGridWindow::cell>> CreateGridWindow::CreateGrid(const Vector<Shape*>& shapes) {
    Vector<Vector<cell>> GRID;
    init(GRID);
    for (Shape* shape : shapes) {
        if (!shape)
            continue;
        for (int point = 0; point < shape->getPointCount(); ++point) {
            const float X = shape->getPoint(static_cast<std::size_t>(point)).x;
            const float Y = shape->getPoint(static_cast<std::size_t>(point)).y;
            if (this->IsPointOutOfBounds(VecPos(X, Y))) {
                continue;
            }
            GRID[static_cast<int>(Y) / CELL_SIZE][static_cast<int>(X) / CELL_SIZE].shapes.Append({ .x = X, .y = Y, .PTR_TO_SHAPE = shape });
        }
    }
    return GRID;
}
void CreateGridWindow::AddShape(Shape* shape) {
    if (!shape)
        return;
    for (int point = 0; point < shape->getPointCount(); ++point) {
        const float X = (shape->getPoint(static_cast<std::size_t>(point)).x);
        const float Y = (shape->getPoint(static_cast<std::size_t>(point)).y);
        if (this->IsPointOutOfBounds(VecPos(X, Y))) {
            continue;
        }
        this->cells[static_cast<int>(Y) / CELL_SIZE][static_cast<int>(X) / CELL_SIZE].shapes.Append({ .x = X, .y = Y, .PTR_TO_SHAPE = shape });
    }
}

void CreateGridWindow::Update(const Vector<Shape*>& shapes) {
    cells = CreateGrid(shapes);
}
