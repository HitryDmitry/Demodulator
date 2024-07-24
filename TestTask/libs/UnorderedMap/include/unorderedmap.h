#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H
#include <iostream>
#include <unordered_map>
#include "UnorderedMap_global.h"

template <class Key, class Value>
struct Pair {
public:
    Pair()
    {}
    Pair(Key key, Value value) : key(key), value(value)
    {}
    Pair(Pair& p) : key(p.key), value(p.value), bucketId(p.bucketId), nextPair(p.nextPair)
    {}
    // copy assignment constructor
    Pair& operator=(const Pair& p)
    {
        if(this != &p) {
            this->bucketId = p.bucketId;
            this->key      = p.key;
            this->value    = p.value;
            this->nextPair = p.nextPair;
        }
        return *this;
    }
    ~Pair()
    {
        if(nextPair)
            delete nextPair;
    }

    Key key;
    Value value;
    int bucketId    = -1;
    Pair* nextPair  = nullptr;
    bool objOnStack = false;
};

template <class Key, class Value>
class UnorderedMap {
public:
    UnorderedMap() : numberOfBuckets(13), bucketPointersArray(new Pair<Key, Value>[numberOfBuckets])
    {}

    // list constructor
    UnorderedMap(const std::initializer_list<UnorderedMap<Key, Value>>& init)
    {}

    UnorderedMap(Key k, Value v)
    {
        if(!bucketPointersArray) {
            numberOfBuckets     = 13;
            bucketPointersArray = new Pair<Key, Value>[numberOfBuckets];
        }
        this->insert(k, v);
    }

    // copy constructor
    UnorderedMap(const UnorderedMap<Key, Value>& objToCopy)
    {
        this->numberOfBuckets     = objToCopy.numberOfBuckets;
        this->bucketPointersArray = new Pair<Key, Value>[this->numberOfBuckets];

        for(int i = 0; i < this->numberOfBuckets; ++i) {
            // // копируем первый объект
            // this->bucketPointersArray[i] = objToCopy.bucketPointersArray[i];

            // указатель на первую пару копируемого объекта
            Pair<Key, Value>* pairOfobjToCopy = objToCopy.bucketPointersArray + i;

            while(pairOfobjToCopy->nextPair != nullptr) {
                this->insert(pairOfobjToCopy->key, pairOfobjToCopy->value);
                pairOfobjToCopy = pairOfobjToCopy->nextPair;
            }
        }
    }

    // assignment operator
    UnorderedMap& operator=(const UnorderedMap<Key, Value>& objectToAssign)
    {}

    void insert(Key key, Value value)
    {
        int indexOfBucketToInsert = hasher(key) % 13;

        // записываем Pair, который содержался в корзине, во временную копию
        Pair<Key, Value>* tmp                      = new Pair<Key, Value>(bucketPointersArray[indexOfBucketToInsert]);
        tmp->bucketId                              = indexOfBucketToInsert;
        bucketPointersArray[indexOfBucketToInsert] = Pair<Key, Value>(key, value);
        bucketPointersArray[indexOfBucketToInsert].nextPair = tmp;
    }

    Value get(Key key)
    {
        Value searchResult;
        // получаем id ключа для поиска
        int targetIndex     = hasher(key) % 13;
        Pair<Key, Value>* b = bucketPointersArray + targetIndex;
        searchResult        = b->value;
        return searchResult;
    }

    void remove(Key key)
    {
        // получаем id ключа для поиска
        int targetIndex = hasher(key) % 13;

        Pair<Key, Value>* pairPtr = bucketPointersArray + targetIndex;
        // pairPtr->objOnStack       = true;

        if((bucketPointersArray + targetIndex)->nextPair) {
            pairPtr                          = pairPtr->nextPair;
            pairPtr->nextPair                = nullptr;
            bucketPointersArray[targetIndex] = *(bucketPointersArray[targetIndex].nextPair);
            delete pairPtr;
        }
    }

    ~UnorderedMap()
    {
        delete[] bucketPointersArray;
    }

private:
    std::hash<Key> hasher;
    int numberOfBuckets                   = 0;
    Pair<Key, Value>* bucketPointersArray = nullptr;
};

// #include "unorderedmap.cpp"
#endif // UNORDEREDMAP_H
