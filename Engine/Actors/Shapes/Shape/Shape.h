#pragma once
#include <typeinfo>
#include <SFML/Graphics.hpp>
class ABS_SHAPE : public sf::Shape
{
public:
    virtual void SetSpeed(float) = 0;
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
    virtual void MoveUp() = 0;
    virtual void MoveDown() = 0;
    virtual float GetSpeed() const = 0;
    virtual bool operator==(ABS_SHAPE*) const = 0;
};
