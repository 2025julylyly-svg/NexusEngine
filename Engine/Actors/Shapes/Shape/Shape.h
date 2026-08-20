#pragma once
#include <SFML/Graphics.hpp>
class Shape : public sf::Shape
{
public:
    virtual void SetSpeed(float) = 0;
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
    virtual void MoveUp() = 0;
    virtual void MoveDown() = 0;
    virtual float GetSpeed() const = 0;
};
