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
    float Speed{};
    float MaxPosX{}, MaxPosY{};
    float MinPosX{}, MinPosY{};
    Vector<pos> PointPositions;
public:
    explicit Rectangle();
    explicit Rectangle(float, float, float, float, float, float, float, float);
    explicit Rectangle(const Rectangle&);
    explicit Rectangle(Rectangle&&) noexcept;
    void SetSpeed(float);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
};