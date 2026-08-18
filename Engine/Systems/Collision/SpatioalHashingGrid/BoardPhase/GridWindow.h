#pragma once
#include <map.h>
#include <Vector.h>
#include <SFML/Graphics.hpp>

class CreateShapeOnGridWindow final
{
private:
    int WidthScreen, HeightScreen;
    Vector<Vector<Vector<float>>> Cells;
    std::unordered_map<sf::Shape*, Vector<sf::Shape*>> ShapeAndShapesOnAsideShape;
private: // private functions
    const Vector<Vector<float>>& GetPointPositions(sf::Shape*);

public:
    explicit CreateShapeOnGridWindow(int, int);
    explicit CreateShapeOnGridWindow(const Vector<sf::Shape*>&);
    void Set_Cells(int, int);
    void Set_ShapeAndShapesOnAsideShape(const Vector<sf::Shape*>&);
    void Update_ShapeAndShapesOnAsideShape();
};
