#include "customerDirectory.h"
#include "customer.h"
#include <iostream>
#include <vector>

void CustomerDirectory::put(Customer* c) {
    if (!c) return;
    table.put(c);
}

Customer* CustomerDirectory::get(int id) const {
    return table.get(id);
}

bool CustomerDirectory::has(int id) const {
    return table.has(id);
}
std::vector<Customer*> HashTable::collectValues() const {
    std::vector<Customer*> out;
    out.reserve(count);
    for (const auto& e : buckets) {
        if (e.occupied && !e.deleted && e.value) {
            out.push_back(e.value);
        }
    }
    return out;
}
void CustomerDirectory::printAll() const {
    std::vector<Customer*> all = table.collectValues();  // requires helper below
    if (all.empty()) {
        std::cout << "(no customers)\n";
        return;
    }
    for (const Customer* c : all) {
        if (!c) continue;
        std::cout << "ID " << c->getId() << " : " << c->getName() << "\n";
    }
}
