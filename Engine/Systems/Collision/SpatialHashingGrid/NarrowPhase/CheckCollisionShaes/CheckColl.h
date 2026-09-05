#pragma once
#include "../../BoardPhase/GridWindow.h"
#include "../../Engine/Actors/Shapes/CircleShape/Circle.h"
#include "../../Engine/Actors/Shapes/PolygonShape/Polygon.h"
#include "../../Engine/Actors/Shapes/RectangleShape/Rectangle.h"

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

private: // static functions
    static Set<sf::Shape*> Filter(const Set<sf::Shape*>&, const Shape_Type&);

private: // private classes
    class Extract
    {
    public:
        static Vector<VecPos> ExtractPointFromShape(const sf::Shape*);
        static VecPos ExtractVector2fToVecPos(const sf::Vector2f&);
    };

    class Point
    {
    public:
        static Vector<VecPos> GetClosestPointsOnSidesOfSqToCircle(const sf::Shape*, const Circle*);
        static VecPos GetClosestPointOnSqToCircle(const Vector<VecPos>&, const Circle*);
        static bool PointIsInShape(const VecPos&, const sf::Shape*);
        static VecPos GetPoint(const sf::Vector2f&, const sf::Shape*);
    };

    class SAT
    {
    public:
        static float DotProduct(const VecPos&, const VecPos&);
        static VecPos Normalize(const VecPos&);
        static VecPos GetNormalLine(const VecPos&, const VecPos&);
        static Vector<float> GetMinAndMaxValue(const Vector<float>&);
        static Vector<float> GetPointsOfShapeOnNormalLine(const sf::Shape*, const VecPos&);
    };

public:
    explicit CheckColl();
    explicit CheckColl(const int&, const int&);
    void set(sf::Shape*);
    void INIT_CGW(const int&, const int&);
    Set<sf::Shape*> CircleCircle(sf::Shape*) const;
    Set<sf::Shape*> CircleRectangle(sf::Shape*) const;
    Set<sf::Shape*> CirclePolygon(sf::Shape*) const;
    Set<sf::Shape*> RectangleRectangle(const Rectangle*) const;
    Set<sf::Shape*> RectanglePolygon(const sf::Shape*) const;
    Set<sf::Shape*> PolygonPolygon(const sf::Shape*) const;
};
