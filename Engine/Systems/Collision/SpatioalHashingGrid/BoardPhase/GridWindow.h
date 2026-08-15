#pragma once
#include <map.h>
#include <Vector.h>
#include <vector>
#include <SFML/Graphics.hpp>

class GridWindow final
{
private:
    float WidthScreen, HeightScreen;
    Vector<Vector<sf::Shape*>> state;
public:
    explicit GridWindow(float,float);
    void Reset();
    void Rebase();
    void Update();
};
