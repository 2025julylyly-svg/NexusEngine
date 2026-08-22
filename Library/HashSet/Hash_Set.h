#pragma once
#include <String.h>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <string>
#include <typeinfo>
#define PRIME_NUMBER 7691
using HashNumber = long long int;
using Size = unsigned long int;
namespace {
    template<typename data>
    HashNumber hash(const data& Data) {
        constexpr int prime[10] = {53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        constexpr short int len = 10;
        int index = 0;
        if constexpr (std::is_integral_v<data> || std::is_floating_point_v<data>) {
            HashNumber result = 0;
            const int LoopNumber = static_cast<int>(sqrt( Data ));
            for (int i = 0; i < LoopNumber; ++i) {
                result += prime[index] + Data + 7;
                index = (index + 1) % len;
            }
            return result % PRIME_NUMBER;
        } else if constexpr (std::is_same_v<data, std::string> || std::is_same_v<data, String>) {
            HashNumber result = 0;
            for (const char& ch : Data) {
                result += (static_cast<int>(ch) + prime[index]) * 11;
                index = (index + 1) % len;
            }
            return result % PRIME_NUMBER;
        } else {
            return -1;
        }
    }
}
template<typename elem>
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
    Bucket** set = nullptr;
    Size size{};
    Size capacity{};

private: // functions
    void inti_set() {
        for (Size i = 0; i < capacity; ++i) {
            set[i] = nullptr;
        }
    }
    void FreeSet() {
        for (Size i = 0; i < capacity; ++i) {
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
    void CopyToSet(Bucket** NewSet, const Size& SizeSet) {
        if (set == nullptr) {
            set = new Bucket*[SizeSet];
        }
        for (Size buck = 0; buck < SizeSet; ++buck) {
            Bucket* temp = NewSet[buck];
            while (temp != nullptr) {
                Bucket* New = new Bucket{temp->Val, temp->next};
                this->InsertToSet( set, SizeSet, New );
                temp = temp->next;
            }
        }
    }
    void InsertToSet(Bucket** target_set, const Size& bucket_number, Bucket* New) {
        Bucket* temp = target_set[bucket_number];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = New;
    }

public:
    explicit HashSet() {
        size = 0;
        capacity = 5;
        set = new Bucket*[capacity];
        this->inti_set();
    }
    explicit HashSet(const std::initializer_list<elem>& list) {
        size = list.size();
        capacity = size <= 1 ? 5 : size * 2;
        set = new Bucket*[capacity];
        inti_set();
    }
    explicit HashSet(const HashSet& other) {
        size = other.size;
        capacity = other.capacity;
        this->CopyToSet( other.set, size );
    }
    explicit HashSet(HashSet&& other) noexcept {
        size = other.size;
        capacity = other.capacity;
        set = other.set;
        //////////////////////////
        other.size = 0;
        other.capacity = 2;
        other.FreeSet();
    }
    ~HashSet() {
        this->FreeSet();
    }
}; // class HashSet
