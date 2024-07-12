#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H
#include <iostream>
#include <unordered_map>
#include "UnorderedMap_global.h"

template <class Key, class Value>
struct Pair {
    Pair()
    {}
    Pair(Key key, Value value) : key(key), value(value)
    {}
    Key key;
    Value value;
    int bucketId   = -1;
    Pair* nextPair = nullptr;
};

template <class Key, class Value>
struct Bucket {
    Bucket()
    {}
    Bucket(Key key, Value value) : key(key), value(value)
    {}
    Key key;
    Value value;
    int bucketId       = -1;
    Bucket* nextBacket = nullptr;
};

template <class Key, class Value>
class UnorderedMap {
public:
    UnorderedMap() : numberOfBuckets(13), bucketPointersArray(new Pair<Key, Value>[numberOfBuckets])
    {
        // for(int i = 0; i < numberOfBuckets; ++i) {
        //     bucketPointersArray + 1 = nullptr;
        // }
    }

    void insert(Key key, Value value)
    {
        unsigned int indexOfBucketToInsert = hasher(key) % 13;
        // создаем новый объект Pair
        Pair<Key, Value> pairToInsert(key, value);
        // Pair<Key, Value>* tmp = new Pair<Key, Value>(key, value);
        // проверяем полученный индекс
        if(bucketPointersArray[indexOfBucketToInsert].bucketId != -1) {
            // записываем Pair, который содержался в корзине, во временную копию
            Pair<Key, Value> tmp = bucketPointersArray[indexOfBucketToInsert];
            //
            bucketPointersArray[indexOfBucketToInsert] = pairToInsert;
            pairToInsert.nextPair                      = &tmp;
        }
        else {
            // указатель по индексу indexOfBucketToInsert указывает на полученный выше объект
            pairToInsert.bucketId                      = indexOfBucketToInsert;
            bucketPointersArray[indexOfBucketToInsert] = pairToInsert;
        }
    }

    Value get()
    {}

    ~UnorderedMap()
    {
        delete[] bucketPointersArray;
    }

private:
    // // позволяет вычислить номер корзины по ключу
    // int hash(Key key)
    // {
    //     int remainder = numberOfBuckets % 8;
    //     ++numberOfBuckets;
    //     return remainder;
    // }

    std::hash<Key> hasher;
    int numberOfBuckets;
    Pair<Key, Value>* bucketPointersArray;
};

// #include "unorderedmap.cpp"
#endif // UNORDEREDMAP_H
