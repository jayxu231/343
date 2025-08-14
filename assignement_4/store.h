#ifndef STORE_H
#define STORE_H

#include <string>
#include "inventory.h"
#include "customerDirectory.h"


using namespace std;

class Store {
private:
    Inventory inventory;
    CustomerDirectory customers;
//will call movie factory in cpp file

public:
    void loadMovies(const string &filename);
    void loadCustomers(const string &filename);
    void processCommands(const string &filename);
    void printInventory() cosnt;
    void printHistory(int customerId) const;
};

#endif