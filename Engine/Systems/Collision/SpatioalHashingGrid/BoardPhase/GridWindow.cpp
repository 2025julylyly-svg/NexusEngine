#include "GridWindow.h"

CreateShapeOnGridWindow::CreateShapeOnGridWindow(const int W, const int H) : WidthScreen(W), HeightScreen(H) {
    this->Set_Cells( W, H );
}


void CreateShapeOnGridWindow::Set_Cells(const int width, const int height) {
    WidthScreen = width; HeightScreen = height;
    for (int y = 0; y < HeightScreen; y += 20) {
        Cells.Append( Vector<float>() );
        for (int x = 0; x < WidthScreen; x += 20) {
            Cells[y].Append( static_cast<float>(x) );
        }
    }
}

void CreateShapeOnGridWindow::Set_ShapeAndShapesOnAsideShape(const Vector<sf::Shape*>& shapes) {
    for (const sf::Shape* shape : shapes) {}
}
