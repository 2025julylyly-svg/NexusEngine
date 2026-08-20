#pragma once
#include <Vector.h>
#include <SFML/Graphics.hpp>
#include "../../Engine/Actors/Shapes/Shape/Shape.h"

class Circle : public sf::CircleShape, public Shape
{
private:
    sf::CircleShape circle;
    float Speed;

public:
    explicit Circle(float /* X : position */, float /* Y : position */);
    void SetSpeed(float) override;
    float GetSpeed() const override;
    void MoveUp() override;
    void MoveDown() override;
    void MoveLeft() override;
    void MoveRight() override;
};
