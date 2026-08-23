#pragma once
#include <cstdlib>
#include "../../Engine/Actors/Shapes/CircleShape/Circle.h"
#include "../../Engine/Actors/Shapes/RectangleShape/Rectangle.h"
#include "../BoardPhase/GridWindow.h"
class CheckColl
{
private:
    CreateGridWindow CGW;
    enum class Shape_Type
    {
        Shape,
        Circle,
        Rectangle,
        Polygon
    };

private: // functions
    static Set<sf::Shape*> Cleaning(const Set<sf::Shape*>&, const Shape_Type&);

public:
    Set<sf::Shape*> CircleCircle(const sf::Shape*);
    Set<sf::Shape*> CircleRectangle(sf::Shape*);
    Set<sf::Shape*> CirclePolygon(sf::Shape*);
    Set<sf::Shape*> RectangleRectangle(Rectangle*);
    Set<sf::Shape*> RectanglePolygon(Rectangle*);
    Set<sf::Shape*> PolygonPolygon(sf::Shape*);
};
