#pragma once
#include <HashMap.h>
#include <Vector.h>
#include <fcntl.h>
#include "../../../../Actors/Shapes/Shape/Shape.h"
#include <Map.h>
#include <VecPos.h>

class CreateGridWindow final
{
private: // structures
    struct shape
    {
        float x;
        float y;
        Shape* PTR_TO_SHAPE;
        bool operator==(const shape& other) const {
            return x == other.x && y == other.y && PTR_TO_SHAPE == other.PTR_TO_SHAPE;
        }
    };

    struct cell
    {
        Vector<shape> shapes;
        cell() = default;

        cell(const float x, const float y, Shape* ptr) {
            shapes.Append( { .x = x, .y = y, .PTR_TO_SHAPE = ptr } );
        }
        bool operator==(const cell& other) const {
            return shapes.operator==( other.shapes );
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
    [[nodiscard]] Vector<Vector<cell>> CreateGrid(const Vector<Shape*>&) const;
    void init(Vector<Vector<cell>>&) const;

public:
    explicit CreateGridWindow(int, int);
    void AddShape(Shape*);
    void Update(const Vector<Shape*>&);
};
