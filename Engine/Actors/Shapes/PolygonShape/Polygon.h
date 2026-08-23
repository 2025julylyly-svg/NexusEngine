#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
class Polygon final : public sf::ConvexShape
{
private:
    sf::ConvexShape CVX;
    float Speed{};
public:
    Polygon();
    explicit Polygon(const std::size_t&);
    explicit Polygon(const std::size_t&, const float&);
    void SetSpeed(const float&);
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
};
