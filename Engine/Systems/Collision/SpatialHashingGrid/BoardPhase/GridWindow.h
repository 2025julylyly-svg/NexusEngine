#pragma once
#include <HashMap.h>
#include <Map.h>
#include <VecPos.h>
#include <Vector.h>
#include <fcntl.h>
#include <set>
#include <Set.h>
#include "../../../../Actors/Shapes/Shape/Shape.h"

class CreateGridWindow final
{
private: // structures
    /*struct shape
    {
        ABS_SHAPE* PTR_TO_SHAPE;
        bool operator==(const shape& other) const {
            return PTR_TO_SHAPE == other.PTR_TO_SHAPE;
        }
    };*/

    struct cell
    {
        Vector<ABS_SHAPE*> shapes;
        cell() = default;

        explicit cell(ABS_SHAPE* ptr) {
            shapes.Append(ptr);
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
    [[nodiscard]] Vector<Vector<cell>> CreateGrid(const Vector<ABS_SHAPE*>&);
    void init(Vector<Vector<cell>>&);
    [[nodiscard]] bool IsPointOutOfBounds(const VecPos&) const;
    static void SetGlobalBounds(float&, float&, float&, float&, const sf::FloatRect&);
    static void SetToGrid(Vector<Vector<cell>>&,const int&, const int&, const int&, const int&, ABS_SHAPE*);
    void SetToCells(const int&, const int&, const int&, const int&, ABS_SHAPE*);
    Set<ABS_SHAPE*> GetShapesInThisSection(const int&, const int&, const int&, const int&);
public:
    explicit CreateGridWindow(int, int);
    void AddShape(ABS_SHAPE*);
    Set<ABS_SHAPE*> Query(const ABS_SHAPE* );
    void Update(const Vector<ABS_SHAPE*>&);
};
