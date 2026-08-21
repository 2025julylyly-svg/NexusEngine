#pragma once
#include <exception>
#include <iostream>
#include <smmintrin.h>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include "NotFoundKeyError.h"
#include "String.h"
#define PRIME 5091
namespace Mapping {
    template<typename type>
    bool is_class() {
        if constexpr (std::is_integral_v<type> or std::is_floating_point_v<type> or std::is_same_v<type, std::string> or std::is_same_v<type, String>) {
            return false;
        } else {
            return true;
        }
    }

    template<typename key>
    class HashKey final
    {
    public:
        long int Hash(const key& KEY) noexcept {
            if constexpr (std::is_integral_v<key> or std::is_floating_point_v<key>) {
                std::size_t sum = 0;
                constexpr int PrimeNumbers[] = { 1009, 1013, 1019, 1021, 1031, 1033, 1039 };
                constexpr int Length = sizeof(PrimeNumbers) / sizeof( int );
                int index = 0;
                for (std::size_t i = 0; i < 10; ++i) {
                    sum = sum + PrimeNumbers[index] + KEY;
                    index = (index + 1) % Length;
                }
                return static_cast<long int>(sum) % PRIME;
            } else if constexpr (std::is_same_v<key, std::string>) {
                std::size_t sum = 0;
                constexpr int PrimeNumbers[] = { 1009, 1013, 1019, 1021, 1031, 1033, 1039 };
                constexpr int Length = sizeof(PrimeNumbers) / sizeof( int );
                int index = 0;
                for (std::size_t i = 0; KEY[i]; ++i) {
                    sum = ((sum + PrimeNumbers[index]) * PrimeNumbers[index]) + KEY[i];
                    index = (index + 1) % Length;
                }
                return static_cast<long int>(sum) % PRIME;
            } else if (std::is_same_v<key, String>) {
                std::size_t sum = 0;
                constexpr int PrimeNumbers[] = { 1009, 1013, 1019, 1021, 1031, 1033, 1039 };
                constexpr int Length = sizeof(PrimeNumbers) / sizeof( int );
                int index = 0;
                for (int i = 0; i < KEY.Length(); ++i) {
                    sum = ((sum + PrimeNumbers[index]) * PrimeNumbers[index]) + KEY[i];
                    index = (index + 1) % Length;
                }
                return static_cast<long int>(sum) % PRIME;
            } else {
                return -1;
            }
        }
    };

    template<typename KeyType, typename ValueType>
    class Iterator;

    template<typename KeyType, typename ValueType>
    class HashMap
    {
    private:
        bool KeyIsClass = Mapping::is_class<int>();

        struct bucket
        {
            std::pair<KeyType, ValueType> Data;
            bucket* next;
        };

        Mapping::HashKey<KeyType> hash;
        bucket** MAP = nullptr;
        bucket** AuxiliaryMAP = nullptr;
        std::size_t KeyCounter;
        std::size_t BucketCounter;

        void init() {
            for (std::size_t i = 0; i < BucketCounter; ++i) {
                MAP[i] = nullptr;
            }
        }

        void InsertDataToBucket(bucket** table, std::size_t bucketNumber, bucket* node) {
            node->next = nullptr;
            if (table[bucketNumber] == nullptr) {
                table[bucketNumber] = node;
                return;
            }
            bucket* current = table[bucketNumber];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }

        void TransferDataToAuxiliaryMAP() {
            AuxiliaryMAP = new bucket*[BucketCounter * 2];
            for (int i = 0; i < BucketCounter; ++i) {
                bucket* temp = MAP[i];
                while (temp != nullptr) {
                    if (const std::size_t BucketNumber = hash.Hash( temp->Data.first ) % (BucketCounter * 2); BucketNumber != 0) this->InsertDataToBucket( MAP, BucketNumber, temp );
                    temp = temp->next;
                }
            }
        }

        void FreeStorageSpace() {
            for (std::size_t i = 0; i < BucketCounter; ++i) {
                bucket* temp = MAP[i];
                while (temp != nullptr) {
                    const bucket* temp2 = temp;
                    temp = temp->next;
                    delete temp2;
                }
            }
            delete[] MAP;
            MAP = nullptr;
            AuxiliaryMAP = nullptr;
        }

        void AppointmentFromMapToAuxiliaryMAP() {
            MAP = AuxiliaryMAP;
        }

    public:
        bucket* Find(const KeyType& key) noexcept {
            bucket* temp = MAP[hash.Hash( key ) % BucketCounter];
            if (temp == nullptr) {
                return nullptr;
            }
            while (temp != nullptr) {
                if (temp->Data.first == key) {
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }

        // class Iterator friend this class
        friend class Iterator<KeyType, ValueType>;

        // Default Constructor
        HashMap() noexcept {
            BucketCounter = 1;
            KeyCounter = 0;
            MAP = new bucket*[BucketCounter];
            this->init();
        }

        // Initialisation Constructor
        explicit HashMap(const std::size_t& SetBucketCounter) noexcept {
            KeyCounter = 0;
            BucketCounter = SetBucketCounter;
            MAP = new bucket*[BucketCounter];
            this->init();
        }

        // Copy Constructor
        HashMap(const HashMap& other) noexcept {
            BucketCounter = other.BucketCounter;
            KeyCounter = other.KeyCounter;
            MAP = new bucket*[BucketCounter];
            for (std::size_t i = 0; i < BucketCounter; ++i) {
                MAP[i] = new bucket;
            }
            for (std::size_t i = 0; i < BucketCounter; ++i) {
                for (std::size_t j = 0; j < BucketCounter; ++j) {
                    MAP[i][j] = other.MAP[i][j];
                }
            }
        }

        // Move Constructor
        HashMap(HashMap&& other) noexcept {
            this->BucketCounter = other.BucketCounter;
            this->KeyCounter = other.KeyCounter;
            delete [] MAP;
            this->MAP = other.MAP;
            this->AuxiliaryMAP = other.AuxiliaryMAP;
            other.BucketCounter = 0;
            other.KeyCounter = 0;
            other.MAP = nullptr;
            other.AuxiliaryMAP = nullptr;
        }

        Iterator<KeyType, ValueType> begin() {
            return Iterator<KeyType, ValueType>( this, static_cast<std::size_t>(0) );
        }

        Iterator<KeyType, ValueType> end() {
            return Iterator<KeyType, ValueType>( this, true );
        }

        void Clear() noexcept {
            this->FreeStorageSpace();
            MAP = new bucket*[BucketCounter];
            this->init();
            KeyCounter = 0;
        }

        void Rehash() {
            if (! KeyIsClass) {
                const std::size_t newBucketCounter = BucketCounter * 2;
                auto** newMap = new bucket*[newBucketCounter] {};
                for (std::size_t i = 0; i < BucketCounter; ++i) {
                    bucket* current = MAP[i];
                    while (current != nullptr) {
                        bucket* next = current->next;
                        const std::size_t newIndex = hash.Hash( current->Data.first ) % newBucketCounter;
                        current->next = newMap[newIndex];
                        newMap[newIndex] = current;
                        current = next;
                    }
                }
                delete[] MAP;
                MAP = newMap;
                BucketCounter = newBucketCounter;
            }
            else {
                const std::size_t newBucketCounter = BucketCounter * 2;
                std::size_t BucketNumber = 0;
                std::size_t KeyNumber = 0;
                auto** newMap = new bucket*[newBucketCounter] {};
                for (std::size_t i = 0; i < BucketCounter; ++i) {
                    bucket* current = MAP[i];
                    while (current != nullptr) {
                        bucket* next = current->next;
                        const std::size_t newIndex = (KeyNumber % 5) == 0 ? ++BucketNumber : BucketNumber;
                        current->next = newMap[newIndex];
                        newMap[newIndex] = current;
                        current = next;
                        ++KeyNumber;
                    }
                }
                delete[] MAP;
                MAP = newMap;
                BucketCounter = newBucketCounter;
            }
        }

        void Remove(const KeyType& KeyTarget) {
            if (bucket* FoundResult = this->Find( KeyTarget ); FoundResult != nullptr) {
            }
        }
        void KeyCreateWithDefaultValue(const KeyType& key) {
            if (KeyCounter >= BucketCounter) {
                this->Rehash();
            }
            if (bucket* found = Find( key ); found != nullptr) {
                return;
            }
            auto* New = new bucket { { *key, ValueType {} }, nullptr };
            const std::size_t BucketIndex = hash.Hash( key ) % BucketCounter;
            InsertDataToBucket( MAP, BucketIndex, New );
            ++KeyCounter;
        }

        ValueType& operator[](const KeyType* key) {
            if (KeyCounter >= BucketCounter) {
                this->Rehash();
            }
            if (bucket* found = Find( *key ); found != nullptr) {
                return found->Data.second;
            }
            auto* New = new bucket { { *key, ValueType {} }, nullptr };
            const std::size_t BucketIndex = hash.Hash( *key ) % BucketCounter;
            InsertDataToBucket( MAP, BucketIndex, New );
            ++KeyCounter;
            return New->Data.second;
        }

        ValueType& operator[](const KeyType& key) {
            if (KeyCounter >= BucketCounter) {
                Rehash();
            }
            if (bucket* found = Find( key ); found != nullptr) {
                return found->Data.second;
            }
            auto* newBucket = new bucket { { key, ValueType {} }, nullptr };
            const std::size_t bucketNumber = hash.Hash( key ) % BucketCounter;
            InsertDataToBucket( MAP, bucketNumber, newBucket );
            ++KeyCounter;
            return newBucket->Data.second;
        }

        ~HashMap() {
            this->FreeStorageSpace();
        }
    };

    template<typename Key, typename Value>
    class Iterator
    {
    private:
        using Reference = std::pair<Key, Value>&;
        using Pointer = std::pair<Key, Value>*;
        using bucket = HashMap<Key, Value>::bucket;
        using bucket_ptr_ptr = bucket**;
        using bucket_ptr = bucket*;

    private:
        std::size_t BuckNumber;
        std::size_t CurrentBucketIndex;
        bucket_ptr CurrentNode;
        bucket_ptr_ptr Bucks;

        void JumpToNextBucket() {
            ++CurrentBucketIndex;
            while (CurrentBucketIndex < BuckNumber && Bucks[CurrentBucketIndex] == nullptr) {
                ++CurrentBucketIndex;
            }
            CurrentNode = (CurrentBucketIndex < BuckNumber) ? Bucks[CurrentBucketIndex] : nullptr;
        }

    public:
        Iterator(HashMap<Key, Value>* map, const std::size_t startIndex) noexcept {
            BuckNumber = map->BucketCounter;
            Bucks = map->MAP;
            CurrentBucketIndex = startIndex;
            CurrentNode = nullptr;
            while (CurrentBucketIndex < BuckNumber) {
                if (Bucks[CurrentBucketIndex] != nullptr) {
                    CurrentNode = Bucks[CurrentBucketIndex];
                    break;
                }
                ++CurrentBucketIndex;
            }
        }

        Iterator(HashMap<Key, Value>* map, bool /*isEnd*/) noexcept {
            BuckNumber = map->BucketCounter;
            Bucks = map->MAP;
            CurrentBucketIndex = BuckNumber;
            CurrentNode = nullptr;
        }

        Pointer operator->() const noexcept {
            return &(this->CurrentNode->Data);
        }

        Reference operator*() noexcept {
            return this->CurrentNode->Data;
        }

        bool operator==(const Iterator& other) const noexcept {
            return this->CurrentNode == other.CurrentNode;
        }

        bool operator!=(const Iterator& other) const noexcept {
            return this->CurrentNode != other.CurrentNode;
        }

        Iterator& operator=(const Iterator& other) {
            if (this == &other) return *this;
            this->BuckNumber = other.BuckNumber;
            this->CurrentBucketIndex = other.CurrentBucketIndex;
            this->CurrentNode = other.CurrentNode;
            this->Bucks = other.Bucks;
            return *this;
        }

        Iterator& operator++() {
            if (CurrentNode->next != nullptr) {
                CurrentNode = CurrentNode->next;
            } else {
                JumpToNextBucket();
            }
            return *this;
        }
    };
}
