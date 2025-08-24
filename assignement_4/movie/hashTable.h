#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include "customer.h"

class HashTable {
private:
    struct Entry {
        int key;            // customer ID
        Customer* value;    // pointer to Customer
        bool occupied;
        Entry() : key(0), value(nullptr), occupied(false) {}
    };

    std::vector<Entry> buckets;
    int capacity;
    int count;
public:
    HashTable(int size = 101);

    // Insert or update
    void put(int key, Customer* value);

    // Get a customer pointer by ID (nullptr if not found)
    Customer* get(int key) const;

    // Check if a customer exists
    bool has(int key) const;
    std::vector<Customer*> HashTable::collectValues() const ;
private:
    int hashFunction(int key) const;

};

#endif
