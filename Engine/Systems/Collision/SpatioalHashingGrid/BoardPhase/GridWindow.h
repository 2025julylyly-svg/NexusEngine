#pragma once
#include <map.h>
#include <Vector.h>
#include <SFML/Graphics.hpp>

class GridWindow
{
private:
    float WidthScreen, HeightScreen;
    Mapping::Map<std::string, Vector<sf::Shape>> StateOfShapes;
public:
    explicit GridWindow(float,float,const Vector<sf::Shape>&);
    void Reset();
    void Rebase();
    void Update();
};
