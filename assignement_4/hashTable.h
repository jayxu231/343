#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>

using namespace std;

template <typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
        bool occupied;
        Entry() : occupied(false) {}
    };

    vector<Entry> buckets;
    int capacity;

public:
    HashTable(int size = 101);
    void put(const K& key, const V& value);
    V get(const K& key) const;
    bool has(const K& key) const;

private:
    int hashFunction(const K& key) const;
};


#endif