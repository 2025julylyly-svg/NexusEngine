#include "GridWindow.h"

CreateShapeOnGridWindow::CreateShapeOnGridWindow(const int W, const int H) : WidthScreen(W), HeightScreen(H) {
    this->Set_Cells( W, H );
}

const Vector<Vector<float>>& CreateShapeOnGridWindow::GetPointPositions(sf::Shape* shape) {
    Vector<Vector<float>> points;
    std::size_t PointsOfShapeNumber = shape->getPointCount();
}

void CreateShapeOnGridWindow::Set_Cells(const int width, const int height) {
    for (int y = 0; y < height; y += 20) {
        this->Cells.Append( Vector<Vector<float>>() );
        for (int x = 0; x < width; x += 20) {
            Cells[y].Append( Vector<float>{static_cast<float>(x), static_cast<float>(y)} );
        }
    }
}

void CreateShapeOnGridWindow::Set_ShapeAndShapesOnAsideShape(const Vector<sf::Shape*>& shapes) {}
