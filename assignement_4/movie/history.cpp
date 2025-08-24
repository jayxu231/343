#include "history.h"
#include <iostream>

using namespace std;

History::~History() {
    for (Transaction* t : transactions) {
        delete t;
    }
    transactions.clear();
}

void History::add(Transaction* t) {
    if (t) transactions.push_back(t);
}

vector<Transaction*> History::latestFirst() const {
    vector<Transaction*> reversed;
    for (auto it = transactions.rbegin(); it != transactions.rend(); ++it) {
        reversed.push_back(*it);
    }
    return reversed;
}

void History::print() const {
    if (transactions.empty()) {
    cout << "  (no transactions)\n";
        return;
    }
    for (auto it = transactions.rbegin(); it != transactions.rend(); ++it) {
        cout << "  " << (*it)->describe() << endl;
    }
}
