#pragma once
#include <SFML/Graphics.hpp>
#include <Vector.h>
class Rectangle final : public sf::RectangleShape
{
private:
    struct pos
    {
        float x;
        float y;
    };
    sf::RectangleShape shape;
    float Speed;
    float MaxPosX, MaxPosY;
    float MinPosX, MinPosY;
    float WidthRectShape, HeightRectShape;
    Vector<pos> PointPositions;
    void SetPointPositions();
public:
    explicit Rectangle(float, float, float, float, float, float, float, float);
    const Vector<pos>& GetPointPositions() const;
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
};