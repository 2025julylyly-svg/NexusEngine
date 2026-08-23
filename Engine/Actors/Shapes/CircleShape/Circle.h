#pragma once
#include <SFML/Graphics.hpp>
#include <Vector.h>

class Circle final : public sf::CircleShape
{
private:
    sf::CircleShape circle;
    float Speed{};
    float MaxPosX{}, MaxPosY{};
    float MinPosX{}, MinPosY{};

public:
    explicit Circle();
    explicit Circle(float /* X : position */, float /* Y : position */);
    explicit Circle(const float& /* X */, const float& /* Y */,
                    const float& /* max pos x*/, const float& /* max pos y */,
                    const float& /* min pos x */, const float& /* min pos y*/);

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
