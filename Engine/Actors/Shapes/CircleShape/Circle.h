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
    bool operator==(sf::Shape*) const;
};
