#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "VecPos.h"
class Polygon final : public sf::ConvexShape
{
private:
    using li = long int;
    sf::ConvexShape CVX;
    float Speed{};
    float MaxPosX, MaxPosY;
    float MinPosX, MinPosY;
    bool CanMoveUp() const;
    bool CanMoveDown() const;
    bool CanMoveLeft() const;
    bool CanMoveRight() const;

public:
    Polygon();
    explicit Polygon(const std::size_t&);
    explicit Polygon(const std::size_t&, const float&);
    void SetSpeed(const float&);
    float GetSpeed() const;
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    void SetPointCount(const std::size_t&);
    li GetPointCount() const;
    void SetPoint(const std::size_t&, const sf::Vector2f&);
    VecPos GetPoint(const std::size_t&) const;
};
