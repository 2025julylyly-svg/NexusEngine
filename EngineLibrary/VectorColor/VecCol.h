#pragma once
#include <SFML/Graphics/Color.hpp>

class VecCol
{
public:
    unsigned char R {};
    unsigned char G {};
    unsigned char B {};
    explicit VecCol();
    VecCol(unsigned char r, unsigned char g, unsigned char b);
    void SetColor(unsigned char r, unsigned char g, unsigned char b);
    void SetRed(unsigned char r);
    void SetGreen(unsigned char g);
    void SetBlue(unsigned char g);
    void ResetColor();
    [[nodiscard]] sf::Color GetColor() const;
};
