#pragma once
#include <SFML/Graphics.hpp>
#include "../../../EngineLibrary/VectorColor/VecCol.h"

class WS final : public sf::RenderWindow
{
private:
    sf::Color ScreenFillColor;

public:
    explicit WS();
    void SetScreenFillColor(const VecCol&);
    sf::Color GetScreenFillColor() const;
};
