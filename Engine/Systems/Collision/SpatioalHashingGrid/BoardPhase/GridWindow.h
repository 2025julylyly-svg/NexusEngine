#pragma once
#include <fcntl.h>
#include <map.h>
#include <Vector.h>
#include <SFML/Graphics.hpp>

class CreateGridWindow final
{
private: // structures
    struct shape
    {
        float x;
        float y;
        sf::Shape* PTR_TO_SHAPE;
    };

    struct cell
    {
        Vector<shape> shapes;
        cell() = default;

        cell(const float x, const float y, sf::Shape* ptr) {
            shapes.Append( { .x = x, .y = y, .PTR_TO_SHAPE = ptr } );
        }
    };

private: // data
    int WidthScreen, HeightScreen;
    Vector<Vector<cell>> cells;

private: // private functions
    void InitializeCells();

public:
    explicit CreateGridWindow(int, int);
    void AddShape(sf::Shape*) const;
};
