#pragma once
#include <Vector.h>

#include <SFML/Graphics.hpp>

class Circle final : public sf::CircleShape {
private:
    using ULI = long int;
    sf::CircleShape circle;
    float Radius;
    float Speed{};
    float MaxPosX{}, MaxPosY{};
    float MinPosX{}, MinPosY{};

public:
    explicit Circle();
    explicit Circle(const float& /* X : position */, const float& /* Y : position */, const float&);
    explicit Circle(const float& /* X */, const float& /* Y */, const float& /* max pos x*/,
        const float& /* max pos y */, const float& /* min pos x */, const float& /* min pos y*/);
    explicit Circle(const Circle*);
    void SetSpeed(float);
    float GetSpeed() const;
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void SetMaxPosX(const float&);
    void SetMaxPosY(const float&);
    void SetMinPosX(const float&);
    void SetMinPosY(const float&);
    void SetRadius(const float& r);
    void SetPointCount(const std::size_t&);
    ULI GetPointCount() const;
    sf::Vector2f GetGeometricCenter() const;
    sf::Vector2f GetPoint(const std::size_t&) const;
    float GetRadius() const;
    bool operator==(sf::Shape*) const;
};
