#pragma once
#include <Vector.h>
#include <SFML/Graphics.hpp>

class Circle final : public sf::CircleShape
{
private:
    sf::CircleShape circle;
    float Speed;

public:
    explicit Circle(float /* X : position */, float /* Y : position */);
    void SetSpeed(float);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
};
