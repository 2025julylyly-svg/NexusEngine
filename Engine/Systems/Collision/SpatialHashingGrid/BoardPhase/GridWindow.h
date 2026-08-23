#pragma once
#include <HashMap.h>
#include <Map.h>
#include <VecPos.h>
#include <Vector.h>
#include <fcntl.h>
#include <set>
#include <Set.h>
#include <SFML/Graphics.hpp>

class CreateGridWindow final
{
private: // structures

    struct cell
    {
        Vector<sf::Shape*> shapes;
        cell() = default;

        explicit cell(sf::Shape* ptr) {
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
    [[nodiscard]] Vector<Vector<cell>> CreateGrid(const Vector<sf::Shape*>&);
    void init(Vector<Vector<cell>>&);
    [[nodiscard]] bool IsPointOutOfBounds(const VecPos&) const;
    static void SetGlobalBounds(float&, float&, float&, float&, const sf::FloatRect&);
    static void SetToGrid(Vector<Vector<cell>>&,const int&, const int&, const int&, const int&, sf::Shape*);
    void SetToCells(const int&, const int&, const int&, const int&, sf::Shape*);
    Set<sf::Shape*> GetShapesInThisSection(const int&, const int&, const int&, const int&);
public:
    explicit CreateGridWindow(int, int);
    void AddShape(sf::Shape*);
    Set<sf::Shape*> Query(const sf::Shape* );
    void Update(const Vector<sf::Shape*>&);
};
