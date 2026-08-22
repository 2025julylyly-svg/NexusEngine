#pragma once
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <typeinfo>

#include "../../Engine/Actors/Shapes/Shape/Shape.h"
template<typename elem> // elem : Element
class Set
{
private:
    elem* set;
    std::size_t size{};
    std::size_t capacity{};

private:
    void CopyToNewStorage(elem* NEW_STORAGE, const int& without = -1) {
        if (without == -1) {
            for (int i = 0; i < size; ++i) {
                NEW_STORAGE[i] = set[i];
            }
            return;
        } else {
            bool found = false;
            for (std::size_t i = 0; i < size; ++i) {
                if (i == static_cast<std::size_t>(without)) {
                    found = true;
                    continue;
                }
                if (!found) {
                    NEW_STORAGE[i] = set[i];
                } else {
                    NEW_STORAGE[i - 1] = set[i];
                }
            }
            return;
        }
    }
    void init() {
        for (std::size_t i = size; i < capacity; ++i) {
            set[i] = elem{};
        }
    }

public:
    // init
    explicit Set() {
        size = 0;
        capacity = 3;
        set = new elem[capacity];
    }
    // init
    explicit Set(const std::initializer_list<elem>& list) {
        size = list.size();
        capacity = size == 0 ? 3 : size * 2;
        set = new elem[capacity];
        int counter = 0;
        for (const elem& it : list) {
            if (auto found = std::find(begin(), end(), it); found == end()) {
                set[counter++] = it;
            }
        }
        std::sort( set, set + size );
    }
    // copy
    explicit Set(const Set& other) {
        this->Copy(other);
    }
    Set(Set&& other) noexcept {
        size = other.size;
        capacity = other.capacity;
        set = other.set;
        ///////////////////////////
        other.size = 0;
        other.capacity = 0;
        other.set = nullptr;
    }
    elem* begin() {
        return set + 0;
    }
    const elem* begin() const {
        return set + 0;
    }
    elem* end() {
        return set + size;
    }
    const elem* end() const {
        return set + size;
    }
    [[nodiscard]] bool IsFull() const {
        return size >= capacity;
    }
    [[nodiscard]] bool IsEmpty() const {
        return size == 0;
    }
    void Resize() {
        capacity *= 2;
        elem* AuxiliarySet = new elem[capacity];
        this->CopyToNewStorage(AuxiliarySet);
        delete[] set;
        set = AuxiliarySet;
    }
    [[nodiscard]] std::size_t Size() const {
        return size;
    }
    [[nodiscard]] std::size_t Capacity() const {
        return capacity;
    }
    void Add(const elem& AddElem) {
        if (this->IsFull()) {
            this->Resize();
        }
        auto it = std::find(this->begin(), this->end(), AddElem);
        if (it == this->end()) {
            set[size++] = AddElem;
            std::sort(set, set + size);
        }
    }
    void PopBack() {
        if (!this->IsEmpty()) {
            --size;
        }
    }
    void PopFront() {
        if (this->IsEmpty()) {
            return;
        }
        elem* AuxiliarySet = new elem[capacity];
        this->CopyToNewStorage(AuxiliarySet, 0);
        delete[] set;
        set = AuxiliarySet;
        --size;
    }
    void Remove(const elem& target) {
        if (this->IsEmpty()) {
            return;
        }
        for (std::size_t i = 0; i < size; ++i) {
            if (set[i] == target) {
                elem* AuxiliarySet = new elem[capacity];
                this->CopyToNewStorage(AuxiliarySet, static_cast<int>(i));
                --size;
                delete[] set;
                set = AuxiliarySet;
                return;
            }
        }
    }
    void Copy(const Set& other) {
        delete[] set;
        size = other.size;
        capacity = other.capacity;
        set = new elem[capacity];
        for (int i = 0; i < size; ++i) {
            set[i] = other.set[i];
        }
    }
    ~Set() {
        delete[] set;
        set = nullptr;
    }
};
