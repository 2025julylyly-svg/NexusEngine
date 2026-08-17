#pragma once
#include <map.h>
#include <Vector.h>
#include <SFML/Graphics.hpp>

class CreateShapeOnGridWindow final
{
private:
    int WidthScreen, HeightScreen;
    Mapping::Map<sf::Shape*, Vector<sf::Shape*>> ShapeAndShapesOnAsideShape;

public:
    explicit CreateShapeOnGridWindow(int, int);
};
