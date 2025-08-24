#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>

class Customer;

class HashTable {
public:
    explicit HashTable(int size = 101);

    // Insert or replace by customer ID (pulled from c->getId()).
    void put(Customer* c);

    // Lookup by ID; returns nullptr if not found.
    Customer* get(int id) const;

    // Convenience exists check.
    bool has(int id) const;

    // Helper to iterate values (for CustomerDirectory::printAll()).
    std::vector<Customer*> collectValues() const;

private:
    struct Entry {
        int key = 0;               // customer ID
        Customer* value = nullptr; // pointer to customer
        bool occupied = false;     // slot currently holds a value
        // No 'deleted' tombstone since we don't implement remove()
    };

    int capacity;
    int count;
    std::vector<Entry> buckets;

    int hashFunction(int key) const;
    void rehash(int newCapacity);
};

#endif
