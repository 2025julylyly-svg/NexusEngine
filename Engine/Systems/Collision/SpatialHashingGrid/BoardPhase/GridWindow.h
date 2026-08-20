#pragma once
#include <fcntl.h>
#include <map.h>
#include <Vector.h>
#include "../../../../Actors/Shapes/Shape/Shape.h"

class CreateGridWindow final
{
private: // structures
    struct shape
    {
        float x;
        float y;
        Shape* PTR_TO_SHAPE;
    };

    struct cell
    {
        Vector<shape> shapes;
        cell() = default;

        cell(const float x, const float y, Shape* ptr) {
            shapes.Append( { .x = x, .y = y, .PTR_TO_SHAPE = ptr } );
        }
    };

private: // enumeration
    // MU = Move Up, MD = Move Down, ML = Move Left, MR = Move Right
    enum MoveDirection { MU, MD, ML, MR };
private: // data
    const int CELL_SIZE = 20;
    int WidthScreen, HeightScreen;
    Vector<Vector<cell>> cells;

private: // private functions
    void InitializeCells();

public:
    explicit CreateGridWindow(int, int);
    void AddShape(Shape*);
    void Update(Shape*);
};
