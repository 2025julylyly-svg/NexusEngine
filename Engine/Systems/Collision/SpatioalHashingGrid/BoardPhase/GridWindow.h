#pragma once
#include <unordered_map>
#include <Vector.h>
#include <string>
#include <SFML/Graphics.hpp>

class GridWindow
{
private:
    float WidthScreen, HeightScreen;
    std::unordered_map<std::string, Vector<sf::Shape>> StateOfShapes;
public:
    explicit GridWindow(float,float,Vector<sf::Shape>);
    void Reset();
    void Update();
};
