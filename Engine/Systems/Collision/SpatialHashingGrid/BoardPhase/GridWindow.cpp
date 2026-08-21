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
    if (*point.x < 0 || *point.x > static_cast<float>(WidthScreen) || *point.y < 0 || *point.y > static_cast<float>(HeightScreen)) {
        return true;
    }
    return false;
}
void CreateGridWindow::SetGlobalBounds(float& MI_X, float& MA_X, float& MI_Y, float& MA_Y, const sf::FloatRect& bound) {
    MI_X = bound.position.x;
    MA_X = bound.position.x + bound.size.x;
    MI_Y = bound.position.y;
    MA_Y = bound.position.y + bound.size.y;
}
void CreateGridWindow::SetToGrid(Vector<Vector<cell>>& GRID,const int& MinCol, const int& MaxCol, const int& MinRow, const int& MaxRow, Shape* shape) {
    for (int row = MinRow; row <= MaxRow; ++row) {
        for (int col = MinCol; col <= MaxCol; ++col) {
            GRID[row][col].shapes.Append({ shape });
        }
    }
}
Vector<Vector<CreateGridWindow::cell>> CreateGridWindow::CreateGrid(const Vector<Shape*>& shapes) {
    Vector<Vector<cell>> GRID;
    init(GRID);
    const int MaxColIndex = (WidthScreen / CELL_SIZE) - 1;
    const int MaxRowIndex = (HeightScreen / CELL_SIZE) - 1;
    for (Shape* shape : shapes) {
        if (!shape)
            continue;
        const sf::FloatRect& Bounds = shape->getGlobalBounds();
        float minx, maxx, miny, maxy;
        CreateGridWindow::SetGlobalBounds(minx, maxx, miny, maxy, Bounds);
        //////////////////////////////////////////////
        int MinCol = static_cast<int>(minx / static_cast<float>(CELL_SIZE));
        int MaxCol = static_cast<int>(maxx / static_cast<float>(CELL_SIZE));
        int MinRow = static_cast<int>(miny / static_cast<float>(CELL_SIZE));
        int MaxRow = static_cast<int>(maxy / static_cast<float>(CELL_SIZE));
        //////////////////////////////////////////////
        MinCol = std::max(0, MinCol);
        MaxCol = std::min(MaxCol, MaxColIndex);
        MinRow = std::min(0, MaxRow);
        MaxRow = std::max(MaxRow, MaxRowIndex);
        //////////////////////////////////////////////
        if (MinCol > MaxCol || MinRow > MaxRow)
            continue;
        CreateGridWindow::SetToGrid(GRID,MinCol, MaxCol, MinRow, MaxRow, shape);
    }
    return GRID;
}
void CreateGridWindow::AddShape(Shape* shape) {
    if (!shape)
        return;
}

void CreateGridWindow::Update(const Vector<Shape*>& shapes) {
    cells = CreateGrid(shapes);
}
