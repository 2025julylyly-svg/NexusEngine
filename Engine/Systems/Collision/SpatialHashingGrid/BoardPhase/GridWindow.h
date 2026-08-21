#pragma once
#include <HashMap.h>
#include <Map.h>
#include <VecPos.h>
#include <Vector.h>
#include <fcntl.h>
#include "../../../../Actors/Shapes/Shape/Shape.h"

class CreateGridWindow final
{
private: // structures
    struct shape
    {
        Shape* PTR_TO_SHAPE;
        bool operator==(const shape& other) const {
            return PTR_TO_SHAPE == other.PTR_TO_SHAPE;
        }
    };

    struct cell
    {
        Vector<shape> shapes;
        cell() = default;

        explicit cell(Shape* ptr) {
            shapes.Append({.PTR_TO_SHAPE = ptr });
        }
        bool operator==(const cell& other) const {
            return shapes.operator==(other.shapes);
        }
    };

private: // data
    const int CELL_SIZE = 10;
    int WidthScreen, HeightScreen;
    Vector<Vector<cell>> cells;

private: // private functions
    [[nodiscard]] Vector<Vector<cell>> CreateGrid(const Vector<Shape*>&);
    void init(Vector<Vector<cell>>&);
    [[nodiscard]] bool IsPointOutOfBounds(const VecPos&) const;
    static void SetGlobalBounds(float&, float&, float&, float&, const sf::FloatRect&);
    static void SetToGrid(Vector<Vector<cell>>&,const int&, const int&, const int&, const int&, Shape*);
    void SetToCells(const int&, const int&, const int&, const int&, Shape*);

public:
    explicit CreateGridWindow(int, int);
    void AddShape(Shape*);
    Vector<Shape*> Query(Shape* );
    void Update(const Vector<Shape*>&);
};
