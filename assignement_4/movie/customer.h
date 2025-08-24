#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "history.h"

using namespace std; 

class Transaction;

class Customer {
private:
    int id;
    string firstName;
    string lastName;

    History history;

public:
    Customer(int i, const string &first, const string &last);

    int getId() const;
    string getName() const;
    string getFirst() const;
    string getLast() const;
    void record(Transaction * t);
    void printHistory() const; 

};


#endif