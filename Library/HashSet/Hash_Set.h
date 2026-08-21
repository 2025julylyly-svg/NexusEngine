#pragma once
#include <cstddef>
template <typename elem>
class HashSet
{
private: // bucket
    class Bucket
    {
    public:
        elem Val;
        Bucket* next;
    };
private: // data
    Bucket** set;
    std::size_t size;
    std::size_t capacity;
private: // functions
    void inti_set() {
        for (std::size_t i = 0; i < capacity; ++i) {
            set[i] = nullptr;
        }
    }
    void FreeSet() {
        for (std::size_t i = 0; i < capacity; ++i) {
            Bucket* temp = set[i];
            while (temp != nullptr) {
                const Bucket* Delete = temp;
                temp = temp->next;
                delete[] Delete;
            }
        }
        delete[] set;
        set = nullptr;
    }
public:
    explicit HashSet() {
        size = 0;
        capacity = 5;
        set = new Bucket*[capacity];
        this->inti_set();
    }
    ~HashSet() {
        this->FreeSet();
    }
};