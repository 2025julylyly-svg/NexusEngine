#pragma once
#include <cstddef>
template <typename Key, typename Value>
class Map
{
private:
    class Box
    {
    public:
        Key key;
        Value value;
        Box() = default;
        Box(Key SetKey, Value SetValue) {
            key = SetKey;
            value = SetValue;
        }
    };
private: // data
    Box* map;
    std::size_t BoxCounter;
    std::size_t Capacity;
public:
    // Default Constructor
    explicit Map() {
        Capacity = 5;
        BoxCounter = 0;
        map = new Box[Capacity];
    }
    // Constructor To set Capacity
    explicit Map(const std::size_t SetCapacity) {
        BoxCounter = 0;
        Capacity = SetCapacity;
        map = new Box [Capacity];
    }
    // Copy Constructor
    explicit Map(const Map& other) {
        this->Capacity = other.Capacity;
        this->BoxCounter = other.BoxCounter;
        map = new Box[Capacity];
    }
};