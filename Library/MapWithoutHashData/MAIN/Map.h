#pragma once
#include <algorithm>
#include <cassert>
#include <cstddef>
template<typename Key, typename Value>
class Map
{
private:
    class Box
    {
    public:
        Key key;
        Value value;
        Box() = default;
        explicit Box(Key SetKey) {
            key = SetKey;
            value = Value{};
        }
        explicit Box(Key SetKey, Value SetValue) {
            key = SetKey;
            value = SetValue;
        }
    };

private: // data
    Box* map;
    std::size_t BoxCounter;
    std::size_t Capacity;

private: // Functions
    void Copy(Box* other) {
        for (std::size_t i = 0; i < BoxCounter; ++i) {
            other[i] = map[i];
        }
    }

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
        map = new Box[Capacity];
    }
    // Copy Constructor
    explicit Map(const Map& other) {
        this->Capacity = other.Capacity;
        this->BoxCounter = other.BoxCounter;
        map = new Box[Capacity];
    }
    // Move Constructor
    explicit Map(Map&& other) noexcept {
        this->Capacity = other.Capacity;
        this->BoxCounter = other.BoxCounter;
        this->map = other.map;
        ////////////////////////////////////
        other.Capacity = 0;
        other.BoxCounter = 0;
        delete[] other.map;
    }
    Box* begin() {
        return map;
    }
    const Box* begin() const {
        return map;
    }
    Box* end() {
        return map + BoxCounter;
    }
    const Box* end() const {
        return map + BoxCounter;
    }
    // in this function delete all data if input argument <= BoxCounter
    void Reserve(const std::size_t& NewSize) {
        assert(NewSize > BoxCounter);
        Capacity = NewSize;
        Box* AuxiliaryMAP = new Box[Capacity];
        Copy(AuxiliaryMAP);
        delete[] map;
        map = AuxiliaryMAP;
    }
    long int found(const Key& KeyInput) {
        for (std::size_t i = 0; i < BoxCounter; ++i) {
            if (map[i].key == KeyInput) {
                return static_cast<long int>(i);
            }
        }
        return -1;
    }
    void Resize() {
        Capacity *= 2;
        Box* AuxiliaryMAP = new Box[Capacity];
        Copy(AuxiliaryMAP);
        delete[] map;
        map = AuxiliaryMAP;
    }
    Value& operator[](const Key& KeyInput) {
        if (BoxCounter >= Capacity) {
            this->Resize();
        }
        if (long int find = this->found(KeyInput); find != -1) {
            return map[find].value;
        }
        map[BoxCounter].key = KeyInput;
        map[BoxCounter].value = Value{};
        return map[BoxCounter++].value;
    }
    ~Map() {
        delete[] map;
        map = nullptr;
    }
};
