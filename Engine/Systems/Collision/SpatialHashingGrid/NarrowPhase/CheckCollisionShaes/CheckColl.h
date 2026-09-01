#pragma once
#include "../../BoardPhase/GridWindow.h"
#include "../../Engine/Actors/Shapes/CircleShape/Circle.h"
#include "../../Engine/Actors/Shapes/PolygonShape/Polygon.h"
#include "../../Engine/Actors/Shapes/RectangleShape/Rectangle.h"
#include "../shape_is/__shapes_is__.h"

class CheckColl {
private:
    CreateGridWindow CGW;
    enum class Shape_Type { Shape, Circle, Rectangle, Polygon };

private: // static functions
    static Set<sf::Shape*> Filter(const Set<sf::Shape*>&, const Shape_Type&);
private: // private classes
    class Point
    {
    public:
        static Vector<VecPos> GetClosestPointsOnSidesOfSqToCircle(const Rectangle*, const Circle*);
        static VecPos GetClosestPointOnSqToCircle(const Vector<VecPos>&, const Circle*);
    };
public:
    explicit CheckColl();
    explicit CheckColl(const int&, const int&);
    void set(sf::Shape*, sf::Shape*);
    Set<sf::Shape*> CircleCircle(sf::Shape*) const;
    Set<sf::Shape*> CircleRectangle(sf::Shape*) const;
    Set<sf::Shape*> CirclePolygon(sf::Shape*);
    Set<sf::Shape*> RectangleRectangle(Rectangle*);
    Set<sf::Shape*> RectanglePolygon(Rectangle*);
    Set<sf::Shape*> PolygonPolygon(sf::Shape*);
};
