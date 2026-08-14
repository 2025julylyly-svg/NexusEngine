#pragma once
#include <SFML/Graphics.hpp>

class Circle final
{
private:
    sf::CircleShape circle;
    float Speed;

public:
    explicit Circle(float /* X : position */, float /* Y : position */);
    void SetSpeed(float);
    void SetColor(uint8_t, uint8_t, uint8_t, float /* state : without outliner if state == 0 */);
    void SetRadius(float);
    void SetPos(float, float);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
};
