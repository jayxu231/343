#include "customer.h"
#include <iostream>

using namespace std;

Customer::Customer(int i, const string &first, const string &last) {
    id = i;
    firstName = first;
    lastName = last;
}

int Customer::getId() const {
    return id;
}
string Customer::getName() const {
    return getFirst() + getLast();
}
string Customer::getFirst() const {
    return firstName;
}
string Customer::getLast() const {
    return lastName;
}
void Customer::record(Transaction* t) {
    if (!t) return;
    history.add(t);
}
void Customer::printHistory() const {
    cout << "History for " << getName()
              << " (ID " << id << "):\n";
    history.print();
}
