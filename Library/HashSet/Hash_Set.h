#pragma once
#include <String.h>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <string>
#include <typeinfo>
#define PRIME_NUMBER 7691
namespace {
    using HashNumber = long long int;
    using USize = unsigned long int;
    using BuckNumber = unsigned int;
    template<typename data>
    HashNumber hash(const data& Data) {
        constexpr int prime[10] = { 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
        constexpr short int len = 10;
        int index = 0;
        if constexpr (std::is_integral_v<data> || std::is_floating_point_v<data>) {
            HashNumber result = 0;
            const int LoopNumber = static_cast<int>(sqrt(Data));
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
} // namespace
template<typename V>
class Iterator;
template<typename elem>
class HashSet
{
private: // bucket
    class Bucket
    {
    public:
        elem Val;
    private:
        Bucket* next;
        friend class HashSet;
        friend class Iterator<elem>;
    };

private: // data
    Bucket** set = nullptr;
    USize size{};
    USize BucketCounter{};
    bool SetIsNull = true;
    friend class Iterator<elem>;

private: // functions
    static void init(Bucket** target, const USize& SIZE) {
        for (USize i = 0; i < SIZE; ++i) {
            target[i] = nullptr;
        }
    }
    void init_set() {
        for (USize i = 0; i < BucketCounter; ++i) {
            set[i] = nullptr;
        }
    }
    void FreeSet() {
        for (USize i = 0; i < BucketCounter; ++i) {
            Bucket* temp = set[i];
            while (temp != nullptr) {
                const Bucket* Delete = temp;
                temp = temp->next;
                delete[] Delete;
            }
        }
        delete[] set;
        set = nullptr;
        SetIsNull = true;
    }
    void CopyToSet(Bucket** NewSet) {
        if (SetIsNull) {
            set = new Bucket*[BucketCounter];
        }
        for (USize buck = 0; buck < BucketCounter; ++buck) {
            Bucket* temp = NewSet[buck];
            while (temp != nullptr) {
                auto* New = new Bucket{ .Val = temp->Val, .next = temp->next };
                const HashNumber& BCK_NMB = hash<elem>(New->Val) % BucketCounter;
                this->InsertToSet(set, BCK_NMB, New);
                temp = temp->next;
            }
        }
    }
    void InsertToSet(Bucket** target_set, const USize& bucket_number, Bucket* New) {
        Bucket* temp = target_set[bucket_number];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = New;
    }
    void MoveTo(Bucket** target) {
        for (USize buck = 0; buck < BucketCounter; ++buck) {
            Bucket* temp = set[buck];
            while (temp != nullptr) {
                const HashNumber Buc_Num = hash<elem>(temp->Val) % (BucketCounter * 2);
                InsertToSet(target, Buc_Num, temp);
                temp = temp->next;
            }
        }
    }
    [[nodiscard]] bool Empty() const {
        return size == 0;
    }
    [[nodiscard]] bool NeedToHash() const {
        return size >= BucketCounter;
    }

public:
    explicit HashSet() {
        size = 0;
        BucketCounter = 5;
        set = new Bucket*[BucketCounter];
        this->init_set();
    }
    explicit HashSet(const std::initializer_list<elem>& list) {
        size = list.size();
        BucketCounter = size <= 1 ? 5 : size * 2;
        set = new Bucket*[BucketCounter];
        init_set();
    }
    explicit HashSet(const HashSet& other) {
        size = other.size;
        BucketCounter = other.BucketCounter;
        this->CopyToSet(other.set);
    }
    explicit HashSet(HashSet&& other) noexcept {
        size = other.size;
        BucketCounter = other.BucketCounter;
        set = other.set;
        //////////////////////////
        other.size = 0;
        other.BucketCounter = 2;
        other.FreeSet();
    }
    Iterator<elem> begin() {
        return Iterator<elem>(this, static_cast<USize>(0));
    }
    Iterator<elem> end() {
        return Iterator<elem>(this, true);
    }
    void ReHashing() {
        if (Empty()) {
            return;
        }
        const USize NewBucketCounter = BucketCounter * 2;
        auto** AuxiliarySet = new Bucket*[NewBucketCounter];
        init(AuxiliarySet, NewBucketCounter);
        for (USize i = 0; i < BucketCounter; ++i) {
            MoveTo(AuxiliarySet, NewBucketCounter);
        }
        this->FreeSet();
        set = AuxiliarySet;
        BucketCounter = NewBucketCounter;
    }
    void Add(const elem& target) {
        if (NeedToHash()) {
            this->ReHashing();
        }
        const BuckNumber BCK_NMB = hash<elem>(target) % BucketCounter;
        auto* New = new Bucket{ .Val = target, .next = nullptr };
        this->InsertToSet(set, BCK_NMB, New);
        SetIsNull = false;
        ++size;
    }
    void Remove(const elem& target);
    HashSet& operator=(const std::initializer_list<elem>& list) {
        size = list.size();
        BucketCounter = size <= 1 ? 5 : size * 2;
        if (SetIsNull) {
            FreeSet();
        }
        set = new Bucket*[BucketCounter];
        this->init_set();
        for (const elem& item : list) {
        }
    }
    bool operator==(const HashSet&) const;
    bool operator==(const std::initializer_list<elem>& list) const;
    ~HashSet() {
        this->FreeSet();
    }
}; // class HashSet
template<typename V>
class Iterator
{
private:
    using Reference = V&;
    using Pointer = V*;
    using bucket = HashSet<V>::Bucket;
    using bucket_ptr = bucket*;
    using bucket_ptr_ptr = bucket**;

private:
    USize BuckNumber;
    USize CurrentBuckNumber;
    Pointer CurrentNode;
    bucket_ptr_ptr Buckets;

private:
    void JumpToNextBucket() {
        ++CurrentBuckNumber;
        while (CurrentBuckNumber < BuckNumber && Buckets[CurrentBuckNumber] == nullptr) {
            ++CurrentBuckNumber;
        }
        CurrentNode = (CurrentBuckNumber < BuckNumber) ? Buckets[CurrentBuckNumber] : nullptr;
    }

public:
    Iterator(HashSet<V>* sh_set, const USize& start_index) {
        CurrentBuckNumber = start_index;
        Buckets = sh_set->set;
        BuckNumber = sh_set->BucketCounter;
        CurrentNode = nullptr;
        while (CurrentBuckNumber < BuckNumber) {
            if (Buckets[CurrentBuckNumber] != nullptr) {
                CurrentNode = Buckets[CurrentBuckNumber];
                break;
            }
            ++CurrentBuckNumber;
        }
    }
    Iterator(HashSet<V>* sh_set, bool /*isEnd*/) noexcept {
        BuckNumber = sh_set->BucketCounter;
        CurrentBuckNumber = BuckNumber;
        Buckets = sh_set->set;
        CurrentNode = nullptr;
    }
    Reference operator*() noexcept {
        return CurrentNode->Val;
    }
    Pointer operator->() const noexcept {
        return &(CurrentNode->Val);
    }
    bool operator==(const Iterator& other) const {
        return *this == other;
    }
    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }
    Iterator& operator=(const Iterator& other) {
        if (&other == this)
            return *this;
        this->BuckNumber = other.BuckNumber;
        this->Buckets = other.Buckets;
        this->CurrentNode = other.CurrentNode;
        this->CurrentBuckNumber = other.CurrentBuckNumber;
        return *this;
    }
    Iterator& operator++() {
        if (CurrentNode->next != nullptr) {
            CurrentNode = CurrentNode->next;
        } else {
            this->JumpToNextBucket();
        }
        return *this;
    }
};
