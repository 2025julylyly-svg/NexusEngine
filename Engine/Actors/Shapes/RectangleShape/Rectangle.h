#pragma once
#include <SFML/Graphics.hpp>
#include <Vector.h>
class Rectangle final : public sf::RectangleShape
{
private:
    sf::RectangleShape shape;
    float Speed;
    float MaxPosX, MaxPosY;
    float MinPosX, MinPosY;
public:
    explicit Rectangle(float, float, float, float);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
};