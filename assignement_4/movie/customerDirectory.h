#ifndef CUSTOMERDIRECTORY_H
#define CUSTOMERDIRECTORY_H

#include "hashTable.h"
#include "customer.h"

class CustomerDirectory {
private:
    HashTable table;
public:
    void put(Customer* c);
    Customer* get(int id) const;
    bool has(int id) const;
    void printAll() const;
    
};

#endif
