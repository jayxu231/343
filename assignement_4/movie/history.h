#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include "transaction.h"

using namespace std; 
class History {
private:
    vector<Transaction *> transactions;

public:
    History() = default;
    ~History();    
    void add(Transaction * t);
    vector<Transaction *> latestFirst() const;
    void print() const;
};

#endif
